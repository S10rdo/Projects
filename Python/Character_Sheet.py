import random

racesList = ["Human", "Orc", "Elf", "Gnome", "Dwarf"] #List of race options
classesList = ["Barbarian", "Rogue", "Wizard", "Cleric", "Bard"] #List of class options

raceChosen = ""


def raceQuery(): #Lists races
    print("Available Races: ") 
    print(*racesList, sep='\n')
    print()

def classQuery(): #Lists classes 
    print("Available Classes: ")
    print(*classesList, sep='\n')
    print()
    
    
def statRollCalc(): #Generates ability scores
    rolls = [random.randint(1, 6) for _ in range(4)]  # roll 4d6
    rolls.remove(min(rolls))  # drop the lowest
    return sum(rolls)  # sum the remaining 3
    print(stat)
    
def statRoll(): #Print each ability score above its resulting roll
    print("STRENGTH",statRollCalc())
    print("DEXTERITY",statRollCalc())
    print("CONSTITUTION",statRollCalc())
    print("INTELLIGENCE",statRollCalc())
    print("WISDOM",statRollCalc())
    print("CHARISMA",statRollCalc())
    
def healthRollCalc(className):
    if className == "Barbarian":
        rHP = random.randint(1, 12) * 3
    elif className == "Wizard":
        rHP = random.randint(1, 6) * 3
    elif className in ["Rogue", "Cleric", "Bard"]:
        rHP = random.randint(1, 8) * 3
    else:
        rHP = 0 #Default hp
    print("HEALTH POINTS:", rHP)
    

def genRace():
    global raceChosen
    while True:
        raceSelect = input("Enter a race from the list, or 'R' for a random race: ")

        if raceSelect.lower() == 'r':
            chosenRace = random.choice(racesList)
        elif raceSelect in racesList:
            chosenRace = raceSelect
        else:
            print("Invalid input. Please try again.")
            raceQuery()
            continue

        print(f"\nYou have selected: {chosenRace}.")
        confirm = input("Is this correct? [Y/N] ")

        if confirm.lower() == 'y':
            raceChosen = chosenRace
            break
        else:
            print("Let's try again.\n")
            raceQuery()

    # Proceed to class selection
    classQuery()
    genClass()

def genClass():
    global raceChosen
    while True:
        classSelect = input("Enter a class from the list, or 'R' for a random class: ")

        if classSelect.lower() == 'r':
            chosenClass = random.choice(classesList)
        elif classSelect in classesList:
            chosenClass = classSelect
        else:
            print("Invalid input. Please try again.")
            classQuery()
            continue

        print(f"\nYou have selected: {chosenClass}.")
        confirm = input("Is this correct? [Y/N] ")

        if confirm.lower() == 'y':
            print("\nCHARACTER SHEET")
            print("----------------")
            print("RACE:", raceChosen)
            print("CLASS:", chosenClass)
            healthRollCalc(chosenClass)
            print()
            statRoll()
            print("----------------\n")
            return
        else:
            print("Let's try again.\n")
            classQuery()

def genRandom():
    global raceChosen
    raceChosen = random.choice(racesList)
    classChosen = random.choice(classesList)

    print("\nCHARACTER SHEET")
    print("----------------")
    print("RACE:", raceChosen)
    print("CLASS:", classChosen)
    healthRollCalc(classChosen)
    print()
    statRoll()
    print("----------------\n")

def genStart():
    while True:
        print("Do you wish to create a character manually, or have one randomly generated?")
        genSelect = input("Enter 'M' for Manual or 'R' for Random: ")
        print()

        if genSelect.lower() == 'm':
            raceQuery()
            genRace()
            break
        elif genSelect.lower() == 'r':
            genRandom()
            break
        else:
            print("Invalid selection. Please enter 'M' or 'R'.\n")
            
genStart()
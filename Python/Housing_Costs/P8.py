print("Project 8")
print()

fileName = input("Enter the file name: ") #set user input as variable

inputFile = open(fileName, 'r') #open and read input file from user input variable

print("%-15s%6s%15s%20s" % ("Location", "Price", "Value", "Rent(mo.)")) #Column headers with spacing
for line in inputFile:
    dataList = line.split() #Take data from file and create data list
    location = dataList[0] #Locations in 1st column
    squareFootage = int(dataList[1]) #Sq ft in 2nd column
    marketValueBase = int(dataList[2]) #Market value in 3rd column
    rentPercentage = float(dataList[3]) #Rent % from value in 4th column
    
    squareFootagePrice = marketValueBase / squareFootage #calculate sq ft pricein
    squareFootagePriceString = "$" + str(squareFootage) + "/sq ft" #convert sq ft price to string
    marketValueBaseString = "$" + str(marketValueBase) #convert market value to string

    monthlyRent = rentPercentage * marketValueBase / 100.0 #Monthly rent cost from market value and % of rent
    monthlyRentString = "$" + str(monthlyRent) #convert monthly rent to string
    
    print("%-15s%9s%12s%18.7s" % (location, squareFootagePriceString, marketValueBaseString, monthlyRentString)) #print results with spacing






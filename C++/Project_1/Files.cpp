#include "Files.h"

void read(floatArray &data){ //Stanley
    std::ifstream file("data.csv");
    std::string line;

    while(getline(file, line)){   
        std::string token;
        std::stringstream parser(line);

        while (getline(parser, token, ',')){ 
            float j = stof(token);
            data.push_back(j); 
        }
    } 
    file.close();
}
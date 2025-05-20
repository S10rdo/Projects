#include "Algorithms.h"

void reverse(floatArray &data){ //Hong Wei
    int numValues = data.size();
    for(int i=0; i<numValues/2; ++i){
        float temp = data.at(i);
        data.at(i) = data.at(numValues-1-i);
        data.at(numValues-1-i) = temp;
    }
}

float maxNeighborDiff (floatArray &data){ //Joseph, Stanley
    float Maxdiff = data.at(1) - data.at(0); 
    int numValues = data.size();
    for (int i = 0; i < numValues-1; ++i){
        float diff = data.at(i + 1) - data.at(i);
        if(diff<0){
            diff=-diff;
        }
        if (diff > Maxdiff) {
            Maxdiff = diff;
        }
    }return Maxdiff;
}
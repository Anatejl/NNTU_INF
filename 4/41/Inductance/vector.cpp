//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

Vector vectorInitialArrayInitialize(const Vector &initialArray, int coeffK) {

    int tempFirst = 0, tempSecond = 0;
    Vector temporaryVector;
    int counter = 0;
    std::vector<int> column;

    while(!std::cin.eof()) {
        int tempCIN;
        for(int i = 0 ;; ++i) {

            if(!std::cin.eof()) {

                temporaryVector.row.push_back(column);

                for (int j = 0; j < coeffK; ++j) {

                    if(!std::cin.eof()) {
                        std::cin >> tempCIN;
                        temporaryVector.row[i].push_back(tempCIN);
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
    }

    //if(temporaryVector.row[temporaryVector.row.end()].[2])

    return temporaryVector;

}

//int vectorGetSize(Vector &v) {
//
//    return v.value.size();
//}

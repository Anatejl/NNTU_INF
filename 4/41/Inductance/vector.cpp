//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

initialVector vectorInitialArrayInitialize(const initialVector &initialArray, int coeffK) {

    initialVector temporaryVector;
    std::vector<std::pair<double,double>> column;

    while(true) {
        std::pair<double,double> tempCIN;
        for(int i = 0 ;; ++i) {

            if(!std::cin.eof()) {

                temporaryVector.row.push_back(column);
                ++temporaryVector.counter;
                for (int j = 0; j < coeffK; ++j) {

                    if(!std::cin.eof()) {
                        std::cin >> tempCIN.first >> tempCIN.second;
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
        break;
    }

    while(temporaryVector.row[temporaryVector.row.size()-1].size() < coeffK){

        std::cout << "Value of " << temporaryVector.row[temporaryVector.row.size()-1][temporaryVector.row[temporaryVector.row.size()-1].size()-1].first
        << "/" << temporaryVector.row[temporaryVector.row.size()-1][temporaryVector.row[temporaryVector.row.size()-1].size()-1].second
        <<" was destroyed, since it don't comply with the rules." << std::endl;
        temporaryVector.row[temporaryVector.row.size()-1].pop_back();

        if(temporaryVector.row[temporaryVector.row.size()-1].empty()){

            temporaryVector.row.pop_back();

        }
    }

    return temporaryVector;

}

int vectorGetSize(initialVector &v) {

    return v.row.size();
}

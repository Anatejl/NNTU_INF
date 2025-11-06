#include "header.h"

int repeat(){

    fflush;
    char answer;
    std::cout << "\nAdd another (y/n)?" << std::endl;
    std::cin >> answer;
    if (answer == 'y'){return true;}
    else{return false;};

}

int addSensor(int currentWorkingSensor){

    std::vector<Sensor> vectorToPush;
    std::cout << "Input serial number for [Sensor " << currentWorkingSensor <<"]:" << std::endl;
    std::cin >> dataToPush.serial;


    std::cout << "Input values for [Sensor " << currentWorkingSensor << "]:" << std::endl;
    
    //debug
    int i = 1;
    
    while(true){

        //debug
        std::cout <<"[" << i << "]" << "Value" << std::endl;

        std::cout << "Enter value: ";
        std::cin >> dataToPush.value;

        vectorToPush.push_back(dataToPush);

        //debug
        std::cout << "Current vector:\n";
        for (int i = 0; i < vectorToPush.size(); ++i)
        {
            std::cout << "[" << i << "] - " << "Serial: " << vectorToPush[i].serial << " Value: " << vectorToPush[i].value << std::endl;
        }

        if(!repeat()){
            std::cout << "End entering values for Sensor " << currentWorkingSensor << ";" << std::endl;
            break;
        }
        ++i;
    
    }

    TotalSensors.push_back(vectorToPush);
    
    return 0;
}

int main(){

    std::cout << "Sensor min/max program!" << std::endl;

    std::cout << "How much Sensors do we have?" << std::endl;
    std::cin >> totalSensors;

    //FILL SENSORS
    for(int i = 1; i <= totalSensors; ++i){

        addSensor(currentWorkingSensor);

        ++currentWorkingSensor;
    }
 
    //DEBUG
    for (int i = 0; i < TotalSensors.size(); ++i){

        std::cout << "\n--- Sensor " << i << " ---" << std::endl;

        for (int j = 0; j < TotalSensors[i].size(); ++j){

            std::cout << "[" << i << "] - " << "Serial: " << TotalSensors[i][j].serial << " Value: " << TotalSensors[i][j].value << std::endl;
        }
    }

    return 0;
}
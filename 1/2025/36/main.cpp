#include "header.h"

int repeat(){

    fflush(stdout);
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
        for (int i = 0; i < vectorToPush.size(); ++i){

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

int findMinMaxAll(){

	MinMaxResults.clear();

	for (int i = 0; i < (int)TotalSensors.size(); ++i){
		MinMaxResult result;
		result.hasValues = false;

		const std::vector<Sensor> &sensorReadings = TotalSensors[i];
		
        if (sensorReadings.empty()){
			MinMaxResults.push_back(result);
			continue;
		}

		result.hasValues = true;
		result.minValue = sensorReadings[0].value;
		result.maxValue = sensorReadings[0].value;
		result.sensorSerial = sensorReadings[0].serial;

		for (int j = 1; j < (int)sensorReadings.size(); ++j){
			if (sensorReadings[j].value < result.minValue){
				result.minValue = sensorReadings[j].value;
			}
			if (sensorReadings[j].value > result.maxValue){
				result.maxValue = sensorReadings[j].value;
			}
		}

		MinMaxResults.push_back(result);
	}

	return 0;
}

void printMinMaxResults(){

    if (MinMaxResults.empty()){
        std::cout << "No min/max results available. Run findMinMaxAll() first." << std::endl;
        return;
    }

    std::cout << "\nMin/Max results per sensor:" << std::endl;
    for (int i = 0; i < (int)MinMaxResults.size(); ++i){

        const MinMaxResult &result = MinMaxResults[i];
        std::cout << "Sensor " << i+1 << ": ";

        if (!result.hasValues){
            std::cout << "(no readings)" << std::endl;
            continue;
        }

        std::cout << "min: " << result.minValue << " max: " << result.maxValue;
        std::cout << " (serial: " << result.sensorSerial << ")" << std::endl;

    }
}

int main(){

    std::cout << "Sensor min/max program!" << std::endl;

    std::cout << "How many Sensors do we have?" << std::endl;
    std::cin >> totalSensors;

    //FILL SENSORS
    for(int i = 1; i <= totalSensors; ++i){

        addSensor(currentWorkingSensor);

        ++currentWorkingSensor;
    }
 
    //DEBUG
    for (int i = 0; i < TotalSensors.size(); ++i){

        std::cout << "\n--- Sensor " << i+1 << " ---" << std::endl;

        for (int j = 0; j < TotalSensors[i].size(); ++j){

            std::cout << "[" << i+1 << "] - " << "Serial: " << TotalSensors[i][j].serial << " Value: " << TotalSensors[i][j].value << std::endl;
        
        }
    }

    findMinMaxAll();
    printMinMaxResults();

    return 0;
}
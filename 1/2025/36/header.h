#ifndef VAR_36
#define VAR_36

#include <iostream>
#include <vector>

typedef struct Sensor {

    int serial;
    int value;

}Sensor;

std::vector<std::vector<Sensor>> TotalSensors;
Sensor dataToPush;

int currentWorkingSensor = 1;
int totalSensors;


#endif //VAR_36
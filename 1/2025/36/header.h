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

typedef struct MinMaxResult {

    bool hasValues;
    int sensorSerial;
    int minValue;
    int maxValue;

} MinMaxResult;

std::vector<MinMaxResult> MinMaxResults;

int addSensor();
int findMinMaxAll();
void printMinMaxResults();

#endif //VAR_36
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

// Result for min/max search per sensor
typedef struct MinMaxResult {

    bool hasValues;
    int sensorSerial;
    int minValue;
    int maxValue;

} MinMaxResult;

// Stores results after running findMinMaxAll()
// (defined here; note: header definition must only be included by one translation unit
// or made inline in multi-TU projects)
std::vector<MinMaxResult> MinMaxResults;

//Add new sensor entry
int addSensor();

// Compute min/max for each sensor vector and populate MinMaxResults
int findMinMaxAll();

// Print results stored in MinMaxResults
void printMinMaxResults();

#endif //VAR_36
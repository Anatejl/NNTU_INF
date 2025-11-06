#ifndef VAR_36
#define VAR_36

#include <iostream>
#include <vector>

typedef struct Sensor {

    int serial;
    float value;

}Sensor;

std::vector<Sensor> vectorS1;
std::vector<Sensor> vectorS2;
std::vector<Sensor> vectorS3;

int currentWorkingSensor;
int vecorAdd();
//int repeat();

#endif //VAR_36
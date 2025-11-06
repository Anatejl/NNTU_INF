#include "header.h"

int repeat(){

    fflush;
    char answer;
    std::cout << "Add another (y/n)?" << std::endl;
    std::cin >> answer;
    if (answer == 'y'){return true;}
    else{return false;};

}

int main(){

    std::cout << "Sensor min/max program!" << std::endl;
    currentWorkingSensor = 1;

    std::cout << "Input values for [Sensor " << currentWorkingSensor <<"]:" << std::endl;

    int i = 1;
    while(true){

 
        std::cout << i << std::endl;

        if(repeat()){}
        else{
            
            std::cout << "End entering values for Sensor " << currentWorkingSensor << ";" << std::endl;
            break;}

        ++i;

    }

    return 0;
}
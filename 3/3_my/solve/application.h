//application.h

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct application {
	
	//Main run method
	static int app_run();

	//Initialize vector and get input from user
	static auto app_initVector(int k);

	//Process data into final vector
	static auto app_processVector(std::vector<IrNumber>& z, int R);

};
#endif // !APPLICATION_H_

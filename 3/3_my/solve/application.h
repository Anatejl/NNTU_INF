//application.h

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <vector>
#include <iostream>
#include "IrNumber.h"

struct application {
	

	static int app_run();

	static auto app_initVector(int k);

	static auto app_processVector(std::vector<IrNumber>& z, int R);

};
#endif // !APPLICATION_H_

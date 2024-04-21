#include "small_rejector.h"

#include <iostream>

int main() {
	SmallRejectorParameters params;
	params.k = 1;
	SmallRejector operation;
	smallRejectorInit(operation, params);

	while (true) {
		InputItem input;
		std::cin >> input.x;
        //std::cout << input.x << std::endl;
		if (std::cin.eof())
			break;

		SmallRejectorOutput output;
		smallRejectorProcess(operation, input, output);

		for ( auto& item : output )
			std::cout << item.y << std::endl;
	}
	smallRejectorDestroy(operation);
	return 0;
}

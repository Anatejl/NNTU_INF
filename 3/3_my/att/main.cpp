// Let the journey begin

#include "header.h"
#include "processing.cpp"

int main() {

	//Introduction
	intro();

	//Harvest info from user
	getInputNumberN();
	getInputNumberR();
	getInputNumberX();
	getInputNumberY();

	//Start processing things
	processInitialArray();


	//"And we're done. This is it..."
	return 0;

}
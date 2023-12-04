//Process!

void intro() {

	cout << "An epiphany is upon you." << endl;

}

void getInputNumberN() {

	cout << "Enter number N, a length of an  array: ";
	cin >> inputNumberN;
	
	// DEBUG
	//cout << inputNumber << endl;
	
}

void getInputNumberR() {

	cout << "Input number R: ";
	cin >> inputNumberR;

}

void getInputNumberX() {

	cout << "Input number X: ";
	cin >> inputNumberX;

}

void getInputNumberY() {

	cout << "Input number Y: ";
	cin >> inputNumberY;

}


void processInitialArray() {

	vector <variableArray> initialArray(inputNumberN);

	for (int i = 0; initialArray.size() > i; i++) {

		initialArray[i].x = inputNumberX;
		initialArray[i].y = inputNumberY;
		initialArray[i].z = sqrt(pow(initialArray[i].x, 2) + pow(initialArray[i].y, 2));
	}

	//vector<int> initialArray (inputNumberArrayLength);
	//
	//for (int i = 0; inputNumberArrayLength > i; i++) {
	//
	//	initialArray[i] = i;
	//
	//}
	//
	////DEBUG
	////cout << "size is: " << initialArray.size() << endl;
	////cout << initialArray[31] << endl;

}
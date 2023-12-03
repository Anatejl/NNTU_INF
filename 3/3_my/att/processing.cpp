//Process!

void intro() {

	cout << "An epiphany is upon you." << endl;

}

void getInputArrayLength() {

	cout << "Input proposed length of an array: ";
	cin >> inputNumberArrayLength;
	
	// DEBUG
	//cout << inputNumber << endl;
	
}

void getInputNumberR() {

	cout << "Input number R: ";
	cin >> inputNumberR;

}

void processInitialArray() {

	vector<int> initialArray (inputNumberArrayLength);

	for (int i = 0; inputNumberArrayLength > i; i++) {

		initialArray[i] = i;

	}
	
	//DEBUG
	cout << "size is: " << initialArray.size() << endl;
	cout << initialArray[31] << endl;

}
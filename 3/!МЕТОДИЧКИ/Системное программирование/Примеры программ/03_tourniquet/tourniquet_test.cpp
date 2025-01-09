#include "tourniquet.h"

#include <iostream>
using namespace std;

int main() {
	Tourniquet tourniquet;
	tourniquetInit(tourniquet);
	if ( !tourniquetAppend(tourniquet,1234) )
		cout << "ошибка 1" << endl;
	if ( !tourniquetAppend(tourniquet,1111) )
		cout << "ошибка 2" << endl;
	if ( !tourniquetEnter(tourniquet,1111) )
		cout << "ошибка 3" << endl;
	if ( !tourniquetEnter(tourniquet,1112) )
		cout << "отказ 4" << endl;
	if ( !tourniquetEnter(tourniquet,1111) )
		cout << "ошибка 5" << endl;
	if ( !tourniquetRemove(tourniquet,1234) )
		cout << "remove error" << endl;
	if ( !tourniquetLeave(tourniquet,1111) )
		cout << "leave error" << endl;
	cout << "count= " << tourniquetCount(tourniquet) << endl;
	return 0;
}

#include "tourniquet.h"

void tourniquetInit(Tourniquet& tourniquet) {
	tourniquet.count = 0;
}

bool tourniquetAppend(Tourniquet& tourniquet, Card card) {
	unsigned enabledCount =
		tourniquet.accessEnabled.size();
	for(unsigned i=0; i<enabledCount; ++i)
		if ( tourniquet.accessEnabled[i] == card )
			return false;
	tourniquet.accessEnabled.push_back(card);
	return true;
}

bool tourniquetRemove(Tourniquet& tourniquet, Card card) {
	unsigned enabledCount = tourniquet.accessEnabled.size();
	for(unsigned i=0; i<enabledCount; ++i)
		if ( tourniquet.accessEnabled[i] == card ) {
			tourniquet.accessEnabled[i] =
				tourniquet.accessEnabled[enabledCount-1];
			tourniquet.accessEnabled.resize(enabledCount-1);
			return true;
		}
	return false;
}

bool tourniquetEnter(Tourniquet& tourniquet, Card card) {
	for(unsigned i=0; i<tourniquet.inside.size(); ++i)
		if ( tourniquet.inside[i] == card )
			return false;
	for(unsigned i=0; i<tourniquet.accessEnabled.size(); ++i)
		if ( tourniquet.accessEnabled[i] == card ) {
			tourniquet.inside.push_back(card);
			++tourniquet.count;
			return true;
		}
	return false;
}
bool tourniquetLeave(Tourniquet& tourniquet, Card card) {
	unsigned insideCount = tourniquet.inside.size();
	for(unsigned i=0; i<insideCount; ++i)
		if ( tourniquet.inside[i] == card ) {
			tourniquet.inside[i] =
				tourniquet.inside[insideCount-1];
			tourniquet.inside.resize(insideCount-1);
			return true;
		}
	return false;
}

unsigned tourniquetCount(const Tourniquet& tourniquet) {
	return tourniquet.count;
}

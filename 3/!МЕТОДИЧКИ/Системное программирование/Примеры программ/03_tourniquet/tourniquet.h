#ifndef TOURNIQUET_H_
#define TOURNIQUET_H_

#include <vector>

typedef unsigned Card;

struct Tourniquet {
	unsigned count; //количество прошедших
	std::vector<Card> accessEnabled; //список имеющих доступ
	std::vector<Card> inside; //список находящихся внутри

};

void tourniquetInit(Tourniquet& tourniquet);
bool tourniquetAppend(Tourniquet& tourniquet, Card card);
bool tourniquetRemove(Tourniquet& tourniquet, Card card);
bool tourniquetEnter(Tourniquet& tourniquet, Card card);
bool tourniquetLeave(Tourniquet& tourniquet, Card card);
unsigned tourniquetCount(const Tourniquet& tourniquet);


#endif /* TOURNIQUET_H_ */

#include <iostream>
#include "point.h"
#include "rectangle.h"
using namespace std;

int main(void) {
	rectangle rec{ 1,1,5,5 };
	rec.showrecinfo();
	return 0;
}
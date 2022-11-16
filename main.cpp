#include <iostream>
#include "func.h"

int main() {
	// Task A
	Time a = {8, 10};
	Time earlier = {10, 30};
	Time later = {13, 40};

	std::cout << minutesSinceMidnight(a) << '\n';
	std::cout << minutesUntil(earlier, later) << '\n';


	return 0;
}
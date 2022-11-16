#include <iostream>
#include "func.h"

int main() {
	Time a = {8, 10};
	Time earlier = {10, 30};
	Time later = {13, 40};
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie3 = {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155};
	Movie movie4 = {"Koe no Katachi", ROMANCE, 129};
	Movie movie5 = {"Fake movie", ACTION, 100};

	TimeSlot morning = {movie1, {9, 15}};  
	TimeSlot daytime = {movie2, {12, 15}}; 
	TimeSlot evening = {movie2, {16, 45}};

	// Task A
	std::cout << minutesSinceMidnight(a) << '\n';
	std::cout << minutesUntil(earlier, later) << '\n';

	// Task B
	std::cout << addMinutes(a, 75).h << ", " << addMinutes(a, 75).m << '\n';

	// Task C
	std::cout << getTimeSlot(morning) << "\n";

	std::cout << getTimeSlot(daytime) << "\n";

	std::cout << getTimeSlot(evening) << "\n";

	// Task D
	TimeSlot nextSchedule = scheduleAfter(evening, movie3);
	std::cout << getTimeSlot(nextSchedule) << "\n";

	// Task E
	TimeSlot ts1 = {movie5, {10, 0}};
	TimeSlot ts2 = {movie4, {11, 29}};
	std::cout << "If 2 timeslot overlaps: " << timeOverlap(ts1, ts2) << "\n";

	return 0;
}
#include <iostream>
#include "time.h"

// Task A
int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    int earlierMin = minutesSinceMidnight(earlier);
    int laterMin = minutesSinceMidnight(later);
    return laterMin - earlierMin;
}
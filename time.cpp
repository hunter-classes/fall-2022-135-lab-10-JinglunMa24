#include <iostream>

class Time { 
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time) {
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
    return (later.h * 60 + later.m) - (earlier.h * 60 + earlier.m);
}
#include <iostream>
#include "func.h"

// Task A
int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    int earlierMin = minutesSinceMidnight(earlier);
    int laterMin = minutesSinceMidnight(later);
    return laterMin - earlierMin;
}


// Task B
Time addMinutes(Time time0, int min) {
    Time result;
    int timeMin = minutesSinceMidnight(time0);
    timeMin += min;

    result.h = timeMin / 60;
    result.m = timeMin % 60;

    return result;
}


// Task C
std::string getMovie(Movie mv) {
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts) {
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);

    std::string newS = getMovie(ts.movie);
    newS += " [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " + std::to_string(endtime.h) + ":" + std::to_string(endtime.m) + "] ";
    return newS;
}


// Task D

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
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    return {nextMovie, endtime};
}


// Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    if (minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)) {
        if (minutesUntil(ts1.startTime, ts2.startTime) > ts1.movie.duration) {
            return false;
        }
        else {
            return true;
        }
    }

    else {
        if (minutesUntil(ts1.startTime, ts2.startTime) > ts2.movie.duration) {
            return false;
        }
        else {
            return true;
        }
    }
}
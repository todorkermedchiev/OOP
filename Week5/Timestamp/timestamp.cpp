#include "timestamp.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Timestamp::Timestamp() {
    setHours(0);
    setMinutes(0);
    setSeconds(0);
}

Timestamp::Timestamp(unsigned short hours, unsigned short minutes, unsigned short seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

void Timestamp::setHours(unsigned short hours) {
    this->hours = hours % 24;
}

void Timestamp::setMinutes(unsigned short minutes) {
    this->minutes = minutes % 60;
}

void Timestamp::setSeconds(unsigned short seconds) {
    this->seconds = seconds % 60;
}

unsigned short Timestamp::getHours() const {
    return hours;
}

unsigned short Timestamp::getMinutes() const {
    return minutes;
}

unsigned short Timestamp::getSeconds() const {
    return seconds;
}

unsigned long Timestamp::timeToSeconds() const {
    int result = 0;
    result += getSeconds();
    result += getMinutes() * 60;
    result += getHours() * 3600;
    return result;
}

unsigned long long Timestamp::timeToMiliseconds() const {
    return timeToSeconds() * 1000;
}

void Timestamp::secondsToTime(unsigned long seconds) {
    setSeconds(seconds % 60);
    setMinutes((seconds / 60) % 60);
    setHours((seconds / 3600) % 60);
}

void Timestamp::addSeconds(unsigned int seconds) {
    unsigned int timeInSeconds = timeToSeconds();
    timeInSeconds += seconds;
    secondsToTime(timeInSeconds);
}

void Timestamp::addMinutes(unsigned int minutes) {
    unsigned int timeInSeconds = timeToSeconds();
    timeInSeconds += minutes * 60;
    secondsToTime(timeInSeconds);
}

void Timestamp::addHours(unsigned int hours) {
    unsigned int timeInSeconds = timeToSeconds();
    timeInSeconds += hours * 3600;
    secondsToTime(timeInSeconds);
}

void Timestamp::tick() {
    addSeconds(1);
}

void Timestamp::print() const {
    cout << "The time:       ";
    cout << setfill('0') << setw(2) << hours << ':' <<
            setfill('0') << setw(2) << minutes << ':' <<
            setfill('0') << setw(2) << seconds << endl;
    cout << "In seconds:     " << timeToSeconds() << endl;
    cout << "In miliseconds: " << timeToMiliseconds() << endl;
}

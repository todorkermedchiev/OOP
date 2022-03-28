#pragma once

class Timestamp
{
private:
    unsigned short hours;
    unsigned short minutes;
    unsigned short seconds;

public:
    Timestamp();
    Timestamp(unsigned short hours, unsigned short minutes, unsigned short seconds);

    void setHours(unsigned short hours);
    void setMinutes(unsigned short minutes);
    void setSeconds(unsigned short seconds);

    unsigned short getHours() const;
    unsigned short getMinutes() const;
    unsigned short getSeconds() const;

    unsigned long timeToSeconds() const;
    unsigned long long timeToMiliseconds() const;
    void secondsToTime(unsigned long seconds);

    void addSeconds(unsigned int seconds);
    void addMinutes(unsigned int minutes);
    void addHours(unsigned int hours);
    void tick();

    void print() const;
};
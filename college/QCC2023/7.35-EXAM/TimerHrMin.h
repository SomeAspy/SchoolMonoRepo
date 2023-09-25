// Copyright 2023
// Create a class called TimerHrMin; See instruction
// add the following methods

// overload subtract operator; subtract T1-T2
// overload >= operator; T1 >= T2

#ifndef h
#define h

class TimerHrMin
{
public:
    TimerHrMin();
    TimerHrMin(int hour, int min);
    int GetHour() const;
    int GetMinute() const;
    TimerHrMin operator-(TimerHrMin x);
    bool operator>=(TimerHrMin x);
    void Print(bool comma) const;

private:
    int hr;
    int min;
};

#endif /* h */

#ifndef DATETIME_H
#define DATETIME_H

class DateTime
{
public:
    DateTime();
    DateTime(int day, int month, int year, int hour, int minute, int second);
    DateTime& operator=(const DateTime& data);
    bool operator==(const DateTime& data);
    void addDay(int day);
    void addMonth(int mounth);
    void addYear(int year);
    void addHour(int hour);
    void addMinute(int minute);
    void addSecond(int second);
    int getDay();
    int getMounth();
    int getYear();
    int getHour();
    int getMinute();
    int getSecond();
    ~DateTime();
private:
int _day;
int _month;
int _year;
int _hour;
int _minute;
int _second;
};

#endif // DATETIME_H

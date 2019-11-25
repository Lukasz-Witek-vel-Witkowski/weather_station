#include "datetime.h"
DateTime::DateTime(){}
DateTime::DateTime(int day, int month, int year, int hour, int minute, int second){
    _day = day;
    _month = month;
    _year = year;
    _hour = hour;
    _minute = minute;
    _second = second;
}
DateTime& DateTime::operator=(const DateTime& data){
    if(this==&data) return *this;
    if(*this==data) return *this;
    _day = data._day;
    _month = data._month;
    _year = data._year;
    _hour = data._hour;
    _minute = data._minute;
    _second = data._second;
    return *this;
}
bool DateTime::operator==(const DateTime& data){
    if(_day==data._day&&_month==data._month&&_year==data._year&&
            _minute==data._minute&&_hour==data._hour&&_second==data._second) return true;
    return false;
}
void DateTime::addDay(int day){_day = day;}
void DateTime::addMonth(int mounth){_month = mounth;}
void DateTime::addYear(int year){_year = year;}
void DateTime::addHour(int hour){_hour = hour;}
void DateTime::addMinute(int minute){_minute=minute;}
void DateTime::addSecond(int second){_second = second;}
int DateTime::getDay() {return _day;}
int DateTime::getMounth() {return _month;}
int DateTime::getYear() {return _year;}
int DateTime::getHour() {return _hour;}
int DateTime::getMinute() {return _minute;}
int DateTime::getSecond() {return _second;}
DateTime::~DateTime(){ }

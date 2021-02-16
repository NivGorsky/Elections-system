
#include "Date.h"

using namespace std;


namespace elections{

//ctor:
Date:: Date() : month(1), day(1), year(2000){}

Date:: Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year)
{
    if (!((day <= 31 && day >= 1) && (month <= 12 && month >= 1)))
        throw logic_error("Date isn't valid");
}
//dtor:
Date:: ~Date()
{}

//setters
void Date:: setDate()
{
    cout << "Date: " << endl; cout << "day: "; cin >> day; cout << endl;
    cout << "month: "; cin >> month; cout << endl;
    cout << "year: "; cin >> year; cout << endl;
    
    if (!((day <= 31 && day >= 1) && (month <= 12 && month >= 1)))
        throw logic_error("Date isn't valid");
}


//getters
int Date:: getDay() const
{
    return day;
}

int Date:: getMonth() const
{
    return month;
}


int Date:: getYear() const
{
    return year;
}

//friends
ostream& operator<<(ostream& os, const Date& d)
{
    os<< d.day<<" "<<d.month<<" "<<d.year;
    return os;
}

void Date:: load(istream& in)
{
    in.read(rcastc(&day), sizeof(day));
    in.read(rcastc(&month), sizeof(month));
    in.read(rcastc(&year), sizeof(year));
    
}

void Date:: save(ostream& out) const
{
    out.write(rcastcc(&day), sizeof(day));
    out.write(rcastcc(&month), sizeof(month));
    out.write(rcastcc(&year), sizeof(year));
    
}



}



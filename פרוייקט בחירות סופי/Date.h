
#pragma once
#include "iostream"
#include <fstream>
#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

using namespace std;
namespace elections{



class Date{
    
private:
    int day;
    int month;
    int year;
    
public:
    
    
    //ctors and dtor
    Date();
    Date(int _day, int _month, int _year);
    ~Date();
    
    
    //methods
    
    void load(istream& in);
    void save(ostream& out) const;
    
    
    //getters
    int getDay() const;
    int getMonth() const ;
    int getYear() const;
    
    //setters
    void setDate();
   
    
    
    //friends
    friend ostream& operator<<(ostream& os, const Date& d);
    

    
};

}




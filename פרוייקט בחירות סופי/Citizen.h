
#pragma once
#include "Date.h"
#include "GlobalConsts.h"
#define IDDIGITS 9


namespace elections {

class Citizen {

private:
    int nameSize;
    string name;
    
    int idLen;
    string id;
   
    bool isDelegate;
    int countySerial;
    Date dob;
    bool voteStatus;
    

public:
    //ctors and dtor
    Citizen();
    Citizen(string name,string id, Date& _dob, int countySerial,bool isDelegate);
    Citizen(Citizen& other);
    ~Citizen();

    //setters
    bool setVoteStatus(bool _status);
    bool setDelegationStatus(bool _newStatus);

    //getters
    string getName() const;
    Date& getDate();
    int getcounty()const;
    bool getVoteStatus()const;
    string getId()const;
    bool getDelStatus()const;
    int getIdLen() {return idLen;}
    
    
    //general
    bool save(ostream& out) const;
    bool load(istream& in);
    
    
   
    //friends
    //friend string myStringDup(string name, int& updateValue);
    friend ostream& operator <<(ostream& os, const Citizen& c);
    
    //operators
    Citizen& operator =(const Citizen& other);
    
};

}





#pragma once
#include "Elections.h"


namespace elections {

class electionsRound{
    
    
private:
    int flag;
    int citizenCounter, countyCounter, partiesCounter;
    CountyList* cList;
    CitizenList* voterRegister;
    VoterList* smallVoterList;
    PartyList* pList;
    bool electionsType;
    Date date;
    bool dateEntered = false;
  
    
public:
    electionsRound(Date d): dateEntered(true){
        setDate(d);
    }
    electionsRound();
    ~electionsRound();
    
    //methods
    void electionsManager(bool isLoaded);
    void save();
    void load();
    
    void setDate(Date& d){date = d;dateEntered=true;}

};



}


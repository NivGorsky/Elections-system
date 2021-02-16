
#pragma once
#include <iostream>
#include "Citizen.h"
#include "Date.h"
#include "VoterList.h"

//forward decleration
//class VoterList;

namespace elections{



class CitizenList : public VoterList{
    
public:
    
    //init empty list
    CitizenList();
    
    //freeList
    ~CitizenList();
    
    //general
    virtual void save(ostream& out) const;
    virtual void load(istream& in);
    bool isThereId(string id)const;
    
    };

}





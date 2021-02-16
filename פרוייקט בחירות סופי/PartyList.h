
#pragma once
#include "Party.h"
//#include <list>
#include "myList.h"


namespace elections {

class PartyList{
    
private:
    
    myList <Party*> Plist;
        
   
public:
    
    //init empty list
    PartyList();
    
    //freeList
    ~PartyList();
    
    //setters
    void addToTail(Party* p);
	void addCountyToAllParties(int serialNum);

    //friends
   friend ostream& operator <<(ostream& os, const PartyList& list);
   
   //getters :
   Party* getPartyByIndex(int index);
   int getSize() { return Plist.size(); }
    
   // general
    void save(ostream& out) const;
    void load(istream& in, VoterList& voterRegister2);


    };
    
    
}


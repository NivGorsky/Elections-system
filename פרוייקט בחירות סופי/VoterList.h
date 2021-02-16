

#pragma once
#include <iostream>
#include "Citizen.h"
//#include <list>
#include "myList.h"
#include "MyExceptions.h"


namespace elections{

class VoterList{
    
protected:
    
    
    
    myList<Citizen*> list;
    
    
    //private methods
    bool deleteList();
    //ListNode* createListNode(Citizen* other);
   
public:
    
    //init empty list
    VoterList();
    
    //freeList
    ~VoterList();
    

    
    //getters:
    int getSize(){return list.size();}
    Citizen* getCitizen(string id) const;
    string getName(string ID) const;

    //setters
    void addToTail(Citizen* c);

    //general
    void printList()const;
    virtual void save(ostream& out) const;
    virtual void load(istream& in);
    bool saveIds(ostream& out)const;
    bool loadIds(istream&in, VoterList& voterRegister2);
  
   
  
    //friends
    friend ostream& operator <<(ostream& os, const VoterList& list);
    };

}




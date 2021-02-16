

#pragma once
#include "VoterList.h"
#include "CitizenList.h"
#include "myList.h"

namespace elections {

class IdList{
    
private:
    
    struct ListNode{
        int serial;
        long int votes;
        VoterList list;
      //  ListNode* next;
       
    };
    
    
    myList<ListNode*> list;
 
    
   
public:
    
    //init empty list
    IdList();
    
    //freeList
    ~IdList();
    
    //public methods
    
 //getters:
	long int* getVotesByParties();
	bool showVoterListByIndex(int index);
    int getSize(){return list.size();}

//setters
    void addToTail(int serial);
    bool addCitizenToList(int serial, Citizen* cPtr);
    bool addVote(int indexNum);
    
    
    //general
     bool save(ostream& out)const;
     bool load(istream& in, VoterList& voterRegister2);


  
    //friends
    friend ostream& operator <<(ostream& os, const IdList& list);
};


}





#pragma once
#include "iostream"
#include "electionsEntity.h"

using namespace std;
namespace elections {

class Party : public electionsEntity {

private:
    
    int candidateNameSize;
    string candidateName;
   
    
    
public:
    //ctors and dtor
    Party();
    Party(string _partName, int _serialNumber,string _candidateName);  
    ~Party();
    
    //getters
   
    string getCandiName()const;
	
    //general
    bool save(ostream& out);
    bool load(istream& out, VoterList& voterRegister2);

    
    //operators
    friend ostream& operator <<(ostream& os, const Party& other);
    
  
    

};




}



#include "Party.h"
#include "GlobalConsts.h"
namespace elections
{
 //ctor:
Party:: Party() : electionsEntity(), candidateName(" "),candidateNameSize(0){}

Party:: Party(string _partyName, int _serialNumber,string _candidateName) : electionsEntity(_serialNumber,_partyName), candidateName(_candidateName){}

//dtor:
Party:: ~Party()
{
	if (!candidateName.empty())
	{
		candidateName.~basic_string();
	}

}

string Party:: getCandiName() const
{
    return candidateName;
}

bool Party:: save(ostream& out)
{
    int size = candidateName.size();
    
    
    
    electionsEntity::save(out);
    out.write(rcastcc(&size), sizeof(size));
    out.write(rcastcc(&candidateName[0]), size);
    return out.good();
    
}

bool Party:: load(istream& in,VoterList& voterRegister2)
{
    int size;
    
    
    
    electionsEntity::load(in,voterRegister2);
    in.read(rcastc(&size), sizeof(size));
    candidateName.resize(size);
    in.read(rcastc(&candidateName[0]), size);
    
    return in.good();
}


//operators:
ostream& operator <<(ostream& os, const Party& other)
{
    os<< "( ";
    os<<"Party "<<other.getName()<<" serial number: "<<other.getSerial();
    os<< ") "<<endl;
    os<<"Candidate Name: "<<other.candidateName<<endl;
    os << "Deligate List:  " << other.delegatesList << endl;
  
    return os;   
    
}

}



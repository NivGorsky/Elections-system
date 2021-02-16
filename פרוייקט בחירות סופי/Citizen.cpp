

#include "Citizen.h"
namespace elections{

 //ctors:
    Citizen:: Citizen() : nameSize(0),voteStatus(false),idLen(0), isDelegate(false),countySerial(0){}

    Citizen:: Citizen(string _name,string _id, Date& _dob, int _countySerial,bool _isDelegate) :
name(_name), dob(_dob), countySerial(_countySerial),id(_id),isDelegate(_isDelegate),voteStatus(false)
{
    nameSize = name.size()+1;
    idLen = id.size()+1;
    if(id.length()!= IDDIGITS)
        throw logic_error("id must contain 9 digits");
}

    Citizen:: Citizen(Citizen& other)
{
    if(this != &other)
    {
        *this = other;
        
    }
}
        
    Citizen:: ~Citizen()
    {
    }

//setters:
    bool Citizen:: setVoteStatus(bool _status)
    {
        //true == already voted
        voteStatus = _status;
        return true;
    }

    bool Citizen::setDelegationStatus(bool _newStatus)
    {
        isDelegate = _newStatus;
        return true;

    }


//getters:

    string Citizen:: getName() const
    {
        return name;
    }

    Date& Citizen:: getDate()
    {
        return dob;
    }

    int Citizen:: getcounty()const
    {
        return countySerial;
    }

    bool Citizen:: getVoteStatus()const
    {
        return voteStatus;
    }

    string Citizen:: getId()const
    {
        return id;
    }

    bool Citizen::getDelStatus()const
    {
        return isDelegate;
    }


    bool Citizen:: save(ostream& out) const
    {
        int nameSize = name.size(); //added 1 for \0
        int idLen = id.size();      //same here
        
        out.write(rcastcc(&nameSize), sizeof(nameSize));
        out.write(rcastcc(&name[0]), nameSize* sizeof(char));

        out.write(rcastcc(&idLen), sizeof(idLen));
        out.write(rcastcc(&id[0]), idLen* sizeof(char));

        out.write(rcastcc(&isDelegate),sizeof(isDelegate));
        out.write(rcastcc(&countySerial),sizeof(countySerial));
        dob.save(out);
        out.write(rcastcc(&voteStatus),sizeof(voteStatus));

        if(!out.good())
            //throw logic_error("file is not good in saving Citizen");
            return false;
        return true;
    }

    bool Citizen:: load(istream& in)
    {
       
        in.read(rcastc(&nameSize), sizeof(nameSize));
        name.resize(nameSize);
        in.read(rcastc(&name[0]), nameSize* sizeof(char));

        in.read(rcastc(&idLen), sizeof(idLen));
        id.resize(idLen);
        in.read(rcastc(&id[0]), idLen* sizeof(char));

        in.read(rcastc(&isDelegate),sizeof(isDelegate));
        in.read(rcastc(&countySerial),sizeof(countySerial));
        dob.load(in);
        in.read(rcastc(&voteStatus),sizeof(voteStatus));
        
        if(!in.good())
            //throw logic_error("file is not good in loading Citizen");
            return false;
        return true;
    }
    ostream& operator <<(ostream& os, const Citizen& c)
    {
        os << "Name: " << c.name << " " << "ID: " << c.id << " " << "DOB: " << c.dob << " " << "county:  " << c.countySerial;
    return os;
    }

     Citizen& Citizen:: operator =(const Citizen& other)
    {
        if(this != & other)
        {
            name = other.getName();
            nameSize = other.nameSize;
            id = other.getId();
            idLen = other.idLen;
            dob = other.dob;
            voteStatus = other.voteStatus;
            isDelegate = other.isDelegate;
            countySerial = other.countySerial;
        }
    return *this;

    }
}



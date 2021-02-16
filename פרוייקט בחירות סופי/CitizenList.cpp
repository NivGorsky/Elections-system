
#include "CitizenList.h"


namespace elections{

//ctors and dtor

    CitizenList:: CitizenList() : VoterList(){}

    CitizenList:: ~CitizenList()
    {
        deleteList();
    }

    bool CitizenList::isThereId(string id)const
    {
        ::myList<Citizen*>::Iterator itr= list.cbegin();
        ::myList<Citizen*>::Iterator end = list.cend();

        

        while (itr!=(end--))
        {
            if ((*itr)->getId()==id)return true;
            ++itr;
        }
        return true;
    }

void CitizenList:: save(ostream& out) const
{
     VoterList:: save(out);
}

void CitizenList:: load(istream& in)
{
    
     VoterList:: load(in);
}

}





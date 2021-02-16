

#include "PartyList.h"

namespace elections{

	//ctor 
    PartyList:: PartyList() : Plist(){}
	//dtor
    PartyList:: ~PartyList()
    {
        Plist.~myList();
    }

//setter:

    void PartyList:: addToTail(Party* p)
    {
        Plist.insert(p);
    }

	void PartyList::addCountyToAllParties(int serialNum)
	{
        myList<Party*>::Iterator ptr;
       for(ptr = Plist.begin();ptr!=Plist.end();++ptr)
		{
			(*ptr)->addEntityToList(serialNum);
		}
	}

//getters :

	Party* PartyList:: getPartyByIndex(int index)
	{
        myList<Party*>::Iterator ptr;
        ptr = Plist.begin();
        for (int i =1; i < Plist.size()-index; i++)
        {
            ++ptr;
        }
        return (*ptr);
	}

//general

        void PartyList:: save(ostream& out) const
        {
            int size = Plist.size();
            Party* p;
            bool isOk;
            out.write(rcastcc(&size), sizeof(size));
            
            myList<Party*>::reverse_iterator itr = Plist.crbegin();
            myList<Party*>::reverse_iterator end = Plist.crend();
            
            while(itr!=end)
            {
                p = *itr;
                isOk = p->save(out);
                if(!isOk)
                    cout<<"failed to save party"<<endl;
                ++itr;
            }
            
           if(!out.good())
               throw fileException();
            
           
           
            
        }

        void PartyList:: load(istream& in, VoterList& voterRegister2)
        {
            int size;
            Party* p;
            bool isOk;
            in.read(rcastc(&size), sizeof(size));
            
            for(int i = 0;i<size;i++)
            {
                p = new Party;
                isOk = p->load(in, voterRegister2);
                Plist.insert(p);
                if(!isOk)
                    cout<<"failed to load party"<<endl;
            }
           if(!in.good())
               throw fileException();
            
        }






 //operators :

    ostream& operator <<(ostream& os, const PartyList& list)
    {
        for (auto it = list.Plist.cbegin(); it != list.Plist.cend(); it++)
        {
            os<<endl;
            os<<**(it);
            os<<endl;
          
        }

        os<<endl;
        return os;

    }


}

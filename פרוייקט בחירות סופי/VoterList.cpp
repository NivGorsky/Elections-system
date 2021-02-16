
#include "VoterList.h"

using namespace std;

namespace elections{

    VoterList:: VoterList():list(){}

    VoterList:: ~VoterList()
    {
   
    }

//private methods:

        bool VoterList:: deleteList()
        {
            
            list.~myList();
            return true;
            
        }

    //setter:

//    VoterList:: ListNode* VoterList:: createListNode(Citizen* other)
//    {
//
//        ListNode* newNode = new ListNode;
//        newNode->c = other;
//        newNode->next = nullptr;
//        return newNode;
//
//    }

    void VoterList:: addToTail(Citizen* c)
    {
        list.insert(c);
    }

    

    //getter:

    Citizen* VoterList:: getCitizen(string id) const
    {
      
        myList<Citizen*> ::Iterator ptr;

        for ((ptr) = (list.cbegin()); (ptr) != (list.cend()); ++ptr)
        { 
           if(id == (*ptr)->getId())
               return(*ptr);         
        }
        
        throw logic_error("Citizen wasn't found");
    }

    string VoterList:: getName(string ID)const
    {
        Citizen* cptr = getCitizen(ID);
        if(!cptr)
            throw logic_error("Citizen wasn't found");
        return cptr->getName();
        
    }



    //operators:

    ostream& operator <<(ostream& os, const VoterList& list)
    {
        
        myList<Citizen*> ::Iterator ptr;

        for ((ptr) = (list.list.cbegin()); (ptr) != (list.list.cend()); ++ptr)
        {
            os<<"------------------------------"<<endl;
            os<<(**ptr);
            os<<endl;
           
 
        }
        
        os<<endl;
        return os;
        
    }

    //general:

    void VoterList::printList()const
    {
        myList<Citizen*> ::Iterator ptr;

        for ((ptr) = (list.cbegin()); (ptr) != (list.cend()); ++ptr)
        {
           
            cout << "------------------------------" << endl;
            cout << **ptr;
            cout << endl;
            cout << "------------------------------" << endl;
            
            
        }
    }

   void VoterList:: save(ostream& out) const
    {
        
        Citizen* c;
        int size = list.size();
        out.write(rcastcc(&size), sizeof(size));
        
        //init the itr to head and tail of the list
        ::myList<Citizen*>::reverse_iterator itr = list.crbegin();
        ::myList<Citizen*>::reverse_iterator end = list.crend();

        //running through the list
        while(itr!= end)
        {
            //getting the current citizenPtr in the list
            c = (*itr);
            //saving the currCitizen
            c->save(out);
            ++itr;
        }
        if(!out.good())
            throw fileException();
        
    }

    void VoterList:: load(istream& in)
    {
        
        Citizen* c;
        int sizeFromFile;
        in.read(rcastc(&sizeFromFile), sizeof(sizeFromFile));
        
    
        //running size iterations - loading a citizen and adding it to the list
        for(int i =0;i<sizeFromFile;i++)
        {
            c = new Citizen;
            c->load(in);
            list.insert(c);
            
        }
        
       if(!in.good())
           throw fileException();
       
    }




























   
    bool VoterList:: saveIds(ostream& out)const
    {
        int size = list.size();
        int idLen;
        string id;
        Citizen* cPtr;
        out.write(rcastcc(&size), sizeof(size));
        
        ::myList<Citizen*>::reverse_iterator itr = list.crbegin();
        ::myList<Citizen*>::reverse_iterator end = list.crend();

        while(itr!=end)
        {
            cPtr = *itr;
            id = cPtr->getId();
            idLen = id.size();
            
            out.write(rcastcc(&idLen), sizeof(idLen));
            out.write(rcastcc(&id[0]), idLen);
            
            ++itr;
        }
        
        return out.good();
        

    }
    

   
    bool VoterList:: loadIds(istream& in,VoterList& voterRegister2)
    {
        
        int size;
        int idLen;
        string id;
        Citizen* cPtr;
        in.read(rcastc(&size), sizeof(size));
        
        
        for(int i =0;i<size;i++)
        {
            in.read(rcastc(&idLen), sizeof(idLen));
            id.resize(idLen);
            in.read(rcastc(&id[0]),idLen);
            
            cPtr = voterRegister2.getCitizen(id);
            list.insert(cPtr);
            
        }
        
        return in.good();


    }
}




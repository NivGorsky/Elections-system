

#include "IdList.h"
namespace elections
{

//ctor:
IdList :: IdList() :list (){}


//dtor:
IdList :: ~IdList()
{
    list.~myList();
}

//getters:
long int* IdList::getVotesByParties()
{
    int size = list.size();
    long int* votesByParties = new long int[size];
    //init the array
    for (int i = 0; i < size; i++)
    {
        votesByParties[i] = 0;
    }

    myList<ListNode*> ::Iterator ptr;

    int i = size-1;
    for ((ptr) = (list.begin()); (ptr) != (list.end()); ++ptr)
    {
        votesByParties[i] = (*ptr)->votes;

        i--;
    
    }
    return votesByParties;

}


//general
bool IdList::showVoterListByIndex(int index)
{
    
    myList<ListNode*> ::reverse_iterator ptr;
    ptr = list.rbegin();
    for(int i=1;i<index;i++)
    {
        ++ptr;
    }
    cout << (*ptr)->list << endl;
    return true;
}


//setters
//IdList:: ListNode* IdList:: createListNode(int serial)
//{
//    
//    ListNode* newNode = new ListNode;
//    newNode->next = nullptr;
//    newNode->serial = serial; //serial is county's serial number
//    newNode->votes = 0; //init with 0 votes from that county
//    
//    return newNode;
//
//}

void IdList:: addToTail(int serial)
{
    ListNode* newNode = new ListNode();
    //newNode. = nullptr;
    newNode->serial = serial; //serial is county's serial number
    newNode->votes = 0; //init with 0 votes from that county
    list.insert(newNode);
}

bool IdList:: addCitizenToList(int serial, Citizen *cPtr)
{
    myList<ListNode*> ::Iterator ptr;
   
    for ((ptr) = (list.begin()); (ptr) != (list.end()); ++ptr)
    {
        if((*ptr)->serial== serial)
        {
            (*ptr)->list.addToTail(cPtr);
            return true;
        }
    }
    return false;    
}
   
bool IdList:: addVote(int indexNum)
{
    myList<ListNode*> ::reverse_iterator ptr;
    ptr = list.rbegin();
	for(int i=1;i<indexNum;i++)
	{
        ++ptr;
	}
    (*ptr)->votes++;
	return true;
}


ostream& operator <<(ostream& os, const IdList& list)
{
   

        myList<IdList::ListNode*> ::reverse_iterator ptr;

    int i = 0;
    for ((ptr) = (list.list.crbegin()); (ptr) != (list.list.crend()); ++ptr)
      
          {
              
              os<<" "<<(*ptr)->serial<<":";
              
              os<<(*ptr)->list; //printing operator for voterlist was implemented
             
          }
  
          os<<endl;
          return os;
    
}














    bool IdList:: save(ostream& out)const
    {
        int size = list.size();
        int idLen;
        string name;
        
        out.write(rcastcc(&size), sizeof(size));
        
        myList<ListNode*>::reverse_iterator itr = list.crbegin();
        myList <ListNode*>::reverse_iterator end = list.crend();
        
        while(itr!=end)
        {
            
            out.write(rcastcc(&(*itr)->serial), sizeof((*itr)->serial));
            out.write(rcastcc(&(*itr)->votes), sizeof((*itr)->votes));
            (*itr)->list.saveIds(out);
   
            ++itr;
        }
        
        return out.good();

        
    }




    bool IdList:: load(istream& in, VoterList& voterRegister2)
    {
        
        int size;
        int idLen;
        string name;
        
        in.read(rcastc(&size), sizeof(size));
        

        for(int i = 0; i<size; i++)
        {
            ListNode* newNode = new ListNode();
            in.read(rcastc(&(*newNode).serial), sizeof((*newNode).serial));
            in.read(rcastc(&(*newNode).votes),sizeof((*newNode).votes));
            (*newNode).list.loadIds(in, voterRegister2);
            
            list.insert(newNode);
        }
        
        return in.good();

        
    }
}

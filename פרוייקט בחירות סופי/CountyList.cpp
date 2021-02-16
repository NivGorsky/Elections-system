
#include "CountyList.h"


namespace elections {

//ctor:

	CountyList::CountyList() : Clist() {}
//dtor:
	CountyList:: ~CountyList()
	{
		Clist.~myList();
	}

//setters:



	void CountyList::addPartyToAllCounties(int serialNum)
	{
		 myList<County*> ::Iterator ptr;
		
		for ((ptr) = (Clist.begin()); (ptr) != (Clist.end()); ++ptr)
		{
			(*ptr)->addEntityToList(serialNum);
		}
	}

	void CountyList::addToTail(County* c)
	{
		Clist.insert(c);
	}

//getters:
	int CountyList::getSize()
	{
		return Clist.size();
	}

	County* CountyList::getCountyByIndex(int index)
	{
			myList<County*> ::reverse_iterator ptr;
			(ptr) = (Clist.rbegin());
			
			for ( int i=1;i<index;i++)
			{
				++ptr;
			}
			return (*ptr);
		
	}

//general
	 int* CountyList::winningPartyForAllCounty(int arraySize ,int partiesCounter)
	{
		 int* winningPartyForAllCounty = new int[arraySize];
		//init the array
		for (int i = 0; i < arraySize; i++)
		{
			winningPartyForAllCounty[i] = 0;
		}

		myList<County*> :: reverse_iterator ptr;

		int i = 0;
		for (ptr = Clist.rbegin(); ptr != Clist.rend(); ++ptr)
		{
			winningPartyForAllCounty[i] = (*ptr)->getMaxVotesEntity(partiesCounter);
			i++;
		}
	
		return winningPartyForAllCounty;

	}

	 float* CountyList::PctOfWinningAllCounties(int arraySize, int partiesCounter)
	 {
		 float* PctOfWinningForAllCounty = new float[arraySize];
		 //init the array
		 for (int i = 0; i < arraySize; i++)
		 {
			 PctOfWinningForAllCounty[i] = 0;
		 }

		 
		 int max = 0;
		 int sum = 0;
		 int i = 0;

		 myList<County*> ::Iterator ptr;

		 for ((ptr) = (Clist.begin()); (ptr) != (Clist.end()); ++ptr)
		 {
			 max =(*ptr)->getMaxValue(partiesCounter);
			 sum = (*ptr)->getTotalVotesOfEntity(partiesCounter); 
			 PctOfWinningForAllCounty[i] = (float)max / (float)sum;
			 i++;
		 }
	
		 return PctOfWinningForAllCounty;

	}

	 float* CountyList::PctOfVotingAllCounties(int arraySize, int partiesCounter)
	 {
		 float* PctOfVotingForAllCounty = new float[arraySize];
		 //init the array
		 for (int i = 0; i < arraySize; i++)
		 {
			 PctOfVotingForAllCounty[i] = 0;
		 }

		
		 int sumCitizen = 0;
		 int sumVotes = 0;
		 int i = 0;
	

		 myList<County*> ::Iterator ptr;

		 for ((ptr) = (Clist.begin()); (ptr) != (Clist.end()); ++ptr)
		 {
			 sumCitizen = (*ptr)->getCitizenNum();
			 sumVotes = (*ptr)->getTotalVotesOfEntity(partiesCounter);
			 PctOfVotingForAllCounty[i] = (float)sumVotes / (float)sumCitizen;
			 i++;
		 }
	
		 return PctOfVotingForAllCounty;

	 }

	 void CountyList::erase()
	 {
		 myList<County*> ::Iterator ptr;
		 myList<County*> ::Iterator ptr2;
		 ptr = Clist.begin();
		 ptr2 = Clist.end();
		 Clist.eraseRange(ptr,ptr2);
		 

	 }

    void CountyList:: save(ostream& out) const
    {
    
        countyType type;
        int size = Clist.size();
        bool isOK;
        
        //save the size of the list
        out.write(rcastcc(&size), sizeof(size));
        
        myList<County*>:: reverse_iterator itr = Clist.crbegin();
        myList<County*>::reverse_iterator end = Clist.crend();
        
        County* currCounty;
        
        //running through the list and saving the counties
        while(itr!=end)
        {
            currCounty = *itr;
            
            //using polymorphysm to save the county according to its type
            devidedCounty* d = dynamic_cast<devidedCounty*>(currCounty);
            if(d)
                type = countyType:: devided;
            else
                type = countyType:: regular;
            out.write(rcastcc(&type), sizeof(type));
            isOK = currCounty->save(out);
            if(!isOK)
                cout<<"failed to save county "<<currCounty->getSerial()<<endl;
           
            ++itr;
        }
        if(!out.good())
            throw fileException();
            
    }

    void CountyList:: load(istream& in, VoterList& voterRegister2)
    {
        
        countyType type;
        
        
        //getting the size of the list
        int sizeFromFile;
        in.read(rcastc(&sizeFromFile), sizeof(sizeFromFile));
        bool isOK;
        County* c;
        
        //adding every county to the list
        for(int i =0;i<sizeFromFile;i++)
        {
            //loading the type of the county from the file
            in.read(rcastc(&type), sizeof(type));
            
            if(type == countyType::regular)
                c = new County;
            
            else
                c = new devidedCounty;
                
            isOK = c->load(in,voterRegister2);
            addToTail(c);
            if(!isOK)
                cout<<"failed to load county "<<endl;
        }
        if(!in.good())
            throw fileException();
    }
//operators:

	ostream& operator <<(ostream& os,  CountyList& myList)
	{
	
			for (auto it = myList.Clist.rbegin(); it != myList.Clist.rend(); it++)
			{
				os << endl;
				os << (*(*it));
				os << endl;
			}

		
		os << endl;
		return os;

	}



	
}

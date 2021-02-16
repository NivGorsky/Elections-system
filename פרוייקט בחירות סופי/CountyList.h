

#pragma once
#include "County.h"
#include "devidedCounty.h"
//#include <list>
#include "myList.h"





namespace elections {



    enum class countyType{regular, devided};

	class CountyList {

	private:
	

		myList <County*> Clist ;
	

	
	public:

		//init empty list
		CountyList();

		//freeList
		~CountyList();



	//setters:
		void addToTail(County* p);
		void addPartyToAllCounties(int serialNum);
		void erase();

	
	//general:
        int* winningPartyForAllCounty(int arraySize, int partiesCounter);
        float* PctOfWinningAllCounties(int arraySize, int partiesCounter);
        float* PctOfVotingAllCounties(int arraySize, int partiesCounter);
        void save(ostream& out) const;
        void load(istream& in,VoterList& voterRegister2);




		//getters :
		County* getCountyByIndex(int index);
		int getSize();

        /*int getSize() { return size; }*/



		//friends
		friend ostream& operator <<(ostream& os,  CountyList& list);

	};


}


#pragma once
#include <iostream>
#include "PartyList.h"
#include "VoterList.h"
#include "electionsEntity.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std; 
namespace elections {





	const int MaxName = 20;

	class County : public electionsEntity {

	private:

		int delegationsNum;
		int citizensNum;

	public:
		
		//ctors and dtors:
		County();
		County(string _countyName, int _serialNumber, int _delegationsNum, int _citizenNum);
		~County();
		
		//getters

		int getDelNum() const;
		int getCitizenNum() const;
		bool addCitizenToCounty();
		
		virtual void printIfDevided()const ;
		virtual void showResult(int partyCounter, int* DelegatesSumForAllParties,int winningParty);
		virtual void  showCountyDetails (int partyCounter, float PctOfWinningCounty,int winningParty);
        
        //general
        bool save(ostream& out);
        bool load(istream& out, VoterList& voterRegister2);

		//operators

		friend ostream& operator <<(ostream& os, const County& other);



	};


}

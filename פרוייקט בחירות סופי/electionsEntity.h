

#pragma once
#include "iostream"
#include "Citizen.h"
#include "IdList.h"

using namespace std;
namespace elections
{
	class electionsEntity
	{
	protected:
		int serialNumber;
        int NameSize;
		string Name;
		

		IdList delegatesList;

	public:
		//ctor and dtor
		electionsEntity();
		electionsEntity(int _serialNumber, string _Name);
        
		~electionsEntity();

		//getters
		int getSerial()const;
		string getName()const;
		int getTotalVotesOfEntity(int size);
		IdList getDelegateList()const;
		int getMaxValue(int partyNum);
		long int* getVotes();
		bool getVotesOfEntity();
		bool showWinningDelegatesList(int winningPartyIndex);
		bool printDelegateList()const;
		int getMaxVotesEntity(int partyNum);
		int* delegationsNumEachEntity(int totalVotes, int partyCounter,int delNum);
		long int* getVotesArray(int partyNum);


		//setters:
		bool setSerial(int _serial);
		bool vote(int indexNum);
		bool addEntity(int serial);
		bool updateEntity(int size);
		bool addEntityToList(int serial);
		bool addDelegate(Citizen *cPtr, int countySerial);
        
        bool save(ostream& out);
        bool load(istream& out,VoterList& voterRegister2);

	};
}

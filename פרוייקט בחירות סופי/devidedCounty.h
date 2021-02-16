
#pragma once
#include "County.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace elections {



	class devidedCounty : public County {
	public:
        
        devidedCounty() : County(){}
		devidedCounty(string _countyName, int _serialNumber, int _delegationsNum, int _citizenNum) :County(_countyName, _serialNumber, _delegationsNum, _citizenNum)
		{}
		~devidedCounty() {}
		

		void showResult(int partyCounter, int* DelegatesSumForAllParties, int winningParty) override
		{
			int* delegatesEachParty;
			int totalVotes;
			totalVotes = getTotalVotesOfEntity(partyCounter);
			delegatesEachParty = delegationsNumEachEntity(totalVotes, partyCounter, getDelNum());
			for (int i = 0; i < partyCounter; i++)
			{
				DelegatesSumForAllParties[i] = DelegatesSumForAllParties[i] + delegatesEachParty[i];
			}
			delete[] delegatesEachParty;
		}
		void printIfDevided() const override
		{
			cout << "Devided" << endl;
		}

		void showCountyDetails(int partyCounter, float PctOfWinningCounty,int winningParty) override
		{
			long int* votesByParties;
			int maxIndex = 0;
			long int maxValue = 0;
			PctOfWinningCounty = 0;
			
			votesByParties = getVotesArray(partyCounter);
			int totalVotes = getTotalVotesOfEntity(partyCounter);
			cout << "*********** Devided County's Parties Details(By Order)***********" << endl;
			for (int j = 0; j < partyCounter; j++)
			{
				for (int i = 0; i < partyCounter; i++)
				{
					if (maxValue < votesByParties[i])
					{
						maxValue = votesByParties[i];
						maxIndex = i;
					}
				}
				cout << "PARTY NUMBER: " << maxIndex+1 << endl;
				cout << "VOTES:" << endl;
				cout << votesByParties[maxIndex] << endl;
				PctOfWinningCounty = (float)votesByParties[maxIndex] / (float)totalVotes;
				cout << "Vote Precentage:" << endl;
				cout << PctOfWinningCounty * 100 << "%" << endl;
				cout << "Party Deligate List Is : " << endl;
				showWinningDelegatesList(maxIndex);
				votesByParties[maxIndex] = -1;
				maxValue = -2;
			}
		}


	};


}

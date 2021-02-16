#include "County.h"
#include "GlobalConsts.h"

#include <iostream>


using namespace std;
#define _CRT_SECURE_NO_WARNINGS


namespace elections {

	//ctors:
	County::County() : electionsEntity(), delegationsNum(0), citizensNum(0) {};
	County::County(string _countyName, int _serialNumber, int _delegationsNum, int _citizensNum) : electionsEntity(_serialNumber, _countyName), delegationsNum(_delegationsNum), citizensNum(_citizensNum) {}
	//dtor:
	County ::~County() {}


	bool County::addCitizenToCounty()
	{
		citizensNum++;
		return true;
	}

	int County::getDelNum() const
	{
		return delegationsNum;
	}

	int County::getCitizenNum() const
	{
		return citizensNum;
	}



	//general
	bool County::save(ostream& out)
	{
        
		electionsEntity::save(out);
		out.write(rcastcc(&delegationsNum), sizeof(delegationsNum));
		out.write(rcastcc(&citizensNum), sizeof(citizensNum));
		//out.write(rcastcc(&isDevided), sizeof(isDevided));

		return out.good();
	}

	bool County::load(istream& in, VoterList& voterRegister2)
	{
		electionsEntity::load(in, voterRegister2);
		in.read(rcastc(&delegationsNum), sizeof(delegationsNum));
		in.read(rcastc(&citizensNum), sizeof(citizensNum));
		//in.read(rcastc(&isDevided), sizeof(isDevided));

		return in.good();

	}



	//operators:

	ostream& operator <<(ostream& os, const County& other)
	{
		os << "( ";
		os << "County Name:" << other.getName() << " Serial Number: " << other.getSerial();
		os << ") " << endl;
		os << "Number Of Deligates In County :" << other.getDelNum() << endl;
		os << "Number of citizens: " << other.getCitizenNum() << endl;
		os << "Delegates List By Party Number " << endl;
		os << "County Type is : ";
		other.printIfDevided();
	





		other.printDelegateList();
		return os;
	}



	 void County::showResult(int partyCounter, int* DelegatesSumForAllParties,int winningParty)

	{
		DelegatesSumForAllParties[winningParty] = DelegatesSumForAllParties[winningParty] + getDelNum();
	}

	 void County :: printIfDevided()const
	 {
		 cout << "Regular" << endl;
	 }

	 void County :: showCountyDetails (int partyCounter,float PctOfWinningCounty,int winningParty)
	 {
		
		 cout << "***********County's Winning Party Details***********" << endl;
		 cout << "VOTES:" << endl;
		 cout << getMaxValue(partyCounter) << endl;
		 cout << "Winner Vote Precentage:" << endl;

		 cout << PctOfWinningCounty * 100 << "%" << endl;
		 cout << "Winning Party Deligate List Is : " << endl;
		 showWinningDelegatesList(winningParty);
	 }
}




#include "electionsEntity.h"


namespace elections
{
	//ctor
	electionsEntity::electionsEntity() : serialNumber(0), Name(" "), NameSize(0) {}
	electionsEntity::electionsEntity(int _serialNumber, string _Name) : serialNumber(_serialNumber), Name(_Name), NameSize(_Name.size()) {}


	//dtor
	electionsEntity::~electionsEntity()
    {
		Name.~basic_string();
	/*	if (Name)
			delete[] Name*/;
	}

	//getters:
	int electionsEntity::getSerial()const
	{
		return serialNumber;
	}

	string electionsEntity::getName()const
	{
		return Name;
	}

	int electionsEntity::getTotalVotesOfEntity(int size)
	{
		{
			long int* votesByParty = new long int[size];
			votesByParty = delegatesList.getVotesByParties();
			int sum = 0;

			for (int i = 0; i < size; i++)
			{
				sum = sum + votesByParty[i];
			}
			delete[] votesByParty;
			return sum;

		}
	}

	IdList electionsEntity::getDelegateList() const
	{
		return delegatesList;
	}

	int electionsEntity::getMaxValue(int partyNum)
	{
		long int* votesByParty = new long int[partyNum];
		votesByParty = delegatesList.getVotesByParties();
		int max = 0;

		for (int i = 0; i < partyNum; i++)
		{
			if (max < votesByParty[i])
			{
				max = votesByParty[i];
			}
		}
		delete[] votesByParty;
		return max;
	}

	long int* electionsEntity::getVotesArray(int partyNum)
	{
		long int* votesByParty = new long int[partyNum];
		votesByParty = delegatesList.getVotesByParties();
		return votesByParty;
	}

	int electionsEntity::getMaxVotesEntity(int partyNum)
	{
		long int* votesByParty = new long int[partyNum];
		votesByParty = delegatesList.getVotesByParties();
		int max = 0;
		int maxIndex = 0;
		for (int i = 0; i < partyNum; i++)
		{
			if (max < votesByParty[i])
			{
				max = votesByParty[i];
				maxIndex = i;
			}
		}
		delete[] votesByParty;
		return maxIndex;

	}

	long int* electionsEntity::getVotes()
	{

		long int* votesByParties = delegatesList.getVotesByParties();
		return votesByParties;


	}
	//probably not useful: Delete!!
	bool electionsEntity::getVotesOfEntity()
	{

		this->delegatesList.getVotesByParties();
		return true;
	}

	bool electionsEntity::showWinningDelegatesList(int winningPartyIndex)
	{
		delegatesList.showVoterListByIndex(winningPartyIndex);
		return true;
	}



	bool electionsEntity :: printDelegateList() const
	{
		cout << delegatesList;
        return true;
	}

	//setters :

	bool electionsEntity::setSerial(int _serial)
	{
		serialNumber = _serial;
		return true;
	}

	bool electionsEntity::vote(int indexNum)
	{
		delegatesList.addVote(indexNum);
		return true;
	}

	bool electionsEntity::addEntity(int serial)
	{
		delegatesList.addToTail(serial);
		return true;
	}
	bool electionsEntity::updateEntity(int size)
	{
		for (int i = 0; i < size; i++)
		{
			delegatesList.addToTail(i + 1);

		}

		return true;
	}
	bool electionsEntity::addEntityToList(int serial)
	{
		delegatesList.addToTail(serial);
		return true;
	}
	bool electionsEntity::addDelegate(Citizen *cPtr, int countySerial)
	{
		if (delegatesList.addCitizenToList(countySerial, cPtr))
			return true;
		else
			return false;
	}
	int* electionsEntity::delegationsNumEachEntity(int totalVotes,int partyCounter,int delNum)
	{
		long * votesByParties =delegatesList.getVotesByParties();
		int* delByParties = new int[partyCounter];
		int sum = 0;
		for (int i = 0; i < partyCounter; i++)
		{
			delByParties[i]=(int)(((float) votesByParties[i]/(float)totalVotes)*((float)delNum));
			sum = sum + delByParties[i];
		}
		if (delNum > sum)delByParties[0] = delByParties[0] + (delNum - sum);
		return delByParties;
		
	}


//general

    bool electionsEntity:: save(ostream& out)
    {
        int size = Name.size();
        out.write(rcastcc(&serialNumber), sizeof(serialNumber));
        out.write(rcastcc(&size), sizeof(size));
        out.write(rcastcc(&Name[0]),size);
        
       delegatesList.save(out);
       
        return out.good();
    }




    bool electionsEntity:: load(istream& in,VoterList& voterRegister2)
    {
        in.read(rcastc(&serialNumber), sizeof(serialNumber));
        in.read(rcastc(&NameSize), sizeof(NameSize));
        Name.resize(NameSize);
        in.read(rcastc(&Name[0]),NameSize);
        
        delegatesList.load(in, voterRegister2);
        
        return in.good();
    }
       
}

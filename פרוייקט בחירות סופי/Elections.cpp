#include "Elections.h"



//electionsManagerFunctions
//input check
bool checkInput(int day, int month, int year)
{
    if ((day <= 31 && day >= 1) && (month <= 12 && month >= 1))
        return true;
    else
        return false;
}

bool checkInput(string name)
{
    if (!name.empty())
        return true;
    else
        return false;
}

//q 1
//*****Change : added another argument : is devided ****//
void addCounty(CountyList* cList, bool isSimple,int countyCounter)
{
    if(isSimple)
        cout<<"This is a simple elections round, adding a county isn't possible"<<endl;
    if (!isSimple) cout << "Adding County: " << endl;
    else cout << "Adding Country: " << endl;
   string countyName;
    int delNum;
    bool isDevided;
    if (!isSimple) cout << "Please enter county name :" << endl;
    else cout << "Please enter country name :" << endl;
    cin >> countyName;
    if (!isSimple) cout << "Please enter the amount of delegates at county :" << endl;
    else cout << "Please enter the amount of delegates at country :" << endl;
    cin >> delNum;
	if (!isSimple)
	{
		cout << "Please choose County type (Devided/Regular) :" << endl;
		cout << "Devided (Press 1) *** Regular (Press 0) :" << endl;
		cin >> isDevided;
	}
     else isDevided = 1;
	County* c;
	if (isDevided == 0 ) c = new County(countyName, countyCounter, delNum, 0);
	else
	{
		
		devidedCounty* dc = new devidedCounty(countyName, countyCounter, delNum, 0);
		c = dc;
	}
    cList->addToTail(c);
}
//q 2
void addCitizen(CitizenList& voterRegister, CountyList& cList, int countyCounter, int citizenCounter, bool isSimple)
{

    cout << "Adding Citizen: " << endl;

    string name;
    string ID;
    int year;
    int month;
    int day;
    int countyNumber = 1;
    bool isDelegate;


    cout << "Please enter the following: Name, ID number, date of birth, county number, delegation status." << endl;
    cout << "Name: "; cin >> name; cout << endl;
    cout << "ID Number: "; cin >> ID; cout << endl;
    cout << "Date of birth - " << endl; cout << "day: "; cin >> day; cout << endl;
    cout << "month: "; cin >> month; cout << endl;
    cout << "year: "; cin >> year; cout << endl;
    if (!isSimple) { cout << "county number: "; cin >> countyNumber; }
    if (countyNumber > countyCounter)
        throw logic_error("county number isn't valid");

    Date date(day, month, year);
    Citizen* c = new Citizen(name, ID, date, countyNumber, false);
    cList.getCountyByIndex(countyNumber)->addCitizenToCounty();
    voterRegister.addToTail(c);
    

}
//q 3
void addParty(CitizenList& voterRegister, PartyList& plist, CountyList& clist)
{
    string partyName;
    string ID;

    //receiveing date from user
    cout << "Adding Party: " << endl;
    cout << "Please enter the following: Party name, ID of party leader." << endl;
    cout << "Party name: "; cin >> partyName; cout << endl;
    cout << "ID of party leader: "; cin >> ID;


    //getting the serial number of the party - its number in order of parties list
    int serial = plist.getSize() + 1;
    //getting the name of the party leader
    string candidateName = voterRegister.getName(ID);
    //creating new party with the details
    Party* p = new Party(partyName, serial, candidateName);
    //adding the party to the parties list
    plist.addToTail(p);
    //updating all counties with the new party & updating the party with all counties
    addPartyToAllCounties(plist.getSize(), &clist);
    addAllCountiesToParty(clist, *p);
    

}
//q 4
void addCountyToAllParties(CountyList* cList, int serialNum)
{
    cList->addPartyToAllCounties(serialNum);
}

void addPartyToAllCounties(int serial, CountyList* cList)
{
    cList->addPartyToAllCounties(serial);
    
}

void addAllCountiesToParty(CountyList& clist, Party& p)
{
    int size = clist.getSize();
    p.updateEntity(size);
    
}

void AddCitizenAsDelegate(CountyList& clist, PartyList& plist, CitizenList& voterRegister, int countyCounter, bool isSimple)
{

    int partySerial;
    int countySerial = 1;
    string ID;
    
    
    //receving data from the user
    cout << "Delegate's ID: "; cin >> ID; cout << endl;
    cout << "Party's serial number: "; cin >> partySerial; cout << endl;
    if (!isSimple) { cout << "County's serial number: "; cin >> countySerial; cout << endl; }
    if (countyCounter < countySerial)
        throw logic_error("there is no such party serial");


    //setting citizen's delegation status to "delegate"
    Citizen* newDelegate = voterRegister.getCitizen(ID);
    if (newDelegate->getDelStatus())
        throw logic_error("the new delegate is already a delegate");
    newDelegate->setDelegationStatus(true);

    //getting the correct party from list and adding the new delegate accoring to his or her county
    Party* party = plist.getPartyByIndex(partySerial - 1);
    if (party)
        party->addDelegate(newDelegate, countySerial);

    else
        throw logic_error("party's serial number isn't valid");


    
    //getting the correct county from list and adding the new delegate accoring to his or her party
    County* county = clist.getCountyByIndex(countySerial);
    if (county)
    {
        county->addDelegate(newDelegate, partySerial);
    }

    else
        throw logic_error("county's serial number isn't valid");

}


//q 8

void voteEligibility(string id, CitizenList* voterRegister,Date& date)
{
    Citizen* c = voterRegister->getCitizen(id);
    Date d = c->getDate();
    if(date.getYear() - d.getYear()<VOTINGAGE)
        throw logic_error("citizen has not turned 18 yet, so he or she can't vote");
    if( c->getVoteStatus()==true)
        throw logic_error("Citizen had already voted");
     
}


void vote(string id, int partyNum, CitizenList* voterRegister, CountyList* cList, PartyList* pList)
{
    Citizen* c;
    Party* currParty;
    County* currCounty;
    c = voterRegister->getCitizen(id);
    c->setVoteStatus(true);
    
    currCounty = cList->getCountyByIndex(c->getcounty());
    currCounty->vote(partyNum);
    currParty = pList->getPartyByIndex(partyNum - 1);
    currParty->vote(c->getcounty());

}

void voteSelection(CitizenList* voterRegister, CountyList* cList, PartyList* pList, bool dateEntered,Date& date)
{
    if(!dateEntered)
    {
        cout<<"round's date must be set before voting"<<endl;
        return;
    }
    
    string id;
    int partyNum = 0;
    cout << "Please Vote" << endl;
    cout << "insert ID number:" << endl;
    cin >> id;
    voteEligibility(id,voterRegister,date);
        
    cout << "insert Party number:" << endl;
    cin >> partyNum;
    vote(id, partyNum, voterRegister, cList, pList);
   
}

//q 9
void showResults(CountyList* cList, PartyList* pList, CitizenList* voterRegister, int partyCounter, int countyCounter)
{
    string winningCandidate;
    int* winningPartyForAllCounty = new int[countyCounter];
    int* DelegatesSumForAllParties = new int[partyCounter];
    int *DelagatesForDevidedCounty;
    for (int i = 0; i < partyCounter; i++)DelegatesSumForAllParties[i] = 0;
    float* PctOfWinningAllCounties = new float[countyCounter];
    float* PctOfVotingAllCounties = new float[countyCounter];
    PctOfWinningAllCounties = cList->PctOfWinningAllCounties(countyCounter, partyCounter);
    winningPartyForAllCounty = cList->winningPartyForAllCounty(countyCounter, partyCounter);
    PctOfVotingAllCounties = cList->PctOfVotingAllCounties(countyCounter, partyCounter);
    for (int i = 0; i < countyCounter; i++)
    {
		County* c = cList->getCountyByIndex(i +1);
        cout << "******************County Details********************" << endl;
        cout << *(c) << endl;
		c->showCountyDetails(partyCounter, PctOfWinningAllCounties[i], winningPartyForAllCounty[i]);
        winningCandidate = pList->getPartyByIndex(winningPartyForAllCounty[i])->getCandiName();
        //Making an array that sums all the Deligates each party won
        //***change 27/12****
	
		//Polymorphism
	        
        cout << "Winning County's Candidate Is : " << endl << winningCandidate << endl;

        cout << "General vote precentage:" << endl;
        cout << PctOfVotingAllCounties[i] * 100 << "%" << endl << endl;
		c->showResult(partyCounter, DelegatesSumForAllParties, winningPartyForAllCounty[i]);
    }

    int max = 0;
    int maxIndex = 0;
    cout << " ********Party Details By Order (Most Delegates to Least Delegates)********" << endl;
    cout << " ********First Is The Winner********" << endl;
    for (int j = 0; j < partyCounter; j++)
    {
        for (int index = 0; index < partyCounter; index++)
        {
            if (max < DelegatesSumForAllParties[index])
            {
                max = DelegatesSumForAllParties[index];
                maxIndex = index;
            }

        }

        cout << "Party NO. #" << maxIndex + 1 << ":" << endl;

        cout << "Party Candidate name : " << endl;
        cout << pList->getPartyByIndex(maxIndex)->getCandiName() << endl;
        cout << "Sum Of Delegates: " << endl;
        cout << DelegatesSumForAllParties[maxIndex] << endl;
        cout << "Sum Of Votes: " << endl;
        cout << pList->getPartyByIndex(maxIndex)->getTotalVotesOfEntity(countyCounter) << endl;
        DelegatesSumForAllParties[maxIndex] = -1;
        max = -1;
    }

}

//general
void printMenu(bool isSimple)
{
    cout << "Please choose one of the following options :" << endl << endl;
    if (!isSimple) cout << "Option 1 : Add county" << endl;
    else cout << "Option 1 : Add country" << endl;
    cout << "Option 2 : Add citizen" << endl;
    cout << "Option 3 : Add party" << endl;
    cout << "Option 4 : Add citizen as delgate of party" << endl;
    if (!isSimple) cout << "Option 5 : Show all counties" << endl;
    else cout << "Option 5 : Show Country Details" << endl;
    cout << "Option 6 : Show all citizens" << endl;
    cout << "Option 7 : Show all parties" << endl;
    cout << "Option 8 : VOTE" << endl;
    cout << "Option 9 : SHOW RESULTS" << endl;
    cout << "Option 10: Save current Round"<<endl;
    cout << "Option 11: set round's date"<<endl;
    cout << "Option 0 : Exit system" << endl;

    cout << endl;
    cout << "-------------------------Please Choose-------------------------" << endl;

}







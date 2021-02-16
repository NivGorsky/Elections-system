
#include <iostream>
#include "CountyList.h"
#include "County.h"
#include "CitizenList.h"
#include "IdList.h"
#include "Date.h"
#include "Citizen.h"
#include "GlobalConsts.h"
#include "VoterList.h"
#include "Party.h"
#include "PartyList.h"
#include "devidedCounty.h"
//#include "Node.h"
//#include <list>
#include <vector>
#include <string>
#define IDDIGITS 9
#define VOTINGAGE 18

using namespace elections;
using namespace std;



//declerations global functions
void printMenu(bool isSimple);
void vote(string id, int partyNum, CitizenList* voterRegister, CountyList* cList, PartyList* pList);
void addCitizen(CitizenList& voterRegister, CountyList& cList, int countyCounter, int citizenCounter, bool isSimple);
void addParty(CitizenList& voterRegister, PartyList& plist, CountyList& clist);
void addCounty(CountyList* cList,bool isSimple,int countyCounter);
void addCountyToAllParties(CountyList* cList, int serialNum);
void addPartyToAllCounties(int serial, CountyList* cList);
void addAllCountiesToParty(CountyList& clist, Party& p);
void AddCitizenAsDelegate(CountyList& clist, PartyList& plist, CitizenList& voterRegister, int countyCounter,bool isSimple);
//bool addNewCounty(CountyList& clist);
void voteSelection(CitizenList* voterRegister, CountyList* cList, PartyList* pList,bool dateEntered, Date& date);
void showResults(CountyList* cList, PartyList* pList, CitizenList* voterRegister, int partyCounter, int countyCounter);
int * calculateDelByParty(int PartyCounter, CountyList* cList, int i);

//check input
bool checkInput(int day, int month, int year);
bool checkInput(string citizen);
void voteEligibility(string id, CitizenList* voterRegister,Date& date);


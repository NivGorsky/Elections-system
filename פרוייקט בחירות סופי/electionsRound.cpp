
#include "electionsRound.h"
#include <fstream>
namespace elections{

electionsRound:: electionsRound() :
  
    flag(-1),
    citizenCounter(0),
    countyCounter(0),
    partiesCounter(0),
    cList(new CountyList),
    voterRegister(new CitizenList),
    smallVoterList(new VoterList),
    pList(new PartyList){}

electionsRound:: ~electionsRound()
{
    
}

void electionsRound:: electionsManager(bool isLoaded)
{
    
    if(!isLoaded)
    {
        cout << "For Simple Election Round Please Press 1" << endl;
        cout << "For Regular Election Round Please Press 0" << endl;
        cin >> electionsType;
    }
    
    //As long as the user didnt press '0' the menu will keep going
    while (flag != 0)
    {
        try{
        printMenu(electionsType);
        cin >> flag;
        cout << endl;
        if (flag == 1)
        {
            if (electionsType)
            {
                if (countyCounter == 0) { countyCounter++; addCounty(cList, electionsType, countyCounter); }
                else
                    throw logic_error("SIMPLE ELECTIONS ROUND , YOU HAVE ONE COUNTRY , NO COUNTIES");
            }
            else
            {
                countyCounter++;
                addCounty(cList, electionsType, countyCounter);
              
            }
        }
        if (flag == 2)
        {
            if (countyCounter == 0)
                throw logic_error("There are no Counties yet , So it's impossible to have Citizens listed ");
            else
                (addCitizen(*voterRegister, *cList, countyCounter, citizenCounter, electionsType));
        }
        if (flag == 3)
        {
            if (voterRegister->getSize() <= partiesCounter)
                throw logic_error("Not enough citizens listed to have enough Candidates ");
            else
            {
                addParty(*voterRegister, *pList, *cList); partiesCounter++;
            }
        }
            
        if (flag == 4)
            AddCitizenAsDelegate(*cList, *pList, *voterRegister, countyCounter, electionsType);
            
        if (flag == 5) cout << (*cList);
            
            
        if (flag == 6) cout << *voterRegister;
            
            
        if (flag == 7) cout << *pList;
            
            
        if (flag == 8)
        {

            if (partiesCounter == 0)
                throw logic_error("There are no Parties yet , So it's impossible to vote ");
            else voteSelection(voterRegister, cList, pList,dateEntered,date);
        }
        if (flag == 9)
        {
            showResults(cList, pList, voterRegister, partiesCounter, countyCounter);
        }
        
        if(flag==10)
            save();
        
        
       if(flag==11)
        {
            Date d;
            d.setDate();
            setDate(d);
        }
        
    
    }
        
        
        
        
        //catch
        catch(fileException& ex)
        {
            cout<<"Eror: "<<ex.what()<<endl;
            cout<<"Please make sure that the file isn't being used by other program"<<endl;
            cout<<"---------------Try again---------------"<<endl;
            
            
        }
        
        catch(std::exception& ex){
            cout<<"Eror: "<<ex.what()<<endl;
            cout<<"---------------Try again---------------"<<endl;
            
        }
        
        catch(std:: bad_alloc& ba)
        {
            cout<<"Eror: "<<ba.what()<<endl;
            exit(1);
        }
    }

}

void electionsRound:: save()
{
    
    char fileName[MAXNAME()];
    
    cout<<"please enter file name"<<endl;
    cin >>fileName;
    
    
    ofstream outFile(fileName, ios::binary | ios:: trunc);
    if(!outFile)
        throw "problem with openning the file for saving";
    
    //saving general details
    outFile.write(rcastcc(&electionsType), sizeof(electionsType));
    outFile.write(rcastcc(&countyCounter), sizeof(countyCounter));
    outFile.write(rcastcc(&partiesCounter), sizeof(partiesCounter));
    
    date.save(outFile);
    
    voterRegister->save(outFile);
    
    cList->save(outFile);
    
    pList->save(outFile);
   

    outFile.close();
    
}
void electionsRound:: load()
{
    
   
    char fileName[MAXNAME()];
    cout<<"please enter file name: "<<endl;
    cin>>fileName;
    
    ifstream inFile(fileName, ios::binary);
    if(!inFile)
        throw "problem with openning the file for loading";
    
    //getting the type of elections (either simple or devided)
    inFile.read(rcastc(&electionsType), sizeof(electionsType));
    inFile.read(rcastc(&countyCounter), sizeof(countyCounter));
    inFile.read(rcastc(&partiesCounter), sizeof(partiesCounter));
    
    date.load(inFile);
    
    voterRegister->load(inFile);
   
    
    VoterList& voterRegister2 = reinterpret_cast<VoterList&>(*(voterRegister));
    cList->load(inFile, voterRegister2);
    pList->load(inFile, voterRegister2);

    inFile.close();
    
}


}


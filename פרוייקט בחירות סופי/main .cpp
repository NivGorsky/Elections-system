#include "electionsRound.h"
void MacroMenu();

int main()
{
    //--------------Main Menu------------------------

    cout << "-------Welcome to Niv & Ido Election system-------" << endl << endl;
    MacroMenu();
}


void MacroMenu()
{
    
    
   
    int flag;
    electionsRound round;
   
    
    cout<<"Please choose on of the following options:"<<endl;
    cout << "Option 1 : Load saved elections round" << endl;
    cout << "Option 2 : create a new electoins round" << endl;
    
    cin>>flag;
    
    switch (flag) {
            
        case 1:
            round.load();
            round.electionsManager(true);
            break;
            
        case 2:
            

            round.electionsManager(false);
            break;
    }
    
}




#include "GlobalConsts.h"

namespace elections {

    char* myStringDup(char* name, int& updateValue)
    {
        int size = strlen(name);
        size+=1;
        char* newName = new char[size];
        int i;
        for(i = 0;i<size;i++)
        {
            newName[i] = name[i];
        }
        newName[i] = '\0';
        updateValue = size;
        
        
        return newName;
    }

}





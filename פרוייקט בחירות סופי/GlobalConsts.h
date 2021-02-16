

#pragma once

#include "cstring"


using namespace std;
namespace elections{

constexpr int MAXNAME(void)
{
    return 50;
}

constexpr int IDLENGTH(void)
{
    return 11;
}

char* myStringDup(char* name, int& updateValue);

}

#pragma once
#include <iostream>


namespace elections {


class fileException : public exception{

public:
    const char* what() const throw()
    {
    
        return "problem with saving or loading the file";
    
    }
};


}

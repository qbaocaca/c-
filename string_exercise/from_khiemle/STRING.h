#ifndef STRING_h
#define STRING_h
#include "CHAR.h"
#include <string>

class STRING
{
private:
    CHAR *content; // string is an array of char so use ptr
    int length;

public:
    STRING();
    STRING(std::string);
    STRING(char);
    STRING(CHAR);

    std::string getContent() const;

    STRING &expand(char);
    STRING &expand(CHAR);
    STRING &expand(STRING);
    STRING &expand(std::string);
    
    STRING &remove(CHAR);
    STRING &remove(char);

    void input();
};

#endif
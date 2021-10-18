#include "CHAR.h"
#include <iostream>
using namespace std;
// :: scope resolution operator (toan tu pham vi)
CHAR::CHAR()
{
}

CHAR::CHAR(char ch)
{
    this->content = ch;
}

char CHAR::getContent() const
{
    return this->content;
}
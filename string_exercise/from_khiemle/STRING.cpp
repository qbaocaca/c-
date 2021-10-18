#include "STRING.h"
#include "CHAR.h"
#include <iostream>
#include <string>

void allocate_(CHAR *&a, int size)
{
    a = new CHAR[size];
}
STRING::STRING()
{
    this->content = NULL;
    this->length = 0;
}

STRING::STRING(std::string other)
{
    int i = 0, len = 0;
    while (other[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, this->length + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = other[i];
    }
}

STRING::STRING(char ch)
{
    allocate_(this->content, 1);
    this->length = 1;
    this->content[0] = CHAR(ch);
}

STRING::STRING(CHAR ch)
{
    allocate_(this->content, 1);
    this->length = 1;
    this->content[0] = ch;
}

// convert STRING content to std::string
std::string STRING::getContent() const
{
    std::string str;
    for (int i = 0; i < this->length; i++)
    {
        str.push_back(this->content[i].getContent());
    }
    return str;
}

STRING &STRING::expand(CHAR ch)
{
    std::string str = this->getContent();
    str.push_back(ch.getContent());
    // STRING(str);

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, this->length + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = str[i];
    }

    return *this; // return the value of this
}

STRING &STRING::expand(std::string str)
{
    std::string finalStr = this->getContent();
    finalStr.append(str);
    // STRING(finalStr);

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (finalStr[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, this->length + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = finalStr[i];
    }

    return *this;
}

STRING &STRING::expand(char ch)
{
    std::string str = this->getContent();
    str.push_back(ch);
    // STRING(str);

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, this->length + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = str[i];
    }

    return *this;
}

STRING &STRING::expand(STRING other)
{
    std::string finalStr = this->getContent();
    finalStr.append(other.getContent());
    // STRING(finalStr);

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (finalStr[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, this->length + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = finalStr[i];
    }

    return *this;
}

STRING &STRING::remove(CHAR ch)
{
    std::string str;
    for (int i = 0; i < this->length; i++)
    {
        if (this->content[i].getContent() != ch.getContent())
        {
            str.push_back(this->content[i].getContent());
        }
    }

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, len + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = str[i];
    }
    return *this;
}

STRING &STRING::remove(char ch)
{
    std::string str;
    for (int i = 0; i < this->length; i++)
    {
        if (this->content[i].getContent() != ch)
        {
            str.push_back(this->content[i].getContent());
        }
    }

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, len + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = str[i];
    }
    return *this;
}

void STRING::input()
{
    std::string str;
    getline(std::cin, str);

    if (this->content != NULL)
    {
        delete[] this->content;
    }

    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    this->length = len;
    allocate_(this->content, len + 1);
    for (int i = 0; i < this->length; i++)
    {
        this->content[i] = str[i];
    }
}
#pragma once


class BaseCObject
{
public:
    virtual const char* classname() = 0;
    virtual unsigned int size() = 0;
};

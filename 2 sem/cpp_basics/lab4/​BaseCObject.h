#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


class BaseCObject
{
    public:
        virtual const char* classname() = 0;
        virtual unsigned int size() = 0;
};


#endif
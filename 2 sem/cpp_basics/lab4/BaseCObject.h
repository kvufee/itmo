#pragma once


class BaseCObject
{
    public:
        char str[100];

        const char* fig_name = str;
        unsigned int fig_size;
        
        virtual const char* classname() = 0;
        virtual unsigned int size() = 0;
};

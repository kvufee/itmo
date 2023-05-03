#include "BaseCObject.h"
#include "IDialogInitiable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"

#include <bits/stdc++.h>

using namespace std;


class BaseCObject
{
    public:
        virtual const char* classname();
        virtual unsigned int size();
};

class IDialogInitiable
{
    public:

};

class IGeoFig
{
    public:
        int square, perimeter;

        double square()
        {
            cin >> square;
        }

        double perimeter()
        {
            cin >> perimeter;
        }

};

class IPhysObject
{
    public:
        double mass;

        double mass()
        {
            cin >> mass;
        }


};

class IPrintable
{
    public:

};

class hexagon : public BaseCObject, public IDialogInitiable, public IGeoFig, public IPhysObject, public IPrintable
{
    public:
        const char* classname() override
        {

        }

        unsigned int size() override
        {
            
        }


};
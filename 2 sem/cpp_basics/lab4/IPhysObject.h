#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include "CVector2D.h"


class IPhysObject
{
    public:
        virtual double mass() = 0;
        virtual CVector2D position() = 0;
        virtual bool operator== ( const IPhysObject& ob ) const = 0;
        virtual bool operator< ( const IPhysObject& ob ) const = 0;
};


#endif
#pragma once


class IPhysObject
{
    public:
        virtual double mass() = 0;
        virtual bool operator== ( const IPhysObject& ob ) const = 0;
        virtual bool operator< ( const IPhysObject& ob ) const = 0;
};

#pragma once


class IPhysObject
{
    public:
        virtual double mass() = 0;
        virtual bool operator== (IPhysObject& ob) = 0;
        virtual bool operator< (IPhysObject& ob) = 0;
};

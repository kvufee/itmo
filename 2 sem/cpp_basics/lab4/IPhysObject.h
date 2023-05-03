#pragma once


class IPhysObject
{
    public:
        virtual double mass() = 0;
        virtual bool operator== (IPhysObject& ob) const = 0;
        virtual bool operator< (IPhysObject& ob) const = 0;
};

#include <bits/stdc++.h>

using namespace std;


class IGeoFig {
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double mass() = 0;
    virtual CVector2D position() = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogInitiable {
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char* classname() = 0;
    virtual unsigned int size() = 0;
};

struct IFigure : IPrintable, IGeoFig, IPhysObject, IDialogInitiable, BaseCObject {};


class EquilateralTriangle : public IFigure {
private:
    double sideLength;
    double mass_;
    CVector2D center;
public:
    EquilateralTriangle(double length) : sideLength(length) {}
    ~EquilateralTriangle();
    double square() override {
        return (sqrt(3) / 4) * sideLength * sideLength;
    }

    double perimeter() override {
        return 3 * sideLength;
    }

    double mass() override {
        return mass_;
    }

    virtual CVector2D position() override {
        return center;
    };

    void draw() override {
        cout << "Side lenght: " << sideLength << "\n";
        cout << "Square: " << square() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
        cout << "Mass: " << mass() << "\n";
        cout << "Enter center coords: (" << position().x << ", " << position().y << ")" << "\n";
    }

    void initFromDialog() override {
        cout << "Enter lenght side: ";
        cin >> sideLength;
        cout << "Enter mass: ";
        cin >> mass_;
        cout << "Enter center coords: ";
        cin >> center.x >> center.y;

        cout << "\n";
    }

    const char* classname() override {
        return "EquilateralTriangle";
    }

    unsigned int size() override {
        return sizeof(*this);
    }
};

class Hexagon : public IFigure {
private:
    double sideLength;
    double mass_;
    CVector2D center;
public:
    Hexagon(double length) : sideLength(length) {}
    ~Hexagon();
    double square() override {
        return (3 * sqrt(3) / 2) * sideLength * sideLength;
    }

    double perimeter() override {
        return 6 * sideLength;
    }

    double mass() override {
        return mass_;
    }

    virtual CVector2D position() override {
        return center;
    };

    void draw() override {
        cout << "Side lenght: " << sideLength << "\n";
        cout << "Square: " << square() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
        cout << "Mass: " << mass() << "\n";
        cout << "Enter center coords: (" << position().x << ", " << position().y << ")" << "\n";
    }

    void initFromDialog() override {
        cout << "Enter lenght side: ";
        cin >> sideLength;
        cout << "Enter mass: ";
        cin >> mass_;
        cout << "Enter center coords: ";
        cin >> center.x >> center.y;
        cout << "\n";
    }

    const char* classname() override {
        return "Hexagon";
    }

    unsigned int size() override {
        return sizeof(*this);
    }
};
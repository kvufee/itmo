#include "BaseCObject.h"
#include "IDialogInitiable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"


class hexagon : public BaseCObject, public IDialogInitiable, public IGeoFig, public IPhysObject, public IPrintable
{
public:
    hexagon();

    hexagon(double fig_side, double fig_square, double fig_perimeter, double fig_mass);

    //BaseCObject
    const char* classname() override;
    unsigned int size() override;

    //IDialogInitiable
    void InitFromDialog() override;

    //IGeoFig
    double square() override;
    double perimeter() override;

    //IPhysObject
    double mass() override;
    bool operator==(IPhysObject& ob) override;
    bool operator<(IPhysObject& ob) override;

    //IPrintable
    void draw() override;


private:
    double fig_side;
    double fig_square, fig_perimeter;
    double fig_mass;
};
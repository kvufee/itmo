#include "BaseCObject.h"
#include "IDialogInitiable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"


class ellips : public BaseCObject, public IDialogInitiable, public IGeoFig, public IPhysObject, public IPrintable
{
public:
    ellips();

    ellips(double fig_radius, double fig_mass, double fig_diag1,
           double fig_diag2, double fig_square, double fig_perimeter);

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
    double fig_radius;
    double fig_mass;
    double fig_diag1, fig_diag2;
    double fig_square, fig_perimeter;
};
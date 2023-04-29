#include "BaseCObject.h"
#include "CVector2D.h"
#include "IDialogInitiable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"

#include <bits/stdc++.h>

using namespace std;


class hexagon : public BaseCObject, public CVector2D, public IDialogInitiable, public IGeoFig, public IPhysObject, public IPrintable
{
    public:

}
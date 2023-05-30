#include"interface.h"

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<IFigure*> objects;

    int choice;

    while (true) {
        cout << "1. Add triangle \n2. Add hexagon\n3. Sort\n4. Output all figures\n0. Exit\n ";
        cin >> choice;

        if (choice == 0) {
            cout << "\n";
            break;
        }

        else if (choice == 1) {
            EquilateralTriangle* triangle = new EquilateralTriangle(0.0);
            triangle->initFromDialog();
            objects.push_back(triangle);
        }
        else if (choice == 2) {
            Hexagon* hexagon = new Hexagon(0.0);
            hexagon->initFromDialog();
            objects.push_back(hexagon);
        }
        else if (choice == 3) {
            sort(objects.begin(), objects.end(), [](IPhysObject* obj1, IPhysObject* obj2) {
                return obj1->mass() < obj2->mass();
                });
        }
        else if (choice == 4) {
            cout << "All figures: " << "\n";
            for (const auto& object : objects) {
                object->draw();
                cout << "\n";
            }

            double totalSquare = 0.0;
            for (const auto& object : objects) {
                totalSquare += object->square();
            }
            cout << "Summary square: " << totalSquare << "\n";

            double totalPerimeter = 0.0;
            for (const auto& object : objects) {
                totalPerimeter += object->perimeter();
            }
            cout << "Summary perimeter: " << totalPerimeter << "\n";

            double massXSum = 0.0;
            double massYSum = 0.0;
            double totalMass = 0.0;
            for (const auto& object : objects) {
                CVector2D position = object->position();
                double mass = object->mass();
                massXSum += mass * position.x;
                massYSum += mass * position.y;
                totalMass += mass;
            }
            CVector2D centerOfMass;
            centerOfMass.x = massXSum / totalMass;
            centerOfMass.y = massYSum / totalMass;
            cout << "Center mass: (" << centerOfMass.x << ", " << centerOfMass.y << ")" << "\n";
            unsigned int totalSize = 0;
            for (const auto& object : objects) {
                totalSize += object->size();
            }
            cout << "Overall memory: " << totalSize << " bites" << "\n";

        }
    }

    for (const auto& object : objects) {
        delete object;
    }

    return 0;
}
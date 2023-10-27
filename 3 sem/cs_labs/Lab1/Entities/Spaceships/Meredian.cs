using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Meredian : Spaceship
{
    private EngineTypeE _engineTypeE = new EngineTypeE();

    public Meredian()
    {
        SpaceshipType = this.GetType().Name;
        SpaceshipEngineType = new List<string>();
        SpaceshipDeflectorType = "Class 2";
        SpaceshipEndurance = 0;
        SpaceshipStrengthClass = 2;
        SpaceshipMass = 500;
        IsModifiedAntiNitrine = true;

        SpaceshipEngineType.Add(_engineTypeE.EngineType);
    }
}
using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class WalkShuttle : Spaceship
{
    private EngineTypeC _engineTypeC = new EngineTypeC();

    public WalkShuttle()
    {
        SpaceshipType = this.GetType().Name;
        SpaceshipEngineType = new List<string>();
        SpaceshipDeflectorType = "None";
        SpaceshipEndurance = 0;
        SpaceshipStrengthClass = 1;
        SpaceshipMass = 250;
        IsModifiedAntiNitrine = false;

        SpaceshipEngineType.Add(_engineTypeC.EngineType);
    }
}
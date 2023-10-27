using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Vaklas : Spaceship
{
    private EngineTypeE _engineTypeE = new EngineTypeE();
    private JumpingEngineGamma _jumpingEngineGamma = new JumpingEngineGamma();
    public Vaklas()
    {
        SpaceshipType = this.GetType().Name;
        SpaceshipEngineType = new List<string>();
        SpaceshipDeflectorType = "Class 1";
        SpaceshipEndurance = 0;
        SpaceshipStrengthClass = 2;
        SpaceshipMass = 100;
        IsModifiedAntiNitrine = false;

        SpaceshipEngineType.Add(_engineTypeE.EngineType);
        SpaceshipEngineType.Add(_jumpingEngineGamma.EngineType);
    }
}
using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Stella : Spaceship
{
    private EngineTypeC _engineTypeC = new EngineTypeC();
    private JumpingEngineOmega _jumpingEngineOmega = new JumpingEngineOmega();
    public Stella()
    {
        SpaceshipType = this.GetType().Name;
        SpaceshipEngineType = new List<string>();
        SpaceshipDeflectorType = "Class 1";
        SpaceshipEndurance = 0;
        SpaceshipStrengthClass = 1;
        SpaceshipMass = 250;
        IsModifiedAntiNitrine = false;

        SpaceshipEngineType.Add(_engineTypeC.EngineType);
        SpaceshipEngineType.Add(_jumpingEngineOmega.EngineType);
    }
}
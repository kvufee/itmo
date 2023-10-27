using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;
namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Avgur : Spaceship
{
    private EngineTypeE _engineTypeE = new EngineTypeE();
    private JumpingEngineAlpha _jumpingEngineAlpha = new JumpingEngineAlpha();
    public Avgur()
    {
        SpaceshipType = this.GetType().Name;
        SpaceshipEngineType = new List<string>();
        SpaceshipDeflectorType = "Class 3";
        SpaceshipEndurance = 0;
        SpaceshipStrengthClass = 3;
        SpaceshipMass = 750;
        IsModifiedAntiNitrine = false;

        SpaceshipEngineType.Add(_engineTypeE.EngineType);
        SpaceshipEngineType.Add(_jumpingEngineAlpha.EngineType);
    }
}
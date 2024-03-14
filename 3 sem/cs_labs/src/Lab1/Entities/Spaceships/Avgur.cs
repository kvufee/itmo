using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Avgur : Spaceship
{
    public Avgur(bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
        : base(new EngineTypeC(), null, new JumpingEngineAlpha(), "Heavy", 150, 3, 3, isModifiedAntiNeutronAbsorber, isModifiedPhotonicDeflector)
    { }
}
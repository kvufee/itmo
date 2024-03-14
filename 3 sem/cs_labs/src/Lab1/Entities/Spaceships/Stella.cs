using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Stella : Spaceship
{
    public Stella(bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
        : base(new EngineTypeC(), null, new JumpingEngineOmega(), "Light", 30, 1, 1, isModifiedAntiNeutronAbsorber, isModifiedPhotonicDeflector)
    { }
}
using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Vaklas : Spaceship
{
    public Vaklas(bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
        : base(null, new EngineTypeE(), new JumpingEngineGamma(), "Mid", 70, 1, 2, isModifiedAntiNeutronAbsorber, isModifiedPhotonicDeflector)
    { }
}
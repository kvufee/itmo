using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class Meredian : Spaceship
{
    public Meredian(bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
        : base(null, new EngineTypeE(), null, "Mid", 90, 2, 2, isModifiedAntiNeutronAbsorber, isModifiedPhotonicDeflector)
    { }
}
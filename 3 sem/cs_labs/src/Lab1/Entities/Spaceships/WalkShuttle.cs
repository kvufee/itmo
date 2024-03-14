using Itmo.ObjectOrientedProgramming.Lab1.Engines;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public class WalkShuttle : Spaceship
{
    public WalkShuttle(bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
        : base(new EngineTypeC(), null, null, "Light", 20, 0, 1, isModifiedAntiNeutronAbsorber, isModifiedPhotonicDeflector)
    { }
}
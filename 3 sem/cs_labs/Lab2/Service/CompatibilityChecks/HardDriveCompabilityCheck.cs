using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class HardDriveCompabilityCheck
{
    public static bool IsHardDriveCompatible(HardDrive hardDrive, Motherboard motherboard)
    {
        if (hardDrive is null || motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if (motherboard.SataSlotsAmountProperty >= 1)
        {
            return true;
        }

        return false;
    }
}
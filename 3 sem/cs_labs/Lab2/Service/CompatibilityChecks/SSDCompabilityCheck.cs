using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class SSDCompabilityCheck
{
    public static bool IsSsdCompatible(SSD ssd, Motherboard motherboard)
    {
        if (ssd is null || motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if ((motherboard.SataSlotsAmountProperty >= 1 && ssd.IsSataConnectionProperty == true) ||
             (motherboard.PciELinesProperty is not null && ssd.IsSataConnectionProperty == false))
        {
            return true;
        }

        return false;
    }
}
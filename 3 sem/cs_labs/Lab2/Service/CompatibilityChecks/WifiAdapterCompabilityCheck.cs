using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class WifiAdapterCompabilityCheck
{
    public static bool IsWifiAdapterCompatible(Motherboard motherboard)
    {
        if (motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if (motherboard.IsWifiModifiedProperty == false)
        {
            return true;
        }

        return false;
    }
}
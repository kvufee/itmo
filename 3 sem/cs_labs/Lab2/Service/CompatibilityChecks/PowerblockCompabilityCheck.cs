using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class PowerblockCompabilityCheck
{
    public static bool IsPowerblockCompatible(PowerBlock powerBlock, CPU cpu, GPU gpu, HardDrive hardDrive, RAM ram, SSD ssd, WifiAdapter wifiAdapter)
    {
        if (powerBlock is null || cpu is null || gpu is null || hardDrive is null || ram is null || ssd is null || wifiAdapter is null)
            throw new NullParameterException("One of the parameters is null");
        if (powerBlock.PowerCapacityProperty >= (cpu.PowerAmountProperty + gpu.RequiredPowerProperty + hardDrive.RequiredPowerProperty +
                                                    ram.RequiredPowerProperty + ssd.RequiredPowerProperty + wifiAdapter.RequiredPowerProperty))
        {
            return true;
        }

        return false;
    }
}
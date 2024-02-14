using System;
using Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public static class Checker
{
    public static bool CorrectnessCheck(BuiltPc pc)
    {
        if (pc is null) throw new ArgumentNullException(nameof(pc), "Computer does not exist");
        if (CoolingSystemCompabilityCheck.IsCoolingSystemCompatible(pc.GetCoolingSystem(), pc.GetCpu(), pc.GetPcCase()) &&
            CPUCompabilityCheck.IsCpuCompatible(pc.GetCpu(), pc.GetRam(), pc.GetMotherboard(), pc.GetCoolingSystem()) &&
            GPUCompabilityCheck.IsGpuCompatible(pc.GetGpu(), pc.GetPcCase(), pc.GetMotherboard()) &&
            HardDriveCompabilityCheck.IsHardDriveCompatible(pc.GetHardDrive(), pc.GetMotherboard()) &&
            MotherboardCompabilityCheck.IsMotherboardCompatible(pc.GetMotherboard(), pc.GetPcCase(), pc.GetCpu(), pc.GetRam(), pc.GetSsd()) &&
            PcCaseCompabilityCheck.IsPcCaseCompatible(pc.GetPcCase(), pc.GetGpu(), pc.GetMotherboard()) &&
            PowerblockCompabilityCheck.IsPowerblockCompatible(pc.GetPowerBlock(), pc.GetCpu(), pc.GetGpu(), pc.GetHardDrive(), pc.GetRam(), pc.GetSsd(), pc.GetWifiAdapter()) &&
            RAMCompabilityCheck.IsRamCompatible(pc.GetRam(), pc.GetMotherboard(), pc.GetCpu()) &&
            SSDCompabilityCheck.IsSsdCompatible(pc.GetSsd(), pc.GetMotherboard()) &&
            WifiAdapterCompabilityCheck.IsWifiAdapterCompatible(pc.GetMotherboard()))
        {
            return true;
        }
        else
        {
            throw new BuildUnsuccessfullException("Build failed");
        }
    }
}
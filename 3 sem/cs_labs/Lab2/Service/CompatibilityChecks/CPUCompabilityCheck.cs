using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class CPUCompabilityCheck
{
    public static bool IsCpuCompatible(CPU cpu, RAM ram, Motherboard motherboard, CoolingSystem? coolingSystem)
    {
        if (coolingSystem is null || cpu is null || ram is null || motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if (cpu.SupportedRamFrequencesProperty is not null &&
            cpu.SocketTypeProperty is not null &&
            coolingSystem.SupportedCpuSocketsProperty is not null &&
            ram.AvailableMemoryProfilesProperty is not null &&
            cpu.SocketTypeProperty == motherboard.SocketTypeProperty &&
            cpu.SupportedRamFrequencesProperty.Intersect(ram.AvailableMemoryProfilesProperty).Any() &&
            coolingSystem.SupportedCpuSocketsProperty.Contains(cpu.SocketTypeProperty))
        {
            return true;
        }

        return false;
    }
}
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class RAMCompabilityCheck
{
    public static bool IsRamCompatible(RAM ram, Motherboard motherboard, CPU cpu)
    {
        if (ram is null || cpu is null || motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if (cpu.SupportedRamFrequencesProperty is not null &&
            ram.AvailableMemoryProfilesProperty is not null &&
            motherboard.SupportedRamFrequencyProperty is not null &&
            motherboard.RamFormfactorProperty == ram.RamFormfactorProperty &&
            motherboard.SupportedDdrTypeProperty == ram.RamMemoryStandartProperty &&
            motherboard.SupportedRamFrequencyProperty.Intersect<int>(ram.AvailableMemoryProfilesProperty).Any() &&
            cpu.SupportedRamFrequencesProperty.Intersect<int>(ram.AvailableMemoryProfilesProperty).Any())
        {
            return true;
        }

        return false;
    }
}
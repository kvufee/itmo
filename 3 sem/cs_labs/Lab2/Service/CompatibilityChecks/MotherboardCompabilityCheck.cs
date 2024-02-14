using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class MotherboardCompabilityCheck
{
    public static bool IsMotherboardCompatible(Motherboard motherboard, PcCase pcCase, CPU cpu, RAM ram, SSD ssd)
    {
        if (ram is null || cpu is null || pcCase is null || motherboard is null || ssd is null)
            throw new NullParameterException("One of the parameters is null");
        if (motherboard.SupportedRamFrequencyProperty is not null &&
            ram.AvailableMemoryProfilesProperty is not null &&
            motherboard.SupportedDdrTypeProperty is not null &&
            ram.RamMemoryStandartProperty is not null &&
            pcCase.SupportedMotherboardFormfactorsProperty is not null &&
            motherboard.MotherboardFormfactorProperty is not null &&
            pcCase.SupportedMotherboardFormfactorsProperty.Contains(motherboard.MotherboardFormfactorProperty) &&
            cpu.SocketTypeProperty == motherboard.SocketTypeProperty &&
            motherboard.RamFormfactorProperty == ram.RamFormfactorProperty &&
            motherboard.SupportedDdrTypeProperty == ram.RamMemoryStandartProperty &&
            motherboard.SupportedRamFrequencyProperty.Intersect(ram.AvailableMemoryProfilesProperty).Any() &&
            ((motherboard.SataSlotsAmountProperty >= 1 && ssd.IsSataConnectionProperty) ||
             (motherboard.PciELinesProperty is not null && ssd.IsSataConnectionProperty == false)))
        {
            return true;
        }

        return false;
    }
}
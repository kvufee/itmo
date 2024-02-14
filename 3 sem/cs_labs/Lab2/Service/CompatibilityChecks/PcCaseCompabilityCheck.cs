using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class PcCaseCompabilityCheck
{
    public static bool IsPcCaseCompatible(PcCase pcCase, GPU gpu, Motherboard motherboard)
    {
        if (gpu is null || motherboard is null || pcCase is null)
            throw new NullParameterException("One of the parameters is null");
        if (motherboard.MotherboardFormfactorProperty is not null &&
            pcCase.SupportedMotherboardFormfactorsProperty is not null &&
            gpu.GpuLenghtProperty < pcCase.CaseLengthProperty &&
            gpu.GpuHeightProperty < pcCase.CaseHeightProperty &&
            pcCase.SupportedMotherboardFormfactorsProperty.Contains(motherboard.MotherboardFormfactorProperty))
        {
            return true;
        }

        return false;
    }
}
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public static class GPUCompabilityCheck
{
    public static bool IsGpuCompatible(GPU gpu, PcCase pcCase, Motherboard motherboard)
    {
        if (gpu is null || pcCase is null || motherboard is null)
            throw new NullParameterException("One of the parameters is null");
        if (gpu.PciEVersionProperty is not null &&
            motherboard.PciELinesProperty is not null &&
            gpu.GpuLenghtProperty < pcCase.CaseLengthProperty &&
            gpu.GpuHeightProperty < pcCase.CaseHeightProperty &&
            motherboard.PciELinesProperty.Contains(gpu.PciEVersionProperty))
        {
            return true;
        }

        return false;
    }
}
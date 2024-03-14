using Itmo.ObjectOrientedProgramming.Lab2.Tests;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class Director
{
    private DataBase _database = new DataBase();
    private RepositoryData _repositoryData;
    public Director()
    {
        _repositoryData = new RepositoryData(_database);
    }

    public PcBuilder Builder { get; set; } = new PcBuilder();

    public BuiltPc? BuildComputer(
        string? coolingSystemName,
        string cpuName,
        string? gpuName,
        string? hardDriveName,
        string motherboardName,
        string? pcCaseName,
        string? powerblockName,
        string ramName,
        string? ssdName,
        string? wifiAdapterName)
    {
        Builder.BuildCoolingSystem(_database.CoolingSystemRepository.Find(coolingSystemName));
        Builder.BuildCpu(_database.CpuRepository.Find(cpuName));
        Builder.BuildGpu(_database.GpuRepository.Find(gpuName));
        Builder.BuildHardDrive(_database.HardDriveRepository.Find(hardDriveName));
        Builder.BuildMotherboard(_database.MotherboardRepository.Find(motherboardName));
        Builder.BuildPcCase(_database.PcCaseRepository.Find(pcCaseName));
        Builder.BuildPowerBlock(_database.PowerblockRepository.Find(powerblockName));
        Builder.BuildRam(_database.RamRepository.Find(ramName));
        Builder.BuildSsd(_database.SsdRepository.Find(ssdName));
        Builder.BuildWifiAdapter(_database.WifiAdapterRepository.Find(wifiAdapterName));
        return Builder.ReturnBuiltPc();
    }
}
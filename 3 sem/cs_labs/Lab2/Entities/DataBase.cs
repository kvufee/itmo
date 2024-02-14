namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class DataBase
{
    public DataBase()
    {
        CoolingSystemRepository = new Repository<CoolingSystem>();
        CpuRepository = new Repository<CPU>();
        GpuRepository = new Repository<GPU>();
        HardDriveRepository = new Repository<HardDrive>();
        MotherboardRepository = new Repository<Motherboard>();
        PcCaseRepository = new Repository<PcCase>();
        PowerblockRepository = new Repository<PowerBlock>();
        RamRepository = new Repository<RAM>();
        SsdRepository = new Repository<SSD>();
        WifiAdapterRepository = new Repository<WifiAdapter>();
    }

    public Repository<CoolingSystem> CoolingSystemRepository { get; }
    public Repository<CPU> CpuRepository { get; }
    public Repository<GPU> GpuRepository { get; }
    public Repository<HardDrive> HardDriveRepository { get; }
    public Repository<Motherboard> MotherboardRepository { get; }
    public Repository<PcCase> PcCaseRepository { get; }
    public Repository<PowerBlock> PowerblockRepository { get; }
    public Repository<RAM> RamRepository { get; }
    public Repository<SSD> SsdRepository { get; }
    public Repository<WifiAdapter> WifiAdapterRepository { get; }
}
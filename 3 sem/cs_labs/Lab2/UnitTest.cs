using Itmo.ObjectOrientedProgramming.Lab2.Entities;
using Xunit;

namespace Itmo.ObjectOrientedProgramming.Lab2.Tests;

public class UnitTest
{
    private readonly DataBase _dataBase;
    private readonly PcBuilder _builder;
    private readonly Director _director;
    private BuiltPc? _firstBuild;
    private BuiltPc? _secondBuild;
    private BuiltPc? _thirdBuild;
    private BuiltPc? _fourthBuild;

    public UnitTest()
    {
        _director = new Director();
        _dataBase = new DataBase();
        _builder = new PcBuilder();
        _firstBuild = _director.BuildComputer(
            "Cooler Master Hyper 212 RGB",
            "AMD Ryzen 7 5800X",
            "Nvidia RTX 3080",
            "Samsung 870 EVO",
            "ASUS ROG Strix B550-F Gaming",
            "Fractal Design Meshify C",
            "Corsair CX550M",
            "Corsair Vengeance LPX",
            null,
            null);
        _secondBuild = _director.BuildComputer(
            "Cooler Master Hyper 212 RGB",
            "AMD Ryzen 7 5800X",
            "Nvidia RTX 3080",
            "Samsung 870 EVO",
            "ASUS ROG Strix B550-F Gaming",
            "Fractal Design Meshify C",
            "Accord ACC-TFX150",
            "Corsair Vengeance LPX",
            null,
            null);
        _thirdBuild = _director.BuildComputer(
            "Noctua NH-L9i",
            "AMD Ryzen 7 5800X",
            "Nvidia RTX 3080",
            "Samsung 870 EVO",
            "ASUS ROG Strix B550-F Gaming",
            "Fractal Design Meshify C",
            "Corsair CX550M",
            "Corsair Vengeance LPX",
            null,
            null);
        _fourthBuild = _director.BuildComputer(
            "NZXT Kraken X63",
            "Intel Core i9-12900K",
            "AMD RX 6900 XT",
            null,
            "Gigabyte B450 AORUS M",
            "NZXT H510",
            "Corsair CX550M",
            "Corsair Vengeance LPX",
            "Western Digital WD Blue SN550",
            "Netgear Nighthawk A7000");
    }

    [Fact]
    public void SuccessfulBuild()
    {
        if (_firstBuild != null)
        {
            BuiltPc pc = _firstBuild;
            Assert.True(Checker.CorrectnessCheck(pc));
        }
    }

    [Fact]
    public void EnergyConsumptionIsTooBig()
    {
        if (_secondBuild != null)
        {
            BuiltPc pc = _secondBuild;
            Assert.False(Checker.CorrectnessCheck(pc));
        }
    }

    [Fact]
    public void NotEnoughTdp()
    {
        if (_thirdBuild != null)
        {
            BuiltPc pc = _thirdBuild;
            Assert.False(Checker.CorrectnessCheck(pc));
        }
    }

    [Fact]
    public void UnsuccessfulBuild()
    {
        if (_fourthBuild != null)
        {
            BuiltPc pc = _fourthBuild;
            Assert.False(Checker.CorrectnessCheck(pc));
        }
    }

    [Theory]
    [InlineData("Mewing AeroChad", true, 2048, 1300, 3000, 7)]
    [InlineData("Colgate White Power", false, 1024, 100, 400, 50)]
    public void AddNewSsd(string name, bool isSataConnection, int memoryCapacity, int maxWriteSpeed, int maxReadSpeed, int requiredPower)
    {
        var newSsd = new SSD(
            name,
            isSataConnection,
            memoryCapacity,
            maxWriteSpeed,
            maxReadSpeed,
            requiredPower);
        _dataBase.SsdRepository.Add(newSsd);
        Assert.IsType<SSD>(_dataBase.SsdRepository.Find(newSsd.Name));
    }

    [Theory]
    [InlineData(1488)]
    [InlineData(1)]
    public void ModifyCoolingSystemWithTdp(int maxTdp)
    {
        CoolingSystem? oldCooler = _dataBase.CoolingSystemRepository.Find("Cooler Master Hyper 212 RGB");
        CoolingSystem? newCooler = oldCooler;
        newCooler?.SetMaxTdp(maxTdp);
        if (newCooler != null && oldCooler != null) Assert.NotEqual(newCooler.MaxTdpProperty, oldCooler.MaxTdpProperty);
    }
}
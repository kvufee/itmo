using System;

namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public abstract class Engine : IEngine
{
    private string _engineType;
    private int _speed;
    private int _time;
    private int _fuelCapacity;
    private int _fuelConsumption;
    private int _pathLenght;
    public string EngineType
    {
        get { return _engineType; }
        set { _engineType = value; }
    }

    public int Speed
    {
        get { return _speed; }
        set { _speed = value; }
    }

    public int Time
    {
        get { return _time; }
        set { _time = value; }
    }

    public int FuelCapacity
    {
        get { return _fuelCapacity; }
        set { _fuelCapacity = value; }
    }

    public int FuelConsumption
    {
        get { return _fuelConsumption; }
        set { _fuelConsumption = value; }
    }

    public int PathLenght
    {
        get { return _pathLenght; }
        set { _pathLenght = value; }
    }

    public virtual int CalculateFuelConsumption()
    {
        switch (EngineType)
        {
            case "EngineTypeE":
                FuelConsumption *= Convert.ToInt32(Math.Exp(FuelConsumption));
                break;
            case "JumpingEngineOmega":
                FuelConsumption *= Convert.ToInt32(Math.Log2(FuelConsumption));
                break;
            case "JumpingEngineGamma":
                FuelConsumption *= FuelConsumption;
                break;
        }

        return _fuelConsumption;
    }

    public virtual int CalculateTime()
    {
        if (EngineType == "EngineTypeE")
        {
            Time = PathLenght / Convert.ToInt32(Math.Exp(Speed));
        }
        else
        {
            Time = PathLenght / Speed;
        }

        return Time;
    }

    public virtual bool IsPassable()
    {
        if (EngineType == "EngineTypeE")
        {
            return CalculateFuelConsumption() * Convert.ToInt32(Math.Exp(Speed)) < FuelCapacity;
        }

        return CalculateFuelConsumption() * Speed < FuelCapacity;
    }

    public virtual void Start() { }
}
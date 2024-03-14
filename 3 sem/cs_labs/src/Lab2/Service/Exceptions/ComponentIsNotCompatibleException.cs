using System;

namespace Itmo.ObjectOrientedProgramming.Lab2.Service;

public class ComponentIsNotCompatibleException : Exception
{
    public ComponentIsNotCompatibleException()
    { }

    public ComponentIsNotCompatibleException(string message)
        : base(message)
    { }

    public ComponentIsNotCompatibleException(string message, Exception innerException)
        : base(message, innerException)
    { }
}
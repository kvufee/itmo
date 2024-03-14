using System;

namespace Itmo.ObjectOrientedProgramming.Lab2.Service;

public class ComponentNotFoundException : Exception
{
    public ComponentNotFoundException()
    { }

    public ComponentNotFoundException(string message)
        : base(message)
    { }

    public ComponentNotFoundException(string message, Exception innerException)
        : base(message, innerException)
    { }
}
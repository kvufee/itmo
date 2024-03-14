using System;

namespace Itmo.ObjectOrientedProgramming.Lab2.Service;

public class NullParameterException : Exception
{
    public NullParameterException()
    {
    }

    public NullParameterException(string? message)
        : base(message)
    {
    }

    public NullParameterException(string? message, Exception? innerException)
        : base(message, innerException)
    {
    }
}
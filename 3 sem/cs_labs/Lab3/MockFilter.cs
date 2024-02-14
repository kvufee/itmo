using System;
using Itmo.ObjectOrientedProgramming.Lab3.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab3.Tests;

public class MockFilter
{
    private ITarget _decoratee;

    public MockFilter(int filterlevel, ITarget decoratee)
    {
        FilterLevel = filterlevel;
        _decoratee = decoratee;
    }

    public int FilterLevel { get; }

    public bool SendMessage(Message message)
    {
        if (message == null)
        {
            throw new ArgumentNullException(nameof(message));
        }

        if (message.ImportanceLevel < FilterLevel)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public interface IMessage
{
    string? Header { get; }
    string? Body { get; }
    int ImportanceLevel { get; }
    bool IsRead { get; }
}
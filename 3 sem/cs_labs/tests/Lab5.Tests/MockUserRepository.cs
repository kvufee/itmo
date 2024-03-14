using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;

namespace Itmo.ObjectOrientedProgramming.Lab5.Tests;

public class MockUserRepository : IUserRepository
{
    public User? GetUserByLogin(string? login, string? password)
    {
        return new User(1, "bobik", "abc123", UserRole.Default);
    }
}
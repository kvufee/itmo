using Lab5.Application.Models;

namespace Lab5.DataAccess.Abstractions;

public interface IUserRepository
{
    User? GetUserByLogin(string? login, string? password);
}
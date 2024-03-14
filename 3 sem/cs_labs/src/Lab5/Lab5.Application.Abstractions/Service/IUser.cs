using Lab5.Application.Models;

namespace Lab5.Application.Abstractions.Service;

public interface IUser
{
    User? UserLogin(string? login, string? password);
}
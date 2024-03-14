using Lab5.Application.Abstractions.Service;
using Lab5.Application.Models;

namespace Lab5.Presentation.Console;

public class Login
{
    private readonly IUser _user;

    public Login(IUser user)
    {
        _user = user;
    }

    public User? Start()
    {
        System.Console.WriteLine("LOGIN\n");

        string? login = System.Console.ReadLine();
        string? password = System.Console.ReadLine();

        return _user.UserLogin(login, password);
    }
}
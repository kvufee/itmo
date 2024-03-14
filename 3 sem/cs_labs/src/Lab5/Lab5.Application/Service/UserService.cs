using Lab5.Application.Abstractions.Service;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;

namespace Lab5.Application.Service;

public class UserService : IUser
{
    private readonly IUserRepository _userRepository;

    public UserService(IUserRepository userRepository)
    {
        _userRepository = userRepository;
    }

    public User? UserLogin(string? login, string? password)
    {
        return _userRepository.GetUserByLogin(login, password);
    }
}
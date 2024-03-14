namespace Lab5.Application.Models;

public class User
{
    public User(int id, string login, string password, UserRole role)
    {
        Id = id;
        Login = login;
        Password = password;
        Role = role;
    }

    public int Id { get; }
    public string Login { get; }
    public string Password { get; }
    public UserRole Role { get; }
}
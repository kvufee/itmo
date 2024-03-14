using Itmo.Dev.Platform.Postgres.Connection;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;
using Npgsql;

namespace Lab5.DataAccess.Repositories;

public class UserRepository : IUserRepository
{
    private readonly IPostgresConnectionProvider _connectionProvider;

    public UserRepository(IPostgresConnectionProvider connectionProvider)
    {
        _connectionProvider = connectionProvider;
    }

    public NpgsqlConnection GetSqlConnection()
    {
        NpgsqlConnection sqlConnection = _connectionProvider
            .GetConnectionAsync(default)
            .AsTask()
            .GetAwaiter()
            .GetResult();

        return sqlConnection;
    }

    public User? GetUserByLogin(string? login, string? password)
    {
        const string sqlRequestForUserData =
            """
            SELECT * FROM USERS
            WHERE username = $login AND password = $password
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        if (login != null) sqlCommand.Parameters.AddWithValue("login", login);
        if (password != null) sqlCommand.Parameters.AddWithValue("password", password);
        using NpgsqlDataReader sqlReader = sqlCommand.ExecuteReader();

        while (sqlReader.Read())
        {
            return new User(
                sqlReader.GetInt32(0),
                sqlReader.GetString(1),
                sqlReader.GetString(2),
                sqlReader.GetFieldValue<UserRole>(3));
        }

        return null;
    }
}
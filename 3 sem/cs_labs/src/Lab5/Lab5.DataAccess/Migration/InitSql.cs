using FluentMigrator;
using Itmo.Dev.Platform.Postgres.Migrations;

namespace Lab5.DataAccess.Migration;

[Migration(1, "Init")]
public class InitSql : SqlMigration
{
    protected override string GetUpSql(IServiceProvider serviceProvider)
    {
        return """
               CREATE TABLE USERS
                (
                    id bigint PRIMARY KEY,
                    username text NOT NULL,
                    password text NOT NULL,
                    role user_role NOT NULL
                );

               CREATE TABLE ACCOUNTS
                (
                    id bigint PRIMARY KEY,
                    user_id int NOT NULL,
                    balance int NOT NULL
                );
                
               CREATE TABLE USER_LOGS
                (
                   id bigint PRIMARY KEY,
                   account_id int NOT NULL,
                   data text NOT NULL
                );
                
               CREATE TYPE user_role AS enum
                (
                   'Default',
                   'Admin'
                );
        """;
    }

    protected override string GetDownSql(IServiceProvider serviceProvider)
    {
        return """
                DROP TABLE USERS
                DROP TABLE ACCOUNTS
                DROP TABLE USER_LOGS

                DROP TYPE user_role
        """;
    }
}
using Lab5.Application.Abstractions.Service;
using Lab5.Application.Service;
using Microsoft.Extensions.DependencyInjection;

namespace Lab5.Application.Extensions;

public static class ServiceCollectionExtensions
{
    public static IServiceCollection AddNewApplication(this IServiceCollection service)
    {
        service.AddScoped<IAccount, AccountService>();

        return service;
    }
}
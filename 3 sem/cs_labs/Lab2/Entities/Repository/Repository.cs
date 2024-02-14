using System.Collections.Generic;
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab2;

public class Repository<T> : IRepository<T>
    where T : Component
{
    private readonly List<T> _list = new List<T>();

    public void Add(T entitiy)
    {
        _list?.Add(entitiy);
    }

    public void Delete(T entity)
    {
        _list?.Remove(entity);
    }

    public T? Find(string? name)
    {
        return _list.FirstOrDefault(x => x.Name == name);
    }
}
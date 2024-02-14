namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public interface IRepository<T>
{
    void Add(T entitiy);
    void Delete(T entity);
    T? Find(string? name);
}
using System;
using Itmo.ObjectOrientedProgramming.Lab3.Entities;
using Xunit;

namespace Itmo.ObjectOrientedProgramming.Lab3.Tests;

public class UnitTest
{
    private Message _firstMessage = new Message("Hello", "SBD Total 475kg", 2, false);
    private Message _secondMessage = new Message("Hello", "SBD Total 475kg", 2, true);

    [Fact]
    public void MessageIsUnreadSuccess()
    {
        var targetUser = new TargetUser(new User.User());
        targetUser.SendMessage(_firstMessage);

        Assert.Equal(_firstMessage.IsRead == false, targetUser.RecievedMessages[^1].IsRead == false);
    }

    [Fact]
    public void UnreadToReadSuccess()
    {
        var targetUser = new TargetUser(new User.User());
        targetUser.SendMessage(_firstMessage);
        targetUser.ChangeMessageStatusToRead();

        Assert.Equal(_firstMessage.IsRead == true, targetUser.RecievedMessages[^1].IsRead == true);
    }

    [Fact]
    public void UnreadToReadFail()
    {
        var targetUser = new TargetUser(new User.User());
        targetUser.SendMessage(_secondMessage);

        Exception ex = Assert.Throws<InvalidOperationException>(() => targetUser.ChangeMessageStatusToRead());
        Assert.Equal("Message was read", ex.Message);
    }

    [Fact]
    public void MockFilteredTargetMessageSendFail()
    {
        var targetUser = new TargetUser(new User.User());
        var mockFilter = new MockFilter(1, targetUser);

        Assert.False(mockFilter.SendMessage(_firstMessage));
    }

    [Fact]
    public void MockLoggerSuccess()
    {
        var targetUser = new TargetUser(new User.User());
        var mockLogger = new MockLogger(targetUser);
        string? log = mockLogger.SendMessage(_firstMessage);

        Assert.Equal(_firstMessage.Body, log);
    }

    [Fact]
    public void MockMessengerViberSuccess()
    {
        string? expectedOutput = "[Viber] -> Hello: SBD Total 475kg";
        string? messengerOutput = MockMessengerViber.SendMessage(_firstMessage);

        Assert.Equal(expectedOutput, messengerOutput);
    }
}
using SwinAdventure;
namespace tests;

public class IdentifierTest
{
    public IdentifiableObject id;
    public IdentifiableObject empty;

    [SetUp]
    public void Setup()
    {
        id = new IdentifiableObject(new string[] { "fred", "bob" });
        empty = new IdentifiableObject(new string[] { });
    }

    [Test]
    public void TestAreYou()
    {
        
        Assert.AreEqual(true, id.AreYou("fred"));
        Assert.AreEqual(true, id.AreYou("bob"));
    }

    [Test]
    public void TestNotAreYou()
    {
        
        Assert.AreEqual(false, id.AreYou("wilma"));
        Assert.AreEqual(false, id.AreYou("boby"));
    }

    [Test]
    public void TestCaseSensitive()
    {
        //this test doesn't make any sense. We shouldn't be testing whether
        //a lowercase word can be called with an uppercase, but the other way around.
        //either way, my code works both ways.
       
        Assert.AreEqual(true, id.AreYou("FRED"));
        Assert.AreEqual(true, id.AreYou("bOB"));
    }

    [Test]
    public void TestFirstID()
    {
       
        Assert.AreEqual("fred", id.FirstId);
    }

    [Test]
    public void TestFirstIdWithoutID()
    {
        
        Assert.AreEqual("", empty.FirstId);
    }

    [Test]
    public void TestAddID()
    {
       
        id.AddIdentifier("wilma");
        Assert.AreEqual(true, id.AreYou("fred"));
        Assert.AreEqual(true, id.AreYou("bob"));
        Assert.AreEqual(true, id.AreYou("wilma"));
       
    }
}

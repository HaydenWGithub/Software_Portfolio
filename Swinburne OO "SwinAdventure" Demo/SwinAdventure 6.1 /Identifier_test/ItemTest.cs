using System;
using SwinAdventure;

namespace tests
{
    public class ItemTest
    {
        public Item myItem;

        [SetUp]
        public void Setup()
        {
            myItem = new Item(new string[] { "Runner", "Shoe" }, "Shoe", "A pair of kicks");
        }

        [Test]
        public void TestIdentify()
        {
            Assert.AreEqual(true, myItem.AreYou("Runner"));
        }

        [Test]
        public void TestShortDesc()
        {
            
            Assert.AreEqual("A Shoe (runner)", myItem.ShortDescription);
        }

        [Test]
        public void TestFullDesc()
        {
           
            Assert.AreEqual("A pair of kicks", myItem.FullDescription);
        }

    }
}



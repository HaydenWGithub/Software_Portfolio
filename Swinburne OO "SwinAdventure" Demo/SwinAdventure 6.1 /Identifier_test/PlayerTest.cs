using System;
using SwinAdventure;

namespace tests
{
    public class PlayerTest
    {
        public Player myPlayer;
        public Inventory myInventory;
        public Item myItem;

        [SetUp]
        public void Setup()
        {
            myPlayer = new Player("Hayden", "A young handsome man");
            myInventory = new Inventory();
            myItem = new Item(new string[] { "Runner", "Shoe" }, "Shoe", "A pair of kicks");
            myPlayer.Inventory.Put(myItem);
        }

        [Test]
        public void TestIdentify()
        {
           
            Assert.AreEqual(true, myPlayer.AreYou("me"));
        }

        [Test]
        public void TestLocateItem()
        {
          
            Assert.AreEqual(myItem, myPlayer.Locate("Runner"));
        }

        [Test]
        public void TestLocateSelf()
        {
           
            Assert.AreEqual(myPlayer, myPlayer.Locate("me"));
            Assert.AreEqual(myPlayer, myPlayer.Locate("inventory"));
        }

        [Test]
        public void TestLocateNull()
        {
           
            Assert.AreEqual(null, myPlayer.Locate("Sword"));
        }

        [Test]
        public void TestFullDesc()
        {
           
           
            var output = "You are Hayden, A young handsome man. You are Carrying: " + "\n\tA Shoe (runner)\n";
            Assert.AreEqual(output, myPlayer.FullDescription);



        }
    }
}


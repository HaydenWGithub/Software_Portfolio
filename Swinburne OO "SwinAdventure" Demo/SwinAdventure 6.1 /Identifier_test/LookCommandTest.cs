using System;
using SwinAdventure;

namespace tests
{
    public class LookCommandTest
    {
        public Player myPlayer;   
        public Item Gem;
        public LookCommand Look;
        public Bag myBag;
        [SetUp]
        public void Setup()
        {
            myPlayer = new Player("Hayden", "A young handsome man");
            Gem = new Item(new string[] { "Gem", "Mineral" }, "Gem", "A precious Gem");
            myPlayer.Inventory.Put(Gem);
            Look = new LookCommand(new string[] { "eyes", "look" });
            myBag = new Bag(new string[] { "bag", "leather" }, "mainBag", "a bag cointaining some items");
        }

        [Test]
        public void LookAtMe()
        {
           
            Assert.AreEqual(myPlayer.FullDescription, Look.Execute(myPlayer, new string[] { "look", "at", "inventory"}));
        }

        [Test]
        public void LookAtGem()
        {
            
            Assert.AreEqual("A precious Gem", Look.Execute(myPlayer, new string[] { "look", "at", "Gem"}));
        }

        [Test]
        public void LookAtUnk()
        {
            myPlayer.Inventory.Take("Gem");
            Assert.AreEqual("I can't find the Gem", Look.Execute(myPlayer, new string[] { "look", "at", "Gem", "in", "inventory" }));
        }

        [Test]
        public void LookAtGemInMe()
        {
            
            Assert.AreEqual("A precious Gem", Look.Execute(myPlayer, new string[] { "look", "at", "Gem", "in", "inventory" }));
        }

        [Test]
        public void LookAtGemInBag()
        {
            myPlayer.Inventory.Take("Gem");
            myBag.Inventory.Put(Gem);
            myPlayer.Inventory.Put(myBag);
            Assert.AreEqual("A precious Gem", Look.Execute(myPlayer, new string[] { "look", "at", "Gem", "in", "bag" }));
        }

        [Test]
        public void LookAtGemInNoBag()
        {
            myPlayer.Inventory.Take("Gem");
            myBag.Inventory.Put(Gem);
            Assert.AreEqual("I can't find the bag", Look.Execute(myPlayer, new string[] { "look", "at", "Gem", "in", "bag" }));
        }

        [Test]
        public void LookAtNoGemInBag()
        {
            myPlayer.Inventory.Take("Gem");
            myPlayer.Inventory.Put(myBag);            
            Assert.AreEqual("I can't find the Gem", Look.Execute(myPlayer, new string[] { "look", "at", "Gem", "in", "bag" }));
        }

        [Test]
        public void InvalidLook()
        {
            Assert.AreEqual("Invalid Look!", Look.Execute(myPlayer, new string[] { "look", "around"}));
            Assert.AreEqual("Invalid Look!", Look.Execute(myPlayer, new string[] { "Hello"}));
            Assert.AreEqual("Invalid Look!", Look.Execute(myPlayer, new string[] { "look", "at", "a", "at", "b" }));
        }
    }
}


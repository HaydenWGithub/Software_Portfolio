using System;
using SwinAdventure;

namespace tests
{
    public class InventoryTest
    {
        public Inventory myInventory;
        public Item myItem;

        [SetUp]
        public void Setup()
        {
            myItem = new Item(new string[] { "Runner", "Shoe" }, "Shoe", "A pair of kicks");
            myInventory = new Inventory();
            myInventory.Put(myItem);
        }

        [Test]
        public void TestFindItem()
        {
            
            Assert.AreEqual(true, myInventory.HasItem("Runner"));
        }

        [Test]
        public void TestNoItem()
        {
           
            Assert.AreEqual(false, myInventory.HasItem("banana"));
        }

        [Test]
        public void TestFetchItem()
        {
           
            Assert.AreEqual(myItem, myInventory.Fetch("Runner"));
            Assert.AreEqual(true, myInventory.HasItem("Runner"));
        }

        [Test]
        public void TestTakeItem()
        {
           
            Assert.AreEqual(myItem, myInventory.Take("Runner"));
            Assert.AreEqual(false, myInventory.HasItem("Runner"));
        }

        [Test]
        public void TestItemList()
        {
            
            Item myItem2 = new Item(new string[] { "Soda", "drink" }, "drink", "A refreshing carbonated beverage");
            myInventory.Put(myItem2);
            var output = "You are Carrying: \n" + "\t" + "A Shoe (runner)" + "\n" + "\t" + "A drink (soda)" + "\n";
            Assert.AreEqual(output, myInventory.ItemList);

        }
    }
}


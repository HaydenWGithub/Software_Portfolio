using System;
using SwinAdventure;

namespace tests
{
    public class BagTest
    {
        public Bag myBag;
        public Item myItem;
        public Bag myBag2;
        public Item myItem2;


        [SetUp]
        public void Setup()
        {
            myBag = new Bag(new string[] { "bag", "leather" }, "mainBag", "a bag cointaining some items");
            myItem = new Item(new string[] { "Runner", "Shoe" }, "Shoe", "A pair of kicks");
            myBag.Inventory.Put(myItem);
            myBag2 = new Bag(new string[] { "bag2", "leather" }, "mainBag2", "a bag cointaining some items");
            myItem2 = new Item(new string[] { "Runner2", "Shoe" }, "Shoe2", "A pair of kicks");
            
        }

        [Test]
        public void TestBagLocate()
        {
           
            Assert.AreEqual(myItem, myBag.Locate("Runner"));
        }

        [Test]
        public void TestBagLocateSelf()
        {
           
            Assert.AreEqual(myBag, myBag.Locate("bag"));
        }

        [Test]
        public void TestBagLocateNull()
        {
            
            Assert.AreEqual(null, myBag.Locate("pencil"));
        }

        [Test]
        public void TestBagFullDesc()
        {
            var output = "in the mainBag you can see: \n \tYou are Carrying: \n\tA Shoe (runner)\n";
            Assert.AreEqual(output, myBag.FullDescription);
            
        }

        [Test]
        public void TestBagInBag()
        {

            myBag.Inventory.Put(myBag2);
            Assert.AreEqual(myBag2, myBag.Locate("bag2"));
            Assert.AreEqual(myItem, myBag.Locate("Runner"));
            Assert.AreEqual(null, myBag.Locate("runner2"));

        }
    }
}


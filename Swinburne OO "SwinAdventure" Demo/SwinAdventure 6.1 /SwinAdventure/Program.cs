using System;

namespace SwinAdventure
{
    public class MainClass
    {
        

        public static void Main(string[] args)
        {
            Console.WriteLine("Enter your name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Enter your description: ");
            string desc = Console.ReadLine();
            Player myPlayer = new Player(name, desc);
            Item myShoe= new Item(new string[] { "Runner", "Shoe" }, "Shoe", "A pair of kicks");
            Item myKey = new Item(new string[] { "key", "lockKey" }, "Key", "A shiny red key");
            Item mySword = new Item(new string[] { "Sword", "weapon" }, "Sword", "A gleaming silver sword");
            Bag myBag = new Bag(new string[] { "bag", "leather" }, "mainBag", "a bag cointaining some items");
            myBag.Inventory.Put(mySword);
            myPlayer.Inventory.Put(myShoe);
            myPlayer.Inventory.Put(myKey);
            myPlayer.Inventory.Put(myBag);
            LookCommand Look = new LookCommand(new string[] { "eyes", "look" });
            while (true)
            {
                Console.WriteLine("Enter a Look-Command to view your surroundings: ");
                string input = Console.ReadLine();
                Console.WriteLine("...");
                string[] words = input.Split(" ");
                Console.WriteLine(Look.Execute(myPlayer, words));
                Console.WriteLine("...");
            }
        }
    }
}


using System;
namespace SwinAdventure
{
    public class Player : GameObject, IHaveInventory
    {
        private Inventory _inventory = new Inventory();
        private string _description;
        
        public Player(string name, string desc) : base(new string[] { "me", "inventory" }, name, desc)
        {
            // need to still put the description variable here since the full description for the player
            // is the same as a short description for other objects.
            _description = desc;
        }

        public GameObject Locate(string id)
        {
            if (AreYou(id))
            {
                return this;
            }
            else
            {
                return _inventory.Fetch(id);
            }
        }

        public override string FullDescription
        {
            get
            {
                return "You are " + Name + ", " + _description + ". " + _inventory.ItemList;
            }
        }

        public override string ShortDescription
        {
            get
            {
                return _description;
            }
        }

        public Inventory Inventory
        {
            get
            {
                return _inventory;
            }
        }
    }
}


using System;
namespace SwinAdventure
{
    public class Inventory
    {
        private List<Item> _items;

        public Inventory()
        {
            _items = new List<Item>();
        }

        public bool HasItem(string id)
        {
            var output = false;
            foreach (Item item in _items)
            {
                if (item.AreYou(id) == true)
                {
                    output = true;
                }
            }
            return output;
     
        }

        public void Put(Item itm)
        {
            _items.Add(itm);

        }

        public Item Take(string id)
        {
            foreach (Item item in _items)
            {
                 if (item.AreYou(id) == true)
                {
                    var output = item;
                    _items.Remove(item);
                    return output;
                }
            }
            return null;
            
            

        }

        public Item Fetch(string id)
        {
            foreach (Item item in _items)
            {
                if (item.AreYou(id) == true)
                {
                    var output = item;
                    return output;
                }
            }
            return null;

        }

        public string ItemList
        {
            get
            {
                string output = "You are Carrying: \n";
                foreach (Item item in _items)
                {
                    output = output + "\t" + item.ShortDescription + "\n";
                }
                return output;
             
            }
        }
    }
}


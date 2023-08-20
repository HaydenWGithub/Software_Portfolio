using System;
namespace SwinAdventure
{
    public class LookCommand : Command
    {
        public LookCommand(string[] ids) : base(ids)
        {
            

        }

        public override string Execute(Player p, string[] text)
        {
            IHaveInventory container = p;
            if (text.Length == 3 && text[0].ToLower() == "look" && text[1].ToLower() == "at" || text.Length == 5 && text[0].ToLower() == "look" && text[1].ToLower() == "at" && text[3].ToLower() == "in")
            {
                if (text.Length == 5)
                {
                    container = FetchContainer(p, text[4]);
                    if (container == null)
                    {
                        return "I can't find the " + text[4];
                    }
                }
                return LookAtIn(text[2], container);               
            }
            else
            {
                return "Invalid Look!";
            }
            
        }


        public IHaveInventory FetchContainer(Player p, string containerId)
        {
            return p.Locate(containerId) as IHaveInventory;      
        }

        
        public string LookAtIn(string thingId, IHaveInventory container)
        {            
            var thing =  container.Locate(thingId);
            if (thing == null)
            {
                return "I can't find the " + thingId;
            }
            return thing.FullDescription;           
        }
    }
}


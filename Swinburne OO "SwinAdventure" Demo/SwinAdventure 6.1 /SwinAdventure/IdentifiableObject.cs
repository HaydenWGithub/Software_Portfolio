using System;
namespace SwinAdventure
{
    public class IdentifiableObject
    {
        private List<string> _identifiers = new List<string>();


        public IdentifiableObject(string[] idents)
        {
            foreach (string ident in idents)
            {
                AddIdentifier(ident);
            }
        }

        public void AddIdentifier(string id)
        {
            _identifiers.Add(id.ToLower());
        }

        public bool AreYou(string id)
        {
            var output = false;
            foreach (string ident in _identifiers)
            {
                if (ident == id.ToLower())
                {
                    output = true;
                }
            }
            return output;
        }

        public string FirstId
        {
            get
            {
                if ( _identifiers.Count == 0)
                {
                    return "";
                }
                else
                {
                    return _identifiers[0];
                }
            }
        }

       

    }

}


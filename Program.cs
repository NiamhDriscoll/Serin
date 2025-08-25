using System;
using System.Diagnostics;
using System.IO;
namespace serin
{
    class Program
    {
        static void Main(string[] args)
        {
            new Serin();
            Serin varible = new Serin();
            
            varible.type = "string";
            varible.data = "Hello, World!";
            varible.Send();
        }

    }
    public class Serin
    {
        public string type;
        public string target1 = "data.txt";
        public string target2 = "type.txt";
        public string data;
        public int VaribleType(string type)
        {
            if (type == "string")
            {
                type = "string";
                return 0;


            }
            else if (type == "int")
            {
                type = "int";
                return 0;

            }
            else if (type == "float")
            {
                type = "float";
                return 0;
            }
            else
            {
                Console.WriteLine("Invalid type specified.");
                return -1;
            }
        }

        public void Data(string stuff)
        {
            string data = stuff;
        }
        public void Send()
        {

            File.Delete(target1);
            File.Delete(target2);
            File.WriteAllText(target1, data);
            File.WriteAllText(target2, type);
            Process.Start("reader.exe");


        }







    }
}
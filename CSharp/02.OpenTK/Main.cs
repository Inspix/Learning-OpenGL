using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenTK.Utils;
using OpenTK;

namespace _02.OpenTK
{
    class MainClass
    {
        [STAThread]
        static void Main(string[] args)
        {
            new Game(640, 480).Run();
        }
    }
}

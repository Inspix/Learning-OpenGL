using OpenTK;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenTKShaders.Utils
{
    public static class Interpolation
    {
        public static Vector2 Lerp(Vector2 start, Vector2 destination, float amount)
        {
            return (start + amount * (destination - start));
        }

        public static float Lerp(float start, float destination, float amount)
        {
            float result = (start + amount * (destination - start));
            if (Math.Abs(result - destination) < float.Epsilon)
            {
                return destination;
            }
            return result;
        }
    }
}

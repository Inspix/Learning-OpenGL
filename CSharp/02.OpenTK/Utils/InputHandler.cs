using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenTK.Input;
using OpenTK;

namespace OpenTKShaders.Utils
{
    public static class InputHandler
    {
        private static MouseState currentState;
        private static MouseState prevState;
        private static Vector2 delta;
        private static Vector2 mousePos;
        public static float WheelDelta { get; private set; }
        public static bool MouseLeft { get; private set; }
        public static bool MouseMiddle { get; private set; }
        public static bool MouseRight { get; private set; }

        public static Vector2 Delta {
            get
            {                
                return delta;
            }
            private set
            {
                delta = value;
            }
        }
        public static Vector2 MousePos
        {
            get { return mousePos; }
        }

        public static void UpdateMouse()
        {
            currentState = Mouse.GetState();            
            delta.X = currentState.X - prevState.X;
            delta.Y = currentState.Y - prevState.Y;
            WheelDelta = MathHelper.Clamp(currentState.WheelPrecise - prevState.WheelPrecise,-1,1);
            mousePos.X = currentState.X;
            mousePos.Y = currentState.Y;
            MouseLeft = currentState.LeftButton == ButtonState.Pressed;
            MouseMiddle = currentState.MiddleButton == ButtonState.Pressed;
            MouseRight = currentState.RightButton == ButtonState.Pressed;
            prevState = currentState;

        }
    }
}

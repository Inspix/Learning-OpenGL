using System;
using System.Drawing;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;

namespace OpenTKShaders
{
    public class Game : GameWindow
    {        
        //public Matrix4 Projection { get; set; }
        //public Matrix4 Model { get; set; }
        //public Matrix4 View { get; set; }
        private Program program;

        public Game(int width,int height) : base(width,height)
        {
            this.RenderFrame += Render;
            this.UpdateFrame += Update;
            base.Load += Init;
        }

        public void Init(object sender,EventArgs e)
        {
            GL.Enable(EnableCap.DepthTest);
            GL.Enable(EnableCap.Blend);
            GL.DepthFunc(DepthFunction.Less);
            GL.BlendFunc(BlendingFactorSrc.SrcAlpha, BlendingFactorDest.OneMinusSrcAlpha);
            SetBackgroundColor = Color.CornflowerBlue;
            program = new Program("Shader/basic");

        }



        public void Render(object sender, FrameEventArgs e)
        {
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            this.SwapBuffers();
        }

        public void Update(object sender, FrameEventArgs e)
        {

        }

        public Color SetBackgroundColor 
        {
            set { GL.ClearColor(value); }
        }
    }
}

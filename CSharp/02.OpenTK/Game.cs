using System;
using System.Drawing;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using OpenTKShaders.Graphics;
using OpenTKShaders.Utils;
using OpenTK.Input;

namespace OpenTKShaders
{
    public class Game : GameWindow
    {
        //public Matrix4 Projection { get; set; }
        //public Matrix4 Model { get; set; }
        //public Matrix4 View { get; set; }

        private ShaderProgram program;
        private float scale;
        private float destinationScale;
        private Vector2 offset;
        private bool moving;
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
            this.SetBackgroundColor = Color.CornflowerBlue;
            this.program = new ShaderProgram("Shader/basic");
            this.scale = 1f;
            this.offset = new Vector2(-0.5f, 0);
            this.destinationScale = this.scale;
            this.program.Enable();
            GL.Uniform2(program.GetUniformLocation("uSize"), new Vector2(this.Width, this.Height));
            GL.Uniform1(program.GetUniformLocation("scale"),scale);
            GL.Uniform2(program.GetUniformLocation("offset"), offset);

        }

        public void Render(object sender, FrameEventArgs e)
        {
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.Begin(PrimitiveType.TriangleStrip);
            GL.Vertex2(-1, -1);
            GL.Vertex2(1, -1);
            GL.Vertex2(-1, 1);
            GL.Vertex2(1, 1);
            GL.End();
            this.SwapBuffers();
        }

        public void Update(object sender, FrameEventArgs e)
        {
            InputHandler.UpdateMouse();
            moving = InputHandler.MouseLeft;
            if (moving)
            {
                offset += new Vector2(-InputHandler.Delta.X * (scale / this.Width*2), InputHandler.Delta.Y * (scale / this.Height*2));
                GL.Uniform2(program.GetUniformLocation("offset"), offset);
            }
            float delta = InputHandler.WheelDelta;
            if (delta != 0)
            {
                if (delta > 0)
                {
                    destinationScale = scale * Math.Abs(delta * 0.800f);
                }
                else
                {
                    destinationScale = scale / Math.Abs(delta * 0.800f);
                }
            }
            scale = Interpolation.Lerp(scale, destinationScale, 0.1f);
            GL.Uniform1(program.GetUniformLocation("scale"), scale);

        }

        public Color SetBackgroundColor 
        {
            set { GL.ClearColor(value); }
        }
    }
}

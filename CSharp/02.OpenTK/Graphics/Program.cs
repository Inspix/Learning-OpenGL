using _02.OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using System;

namespace OpenTK.Graphics
{
    public class Program
    {
        private Shader vShader;
        private Shader fShader;
        
        public int ID { get; private set; }

        public Program(string path,bool keepshaders = false)
        {
            this.CreateProgram(path, path,keepshaders);
        }

        public Program(string vspath,string fspath, bool keepshaders = false)
        {
            this.CreateProgram(vspath,fspath,keepshaders);
        }

        private void CreateProgram(string vs, string fs,bool keepShaders)
        {
            vShader = new Shader(vs, ShaderType.VertexShader);
            fShader = new Shader(fs, ShaderType.FragmentShader);

            this.ID = GL.CreateProgram();
            GL.AttachShader(this.ID, vShader.ID);
            GL.AttachShader(this.ID, fShader.ID);
            GL.LinkProgram(this.ID);

            int programStatus = 0;

            GL.GetProgram(this.ID, GetProgramParameterName.LinkStatus, out programStatus);
            if (programStatus == (int)All.False)
            {
                string status = GL.GetProgramInfoLog(this.ID);
                Console.WriteLine("The program failed to compile.\n" + status);
                GL.DeleteProgram(this.ID);
                GL.DeleteShader(vShader.ID);
                GL.DeleteShader(fShader.ID);
                return;
            }
            GL.DetachShader(this.ID, vShader.ID);
            GL.DetachShader(this.ID, fShader.ID);
            if (!keepShaders)
            {
                GL.DeleteShader(this.vShader.ID);
                GL.DeleteShader(this.fShader.ID);
            }
            Console.WriteLine("Program succesfully linked.");
        }

        public void Enable()
        {
            GL.UseProgram(this.ID);
        }

        public void Disable()
        {
            GL.UseProgram(0);
        }
    }
}

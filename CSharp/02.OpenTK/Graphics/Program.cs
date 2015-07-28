using System;
using System.Collections.Generic;
using OpenTK.Graphics.OpenGL;

namespace OpenTKShaders.Graphics
{
    public class ShaderProgram : IDisposable
    {
        private Shader vShader;
        private Shader fShader;

        private Dictionary<string, int> uniformLocations;
        private Dictionary<string, int> attribLocations;

        public int ID { get; private set; }

        public ShaderProgram(string path,bool keepshaders = false) : this(path,path,keepshaders)
        {
        }

        public ShaderProgram(string vspath,string fspath, bool keepshaders = false)
        {
            this.uniformLocations = new Dictionary<string, int>();
            this.attribLocations = new Dictionary<string, int>();
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
                Console.WriteLine("The program failed to link.\n" + status);
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

        public int GetUniformLocation(string name)
        {
            if (uniformLocations.ContainsKey(name))
            {
                return uniformLocations[name];
            }
            int loc = GL.GetUniformLocation(this.ID, name);
            if (loc == -1)
            {
                Console.WriteLine("Error getting the uniform location of '{0}', errorCode: '{1}'",name,loc);
                return -1;
            }
            uniformLocations[name] = loc;
            return loc;
        }

        public int GetAttribLocation(string name)
        {
            if (attribLocations.ContainsKey(name))
            {
                return attribLocations[name];
            }
            int loc = GL.GetAttribLocation(this.ID, name);
            if (loc == (int)All.InvalidValue || loc == (int)All.InvalidValue)
            {
                Console.WriteLine("Error getting the attribute location of '{0}', errorCode: '{1}'", name, loc);
                return -1;
            }
            attribLocations[name] = loc;
            return loc;
        }

        public void Enable()
        {
            GL.UseProgram(this.ID);
        }

        public void Disable()
        {
            GL.UseProgram(0);
        }

        public void Dispose()
        {
            GL.DeleteProgram(this.ID);
        }
    }
}

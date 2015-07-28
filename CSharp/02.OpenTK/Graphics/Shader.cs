using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using System.IO;
using OpenTKShaders.Utils;

namespace OpenTKShaders.Graphics
{

    public class Shader : IDisposable
    {
        private readonly string path;
        private readonly ShaderType type;

        public Shader(string path, ShaderType type)
        {
            this.path = path;
            this.type = type;
            this.CreateShader();
        }

        public int ID { get; private set; }

        private void CreateShader()
        {
            this.ID = GL.CreateShader(this.type);
            string shaderSource = String.Empty;
            try
            {
                shaderSource = FileUtils.ReadShader(this.path, this.type);
            }
            catch (FileNotFoundException e)
            {
                Console.WriteLine(e.Message);
            }

            GL.ShaderSource(this.ID, shaderSource);
            GL.CompileShader(this.ID);

            int compileStatus = 0;
            GL.GetShader(this.ID, ShaderParameter.CompileStatus, out compileStatus);
            
            if (compileStatus == (int)All.False)
            {

                string status = GL.GetShaderInfoLog(this.ID);
                Console.WriteLine("Shader '{0}' compilation failed:\n{1}",this.path, status);
                GL.DeleteShader(this.ID);
                this.ID = -1;
            }
        }

        public void Dispose()
        {
            GL.DeleteShader(this.ID);
        }

    }
}

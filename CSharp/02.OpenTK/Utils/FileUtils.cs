using System.IO;
using OpenTK.Graphics.OpenGL;

namespace OpenTKShaders.Utils
{
    public static class FileUtils
    {
        public static void ReadShaders(string path, out string vsString, out string fsString)
        {
            vsString = File.ReadAllText(Directory.GetCurrentDirectory() + "/" + path + ".vert");
            fsString = File.ReadAllText(Directory.GetCurrentDirectory() + "/" + path + ".frag");
        }

        public static string ReadShader(string path, ShaderType type)
        {
            string extension = string.Empty;
            switch (type)
            {
                case ShaderType.FragmentShader:
                    extension = ".frag";
                    break;
                case ShaderType.VertexShader:
                    extension = ".vert";
                    break;
                case ShaderType.GeometryShader:
                    extension = ".geom";
                    break;
                case ShaderType.TessEvaluationShader:
                    extension = ".tess";
                    break;
                case ShaderType.TessControlShader:
                    extension = ".tctrl";
                    break;
                case ShaderType.ComputeShader:
                    extension = ".comp";
                    break;
            }
            string output = File.ReadAllText(Directory.GetCurrentDirectory() + "/" + path + extension);
            return output;
        }
    }
}

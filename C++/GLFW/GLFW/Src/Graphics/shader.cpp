#include <Graphics/shader.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace OpenGL {
	namespace Graphics {

		Shader::Shader(GLenum type, const std::string &filename) {
			CreateShader(type, filename);
		}

		Shader::~Shader() {
			glDeleteShader(m_shaderID);
		}

		void Shader::CreateShader(GLenum type, const std::string &filename) {
			m_shaderID = glCreateShader(type);
			std::string sourceString = ShaderSourseFromFile(filename);
			const char* source = sourceString.c_str();
			glShaderSource(m_shaderID, 1, &source, nullptr);
			glCompileShader(m_shaderID);

			GLint status = 0;
			glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint lenght = 0;
				glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &lenght);
				std::vector<GLchar> errorlog(lenght);
				glGetShaderInfoLog(m_shaderID, lenght, &lenght, &errorlog[0]);

				for (GLchar const &i : errorlog)
				{
					std::cout << i;
				}
				glDeleteShader(m_shaderID);
			}
		}

		std::string Shader::ShaderSourseFromFile(const std::string &filename) {

			std::ifstream file;

			file.open(filename.c_str(), std::ios::in | std::ios::binary);
			
			std::string output;
			std::string line;

			if (!file.is_open()) {
				std::cout << std::string("Error opening file: ") + filename << std::endl;
			}
			else {
				while (file.good()) {
					getline(file, line);
					output.append(line + "\n");
				}
			}

			file.close();

			return output;
		}
	}
}

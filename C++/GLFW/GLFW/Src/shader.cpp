#include <shader.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
namespace OpenGL {
	namespace Graphics {

		Shader::Shader(GLenum type, const std::string &filename) {
			this->CreateShader(type, filename);
		}

		Shader::~Shader() {}

		void Shader::CreateShader(GLenum type, const std::string &filename) {
			m_shaderID = glCreateShader(type);
			std::string sourceString = ShaderSourseFromFile(filename);
			const char* source = sourceString.c_str();
			glShaderSource(m_shaderID, 1, &source, nullptr);
			glCompileShader(m_shaderID);

			// TODO: Check for compilation errors and save it to m_errorLog;
			std::cout << sourceString << std::endl;
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

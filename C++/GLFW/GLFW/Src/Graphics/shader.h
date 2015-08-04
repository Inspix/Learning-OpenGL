#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <GL/glew.h>

namespace OpenGL {
	namespace Graphics {
		class Shader {

		public:
			Shader(GLenum type, const std::string &filename);
			virtual ~Shader();
			
			inline GLint ID() const { return m_shaderID; }

		private:
			void CreateShader(GLenum type, const std::string &filename);
			static std::string ShaderSourseFromFile(const std::string &filename);
			GLenum m_type;
			GLuint m_shaderID;
		};
	}
}

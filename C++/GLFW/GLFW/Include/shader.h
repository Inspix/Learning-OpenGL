#pragma once

#include <string>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace OpenGL {
namespace Graphics {
	class Shader {
	
	public:
		Shader(GLenum type, const std::string &filename);
		virtual ~Shader();
		

		inline std::string ErrorLog() const { return m_errorLog; }
		inline GLint ID() const { return m_shaderID; }
		
	private:
		void CreateShader(GLenum type, const std::string &filename);
		static std::string ShaderSourseFromFile(const std::string &filename);
		std::string m_errorLog;
		GLenum m_type;
		GLuint m_shaderID;
	};
}
}

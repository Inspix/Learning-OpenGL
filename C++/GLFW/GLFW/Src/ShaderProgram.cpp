#include <ShaderProgram.h>
#include <iostream>
#include <vector>

namespace OpenGL {
	namespace Graphics {
		ShaderProgram::ShaderProgram(Shader vert, Shader frag)
			: m_VertShader(vert), m_FragShader(frag)
		{
			CreateProgram();
		}
		
		ShaderProgram::~ShaderProgram() {
			delete &m_FragShader;
			delete &m_VertShader;
			glDeleteProgram(m_ProgramID);
		}

		void ShaderProgram::CreateProgram() {
			m_ProgramID = glCreateProgram();
			
			glAttachShader(m_ProgramID, m_VertShader.ID());
			glAttachShader(m_ProgramID, m_FragShader.ID());

			glLinkProgram(m_ProgramID);

			GLint linkStatus = 0;
			glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &linkStatus);
			if (linkStatus == GL_FALSE)
			{
				GLint lenght = 0;
				glGetProgramiv(m_ProgramID, GL_INFO_LOG_LENGTH, &lenght);
				std::vector<GLchar> infoLog(lenght);
				glGetProgramInfoLog(m_ProgramID, lenght, &lenght, &infoLog[0]);
				for (GLchar const &i: infoLog)
				{
					std::cout << i;
				}
				std::cout << std::endl;
				delete &m_VertShader;
				delete &m_FragShader;
				glDeleteProgram(m_ProgramID);
			}
		}
	}
}

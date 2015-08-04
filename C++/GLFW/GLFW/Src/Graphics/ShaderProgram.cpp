#include <Graphics/ShaderProgram.h>
#include <iostream>
#include <vector>

namespace OpenGL {
	namespace Graphics {
		ShaderProgram::ShaderProgram(Shader &vert, Shader &frag)
			: m_VertShader(vert.ID()), m_FragShader(frag.ID())
		{
			CreateProgram();
		}
		
		ShaderProgram::~ShaderProgram() {
			glDeleteProgram(m_ProgramID);
		}

		void ShaderProgram::Enable() const {
			glUseProgram(m_ProgramID);
		}
		void ShaderProgram::Disable() const {
			glUseProgram(0);
		}

		void ShaderProgram::CreateProgram() {
			m_ProgramID = glCreateProgram();
			
			glAttachShader(m_ProgramID, m_VertShader);
			glAttachShader(m_ProgramID, m_FragShader);

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
				glDeleteProgram(m_ProgramID);
			}
		}
	}
}

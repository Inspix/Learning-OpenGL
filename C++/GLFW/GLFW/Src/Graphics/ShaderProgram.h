#pragma once

#include <Graphics/Shader.h>

namespace OpenGL {
	namespace Graphics {
		class ShaderProgram {
		public:
			ShaderProgram(Shader &vert, Shader &frag);
			virtual ~ShaderProgram();

			void Enable() const;
			void Disable() const; 
			inline GLuint VertexShader() const { return m_VertShader; }
			inline GLuint FragmentShader() const { return m_FragShader; }
			inline GLuint ID() const { return m_ProgramID; }
		private:
			void CreateProgram();
			GLuint m_ProgramID;
			GLuint m_VertShader;
			GLuint m_FragShader;
		};
	}
}

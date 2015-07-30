#pragma once

#include <Shader.h>

namespace OpenGL {
	namespace Graphics {
		class ShaderProgram {
		public:
			ShaderProgram(Shader vert, Shader frag);
			virtual ~ShaderProgram();


			void Enable() const;
			void Disable() const; 
			inline Shader &VertexShader() { return m_VertShader; }
			inline Shader &FragmentShader() { return m_FragShader; }
			inline GLuint ID() const { return m_ProgramID; }
		private:
			void CreateProgram();
			GLuint m_ProgramID;
			Shader m_VertShader;
			Shader m_FragShader;
		};
	}
}

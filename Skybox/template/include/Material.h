#ifndef MATERIAL_H_DEFINED
#define MATERIAL_H_DEFINED
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <queue>
#include <vector>
#include <map>
#include <iostream>
#include <filesystem>

struct Material {
	// Shader program
	GLuint m_program;
	GLuint m_programMesh;
	GLuint m_programSkybox; 

    GLuint skyboxVAO;
	GLuint skyboxVBO; 

	GLuint cubemapTexture;

	// Material parameters
	glm::vec4 m_color;
	glm::vec3 m_lightColor;
	glm::vec3 m_lightPos;

	GLint m_texture;
	GLint m_normale;


	inline void check() {
		if (m_programMesh == 0) {
			throw std::runtime_error("Shader program not initialized");
		}
		if (m_programSkybox == 0) {
			throw std::runtime_error("Shader program not initialized");
		}
		
	}

	Material(): m_program(0) {

	}
	

	virtual ~Material();

	virtual void init();

	virtual void clear();

	void bind(int index);

	virtual void internalBind(int index);

	void setMatrices(glm::mat4& projectionMatrix, glm::mat4& viewMatrix, glm::mat4& modelMatrix);

	GLint getAttribute(const std::string& in_attributeName);

	GLint getUniform(const std::string& in_uniformName);
};

#endif

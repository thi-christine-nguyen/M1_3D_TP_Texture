// Local includes
#include "Material.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include "Context.h"
// GLM includes
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
// OPENGL includes
#include <GL/glew.h>
#include <GL/glut.h>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <iostream>
#include <filesystem>

Material::~Material() {
	if (m_program != 0) {
		glDeleteProgram(m_program);
	}
}

void Material::init() {
	// TODO : Change shader by your
	m_program = load_shaders("shaders/unlit/vertex.glsl", "shaders/unlit/fragment.glsl");
	
	check();
	// TODO : set initial parameters
	m_color = {1.0, 1.0, 1.0, 1.0};
	m_lightColor = {1.0, 1.0, 1.0};
	m_lightPos =  {0.5, 1, 0.5};

	
	m_texture = loadTexture2DFromFilePath("./data/WaterBottle_baseColor.png"); 
	m_normale = loadNormaleFromFilePath("./data/WaterBottle_normal.png"); 

}

void Material::clear() {
	// nothing to clear
	// TODO: Add the texture or buffer you want to destroy for your material
}

void Material::bind() {
	check();
	glUseProgram(m_program);
	internalBind();
}

void Material::internalBind() {
	// bind parameters
	

	
		GLint color = getUniform("color");
		glUniform4fv(color, 1, glm::value_ptr(m_color));

		if (m_texture != -1) {
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			glUniform1i(getUniform("colorTexture"), 0);
		}

		if (m_normale != -1) {
			glActiveTexture(GL_TEXTURE0 +1);
			glBindTexture(GL_TEXTURE_2D, m_normale);
		
			glUniform1i(getUniform("normaleTexture"), 1);
		}


	glUniform3fv(getUniform("viewPos"), 1, glm::value_ptr(Context::camera.position));
	glUniform3fv(getUniform("lightPos"), 1, glm::value_ptr(m_lightPos));
	GLint light = getUniform("lightColor");
	glUniform3fv(light, 1, glm::value_ptr(m_lightColor));


	



	// TODO : Add your custom parameters here
}

void Material::setMatrices(glm::mat4& projectionMatrix, glm::mat4& viewMatrix, glm::mat4& modelMatrix)
{
	check();
	glUniformMatrix4fv(getUniform("projection"), 1, false, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(getUniform("view"), 1, false, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(getUniform("model"), 1, false, glm::value_ptr(modelMatrix));
	
}

GLint Material::getAttribute(const std::string& in_attributeName) {
	check();
	return glGetAttribLocation(m_program, in_attributeName.c_str());
}

GLint Material::getUniform(const std::string& in_uniformName) {
	check();
	return glGetUniformLocation(m_program, in_uniformName.c_str());
}



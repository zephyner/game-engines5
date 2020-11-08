#include "Particle.h"
Particle::Particle(GLuint shaderProgram_)
{
	shaderProgram = shaderProgram_;
	GenerateBuffers();

}

Particle::~Particle()
{
	OnDestroy();
}

void Particle::OnDestroy()
{
	glDeleteVertexArrays(1, &VAO);

}

void Particle::Render(Camera* camera_)
{
	//view and projection matrix
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetPrespective()));

	//model matrix
	//glUniform3f(projLoc, camera_->GetPosition().x, camera_->GetPosition().y, camera_->GetPosition().z);

	glBindVertexArray(VAO);
	glUniform3f(tintColour, 15, 0, 15);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisable(GL_PROGRAM_POINT_SIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	


	
}

void Particle::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projLoc = glGetUniformLocation(shaderProgram, "proj");
	camPosLoc = glGetUniformLocation(shaderProgram, "cameraPos");
	tintColour = glGetUniformLocation(shaderProgram, "tintColour");


}
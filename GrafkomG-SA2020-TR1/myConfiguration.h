#pragma once
class myConfiguration {
public:
	bool mouseDown = false;
	bool manualLighting = false;
	bool fscreen = false;

	// Mouse controller
	float xrot = 0.0f;
	float yrot = 0.0f;
	float xdiff = 0.0f;
	float ydiff = 0.0f;

	// Lighting controller
	float mouseX, mouseY, mouseZ = 700;

	// Animation
	bool moveLeft1 = true, moveLeft2 = true, moveLeft3 = true, moveLeft4 = true, moveLeft5 = true;
	float deltaStar1 = 10.0, deltaStar2 = 10.0, deltaStar3 = 10.0, deltaStar4 = 10.0, deltaStar5 = 10.0;

	// Window controller
	float width = 1920;
	float height = 1080;
	float windowPositionX = -1;
	float windowPositionY = -1;

	// Project Controller

	GLfloat ambientLight[4] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuseLight[4] = { 0.8f, 0.8f, 0.8, 1.0f };
	GLfloat specularLight[4] = { 0, 0, 0, 1 };
	GLfloat emission[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat position[4] = { 400.0f, 100.0f, 500.0f, 0.5 };

};
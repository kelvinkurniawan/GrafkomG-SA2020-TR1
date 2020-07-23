#include <iostream>

#include <GL/freeglut.h>

#include <time.h> 
#include <cmath>

#include "loadImage.h";
#include "objectDrawer.h";
#include "colorOption.h";
#include "myConfiguration.h";

using namespace std;

myConfiguration config;
myColor color;
myObject obj;

void reshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, width / height, 5.0, 1000.0);
	glTranslatef(-25.0, -100.0, -500.0);
	glMatrixMode(GL_MODELVIEW); 
	glViewport(0, 0, (GLsizei)width, (GLsizei)width);
}

void timer(int) {
	glutTimerFunc(1000 / 30, timer, 0);
	// Car
	{
		for (int i = 0; i < 5; i++) {
			carPositionX[i] -= carSpeed[i];
			for (int j = 0; j < 5; j++) {
				float range = carPositionX[i] - carPositionX[j];
				if (carPositionZ[i] == carPositionZ[j]) {
					if (abs(range) < 50 && i != j) {
						if (carSpeed[i] == 0) {
							carSpeed[i] = carSpeed[j];
						}
						else {
							if (carPositionX[i] > -300) {
								if (carPositionZ[i] == 400) {
									carPositionZ[i] = 475;
									break;
								}
								else {
									carPositionZ[i] = 400;
									break;
								}
							}
							else {
								carSpeed[i] = carSpeed[j];
								break;
							}
						}
						// cout << "car " << i << " & car " << j << " = " << abs(range) << endl;
						// cout << "mobil " << i << " dan " << j << " mepet " << "dengan jarak " << abs(range) << endl;
					}
					if (abs(range) < 40 && abs(range) > -40 && i != j) {
						if (carSpeed[i] > 0.0) {
							carSpeed[i] -= 0.002;
						}
						else {
							break;
						}
						//carPositionX[i] -= 50;
						//carPositionX[j] += 100;
						// cout << "car " << i << " & car " << j << " = " << abs(range) << endl;
						// cout << "mobil " << i << " dan " << j << " mepet " << "dengan jarak " << abs(range) << endl;
					}
				}
			}


			if (carPositionX[i] < -415 && carPositionX[i] > -470 && redOn) {
				carSpeed[i] = 0;
			}

			if (carPositionX[i] < -415 && carPositionX[i] > -470 && greenOn) {
				carSpeed[i] = rand() % ((4 - 2) + 1) + 2;
			}

			if (carPositionX[i] < -960) {
				carPositionX[i] = 380;
				carSpeed[i] = rand() % ((4 - 2) + 1) + 2;
				carColor[i] = rand() % ((8 - 1) + 1) + 1;
			}

		}
	}

	// Sunlight
	{
		if (sunlightAutoMovement) {
			sunlightPosition += 5;

			if (sunlightPosition > 800)
				sunlightPosition = -1200;

			GLfloat sunlightMovement[4] = { sunlightPosition, 100.0f, 500.0f, 0.5 };
			glLightfv(GL_LIGHT0, GL_POSITION, sunlightMovement);
		}
	}

	// Tree Animation
	{

		if (treeAnimation < 5 && !treeAnimationLeft) {
			treeAnimation += 0.2;
		}
		else {
			treeAnimationLeft = true;
		}

		if (treeAnimation > -5 && treeAnimationLeft) {
			treeAnimation -= 0.2;
		}
		else {
			treeAnimationLeft = false;
		}
	}

	// Traffic light
	{
		if (redLight > 0) {
			redOn = true;
			yellowOn = false;
			greenOn = false;

			if (redLight > 0)
				redLight -= 10;

			if (redLight < 50)
				yellowLight = 500;
		}
		else if (yellowLight > 0) {
			redOn = false;
			yellowOn = true;
			greenOn = false;

			if (yellowLight > 0)
				yellowLight -= 10;

			if (yellowLight < 50)
				greenLight = 1000;


		}
		else if (greenLight > 0) {
			redOn = false;
			yellowOn = false;
			greenOn = true;

			if (greenLight > 0)
				greenLight -= 10;

			if (greenLight < 50)
				redLight = 1000;

		}} // Traffic Light

	// Star
	{

		{
			if (config.deltaStar1 > -500 && config.moveLeft1)
			{
				config.deltaStar1 -= 0.8;
			}
			else {
				config.moveLeft1 = false;
			}
			if (config.deltaStar1 < 1000 && !config.moveLeft1)
			{
				config.deltaStar1 += 0.8;
			}
			else {
				config.moveLeft1 = true;
			}
		}
		{
			if (config.deltaStar2 > -1000 && config.moveLeft2)
			{
				config.deltaStar2 -= 0.5;
			}
			else {
				config.moveLeft2 = false;
			}
			if (config.deltaStar2 < 900 && !config.moveLeft2)
			{
				config.deltaStar2 += 0.5;
			}
			else {
				config.moveLeft2 = true;
			}
		}
		{
			if (config.deltaStar3 > -875 && config.moveLeft3)
			{
				config.deltaStar3 -= 0.2;
			}
			else {
				config.moveLeft3 = false;
			}
			if (config.deltaStar3 < 625 && !config.moveLeft3)
			{
				config.deltaStar3 += 0.2;
			}
			else {
				config.moveLeft3 = true;
			}
		}
		{
			if (config.deltaStar4 > -1100 && config.moveLeft4)
			{
				config.deltaStar4 -= 0.3;
			}
			else {
				config.moveLeft4 = false;
			}
			if (config.deltaStar4 < 300 && !config.moveLeft4)
			{
				config.deltaStar4 += 0.3;
			}
			else {
				config.moveLeft4 = true;
			}
		}
		{
			if (config.deltaStar5 > -1400 && config.moveLeft5)
			{
				config.deltaStar5 -= 0.4;
			}
			else {
				config.moveLeft5 = false;
			}
			if (config.deltaStar5 < 100 && !config.moveLeft5)
			{
				config.deltaStar5 += 0.4;
			}
			else {
				config.moveLeft5 = true;
			}
		}
	}

	glutPostRedisplay();

}

void display() {

	if (config.manualLighting) {
		GLfloat position[] = { config.mouseX, config.mouseY, config.mouseZ, 1 };
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	obj.drawBuildingA();
	obj.drawBuildingB();
	obj.drawBuildingC();
	obj.drawBuildingD();
	obj.drawBuildingE();
	obj.drawBuildingF();
	obj.drawBuildingG();
	obj.drawBuildingH();
	obj.drawBuildingI();
	obj.drawBuildingJ();

	obj.myTree(170.0, 340);
	obj.myTree(170.0, 130);
	obj.myTree(70.0, -400);
	obj.myTree(150.0, -500);
	obj.myTree(0.0, 340);
	obj.myTree(-100.0, 340);
	obj.myTree(-200.0, 340);
	obj.myTree(-330.0, 340);
	obj.myTree(-580.0, -550);
	obj.myTree(-120.0, -50);
	obj.myTree(300.0, 580);
	obj.myTree(120.0, 575);
	obj.myTree(-90.0, 550);
	obj.myTree(-220.0, 540);
	obj.myTree(-300.0, 530);
	obj.myTree(-770.0, 550);
	obj.myTree(-670.0, 530);
	obj.myTree(-470.0, 530);

	obj.street();
	obj.anotherStreet();
	obj.trafficLight();
	obj.gasStation();
	obj.indomaretStore();
	obj.parkingArea();

	obj.carObject(carPositionX[0], carPositionZ[0], carColor[0]);
	obj.carObject(carPositionX[1], carPositionZ[1], carColor[1]);
	obj.carObject(carPositionX[2], carPositionZ[2], carColor[2]);
	obj.carObject(carPositionX[3], carPositionZ[3], carColor[3]);
	obj.carObject(carPositionX[4], carPositionZ[4], carColor[4]);

	obj.starObject(-500.0 + config.deltaStar1, 1000.0, -550.0 + config.deltaStar1, 900.0, -500.0 + config.deltaStar1, 900.0, -550.0 + config.deltaStar1, 1000.0);
	obj.starObject(-300.0 + config.deltaStar2, 1300.0, -350.0 + config.deltaStar2, 1200.0, -300.0 + config.deltaStar2, 1200.0, -350.0 + config.deltaStar2, 1300.0);
	obj.starObject(-25.0 + config.deltaStar3, 1500.0, 25.0 + config.deltaStar3, 1400.0, -25.0 + config.deltaStar3, 1400.0, 25.0 + config.deltaStar3, 1500.0);
	obj.starObject(300.0 + config.deltaStar4, 1300.0, 350.0 + config.deltaStar4, 1200.0, 300.0 + config.deltaStar4, 1200.0, 350.0 + config.deltaStar4, 1300.0);
	obj.starObject(500.0 + config.deltaStar5, 1000.0, 550.0 + config.deltaStar5, 900.0, 500.0 + config.deltaStar5, 900.0, 550.0 + config.deltaStar5, 1000.0);

	obj.tweening();

	obj.drawBuildingBase();
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glutSwapBuffers();
}

// Action Controller

void keyFun(unsigned char key, int x, int y) {
	switch (key) {
		// Right - Left
	case 'a':
		glRotatef(-5.0, 0.0, 1.0, 0.0);
		break;
	case 'd':
		glRotatef(5.0, 0.0, 1.0, 0.0);
		break;

		// Up - Down
	case 'w':
		glRotatef(-5.0, 1.0, 0.0, 0.0);
		break;
	case 's':
		glRotatef(5.0, 1.0, 0.0, 0.0);
		break;

		// Rotate - Z
	case 'q':
		glRotatef(5.0, 0.0, 0.0, 1.0);
		break;
	case 'e':
		glRotatef(-5.0, 0.0, 0.0, 1.0);
		break;

		// enable manual lighting
	case 'r':
		if (!config.manualLighting) {
			config.manualLighting = true; 
			sunlightAutoMovement = false;
			cout << "Manual Lighting enabled!" << endl;
		}
		else {
			config.manualLighting = false;
			GLfloat position[] = { 400.0f, 100.0f, 500.0f, 0.5 };
			glLightfv(GL_LIGHT0, GL_POSITION, position);
			cout << "Manual Lighting disabled!" << endl;
		}
		break;

	case 'g':
		if (!sunlightAutoMovement) {
			sunlightAutoMovement = true;
			cout << "Auto movement lighting enabled!" << endl;
		}
		else {
			GLfloat position[] = { 400.0f, 100.0f, 500.0f, 0.5 };
			glLightfv(GL_LIGHT0, GL_POSITION, position);
			sunlightAutoMovement = false;
			cout << "Auto movement lighting disabled!" << endl;
		}
		break;

	case 'f':
		if (!config.fscreen) {
			glutFullScreen();
			config.fscreen = true;
			cout << "Fullscreen enabled!" << endl;
		}
		else {
			config.fscreen = false;
			glutReshapeWindow(config.width, config.height);
			glutPositionWindow(config.windowPositionX, config.windowPositionY);
			cout << "Fullscreen disabled!" << endl;
		}
		break;

		// moving z point
	case 't':
		config.mouseZ += 100.0f;
		break;
	case 'y':
		config.mouseZ -= 100.0f;
		break;
		// Zoom In - Out
	case '1':
		glScalef(1.025, 1.025, 1.025);
		break;
	case '2':
		glScalef(0.975, 0.975, 0.975);
		break;
	}
	glutPostRedisplay();
}

void keySpecialFun(int key, int x, int y) {
	switch (key) {
		// Left
	case 100:
		glTranslatef(-5.0, 0.0, 0.0);
		break;
		// Up
	case 101:
		glTranslatef(0.0, 5.0, 0.0);
		break;
		// Right
	case 102:
		glTranslatef(5.0, 0.0, 0.0);
		break;
		// Down
	case 103:
		glTranslatef(0.0, -5.0, 0.0);
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		config.mouseDown = true;
		config.xdiff = (x + config.xrot);
		config.ydiff = (-y + config.yrot);
	}
	else {
		config.mouseDown = false;
	}
}

void mouseMotion(int x, int y) {
	if (config.mouseDown)
	{
		config.xrot = (y + config.ydiff) / 150;
		config.yrot = (x - config.xdiff) / 150;

		glutPostRedisplay();

		glRotatef(config.xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(config.yrot, 0.0f, 1.0f, 0.0f);
	}


}

void mouseWheel(int button, int dir, int x, int y) {

	if (dir > 0) {
		glScalef(1.025, 1.025, 1.025);
	}
	else {
		glScalef(0.975, 0.975, 0.975);
	}
	glutPostRedisplay();

}

void mouseMotionActive(int x, int y) {
	config.mouseX = x;
	config.mouseY = y;

	glutPostRedisplay();
}

// Inisialisasi

void myinit() {
	glClearColor(0.93, 0.86, 0.64, 1.0);
	glPointSize(5.0);
	glLineWidth(2.5);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	//gluOrtho2D(0, 500.0, -500.0, 500.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, config.ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, config.diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, config.specularLight);
	glLightfv(GL_LIGHT0, GL_EMISSION, config.emission);
	glLightfv(GL_LIGHT0, GL_POSITION, config.position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(config.width, config.height);
	glutInitWindowPosition(config.windowPositionX, config.windowPositionY);
	glutCreateWindow("TR - Grafkom Asdos");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyFun);
	glutSpecialFunc(keySpecialFun);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutTimerFunc(0, timer, 0);
	glutMouseWheelFunc(mouseWheel);
	glutPassiveMotionFunc(mouseMotionActive);

	cout << " << Hint <<" << endl << endl;
	cout << " > Press W, A, S, D to rotate the object" << endl;
	cout << " > Press arrow button to translate the object" << endl;
	cout << " > Press 1 or scroll up your mouse to increase scale" << endl;
	cout << " > Press 2 or scroll up your mouse to decrease scale" << endl;
	cout << " > Press r to enable/disable manual lighting" << endl;
	cout << " > Press g to enable/disable auto movement lighting" << endl;
	cout << " > Press t/y to adjust the depth of lighting" << endl;
	cout << " > Press left click and hold your mouse to rotate the object" << endl;
	cout << " > Press f to toggle fullscreen" << endl << endl;

	myinit();
	glutMainLoop();

	return 0;
}

#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void drawRectangle(float x, float y, float z, float dx, float dy, float dz) {
	// Belakang
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x - dx, y + dy, z - dz);
	glVertex3f(x + dx, y + dy, z - dz);
	glVertex3f(x + dx, y - dy, z - dz);
	glVertex3f(x - dx, y - dy, z - dz);
	glEnd();

	// Depan
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x - dx, y + dy, z + dz);
	glVertex3f(x + dx, y + dy, z + dz);
	glVertex3f(x + dx, y - dy, z + dz);
	glVertex3f(x - dx, y - dy, z + dz);
	glEnd();

	// Kanan
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(x + dx, y + dy, z - dz);
	glVertex3f(x + dx, y + dy, z + dz);
	glVertex3f(x + dx, y - dy, z + dz);
	glVertex3f(x + dx, y - dy, z - dz);
	glEnd();

	// Kiri
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(x - dx, y + dy, z - dz);
	glVertex3f(x - dx, y + dy, z + dz);
	glVertex3f(x - dx, y - dy, z + dz);
	glVertex3f(x - dx, y - dy, z - dz);
	glEnd();

	// Bawah
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(x + dx, y - dy, z - dz);
	glVertex3f(x - dx, y - dy, z - dz);
	glVertex3f(x - dx, y - dy, z + dz);
	glVertex3f(x + dx, y - dy, z + dz);
	glEnd();

	// Atas
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x + dx, y + dy, z - dz);
	glVertex3f(x - dx, y + dy, z - dz);
	glVertex3f(x - dx, y + dy, z + dz);
	glVertex3f(x + dx, y + dy, z + dz);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	drawRectangle(0.0, 0.0, 0.0, 100.0, 100.0, 100.0);
	glPopMatrix();

	glutSwapBuffers();
}

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

void reshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, width / height, 5.0, 1000.0);
	glTranslatef(0.0, 0.0, -500.0);
	glMatrixMode(GL_MODELVIEW);
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0, 500.0, -500.0, 500.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TR - Grafkom Asdos");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyFun);
	glutSpecialFunc(keySpecialFun);
	glutReshapeFunc(reshape);

	myinit();
	glutMainLoop();

	return 0;
}
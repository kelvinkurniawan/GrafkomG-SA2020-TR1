#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void drawBuildingBase() {
	//Depan
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 0.0, 300.0);
	glVertex3f(400.0, 0.0, 400.0);
	glVertex3f(400.0, 50.0, 400.0);
	glVertex3f(-400.0, 50.0, 300.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-600.0, 0.0, -500.0);
	glVertex3f(400.0, 0.0, -500.0);
	glVertex3f(400.0, 50.0, -500.0);
	glVertex3f(-600.0, 50.0, -500.0);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(400.0, 0.0, -500.0);
	glVertex3f(400.0, 0.0, 400.0);
	glVertex3f(400.0, 50.0, 400.0);
	glVertex3f(400.0, 50.0, -500.0);
	glEnd();

	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 0.0, 300.0);
	glVertex3f(-600.0, 0.0, -500.0);
	glVertex3f(-600.0, 50.0, -500.0);
	glVertex3f(-400.0, 50.0, 300.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 50.0, 300.0);
	glVertex3f(400.0, 50.0, 400.0);
	glVertex3f(400.0, 50.0, -500.0);
	glVertex3f(-600.0, 50.0, -500.0);
	glEnd();

	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 0.0, 300.0);
	glVertex3f(400.0, 0.0, 400.0);
	glVertex3f(400.0, 0.0, -500.0);
	glVertex3f(-600.0, 0.0, -500.0);
	glEnd();
}

void drawBuildingA() {
	glColor3f(1.0, 0.2, 0.2);
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(375.0, 55.0, 350.0); //E
	glVertex3f(375.0, 55.0, 100.0); //G
	glVertex3f(200.0, 55.0, 100.0); //H
	glVertex3f(200.0, 55.0, 325.0); //F
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(375.0, 55.0, 350.0); //E
	glVertex3f(200.0, 55.0, 325.0); //F
	glVertex3f(200.0, 80.0, 325.0); //F-up
	glVertex3f(375.0, 80.0, 350.0); //E-up
	glEnd();

	glColor3f(1, 1, 1);
	//depan-atas
	glBegin(GL_POLYGON);
	glVertex3f(375.0, 80.0, 350.0);
	glVertex3f(200.0, 80.0, 325.0);
	glVertex3f(200.0, 100.0, 325.0);
	glVertex3f(375.0, 100.0, 350.0);
	glEnd();

	glColor3f(1.0, 0.5, 0.7);
	//atapdepan
	glBegin(GL_TRIANGLES);
	glVertex3f(200.0, 100.0, 325.0); //kiri
	glVertex3f(375.0, 100.0, 350.0); //kanan
	glVertex3f(287.5, 120.0, 340.0); //atas
	glEnd();

	glColor3f(1, 1, 1);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(375.0, 55.0, 350.0); //E
	glVertex3f(375.0, 55.0, 100.0); //G
	glVertex3f(375.0, 100.0, 100.0); //G-up
	glVertex3f(375.0, 100.0, 350.0); //E-up
	glEnd();

	glColor3f(1, 1, 1);
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(200.0, 55.0, 100.0); //H
	glVertex3f(200.0, 55.0, 325.0); //F
	glVertex3f(200.0, 100.0, 325.0); //F-up
	glVertex3f(200.0, 100.0, 100.0); //H-up
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(375.0, 55.0, 100.0); //G
	glVertex3f(200.0, 55.0, 100.0); //H
	glVertex3f(200.0, 100.0, 100.0); //H-up
	glVertex3f(375.0, 100.0, 100.0); //G-up
	glEnd();

	glColor3f(1.0, 0.5, 0.7);
	//atapbelakang
	glBegin(GL_TRIANGLES);
	glVertex3f(200.0, 100.0, 100.0); //kiri
	glVertex3f(375.0, 100.0, 100.0); //kanan
	glVertex3f(287.5, 120.0, 100.0); //atas
	glEnd();

	glColor3f(0.3, 0.0, 0.0);
	//atapkanan
	glBegin(GL_POLYGON);
	glVertex3f(287.5, 120.0, 340.0); //tengah-depan-atas
	glVertex3f(375.0, 100.0, 350.0); //kanan-depan-bawah
	glVertex3f(375.0, 100.0, 100.0); //kanan-blkg-bawah
	glVertex3f(287.5, 120.0, 100.0); // tengah-blkg atas
	glEnd();

	glColor3f(0.3, 0.0, 0.0);
	//atapkiri
	glBegin(GL_POLYGON);
	glVertex3f(287.5, 120.0, 340.0); //tengah-depan-atas
	glVertex3f(200.0, 100.0, 325.0); //kiri-depan-bawah
	glVertex3f(200.0, 100.0, 100.0); //kiri-blkg-bawah
	glVertex3f(287.5, 120.0, 100.0); // tengah-blkg atas
	glEnd();

	glColor3f(1.0, 0.5, 0.0);
	//pilar
	glBegin(GL_POLYGON);
	glVertex3f(370.0, 55.0, 349.5);
	glVertex3f(365.0, 55.0, 349.0);
	glVertex3f(365.0, 80.0, 349.0);
	glVertex3f(370.0, 80.0, 349.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(340.0, 55.0, 345.0);
	glVertex3f(335.0, 55.0, 344.5);
	glVertex3f(335.0, 80.0, 344.5);
	glVertex3f(340.0, 80.0, 345.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(310.0, 55.0, 341.0);
	glVertex3f(305.0, 55.0, 340.5);
	glVertex3f(305.0, 80.0, 340.5);
	glVertex3f(310.0, 80.0, 341.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(270.0, 55.0, 335.0);
	glVertex3f(265.0, 55.0, 334.5);
	glVertex3f(265.0, 80.0, 334.5);
	glVertex3f(270.0, 80.0, 335.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(240.0, 55.0, 331.0);
	glVertex3f(235.0, 55.0, 330.5);
	glVertex3f(235.0, 80.0, 330.5);
	glVertex3f(240.0, 80.0, 331.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(210.0, 55.0, 326.5);
	glVertex3f(205.0, 55.0, 326.0);
	glVertex3f(205.0, 80.0, 326.0);
	glVertex3f(210.0, 80.0, 326.5);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	//detail depan
	glBegin(GL_POLYGON);
	glVertex3f(310.0, 55.0, 341.0);
	glVertex3f(270.0, 55.0, 335.0);
	glVertex3f(270.0, 80.0, 335.0);
	glVertex3f(310.0, 80.0, 341.0);
	glEnd();

	glColor4f(0.4, 0.4, 0.4, 0.5);
	//kaca depan
	glBegin(GL_POLYGON);
	glVertex3f(211.5, 75.0, 326.5);
	glVertex3f(232.5, 75.0, 331.0);
	glVertex3f(232.5, 70.0, 331.0);
	glVertex3f(211.5, 70.0, 326.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(242.5, 75.0, 331.0);
	glVertex3f(262.5, 75.0, 334.5);
	glVertex3f(262.5, 70.0, 334.5);
	glVertex3f(242.5, 70.0, 331.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(270.5, 75.0, 335.0);
	glVertex3f(302.0, 75.0, 340.5);
	glVertex3f(302.0, 70.0, 340.5);
	glVertex3f(270.5, 70.0, 335.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(312.25, 75.0, 341.0);
	glVertex3f(332.5, 75.0, 344.5);
	glVertex3f(332.5, 70.0, 344.5);
	glVertex3f(312.25, 70.0, 341.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(340.75, 75.0, 345.0);
	glVertex3f(362.5, 75.0, 349.0);
	glVertex3f(362.5, 70.0, 349.0);
	glVertex3f(340.75, 70.0, 345.0);
	glEnd();
}


void drawBuildingD() {
	glColor3f(1.0, 0.0, 0.0);
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 55.0, 275.0); //S
	glVertex3f(-350.0, 55.0, 265.0); //T
	glVertex3f(-400.0, 55.0, 250.0); //U
	glVertex3f(-400.0, 55.0, 200.0); //V
	glVertex3f(-250.0, 55.0, 200.0); //W
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 650.0, 275.0); //S
	glVertex3f(-350.0, 650.0, 265.0); //T
	glVertex3f(-400.0, 650.0, 250.0); //U
	glVertex3f(-400.0, 650.0, 200.0); //V
	glVertex3f(-250.0, 650.0, 200.0); //W
	glEnd();

	glColor3f(0.0, 0.4, 1.0);
	//depan1
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 55.0, 275.0); //S
	glVertex3f(-350.0, 55.0, 265.0); //T
	glVertex3f(-350.0, 650.0, 265.0); //T
	glVertex3f(-250.0, 650.0, 275.0); //S
	glEnd();

	glColor3f(0.0, 0.6, 1.0);
	//depan2
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 55.0, 265.0); //T
	glVertex3f(-400.0, 55.0, 250.0); //U
	glVertex3f(-400.0, 650.0, 250.0); //U
	glVertex3f(-350.0, 650.0, 265.0); //T
	glEnd();

	glColor3f(0.0, 0.4, 1.0);
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 55.0, 250.0); //U
	glVertex3f(-400.0, 55.0, 200.0); //V
	glVertex3f(-400.0, 650.0, 200.0); //V
	glVertex3f(-400.0, 650.0, 250.0); //U
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 55.0, 200.0); //V
	glVertex3f(-250.0, 55.0, 200.0); //W
	glVertex3f(-250.0, 650.0, 200.0); //W
	glVertex3f(-400.0, 650.0, 200.0); //V
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 55.0, 200.0); //W
	glVertex3f(-250.0, 55.0, 275.0); //S
	glVertex3f(-250.0, 650.0, 275.0); //S
	glVertex3f(-250.0, 650.0, 200.0); //W
	glEnd();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	drawBuildingA();
	drawBuildingD();
	glColor3f(0.0,0.5, 0.0);
	drawBuildingBase();
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
	glTranslatef(-25.0, -100.0, -500.0);
	glMatrixMode(GL_MODELVIEW);
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(2.0);
	glLineWidth(2.5);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
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
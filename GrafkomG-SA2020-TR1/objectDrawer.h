#pragma once

#include "colorOption.h";
#include "myConfiguration.h";

#define deltat .001

float treeAnimation = 0;
float treeAnimationLeft = true;

bool sunlightAutoMovement = false;
float sunlightPosition = 0;

bool redOn = true;
bool yellowOn = false;
bool greenOn = false;

float redLight = 1000, yellowLight = 0, greenLight = 0;

float carSpeed[5] = { 3, 3, 3, 3, 3 };
float carPositionX[5] = { 0, 300, 600, 600, 1200 };
float carPositionZ[5] = { 400, 475, 400, 475, 400 };
float carColor[5] = { 1 , 1 , 3, 4, 4 };
float deltaCar[5] = { 0,0,0,0,0 };

class myObject {

public:
	myColor color;
	myConfiguration config;

	void drawBuildingBase() {
		glColor3ubv(color.groundAccent);
		//Depan
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 50.0, 600.0);
		glVertex3f(-900.0, 50.0, 600.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-825.0, 0.0, -800.0);
		glVertex3f(400.0, 0.0, -800.0);
		glVertex3f(400.0, 50.0, -800.0);
		glVertex3f(-825.0, 50.0, -800.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(400.0, 0.0, -800.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 50.0, 600.0);
		glVertex3f(400.0, 50.0, -800.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(-1125.0, 0.0, -800.0);
		glVertex3f(-1125.0, 50.0, -800.0);
		glVertex3f(-900.0, 50.0, 600.0);
		glEnd();

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, -800.0);
		glVertex3f(-1125.0, 0.0, -800.0);
		glEnd();

		//atas
		glBegin(GL_POLYGON);
		glColor3ubv(color.ground);
		glVertex3f(-900.0, 50.0, 600.0);
		glColor3ubv(color.darkground);
		glVertex3f(400.0, 50.0, 600.0);
		glColor3ubv(color.ground);
		glVertex3f(400.0, 50.0, -800.0);
		glColor3ubv(color.darkground);
		glVertex3f(-1125.0, 50.0, -800.0);
		glEnd();

	}

	void drawBuildingA() {
		glColor3fv(color.black);
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 350.0); //E
		glVertex3f(375.0, 55.0, 100.0); //G
		glVertex3f(200.0, 55.0, 100.0); //H
		glVertex3f(200.0, 55.0, 325.0); //F
		glEnd();

		glColor3fv(color.lightGrey);
		//depan bawah
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 330.0); //E
		glVertex3f(200.0, 55.0, 305.0); //F
		glVertex3f(200.0, 80.0, 305.0); //F-up
		glVertex3f(375.0, 80.0, 330.0); //E-up
		glEnd();

		glColor3fv(color.white);
		//depan-atas
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 80.0, 350.0);
		glVertex3f(200.0, 80.0, 325.0);
		glVertex3f(200.0, 100.0, 325.0);
		glVertex3f(375.0, 100.0, 350.0);
		glEnd();

		glColor3f(1.0, 0.8, 0.0);
		//atapdepan
		glBegin(GL_TRIANGLES);
		glVertex3f(200.0, 100.0, 325.0); //kiri
		glVertex3f(375.0, 100.0, 350.0); //kanan
		glVertex3f(287.5, 120.0, 340.0); //atas
		glEnd();

		glColor3f(1, 1, 1);
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 330.0); //E
		glVertex3f(375.0, 55.0, 100.0); //G
		glVertex3f(375.0, 100.0, 100.0); //G-up
		glVertex3f(375.0, 100.0, 330.0); //E-up
		glEnd();

		glColor3f(1, 1, 1);
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 55.0, 100.0); //H
		glVertex3f(200.0, 55.0, 305.0); //F
		glVertex3f(200.0, 100.0, 305.0); //F-up
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
		//pilar 1
		glBegin(GL_POLYGON);
		glVertex3f(370.0, 55.0, 346.5);
		glVertex3f(365.0, 55.0, 346.0);
		glVertex3f(365.0, 80.0, 346.0);
		glVertex3f(370.0, 80.0, 346.5);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(370.0, 55.0, 344.5);
		glVertex3f(365.0, 55.0, 344.0);
		glVertex3f(365.0, 80.0, 344.0);
		glVertex3f(370.0, 80.0, 344.5);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(365.0, 55.0, 344.0);
		glVertex3f(365.0, 55.0, 346.5);
		glVertex3f(365.0, 80.0, 346.5);
		glVertex3f(365.0, 80.0, 344.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(370.0, 55.0, 344.0);
		glVertex3f(370.0, 55.0, 346.5);
		glVertex3f(370.0, 80.0, 346.5);
		glVertex3f(370.0, 80.0, 344.0);
		glEnd();

		// pilar 2
		glBegin(GL_POLYGON);
		glVertex3f(340.0, 55.0, 343.0);
		glVertex3f(335.0, 55.0, 342.5);
		glVertex3f(335.0, 80.0, 342.5);
		glVertex3f(340.0, 80.0, 343.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(340.0, 55.0, 341.0);
		glVertex3f(335.0, 55.0, 340.5);
		glVertex3f(335.0, 80.0, 340.5);
		glVertex3f(340.0, 80.0, 341.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(335.0, 55.0, 343.0);
		glVertex3f(335.0, 55.0, 340.5);
		glVertex3f(335.0, 80.0, 340.5);
		glVertex3f(335.0, 80.0, 343.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(340.0, 55.0, 343.0);
		glVertex3f(340.0, 55.0, 340.5);
		glVertex3f(340.0, 80.0, 340.5);
		glVertex3f(340.0, 80.0, 343.0);
		glEnd();

		// pilar 3

		glBegin(GL_POLYGON);
		glVertex3f(310.0, 55.0, 339.0);
		glVertex3f(305.0, 55.0, 338.5);
		glVertex3f(305.0, 80.0, 338.5);
		glVertex3f(310.0, 80.0, 339.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(310.0, 55.0, 337.0);
		glVertex3f(305.0, 55.0, 336.5);
		glVertex3f(305.0, 80.0, 336.5);
		glVertex3f(310.0, 80.0, 337.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(305.0, 55.0, 336.5);
		glVertex3f(305.0, 55.0, 339.0);
		glVertex3f(305.0, 80.0, 339.0);
		glVertex3f(305.0, 80.0, 336.5);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(310.0, 55.0, 336.5);
		glVertex3f(310.0, 55.0, 339.0);
		glVertex3f(310.0, 80.0, 339.0);
		glVertex3f(310.0, 80.0, 336.5);
		glEnd();

		// pilar 3

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
		/*
		glBegin(GL_POLYGON);
		glVertex3f(310.0, 60.0, 341.0);
		glVertex3f(270.0, 60.0, 335.0);
		glVertex3f(270.0, 80.0, 335.0);
		glVertex3f(310.0, 80.0, 341.0);
		glEnd();*/
		//detail depan

		glColor3fv(color.white);
		//depan-atas
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 80.0, 350.0);
		glVertex3f(200.0, 80.0, 325.0);
		glVertex3f(200.0, 100.0, 325.0);
		glVertex3f(375.0, 100.0, 350.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(375.0, 80.0, 350.0);
		glVertex3f(200.0, 80.0, 325.0);
		glVertex3f(200.0, 80.0, 100.0);
		glVertex3f(375.0, 80.0, 100.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(375.0, 80.0, 100.0);
		glVertex3f(375.0, 80.0, 350.0);
		glVertex3f(375.0, 100.0, 350.0);
		glVertex3f(375.0, 100.0, 100.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(200.0, 80.0, 100.0);
		glVertex3f(200.0, 80.0, 325.0);
		glVertex3f(200.0, 100.0, 325.0);
		glVertex3f(200.0, 100.0, 100.0);
		glEnd();

		glColor4f(0.4, 0.4, 0.4, 0.5);
		//kaca depan
		glBegin(GL_POLYGON);
		glVertex3f(211.5, 75.0, 306.5);
		glVertex3f(232.5, 75.0, 311.0);
		glVertex3f(232.5, 70.0, 311.0);
		glVertex3f(211.5, 70.0, 306.5);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(242.5, 75.0, 311.0);
		glVertex3f(262.5, 75.0, 316.5);
		glVertex3f(262.5, 70.0, 316.5);
		glVertex3f(242.5, 70.0, 311.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(270.5, 75.0, 315.0);
		glVertex3f(302.0, 75.0, 320.5);
		glVertex3f(302.0, 70.0, 320.5);
		glVertex3f(270.5, 70.0, 315.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(312.25, 75.0, 321.0);
		glVertex3f(332.5, 75.0, 324.5);
		glVertex3f(332.5, 70.0, 324.5);
		glVertex3f(312.25, 70.0, 321.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(340.75, 75.0, 326.0);
		glVertex3f(362.5, 75.0, 329.0);
		glVertex3f(362.5, 70.0, 329.0);
		glVertex3f(340.75, 70.0, 326.0);
		glEnd();
	}

	void drawBuildingB() {
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 50.0); //I
		glVertex3f(150.0, 55.0, 50.0); //J
		glVertex3f(150.0, 55.0, -50.0); //K
		glVertex3f(250.0, 55.0, -50.0); //L
		glVertex3f(250.0, 55.0, -300.0); //M
		glVertex3f(375.0, 55.0, -300.0); //N
		glEnd();

		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 650.0, 50.0); //I
		glVertex3f(150.0, 650.0, 50.0); //J
		glVertex3f(150.0, 650.0, -50.0); //K
		glVertex3f(250.0, 650.0, -50.0); //L
		glVertex3f(250.0, 650.0, -300.0); //M
		glVertex3f(375.0, 650.0, -300.0); //N
		glEnd();

		glColor3fv(color.glass);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 50.0); //I
		glVertex3f(375.0, 650.0, 50.0); //I-up
		glVertex3f(150.0, 650.0, 50.0); //J-up
		glColor3ubv(color.lightglass);
		glVertex3f(150.0, 55.0, 50.0); //J
		glEnd();

		//kiri J-K
		glBegin(GL_POLYGON);
		glVertex3f(150.0, 55.0, 50.0); //J
		glVertex3f(150.0, 55.0, -50.0); //K
		glVertex3f(150.0, 650.0, -50.0); //K-up
		glVertex3f(150.0, 650.0, 50.0); //J-up
		glEnd();

		//kiri K-L
		glBegin(GL_POLYGON);
		glVertex3f(150.0, 55.0, -50.0); //K
		glVertex3f(250.0, 55.0, -50.0); //L
		glVertex3f(250.0, 650.0, -50.0); //L-up
		glVertex3f(150.0, 650.0, -50.0); //K-up
		glEnd();

		//kiri L-M
		glBegin(GL_POLYGON);
		glVertex3f(250.0, 55.0, -50.0); //L
		glVertex3f(250.0, 55.0, -300.0); //M
		glVertex3f(250.0, 650.0, -300.0); //M-up
		glVertex3f(250.0, 650.0, -50.0); //L-up
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(250.0, 55.0, -300.0); //M
		glVertex3f(375.0, 55.0, -300.0); //N
		glVertex3f(375.0, 650.0, -300.0); //N-up
		glVertex3f(250.0, 650.0, -300.0); //M-up
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, -300.0); //N
		glVertex3f(375.0, 55.0, 50.0); //I
		glVertex3f(375.0, 650.0, 50.0); //I-up
		glVertex3f(375.0, 650.0, -300.0); //N-up
		glEnd();

		//detail
		glColor4f(0.3, 0.3, 0.3, 0.3);
		glBegin(GL_POLYGON);
		glVertex3f(325.0, 55.0, 50.5); //I
		glVertex3f(315.0, 55.0, 50.5); //J
		glVertex3f(315.0, 650.0, 50.5); //J-up
		glVertex3f(325.0, 650.0, 50.5); //I-up
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(210.0, 55.0, 50.5); //I
		glVertex3f(200.0, 55.0, 50.5); //J
		glVertex3f(200.0, 650.0, 50.5); //J-up
		glVertex3f(210.0, 650.0, 50.5); //I-up
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(275.0, 55.0, 50.5); //I
		glVertex3f(250.0, 55.0, 50.5); //J
		glVertex3f(250.0, 650.0, 50.5); //J-up
		glVertex3f(275.0, 650.0, 50.5); //I-up
		glEnd();

		glColor4f(1.0, 1.0, 1.0, 0.3);
		float spacingC = 630.0;
		for (int i = 0; i < 60; i++) {
			glBegin(GL_LINE_LOOP);
			glVertex3f(375.0, spacingC, 51.0); //I
			glVertex3f(150.0, spacingC, 51.0); //J
			glVertex3f(150.0, spacingC, -50.5); //K
			glVertex3f(250.0, spacingC, -50.5); //L
			glVertex3f(250.0, spacingC, -300.5); //M
			glVertex3f(375.0, spacingC, -300.5); //N
			glEnd();
			spacingC -= 10.0;
		}

		glColor3fv(color.white);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 52.0); //I
		glVertex3f(150.0, 55.0, 52.0); //J
		glColor3fv(color.lightGrey);
		glVertex3f(150.0, 200.0, 52.0); //J-up
		glVertex3f(375.0, 200.0, 52.0); //I-up
		glEnd();

		//kanan
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(375.5, 55.0, -300.0); //N
		glVertex3f(375.5, 55.0, 50.0); //I
		glColor3fv(color.lightGrey);
		glVertex3f(375.5, 200.0, 50.0); //I-up
		glVertex3f(375.5, 200.0, -300.0); //N-up
		glEnd();

		glColor3fv(color.glass);
		float spacing = 75.0;
		float spacingB = 80.0;
		for (int i = 0; i < 6; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(376.0, spacing, -250.0); //N
			glVertex3f(376.0, spacing, 0.0); //I
			glVertex3f(376.0, spacingB, 0.0); //I-up
			glVertex3f(376.0, spacingB, -250.0); //N-up
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(360.0, spacing, 52.5); //I
			glVertex3f(350.0, spacing, 52.5); //J
			glVertex3f(350.0, spacingB, 52.5); //J-up
			glVertex3f(360.0, spacingB, 52.5); //I-up
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(320.0, spacing, 52.5); //I
			glVertex3f(310.0, spacing, 52.5); //J
			glVertex3f(310.0, spacingB, 52.5); //J-up
			glVertex3f(320.0, spacingB, 52.5); //I-up
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(267.0, spacing, 52.5); //I
			glVertex3f(257.0, spacing, 52.5); //J
			glVertex3f(257.0, spacingB, 52.5); //J-up
			glVertex3f(267.0, spacingB, 52.5); //I-up
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(214.0, spacing, 52.5); //I
			glVertex3f(204.0, spacing, 52.5); //J
			glVertex3f(204.0, spacingB, 52.5); //J-up
			glVertex3f(214.0, spacingB, 52.5); //I-up
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(174.0, spacing, 52.5); //I
			glVertex3f(164.0, spacing, 52.5); //J
			glVertex3f(164.0, spacingB, 52.5); //J-up
			glVertex3f(174.0, spacingB, 52.5); //I-up
			glEnd();

			spacing += 20;
			spacingB += 20;
		}

		glColor3fv(color.lightGrey);
		//topdetail
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 650.5, -200.0);
		glVertex3f(350.0, 650.5, -250.0);
		glVertex3f(280.0, 650.5, -250.0);
		glVertex3f(280.0, 650.5, -200.0);
		glEnd();
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 670.0, -200.0);
		glVertex3f(350.0, 670.0, -250.0);
		glVertex3f(280.0, 670.0, -250.0);
		glVertex3f(280.0, 670.0, -200.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 650.5, -200.0);
		glVertex3f(350.0, 650.5, -250.0);
		glVertex3f(350.0, 670.0, -250.0);
		glVertex3f(350.0, 670.0, -200.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(280.0, 670.0, -250.0);
		glVertex3f(280.0, 670.0, -200.0);
		glVertex3f(280.0, 650.5, -200.0);
		glVertex3f(280.0, 650.5, -250.0);
		glEnd();
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 650.5, -250.0);
		glVertex3f(280.0, 650.5, -250.0);
		glVertex3f(280.0, 670.0, -250.0);
		glVertex3f(350.0, 670.0, -250.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 650.5, -200.0);
		glVertex3f(280.0, 650.5, -200.0);
		glVertex3f(280.0, 670.0, -200.0);
		glVertex3f(350.0, 670.0, -200.0);
		glEnd();

		glColor3fv(color.lightGrey);
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(175.0, 650.5, -25.0);
		glVertex3f(175.0, 650.5, 25.0);
		glVertex3f(200.0, 650.5, 25.0);
		glVertex3f(200.0, 650.5, -25.0);
		glEnd();
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(175.0, 670.0, -25.0);
		glVertex3f(175.0, 670.0, 25.0);
		glVertex3f(200.0, 670.0, 25.0);
		glVertex3f(200.0, 670.0, -25.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(175.0, 650.5, -25.0);
		glVertex3f(175.0, 650.5, 25.0);
		glVertex3f(175.0, 670.0, 25.0);
		glVertex3f(175.0, 670.0, -25.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 650.5, 25.0);
		glVertex3f(200.0, 650.5, -25.0);
		glVertex3f(200.0, 670.0, -25.0);
		glVertex3f(200.0, 670.0, 25.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(175.0, 650.5, 25.0);
		glVertex3f(200.0, 650.5, 25.0);
		glVertex3f(200.0, 670.0, 25.0);
		glVertex3f(175.0, 670.0, 25.0);
		glEnd();
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(175.0, 650.5, -25.0);
		glVertex3f(200.0, 650.5, -25.0);
		glVertex3f(200.0, 670.0, -25.0);
		glVertex3f(175.0, 670.0, -25.0);
		glEnd();


	}

	void drawBuildingC() {
		glColor3fv(color.black);
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 55.0, 300.0); //P
		glVertex3f(125.0, 55.0, 315.0); //O
		glVertex3f(125.0, 55.0, 50.0); //R
		glVertex3f(0.0, 55.0, 35.0); //Q
		glEnd();

		//(color.white);
		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 550.0, 300.0); //P
		glVertex3f(125.0, 550.0, 315.0); //O
		glVertex3f(125.0, 550.0, 50.0); //R
		glVertex3f(0.0, 550.0, 35.0); //Q
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glColor3ubv(color.lightglass);
		glVertex3f(0.0, 55.0, 300.0); //P
		glColor3fv(color.glass);
		glVertex3f(125.0, 55.0, 315.0); //O
		glVertex3f(125.0, 550.0, 315.0); //O-up
		glVertex3f(0.0, 550.0, 300.0); //P-up
		glEnd();

		glBegin(GL_POLYGON);
		glColor3fv(color.lightGrey);
		glVertex3f(15.0, 445.0, 310.0); //P
		glVertex3f(55.0, 445.0, 315.0); //O
		glVertex3f(55.0, 505.0, 315.0); //O-up
		glVertex3f(15.0, 505.0, 310.0); //P-up
		glEnd();

		//kiri
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 55.0, 300.0); //P
		glVertex3f(0.0, 55.0, 35.0); //Q
		glVertex3f(0.0, 550.0, 35.0); //Q-up
		glVertex3f(0.0, 550.0, 300.0); //P-up
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 315.0); //O
		glVertex3f(125.0, 55.0, 50.0); //R
		glVertex3f(125.0, 550.0, 50.0); //R-up
		glVertex3f(125.0, 550.0, 315.0); //O-up
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 50.0); //R
		glVertex3f(0.0, 55.0, 35.0); //Q
		glVertex3f(0.0, 550.0, 35.0); //Q-up
		glVertex3f(125.0, 550.0, 50.0); //R-up
		glEnd();

		//detail
		glColor3fv(color.white);
		glBegin(GL_LINE_LOOP);
		glVertex3f(0.0, 520.0, 300.0); glVertex3f(125.0, 520.0, 315.0);
		glVertex3f(125.0, 520.0, 50.0); glVertex3f(0.0, 520.0, 35.0);
		glEnd();

		glColor4fv(color.line);
		float spacing = 525.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_LINE_LOOP);
			glVertex3f(0.0, spacing, 300.0); glVertex3f(125.0, spacing, 315.0);
			glVertex3f(125.0, spacing, 50.0); glVertex3f(0.0, spacing, 35.0);
			glEnd();
			spacing += 5.0;
		}

		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-1.0, 200.0, 250.0);
		glVertex3f(-1.0, 200.0, 85.0);
		glVertex3f(-1.0, 519.5, 85.0);
		glVertex3f(-1.0, 519.5, 250.0);
		glEnd();

		glColor4fv(color.line);
		float spacingA = 515.0;
		float spacingB = 510.0;
		for (int i = 0; i < 21; i++) {
			glBegin(GL_LINE_LOOP);
			glVertex3f(-1.5, spacingA, 300.0); glVertex3f(125.0, spacingA, 315.0);
			glVertex3f(125.0, spacingA, 50.0); glVertex3f(-1.5, spacingA, 35.0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(-1.5, spacingB, 300.0); glVertex3f(125.0, spacingB, 315.0);
			glVertex3f(125.0, spacingB, 50.0); glVertex3f(-1.5, spacingB, 35.0);
			glEnd();
			spacingA -= 15.0;
			spacingB -= 15.0;
		}

		glColor3fv(color.glass);
		// depan
		glBegin(GL_QUADS);
		glVertex3f(100.0, 100.0, 350); //P
		glVertex3f(150.0, 100.0, 300); //O
		glVertex3f(150.0, 170.0, 300); //O-up
		glVertex3f(100.0, 170.0, 350); //P-up
		glEnd();

		glColor3fv(color.white);
		glBegin(GL_LINES);
		glVertex3f(100.0, 100.0, 350); //P
		glVertex3f(100.0, 170.0, 350); //P-up
		glEnd();

		glColor3fv(color.white);
		glBegin(GL_LINES);
		glVertex3f(100.0, 170.0, 350); //P
		glVertex3f(62.5, 170.0, 300); //O-up
		glEnd();

		glColor3fv(color.white);
		glBegin(GL_LINES);
		glVertex3f(100.0, 170.0, 350); //P
		glVertex3f(150, 170.0, 300); //O-up
		glEnd();

		float triangleSpacing = 0.0f;
		float rowSpacing = 0.0f;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				glColor3ub(160, 205, 219);
				glBegin(GL_TRIANGLES);
				glVertex3f(115.0 + triangleSpacing, 115.0 + rowSpacing, 340 - triangleSpacing);
				glVertex3f(125.0 + triangleSpacing, 115.0 + rowSpacing, 330 - triangleSpacing);
				glVertex3f(115.0 + triangleSpacing, 105.0 + rowSpacing, 340 - triangleSpacing);
				glEnd();
				triangleSpacing += 10.0;
			}
			rowSpacing += 10.0;
			triangleSpacing = 0.0f;
		}

		glColor3fv(color.glass);
		glBegin(GL_QUADS);
		glVertex3f(100.0, 100.0, 350); //P
		glColor3ubv(color.lightglass);
		glVertex3f(62.5, 100.0, 300); //O
		glVertex3f(62.5, 170.0, 300); //O-up
		glColor3fv(color.glass);
		glVertex3f(100.0, 170.0, 350); //P-up
		glEnd();


		glBegin(GL_QUADS);
		glVertex3f(150.0, 100.0, 300); //P
		glVertex3f(100, 100.0, 220); //O
		glVertex3f(100, 170.0, 220); //O-up
		glVertex3f(150.0, 170.0, 300); //P-up
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(100, 100.0, 350); //P
		glVertex3f(62.5, 100.0, 300); //O
		glVertex3f(100, 100.0, 220); //O
		glVertex3f(150.0, 100.0, 300); //P-up
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(100, 170.0, 350); //P
		glVertex3f(62.5, 170.0, 300); //O
		glVertex3f(100, 170.0, 220); //O
		glVertex3f(150.0, 170.0, 300); //P-up
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glColor3ubv(color.lightglass);
		glVertex3f(0.0, 55.0, 300.5); //P
		glColor3ubv(color.lightglass);
		glVertex3f(125.0, 55.0, 315.5); //O
		glColor3ubv(color.softBlue);
		glVertex3f(125.0, 200.0, 315.5); //O-up
		glVertex3f(0.0, 200.0, 300.5); //P-up
		glEnd();

		float row = 0.0f;
		for (int i = 0; i < 5; i++) {
			float distance = 0.0;
			float deltaZ = 0.0;
			for (int j = 0; j < 5; j++) {
				glColor3fv(color.glass);
				glBegin(GL_QUADS);
				glVertex3f(5.0 + distance, 55.0 + row, 302 + deltaZ); //P
				glVertex3f(15.0 + distance, 55.0 + row, 302.5 + deltaZ); //O
				glVertex3f(15.0 + distance, 75.0 + row, 302.5 + deltaZ); //O-up
				glVertex3f(5.0 + distance, 75.0 + row, 302 + deltaZ); //P-up
				glEnd();

				distance += 25.0;
				deltaZ += 3.3f;
			}

			row += 30.0f;
		}

		glColor3ubv(color.softBlue);
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-0.5, 55.0, 300.0); //P
		glVertex3f(-0.5, 55.0, 35.0); //Q
		glVertex3f(-0.5, 200.0, 35.0); //Q-up
		glVertex3f(-0.5, 200.0, 300.0); //P-up
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(125.5, 55.0, 315.0); //O
		glVertex3f(125.5, 55.0, 50.0); //R
		glVertex3f(125.5, 200.0, 50.0); //R-up
		glVertex3f(125.5, 200.0, 315.0); //O-up
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 49.5); //R
		glVertex3f(0.0, 55.0, 34.5); //Q
		glVertex3f(0.0, 200.0, 34.5); //Q-up
		glVertex3f(125.0, 200.0, 49.5); //R-up
		glEnd();


		//top detail
		glColor3fv(color.lightGrey);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(15.0, 560.0, 60.0); //P
		glVertex3f(50.0, 560.0, 60.0); //O
		glVertex3f(50.0, 560.0, 225.0); //R
		glVertex3f(15.0, 560.0, 225.0); //Q
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(50.0, 560.0, 225.0); //P
		glVertex3f(15.0, 560.0, 225.0); //O
		glVertex3f(15.0, 550.0, 225.0); //R
		glVertex3f(50.0, 550.0, 225.0); //Q
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(50.0, 560.0, 60.0); //P
		glVertex3f(15.0, 560.0, 60.0); //O
		glVertex3f(15.0, 550.0, 60.0); //R
		glVertex3f(50.0, 550.0, 60.0); //Q
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(50.0, 560.0, 225.0);
		glVertex3f(50.0, 560.0, 60.0);
		glVertex3f(50.0, 550.0, 60.0);
		glVertex3f(50.0, 550.0, 225.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(15.0, 560.0, 225.0);
		glVertex3f(15.0, 560.0, 60.0);
		glVertex3f(15.0, 550.0, 60.0);
		glVertex3f(15.0, 550.0, 225.0);
		glEnd();

		//cabang atas
		glBegin(GL_POLYGON);
		glVertex3f(5.0, 560.0, 150.0); //P
		glVertex3f(15.0, 560.0, 150.0); //O
		glVertex3f(15.0, 560.0, 190.0); //R
		glVertex3f(5.0, 560.0, 190.0); //Q
		glEnd();

		// cabang depan
		glBegin(GL_POLYGON);
		glVertex3f(5.0, 560.0, 190.0);
		glVertex3f(15.0, 560.0, 190.0);
		glVertex3f(15.0, 550.0, 190.0);
		glVertex3f(5.0, 550.0, 190.0);
		glEnd();

		//cabang belakang
		glBegin(GL_POLYGON);
		glVertex3f(5.0, 560.0, 150.0);
		glVertex3f(15.0, 560.0, 150.0);
		glVertex3f(15.0, 550.0, 150.0);
		glVertex3f(5.0, 550.0, 150.0);
		glEnd();

		//cabang kanan
		glBegin(GL_POLYGON);
		glVertex3f(15.0, 560.0, 150.0);
		glVertex3f(15.0, 560.0, 190.0);
		glVertex3f(15.0, 550.0, 190.0);
		glVertex3f(15.0, 550.0, 150.0);
		glEnd();

		//cabang kiri
		glBegin(GL_POLYGON);
		glVertex3f(5.0, 560.0, 150.0);
		glVertex3f(5.0, 560.0, 190.0);
		glVertex3f(5.0, 550.0, 190.0);
		glVertex3f(5.0, 550.0, 150.0);
		glEnd();
	}

	void drawBuildingD() {
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 55.0, 275.0); //S
		glVertex3f(-350.0, 55.0, 265.0); //T
		glVertex3f(-400.0, 55.0, 250.0); //U
		glVertex3f(-400.0, 55.0, 200.0); //V
		glVertex3f(-250.0, 55.0, 200.0); //W
		glEnd();

		//glColor3fv(color.lightGrey);
		//glColor3fv(color.white);
		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 650.0, 275.0); //S
		glVertex3f(-350.0, 650.0, 265.0); //T
		glVertex3f(-400.0, 650.0, 250.0); //U
		glVertex3f(-400.0, 650.0, 200.0); //V
		glVertex3f(-250.0, 650.0, 200.0); //W
		glEnd();

		glColor3fv(color.glass);
		//depan1
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 55.0, 275.0); //S
		glColor3ubv(color.lightglass);
		glVertex3f(-350.0, 55.0, 265.0); //T
		glColor3fv(color.glass);
		glVertex3f(-350.0, 650.0, 265.0); //T
		glVertex3f(-250.0, 650.0, 275.0); //S
		glEnd();

		//depan2
		glBegin(GL_POLYGON);
		glColor3ubv(color.lightglass);
		glVertex3f(-350.0, 55.0, 265.0); //T
		glVertex3f(-400.0, 55.0, 250.0); //U
		glColor3fv(color.glass);
		glVertex3f(-400.0, 650.0, 250.0); //U
		glVertex3f(-350.0, 650.0, 265.0); //T
		glEnd();

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

		//detail
		glColor4f(0.3, 0.3, 0.3, 0.3);
		glBegin(GL_POLYGON);
		glVertex3f(-270.0, 350.0, 273.5); //S
		glVertex3f(-275.0, 350.0, 273.0); //T
		glVertex3f(-275.0, 650.0, 273.0); //T
		glVertex3f(-270.0, 650.0, 273.5); //S
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.0, 270.0); //S
		glVertex3f(-310.0, 350.0, 269.2); //T
		glVertex3f(-310.0, 650.0, 269.2); //T
		glVertex3f(-300.0, 650.0, 270.0); //S
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-345.0, 350.0, 266.0); //S
		glVertex3f(-355.0, 350.0, 264.0); //T
		glVertex3f(-355.0, 650.0, 264.0); //T
		glVertex3f(-345.0, 650.0, 266.0); //S
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-385.0, 350.0, 255.0); //T
		glVertex3f(-390.0, 350.0, 253.5); //U
		glVertex3f(-390.0, 650.0, 253.5); //U
		glVertex3f(-385.0, 650.0, 255.0); //T
		glEnd();
		//depan1
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 345.0, 275.5); //S
		glVertex3f(-350.0, 345.0, 265.5); //T
		glVertex3f(-350.0, 350.0, 265.5); //T
		glVertex3f(-250.0, 350.0, 275.5); //S
		glEnd();
		//depan2
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 345.0, 265.5); //T
		glVertex3f(-400.0, 345.0, 250.5); //U
		glVertex3f(-400.0, 350.0, 250.5); //U
		glVertex3f(-350.0, 350.0, 265.5); //T
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-400.5, 345.0, 250.0); //U
		glVertex3f(-400.5, 345.0, 200.0); //V
		glVertex3f(-400.5, 350.0, 200.0); //V
		glVertex3f(-400.5, 350.0, 250.0); //U
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-249.5, 345.0, 200.0); //W
		glVertex3f(-249.5, 345.0, 275.0); //S
		glVertex3f(-249.5, 350.0, 275.0); //S
		glVertex3f(-249.5, 350.0, 200.0); //W
		glEnd();

		float spacing = 345.0;
		float spacingB = 350.0;
		for (int i = 0; i < 15; i++) {
			//depan1
			glBegin(GL_POLYGON);
			glVertex3f(-250.0, spacing, 275.5); //S
			glVertex3f(-350.0, spacing, 265.5); //T
			glVertex3f(-350.0, spacingB, 265.5); //T
			glVertex3f(-250.0, spacingB, 275.5); //S
			glEnd();
			//depan2
			glBegin(GL_POLYGON);
			glVertex3f(-350.0, spacing, 265.5); //T
			glVertex3f(-400.0, spacing, 250.5); //U
			glVertex3f(-400.0, spacingB, 250.5); //U
			glVertex3f(-350.0, spacingB, 265.5); //T
			glEnd();
			//kiri
			glBegin(GL_POLYGON);
			glVertex3f(-400.5, spacing, 250.0); //U
			glVertex3f(-400.5, spacing, 200.0); //V
			glVertex3f(-400.5, spacingB, 200.0); //V
			glVertex3f(-400.5, spacingB, 250.0); //U
			glEnd();
			//kanan
			glBegin(GL_POLYGON);
			glVertex3f(-249.5, spacing, 200.0); //W
			glVertex3f(-249.5, spacing, 275.0); //S
			glVertex3f(-249.5, spacingB, 275.0); //S
			glVertex3f(-249.5, spacingB, 200.0); //W
			glEnd();
			//belakang
			glBegin(GL_POLYGON);
			glVertex3f(-400.0, spacing, 199.0); //V
			glVertex3f(-250.0, spacing, 199.0); //W
			glVertex3f(-250.0, spacingB, 199.0); //W
			glVertex3f(-400.0, spacingB, 199.0); //V
			glEnd();

			spacing -= 10.0;
			spacingB -= 10.0;
		}

		glColor3fv(color.white);
		//depan1
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 55.0, 275.5); //S
		glVertex3f(-350.0, 55.0, 265.5); //T
		glVertex3f(-350.0, 200.0, 265.5); //T
		glVertex3f(-250.0, 200.0, 275.5); //S
		glEnd();
		//depan2
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 55.0, 265.5); //T
		glVertex3f(-400.0, 55.0, 250.5); //U
		glVertex3f(-400.0, 200.0, 250.5); //U
		glVertex3f(-350.0, 200.0, 265.5); //T
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-400.5, 55.0, 250.0); //U
		glVertex3f(-400.5, 55.0, 200.0); //V
		glVertex3f(-400.5, 200.0, 200.0); //V
		glVertex3f(-400.5, 200.0, 250.0); //U
		glEnd();
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 55.0, 199.5); //V
		glVertex3f(-250.0, 55.0, 199.5); //W
		glVertex3f(-250.0, 200.0, 199.5); //W
		glVertex3f(-400.0, 200.0, 199.5); //V
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-249.5, 55.0, 200.0); //W
		glVertex3f(-249.5, 55.0, 275.0); //S
		glVertex3f(-249.5, 200.0, 275.0); //S
		glVertex3f(-249.5, 200.0, 200.0); //W
		glEnd();

		glColor4fv(color.lightGrey);
		//depan1
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 640.0, 275.9); //S
		glVertex3f(-350.0, 640.0, 265.9); //T
		glVertex3f(-350.0, 650.0, 265.9); //T
		glVertex3f(-250.0, 650.0, 275.9); //S
		glEnd();
		//depan2
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 640.0, 265.9); //T
		glVertex3f(-400.0, 640.0, 250.9); //U
		glVertex3f(-400.0, 650.0, 250.9); //U
		glVertex3f(-350.0, 650.0, 265.9); //T
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-400.5, 640.0, 250.0); //U
		glVertex3f(-400.5, 640.0, 200.0); //V
		glVertex3f(-400.5, 650.0, 200.0); //V
		glVertex3f(-400.5, 650.0, 250.0); //U
		glEnd();
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 640.0, 199.5); //V
		glVertex3f(-250.0, 640.0, 199.5); //W
		glVertex3f(-250.0, 650.0, 199.5); //W
		glVertex3f(-400.0, 650.0, 199.5); //V
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-249.5, 640.0, 200.0); //W
		glVertex3f(-249.5, 640.0, 275.0); //S
		glVertex3f(-249.5, 650.0, 275.0); //S
		glVertex3f(-249.5, 650.0, 200.0); //W
		glEnd();

		float spacingC = 640.0;
		//garis
		glColor4fv(color.line);
		for (int i = 0; i < 30; i++) {
			glBegin(GL_LINE_LOOP);
			glVertex3f(-250.0, spacingC, 275.9); //S
			glVertex3f(-350.0, spacingC, 265.9); //T
			glVertex3f(-350.0, spacingC, 265.9); //T
			glVertex3f(-400.0, spacingC, 250.9); //U
			glVertex3f(-400.5, spacingC, 250.0); //U
			glVertex3f(-400.5, spacingC, 200.0); //V
			glVertex3f(-400.0, spacingC, 199.5); //V
			glVertex3f(-250.0, spacingC, 199.5); //W
			glVertex3f(-249.5, spacingC, 200.0); //W
			glVertex3f(-249.5, spacingC, 275.0); //S
			glEnd();

			spacingC -= 10.0;
		}

		//detail depan	
		glColor3fv(color.glass);
		//depan1	
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 55.0, 275.7); //S	
		glVertex3f(-350.0, 55.0, 265.7); //T	
		glVertex3f(-350.0, 195.0, 265.7); //T	
		glVertex3f(-250.0, 195.0, 275.7); //S	
		glEnd();
		//depan2	
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 55.0, 265.7); //T	
		glVertex3f(-400.0, 55.0, 250.7); //U	
		glVertex3f(-400.0, 195.0, 250.7); //U	
		glVertex3f(-350.0, 195.0, 265.7); //T	
		glEnd();
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 55.0, 266.5); //T	
		glVertex3f(-360.0, 55.0, 263.5); //U	
		glVertex3f(-360.0, 195.0, 263.5); //U	
		glVertex3f(-350.0, 195.0, 266.5); //T	
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-290.0, 55.0, 273.0); //S	
		glVertex3f(-300.0, 55.0, 270.9); //T	
		glVertex3f(-300.0, 195.0, 270.9); //T	
		glVertex3f(-290.0, 195.0, 273.0); //S	
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-250.0, 55.0, 275.9); //S	
		glVertex3f(-350.0, 55.0, 265.9); //T	
		glVertex3f(-350.0, 150.0, 265.9); //T	
		glVertex3f(-250.0, 150.0, 275.9); //S	
		glEnd();
		//depan2	
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 55.0, 265.9); //T	
		glVertex3f(-400.0, 55.0, 250.9); //U	
		glVertex3f(-400.0, 150.0, 250.9); //U	
		glVertex3f(-350.0, 150.0, 265.9); //T	
		glEnd();

		//top detail
		glColor3fv(color.lightGrey);
		//atas kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-270.0, 660.0, 230.0); //S
		glVertex3f(-280.0, 660.0, 230.0); //U
		glVertex3f(-280.0, 660.0, 250.0); //V
		glVertex3f(-270.0, 660.0, 250.0); //W
		glEnd();
		//kanan kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-270.0, 660.0, 230.0); //S
		glVertex3f(-270.0, 660.0, 250.0); //U
		glVertex3f(-270.0, 650.0, 250.0); //V
		glVertex3f(-270.0, 650.0, 230.0); //W
		glEnd();
		//kiri kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-280.0, 660.0, 230.0); //S
		glVertex3f(-280.0, 660.0, 250.0); //U
		glVertex3f(-280.0, 650.0, 250.0); //V
		glVertex3f(-280.0, 650.0, 230.0); //W
		glEnd();
		//belakang kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-280.0, 660.0, 230.0); //S
		glVertex3f(-270.0, 660.0, 230.0); //U
		glVertex3f(-270.0, 650.0, 230.0); //V
		glVertex3f(-280.0, 650.0, 230.0); //W
		glEnd();
		//depan kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-280.0, 660.0, 250.0); //S
		glVertex3f(-270.0, 660.0, 250.0); //U
		glVertex3f(-270.0, 650.0, 250.0); //V
		glVertex3f(-280.0, 650.0, 250.0); //W
		glEnd();

		//atas kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-290.0, 655.0, 230.0); //S
		glVertex3f(-295.0, 655.0, 230.0); //U
		glVertex3f(-295.0, 655.0, 250.0); //V
		glVertex3f(-290.0, 655.0, 250.0); //W
		glEnd();
		//kanan kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-290.0, 655.0, 230.0); //S
		glVertex3f(-290.0, 655.0, 250.0); //U
		glVertex3f(-290.0, 650.0, 250.0); //V
		glVertex3f(-290.0, 650.0, 230.0); //W
		glEnd();
		//kiri kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-295.0, 655.0, 230.0); //S
		glVertex3f(-295.0, 655.0, 250.0); //U
		glVertex3f(-295.0, 650.0, 250.0); //V
		glVertex3f(-295.0, 650.0, 230.0); //W
		glEnd();
		//belakang kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-295.0, 655.0, 230.0); //S
		glVertex3f(-290.0, 655.0, 230.0); //U
		glVertex3f(-290.0, 650.0, 230.0); //V
		glVertex3f(-295.0, 650.0, 230.0); //W
		glEnd();
		//depan kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-295.0, 655.0, 250.0); //S
		glVertex3f(-290.0, 655.0, 250.0); //U
		glVertex3f(-290.0, 650.0, 250.0); //V
		glVertex3f(-295.0, 650.0, 250.0); //W
		glEnd();

		//atas kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-295.0, 660.0, 230.0); //S
		glVertex3f(-305.0, 660.0, 230.0); //U
		glVertex3f(-305.0, 660.0, 250.0); //V
		glVertex3f(-295.0, 660.0, 250.0); //W
		glEnd();
		//kanan kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-295.0, 660.0, 230.0); //S
		glVertex3f(-295.0, 660.0, 250.0); //U
		glVertex3f(-295.0, 650.0, 250.0); //V
		glVertex3f(-295.0, 650.0, 230.0); //W
		glEnd();
		//kiri kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-305.0, 660.0, 230.0); //S
		glVertex3f(-305.0, 660.0, 250.0); //U
		glVertex3f(-305, 650.0, 250.0); //V
		glVertex3f(-305.0, 650.0, 230.0); //W
		glEnd();
		//belakang kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-305.0, 660.0, 230.0); //S
		glVertex3f(-295.0, 660.0, 230.0); //U
		glVertex3f(-295.0, 650.0, 230.0); //V
		glVertex3f(-305.0, 650.0, 230.0); //W
		glEnd();
		//depan kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-305.0, 660.0, 250.0); //S
		glVertex3f(-295.0, 660.0, 250.0); //U
		glVertex3f(-295.0, 650.0, 250.0); //V
		glVertex3f(-305, 650.0, 250.0); //W
		glEnd();

		//atas kotak 4
		glBegin(GL_POLYGON);
		glVertex3f(-315.0, 655.0, 230.0); //S
		glVertex3f(-325.0, 655.0, 230.0); //U
		glVertex3f(-325.0, 655.0, 250.0); //V
		glVertex3f(-315.0, 655.0, 250.0); //W
		glEnd();
		//kanan kotak 4
		glBegin(GL_POLYGON);
		glVertex3f(-315.0, 655.0, 230.0); //S
		glVertex3f(-315.0, 655.0, 250.0); //U
		glVertex3f(-315.0, 650.0, 250.0); //V
		glVertex3f(-315.0, 650.0, 230.0); //W
		glEnd();
		//kiri kotak 4
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 230.0); //S
		glVertex3f(-325.0, 655.0, 250.0); //U
		glVertex3f(-325, 650.0, 250.0); //V
		glVertex3f(-325.0, 650.0, 230.0); //W
		glEnd();
		//belakang kotak 4
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 230.0); //S
		glVertex3f(-315.0, 655.0, 230.0); //U
		glVertex3f(-315.0, 650.0, 230.0); //V
		glVertex3f(-325.0, 650.0, 230.0); //W
		glEnd();
		//depan kotak 4
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 250.0); //S
		glVertex3f(-315.0, 655.0, 250.0); //U
		glVertex3f(-315.0, 650.0, 250.0); //V
		glVertex3f(-325, 650.0, 250.0); //W
		glEnd();

		//atas kotak 5
		glBegin(GL_POLYGON);
		glVertex3f(-320.0, 655.0, 220.0); //S
		glVertex3f(-325.0, 655.0, 220.0); //U
		glVertex3f(-325.0, 655.0, 230.0); //V
		glVertex3f(-320.0, 655.0, 230.0); //W
		glEnd();
		//kanan kotak 5
		glBegin(GL_POLYGON);
		glVertex3f(-320.0, 655.0, 220.0); //S
		glVertex3f(-320.0, 655.0, 230.0); //U
		glVertex3f(-320.0, 650.0, 230.0); //V
		glVertex3f(-320.0, 650.0, 220.0); //W
		glEnd();
		//kiri kotak 5
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 220.0); //S
		glVertex3f(-325.0, 655.0, 230.0); //U
		glVertex3f(-325.0, 650.0, 230.0); //V
		glVertex3f(-325.0, 650.0, 220.0); //W
		glEnd();
		//belakang kotak 5
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 220.0); //S
		glVertex3f(-320.0, 655.0, 220.0); //U
		glVertex3f(-320.0, 650.0, 220.0); //V
		glVertex3f(-325.0, 650.0, 220.0); //W
		glEnd();
		//depan kotak 5
		glBegin(GL_POLYGON);
		glVertex3f(-325.0, 655.0, 230.0); //S
		glVertex3f(-320.0, 655.0, 230.0); //U
		glVertex3f(-320.0, 650.0, 230.0); //V
		glVertex3f(-325, 650.0, 230.0); //W
		glEnd();

		//atas kotak 6
		glBegin(GL_POLYGON);
		glVertex3f(-330.0, 655.0, 220.0); //S
		glVertex3f(-350.0, 655.0, 220.0); //U
		glVertex3f(-350.0, 655.0, 230.0); //V
		glVertex3f(-330.0, 655.0, 230.0); //W
		glEnd();
		//kanan kotak 6
		glBegin(GL_POLYGON);
		glVertex3f(-330.0, 655.0, 220.0); //S
		glVertex3f(-330.0, 655.0, 230.0); //U
		glVertex3f(-330.0, 650.0, 230.0); //V
		glVertex3f(-330.0, 650.0, 220.0); //W
		glEnd();
		//kiri kotak 6
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 220.0); //S
		glVertex3f(-350.0, 655.0, 230.0); //U
		glVertex3f(-350.0, 650.0, 230.0); //V
		glVertex3f(-350.0, 650.0, 220.0); //W
		glEnd();
		//belakang kotak 6
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 220.0); //S
		glVertex3f(-330.0, 655.0, 220.0); //U
		glVertex3f(-330.0, 650.0, 220.0); //V
		glVertex3f(-350.0, 650.0, 220.0); //W
		glEnd();
		//depan kotak 6
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 230.0); //S
		glVertex3f(-330.0, 655.0, 230.0); //U
		glVertex3f(-330.0, 650.0, 230.0); //V
		glVertex3f(-350.0, 650.0, 230.0); //W
		glEnd();

		//atas kotak 7
		glBegin(GL_POLYGON);
		glVertex3f(-340.0, 655.0, 210.0); //S
		glVertex3f(-350.0, 655.0, 210.0); //U
		glVertex3f(-350.0, 655.0, 230.0); //V
		glVertex3f(-340.0, 655.0, 230.0); //W
		glEnd();
		//kanan kotak 7
		glBegin(GL_POLYGON);
		glVertex3f(-340.0, 655.0, 210.0); //S
		glVertex3f(-340.0, 655.0, 230.0); //U
		glVertex3f(-340.0, 650.0, 230.0); //V
		glVertex3f(-340.0, 650.0, 210.0); //W
		glEnd();
		//kiri kotak 7
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 210.0); //S
		glVertex3f(-350.0, 655.0, 230.0); //U
		glVertex3f(-350.0, 650.0, 230.0); //V
		glVertex3f(-350.0, 650.0, 210.0); //W
		glEnd();
		//belakang kotak 7
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 210.0); //S
		glVertex3f(-340.0, 655.0, 210.0); //U
		glVertex3f(-340.0, 650.0, 210.0); //V
		glVertex3f(-350.0, 650.0, 210.0); //W
		glEnd();
		//depan kotak 7
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 655.0, 230.0); //S
		glVertex3f(-340.0, 655.0, 230.0); //U
		glVertex3f(-340.0, 650.0, 230.0); //V
		glVertex3f(-350, 650.0, 230.0); //W
		glEnd();

		//atas kotak 8
		glBegin(GL_POLYGON);
		glVertex3f(-360.0, 655.0, 230.0); //S
		glVertex3f(-370.0, 655.0, 230.0); //U
		glVertex3f(-370.0, 655.0, 250.0); //V
		glVertex3f(-360.0, 655.0, 250.0); //W
		glEnd();
		//kanan kotak 8
		glBegin(GL_POLYGON);
		glVertex3f(-360.0, 655.0, 230.0); //S
		glVertex3f(-360.0, 655.0, 250.0); //U
		glVertex3f(-360.0, 650.0, 250.0); //V
		glVertex3f(-360.0, 650.0, 230.0); //W
		glEnd();
		//kiri kotak 8
		glBegin(GL_POLYGON);
		glVertex3f(-370.0, 655.0, 230.0); //S
		glVertex3f(-370.0, 655.0, 250.0); //U
		glVertex3f(-370.0, 650.0, 250.0); //V
		glVertex3f(-370.0, 650.0, 230.0); //W
		glEnd();
		//belakang kotak 8
		glBegin(GL_POLYGON);
		glVertex3f(-370.0, 655.0, 230.0); //S
		glVertex3f(-360.0, 655.0, 230.0); //U
		glVertex3f(-360.0, 650.0, 230.0); //V
		glVertex3f(-370.0, 650.0, 230.0); //W
		glEnd();
		//depan kotak 8
		glBegin(GL_POLYGON);
		glVertex3f(-370.0, 655.0, 250.0); //S
		glVertex3f(-360.0, 655.0, 250.0); //U
		glVertex3f(-360.0, 650.0, 250.0); //V
		glVertex3f(-370.0, 650.0, 250.0); //W
		glEnd();

	}

	void drawBuildingE() {
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 55.0, 300.0); //Z
		glVertex3f(-100.0, 55.0, 300.0); //A1
		glVertex3f(-100.0, 55.0, 200.0); //B1
		glVertex3f(-65.0, 55.0, 200.0); //E1
		glVertex3f(-50.0, 55.0, 245.0); //F1
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 265.0); //C1
		glVertex3f(-100.0, 55.0, 265.0); //C1
		glVertex3f(-100.0, 55.0, 200.0); //D1
		glVertex3f(-200.0, 55.0, 200.0); //D1
		glEnd();

		//glColor3fv(color.lightGrey);
		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 350.0, 300.0); //Z
		glVertex3f(-100.0, 350.0, 300.0); //A1
		glVertex3f(-100.0, 350.0, 200.0); //B1
		glVertex3f(-65.0, 350.0, 200.0); //E1
		glVertex3f(-50.0, 350.0, 245.0); //F1
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 350.0, 265.0); //C1
		glVertex3f(-100.0, 350.0, 265.0); //C1
		glVertex3f(-100.0, 350.0, 200.0); //D1
		glVertex3f(-200.0, 350.0, 200.0); //D1
		glEnd();

		glColor3fv(color.glass);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 55.0, 300.0); //Z
		glColor3ubv(color.lightglass);
		glVertex3f(-100.0, 55.0, 300.0); //A1
		glColor3fv(color.glass);
		glVertex3f(-100.0, 350.0, 300.0); //A1
		glVertex3f(-50.0, 350.0, 300.0); //Z
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 55.0, 300.0); //A1
		glVertex3f(-100.0, 55.0, 200.0); //B1
		glVertex3f(-100.0, 350.0, 200.0); //B1
		glVertex3f(-100.0, 350.0, 300.0); //A1
		glEnd();

		//depan2
		glBegin(GL_POLYGON);
		glColor3ubv(color.lightglass);
		glVertex3f(-200.0, 55.0, 265.0); //C1
		glColor3fv(color.glass);
		glVertex3f(-100.0, 55.0, 265.0); //C1
		glVertex3f(-100.0, 350.0, 265.0); //C1
		glVertex3f(-200.0, 350.0, 265.0); //C1
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 265.0); //C1
		glVertex3f(-200.0, 55.0, 200.0); //D1
		glVertex3f(-200.0, 350.0, 200.0); //D1
		glVertex3f(-200.0, 350.0, 265.0); //C1
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 200.0); //D1
		glVertex3f(-65.0, 55.0, 200.0); //E1
		glVertex3f(-65.0, 350.0, 200.0); //E1
		glVertex3f(-200.0, 350.0, 200.0); //D1
		glEnd();

		//kanan1
		glBegin(GL_POLYGON);
		glVertex3f(-65.0, 55.0, 200.0); //E1
		glVertex3f(-50.0, 55.0, 245.0); //F1
		glVertex3f(-50.0, 350.0, 245.0); //F1
		glVertex3f(-65.0, 350.0, 200.0); //E1
		glEnd();

		//kanan2
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 55.0, 245.0); //F1
		glVertex3f(-50.0, 55.0, 300.0); //Z
		glVertex3f(-50.0, 350.0, 300.0); //Z
		glVertex3f(-50.0, 350.0, 245.0); //F1
		glEnd();

		//detail
		glColor4f(1.0, 1.0, 1.0, 0.3);
		float spacing = 350.0;
		for (int i = 0; i < 20; i++) {
			glBegin(GL_LINES);
			glVertex3f(-50.0, spacing, 300.5); //Z
			glVertex3f(-100.0, spacing, 300.5); //A1
			glVertex3f(-100.5, spacing, 300.5); //A1
			glVertex3f(-100.5, spacing, 200.5); //B1
			glVertex3f(-200.0, spacing, 266.0); //C1
			glVertex3f(-100.0, spacing, 266.0); //C1
			glVertex3f(-200.5, spacing, 265.5); //C1
			glVertex3f(-200.5, spacing, 200.5); //D1
			glVertex3f(-64.5, spacing, 200.5); //E1
			glVertex3f(-49.5, spacing, 245.5); //F1
			glVertex3f(-200.0, spacing, 200.0); //D1
			glVertex3f(-65.0, spacing, 200.0); //E1
			glVertex3f(-49.5, spacing, 245.5); //F1
			glVertex3f(-49.5, spacing, 300.5); //Z
			glEnd();
			spacing -= 10.0;
		}

		glBegin(GL_LINE_LOOP);
		glVertex3f(-50.0, 55.0, 300.0); //Z
		glVertex3f(-100.0, 55.0, 300.0); //A1
		glVertex3f(-100.0, 350.0, 300.0); //A1
		glVertex3f(-50.0, 350.0, 300.0); //Z
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 55.0, 300.5); //Z
		glVertex3f(-100.0, 55.0, 300.5); //A1
		glVertex3f(-100.0, 150.0, 300.5); //A1
		glVertex3f(-50.0, 150.0, 300.5); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-100.5, 55.0, 300.0); //A1
		glVertex3f(-100.5, 55.0, 200.0); //B1
		glVertex3f(-100.5, 150.0, 200.0); //B1
		glVertex3f(-100.5, 150.0, 300.0); //A1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 265.5); //C1
		glVertex3f(-100.0, 55.0, 265.5); //C1
		glVertex3f(-100.0, 150.0, 265.5); //C1
		glVertex3f(-200.0, 150.0, 265.5); //C1
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-200.5, 55.0, 265.0); //C1
		glVertex3f(-200.5, 55.0, 200.0); //D1
		glVertex3f(-200.5, 150.0, 200.0); //D1
		glVertex3f(-200.5, 150.0, 265.0); //C1
		glEnd();

		//kanan1
		glBegin(GL_POLYGON);
		glVertex3f(-64.5, 55.0, 200.0); //E1
		glVertex3f(-49.5, 55.0, 245.0); //F1
		glVertex3f(-49.5, 150.0, 245.0); //F1
		glVertex3f(-64.5, 150.0, 200.0); //E1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-49.5, 55.0, 245.0); //F1
		glVertex3f(-49.5, 55.0, 300.0); //Z
		glVertex3f(-49.5, 150.0, 300.0); //Z
		glVertex3f(-49.5, 150.0, 245.0); //F1
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 199.5); //D1
		glVertex3f(-65.0, 55.0, 199.5); //E1
		glVertex3f(-65.0, 150.0, 199.5); //E1
		glVertex3f(-200.0, 150.0, 199.5); //D1
		glEnd();

		//detail kaca depan
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 55.0, 301.0); //Z
		glVertex3f(-55.0, 55.0, 301.0); //A1
		glVertex3f(-55.0, 350.0, 301.0); //A1
		glVertex3f(-50.0, 350.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-95.0, 55.0, 301.0); //Z
		glVertex3f(-100.0, 55.0, 301.0); //A1
		glVertex3f(-100.0, 350.0, 301.0); //A1
		glVertex3f(-95.0, 350.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 345.0, 301.0); //Z
		glVertex3f(-100.0, 345.0, 301.0); //A1
		glVertex3f(-100.0, 350.0, 301.0); //A1
		glVertex3f(-50.0, 350.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 315.0, 301.0); //Z
		glVertex3f(-100.0, 315.0, 301.0); //A1
		glVertex3f(-100.0, 320.0, 301.0); //A1
		glVertex3f(-50.0, 320.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-70.0, 315.0, 301.0); //Z
		glVertex3f(-80.0, 315.0, 301.0); //A1
		glVertex3f(-80.0, 350.0, 301.0); //A1
		glVertex3f(-70.0, 350.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-100.5, 345.0, 300.0); //A1
		glVertex3f(-100.5, 345.0, 200.0); //B1
		glVertex3f(-100.5, 350.0, 200.0); //B1
		glVertex3f(-100.5, 350.0, 300.0); //A1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 345.0, 265.5); //C1
		glVertex3f(-100.0, 345.0, 265.5); //C1
		glVertex3f(-100.0, 350.0, 265.5); //C1
		glVertex3f(-200.0, 350.0, 265.5); //C1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 266.5); //C1
		glVertex3f(-195.0, 55.0, 266.5); //C1
		glVertex3f(-195.0, 350.0, 266.5); //C1
		glVertex3f(-200.0, 350.0, 266.5); //C1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-75.0, 55.0, 301.0); //Z
		glVertex3f(-100.0, 55.0, 301.0); //A1
		glVertex3f(-100.0, 200.0, 301.0); //A1
		glVertex3f(-75.0, 200.0, 301.0); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-100.5, 195.0, 300.0); //A1
		glVertex3f(-100.5, 195.0, 200.0); //B1
		glVertex3f(-100.5, 200.0, 200.0); //B1
		glVertex3f(-100.5, 200.0, 300.0); //A1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 55.0, 265.6); //C1
		glVertex3f(-100.0, 55.0, 265.6); //C1
		glVertex3f(-100.0, 200.0, 265.6); //C1
		glVertex3f(-200.0, 200.0, 265.6); //C1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-165.0, 100.0, 266.5); //C1
		glVertex3f(-160.0, 100.0, 266.5); //C1
		glVertex3f(-160.0, 195.0, 266.5); //C1
		glVertex3f(-165.0, 195.0, 266.5); //C1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-135.0, 100.0, 266.5); //C1
		glVertex3f(-130.0, 100.0, 266.5); //C1
		glVertex3f(-130.0, 195.0, 266.5); //C1
		glVertex3f(-135.0, 195.0, 266.5); //C1
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-105.0, 55.0, 266.5); //C1
		glVertex3f(-100.0, 55.0, 266.5); //C1
		glVertex3f(-100.0, 350.0, 266.5); //C1
		glVertex3f(-105.0, 350.0, 266.5); //C1
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(-80.0, 150.0, 301.2); //Z
		glVertex3f(-95.0, 150.0, 301.2); //A1
		glVertex3f(-95.0, 195.0, 301.2); //A1
		glVertex3f(-80.0, 195.0, 301.2); //Z
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 150.0, 265.9); //C1
		glVertex3f(-100.0, 150.0, 265.9); //C1
		glVertex3f(-100.0, 195.0, 265.9); //C1
		glVertex3f(-200.0, 195.0, 265.9); //C1
		glEnd();



		//top detail
		glColor3fv(color.lightGrey);
		//atas kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-170.0, 360.0, 230.0); //C1
		glVertex3f(-150.0, 360.0, 230.0); //C1
		glVertex3f(-150.0, 360.0, 210.0); //D1
		glVertex3f(-170.0, 360.0, 210.0); //D1
		glEnd();

		//kanan kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-150.0, 360.0, 230.0); //S
		glVertex3f(-150.0, 360.0, 210.0); //U
		glVertex3f(-150.0, 350.0, 230.0); //V
		glVertex3f(-150.0, 350.0, 210.0); //W
		glEnd();
		//kiri kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-170.0, 360.0, 230.0); //S
		glVertex3f(-170.0, 360.0, 210.0); //U
		glVertex3f(-170.0, 350.0, 230.0); //V
		glVertex3f(-170.0, 350.0, 210.0); //W
		glEnd();
		//belakang kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-170.0, 360.0, 210.0); //S
		glVertex3f(-150.0, 360.0, 210.0); //U
		glVertex3f(-150.0, 350.0, 210.0); //V
		glVertex3f(-170.0, 350.0, 210.0); //W
		glEnd();
		//depan kotak 1
		glBegin(GL_POLYGON);
		glVertex3f(-170.0, 360.0, 230.0); //S
		glVertex3f(-150.0, 360.0, 230.0); //U
		glVertex3f(-150.0, 350.0, 230.0); //V
		glVertex3f(-170.0, 350.0, 230.0); //W
		glEnd();


		//atas kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-110.0, 360.0, 230.0); //C1
		glVertex3f(-90.0, 360.0, 230.0); //C1
		glVertex3f(-90.0, 360.0, 210.0); //D1
		glVertex3f(-110.0, 360.0, 210.0); //D1
		glEnd();

		//kanan kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-90.0, 360.0, 230.0); //S
		glVertex3f(-90.0, 360.0, 210.0); //U
		glVertex3f(-90.0, 350.0, 230.0); //V
		glVertex3f(-90.0, 350.0, 210.0); //W
		glEnd();
		//kiri kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-110.0, 360.0, 230.0); //S
		glVertex3f(-110.0, 360.0, 210.0); //U
		glVertex3f(-110.0, 350.0, 230.0); //V
		glVertex3f(-110.0, 350.0, 210.0); //W
		glEnd();
		//belakang kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-110.0, 360.0, 210.0); //S
		glVertex3f(-90.0, 360.0, 210.0); //U
		glVertex3f(-90.0, 350.0, 210.0); //V
		glVertex3f(-110.0, 350.0, 210.0); //W
		glEnd();
		//depan kotak 2
		glBegin(GL_POLYGON);
		glVertex3f(-110.0, 360.0, 230.0); //S
		glVertex3f(-90.0, 360.0, 230.0); //U
		glVertex3f(-90.0, 350.0, 230.0); //V
		glVertex3f(-110.0, 350.0, 230.0); //W
		glEnd();

		//atas kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-60.0, 375.0, 285.0); //Z
		glVertex3f(-90.0, 375.0, 285.0); //A1
		glVertex3f(-90.0, 375.0, 255.0); //B1
		glVertex3f(-60.0, 375.0, 255.0); //E1
		glEnd();

		glColor3fv(color.lightGrey);
		//kanan kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-60.0, 375.0, 285.0); //S
		glVertex3f(-60.0, 375.0, 255.0); //U
		glVertex3f(-60.0, 350.0, 285.0); //V
		glVertex3f(-60.0, 350.0, 255.0); //W
		glEnd();
		//kiri kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-90.0, 375.0, 285.0); //S
		glVertex3f(-90.0, 375.0, 255.0); //U
		glVertex3f(-90.0, 350.0, 285.0); //V
		glVertex3f(-90.0, 350.0, 255.0); //W
		glEnd();
		//belakang kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-90.0, 375.0, 255.0); //S
		glVertex3f(-60.0, 375.0, 255.0); //U
		glVertex3f(-60.0, 350.0, 255.0); //V
		glVertex3f(-90.0, 350.0, 255.0); //W
		glEnd();
		//depan kotak 3
		glBegin(GL_POLYGON);
		glVertex3f(-90.0, 375.0, 285.0); //S
		glVertex3f(-60.0, 375.0, 285.0); //U
		glVertex3f(-60.0, 350.0, 285.0); //V
		glVertex3f(-90.0, 350.0, 285.0); //W
		glEnd();

	}

	void drawBuildingF() {

		glColor3fv(color.lightGrey);
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 50.0);  //depan
		glVertex3f(375.0, 55.0, -750.0); //belakang
		glVertex3f(225.0, 55.0, -750.0); //belakang
		glVertex3f(225.0, 55.0, -300.0); //kiri
		glVertex3f(0.0, 55.0, -300.0); //kiri
		glVertex3f(0.0, 55.0, 50.0); // depan
		glEnd();

		//atas
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 200.0, 50.0);  //depan
		glVertex3f(375.0, 200.0, -750.0); //belakang
		glVertex3f(225.0, 200.0, -750.0); //belakang
		glVertex3f(225.0, 200.0, -300.0); //kiri
		glVertex3f(0.0, 200.0, -300.0); //kiri
		glVertex3f(0.0, 200.0, 50.0); // depan
		glEnd();

		glColor3fv(color.white);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, 50.0);  //depan
		glVertex3f(0.0, 55.0, 50.0); // depan
		glVertex3f(0.0, 200.0, 50.0); // depan
		glVertex3f(375.0, 200.0, 50.0);  //depan
		glEnd();

		//kiri
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(225.0, 55.0, -300.0); //kiri
		glVertex3f(0.0, 55.0, -300.0); //kiri
		glVertex3f(0.0, 200.0, -300.0); //kiri	
		glVertex3f(225.0, 200.0, -300.0); //kiri
		glEnd();
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 55.0, -300.0); //kiri
		glVertex3f(0.0, 55.0, 50.0); // depan
		glColor3fv(color.lightGrey);
		glVertex3f(0.0, 200.0, 50.0); // depan
		glVertex3f(0.0, 200.0, -300.0); //kiri
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(225.0, 55.0, -750.0); //kiri
		glVertex3f(225.0, 55.0, -300.0); //kiri
		glVertex3f(225.0, 200.0, -300.0); //kiri
		glVertex3f(225.0, 200.0, -750.0); //kiri
		glEnd();

		glColor3fv(color.white);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(375.0, 55.0, -750.0); //belakang
		glVertex3f(225.0, 55.0, -750.0); //belakang
		glColor3fv(color.lightGrey);
		glVertex3f(225.0, 200.0, -750.0); //belakang
		glVertex3f(375.0, 200.0, -750.0); //belakang
		glEnd();

		glColor3fv(color.white);
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(374.0, 55.0, -750.0); //belakang
		glVertex3f(374.0, 55.0, 50.0);  //depan
		glColor3fv(color.lightGrey);
		glVertex3f(374.0, 200.0, 50.0);  //depan
		glVertex3f(374.0, 200.0, -750.0); //belakang
		glEnd();

		//detail
		float spacing = 75.0;
		float spacingB = 80.0;
		for (int i = 0; i < 6; i++) {
			glColor3fv(color.glass);
			glBegin(GL_POLYGON);
			glVertex3f(374.5, spacing, -700.0); //belakang
			glVertex3f(374.5, spacing, -350.0);  //depan
			glVertex3f(374.5, spacingB, -350.0);  //depan
			glVertex3f(374.5, spacingB, -700.0); //belakang
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(355.0, spacing, -750.5); //belakang
			glVertex3f(350.0, spacing, -750.5); //belakang
			glVertex3f(350.0, spacingB, -750.5); //belakang
			glVertex3f(355.0, spacingB, -750.5); //belakang
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(300.0, spacing, -750.5); //belakang
			glVertex3f(295.0, spacing, -750.5); //belakang
			glVertex3f(295.0, spacingB, -750.5); //belakang
			glVertex3f(300.0, spacingB, -750.5); //belakang
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(250.0, spacing, -750.5); //belakang
			glVertex3f(245.0, spacing, -750.5); //belakang
			glVertex3f(245.0, spacingB, -750.5); //belakang
			glVertex3f(250.0, spacingB, -750.5); //belakang
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-0.5, spacing, -250.0); //kiri
			glVertex3f(-0.5, spacing, -50.0); // depan
			glVertex3f(-0.5, spacingB, -50.0); // depan
			glVertex3f(-0.5, spacingB, -250.0); //kiri
			glEnd();

			glColor4fv(color.line);
			glBegin(GL_LINES);
			glVertex3f(224.5, spacing, -300.5); //kiri
			glVertex3f(0.0, spacingB, -300.5); //kiri
			glVertex3f(224.5, spacing, -750.0); //kiri
			glVertex3f(224.5, spacingB, -300.0); //kiri
			glEnd();

			spacing += 20.0;
			spacingB += 20.0;
		}

		glColor3fv(color.lightGrey);
		glBegin(GL_POLYGON);
		glVertex3f(225.0, 55.0, -300.9); //kiri
		glVertex3f(0.0, 55.0, -300.9); //kiri
		glVertex3f(0.0, 85.0, -300.9); //kiri	
		glVertex3f(225.0, 85.0, -300.9); //kiri
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(224.0, 55.0, -750.0); //kiri
		glVertex3f(224.0, 55.0, -300.0); //kiri
		glVertex3f(224.0, 85.0, -300.0); //kiri
		glVertex3f(224.0, 85.0, -750.0); //kiri
		glEnd();

		//atap
		glColor3ubv(color.darkBlue);
		glBegin(GL_POLYGON);
		glVertex3f(275.0, 200.5, -350.0);  //depan
		glVertex3f(275.0, 200.5, -700.0); //belakang
		glVertex3f(235.0, 200.5, -700.0); //belakang
		glVertex3f(235.0, 200.5, -350.0); //kiri
		glEnd();

		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 200.5, -350.0);  //depan
		glVertex3f(350.0, 200.5, -700.0); //belakang
		glVertex3f(340.0, 200.5, -700.0); //belakang
		glVertex3f(340.0, 200.5, -350.0); //kiri
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 210.5, -350.0);  //depan
		glVertex3f(350.0, 210.5, -700.0); //belakang
		glVertex3f(340.0, 210.5, -700.0); //belakang
		glVertex3f(340.0, 210.5, -350.0); //kiri
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 200.5, -350.0);  //depan
		glVertex3f(350.0, 200.5, -700.0); //belakang
		glVertex3f(350.0, 210.5, -700.0); //belakang
		glVertex3f(350.0, 210.5, -350.0);  //depan
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(340.0, 200.5, -700.0); //belakang
		glVertex3f(340.0, 200.5, -350.0); //kiri
		glVertex3f(340.0, 210.5, -350.0); //kiri
		glVertex3f(340.0, 210.5, -700.0); //belakang
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 200.5, -350.0);  //depan
		glVertex3f(340.0, 200.5, -350.0); //kiri
		glVertex3f(340.0, 210.5, -350.0); //kiri
		glVertex3f(350.0, 210.5, -350.0);  //depan
		glEnd();
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(350.0, 200.5, -700.0); //belakang
		glVertex3f(340.0, 200.5, -700.0); //belakang
		glVertex3f(340.0, 210.5, -700.0); //belakang
		glVertex3f(350.0, 210.5, -700.0); //belakang
		glEnd();

		// --- //
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 200.5, -200.0); //kiri
		glVertex3f(20.0, 200.5, 25.0);
		glVertex3f(100.0, 200.5, 25.0); // depan
		glVertex3f(100.0, 200.5, -200.0); //kiri
		glEnd();
		glColor3fv(color.darkGrey);
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 210.5, -200.0); //kiri
		glVertex3f(20.0, 210.5, 25.0);
		glVertex3f(100.0, 210.5, 25.0); // depan
		glVertex3f(100.0, 210.5, -200.0); //kiri
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 200.5, -200.0); //kiri
		glVertex3f(20.0, 200.5, 25.0);
		glVertex3f(20.0, 210.5, 25.0);
		glVertex3f(20.0, 210.5, -200.0); //kiri
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 200.5, 25.0);
		glVertex3f(100.0, 200.5, 25.0);
		glVertex3f(100.0, 210.5, 25.0); // depan
		glVertex3f(20.0, 210.5, 25.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(100.0, 200.5, 25.0);
		glVertex3f(100.0, 200.5, -200.0); //kiri
		glVertex3f(100.0, 210.5, -200.0); //kiri
		glVertex3f(100.0, 210.5, 25.0);
		glEnd();


	}

	void drawBuildingG() {

		glColor3fv(color.lightGrey);
		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 314.9); //O
		glVertex3f(-400.0, 55.0, 200.0); //V
		glVertex3f(-450.0, 55.0, 0.0);
		glVertex3f(125.0, 55.0, 0.0);
		glEnd();

		//atas
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 200.0, 314.9); //O
		glVertex3f(-400.0, 200.0, 200.0); //V
		glVertex3f(-450.0, 200.0, 0.0);
		glVertex3f(125.0, 200.0, 0.0);
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 314.0); //O
		glVertex3f(-400.0, 55.0, 200.0); //V
		glVertex3f(-400.0, 200.0, 200.0); //V
		glVertex3f(125.0, 200.0, 314.0); //O
		glEnd();

		//belakang
		glColor3f(0.81, 0.77, 0.7);
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 55.0, 0.0);
		glVertex3f(125.0, 55.0, 0.0);
		glColor3fv(color.darkGrey);
		glVertex3f(125.0, 200.0, 0.0);
		glVertex3f(-450.0, 200.0, 0.0);
		glEnd();

		//kiri
		glColor3f(0.81, 0.77, 0.7);
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 55.0, 200.0); //V
		glVertex3f(-450.0, 55.0, 0.0);
		glColor3fv(color.darkGrey);
		glVertex3f(-450.0, 200.0, 0.0);
		glVertex3f(-400.0, 200.0, 200.0); //V
		glEnd();

		glColor3fv(color.lightGrey);
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(125.0, 55.0, 314.0); //O
		glVertex3f(125.0, 55.0, 0.0);
		glVertex3f(125.0, 200.0, 0.0);
		glVertex3f(125.0, 200.0, 314.0); //O
		glEnd();

		//detail
		glColor3fv(color.darkGrey);
		float spacing = 75.0;
		float spacingB = 80.0;
		for (int i = 0; i < 6; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-430.0, spacing, -0.5);
			glVertex3f(-400.0, spacing, -0.5);
			glVertex3f(-400.0, spacingB, -0.5);
			glVertex3f(-430.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-380.0, spacing, -0.5);
			glVertex3f(-350.0, spacing, -0.5);
			glVertex3f(-350.0, spacingB, -0.5);
			glVertex3f(-380.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-330.0, spacing, -0.5);
			glVertex3f(-300.0, spacing, -0.5);
			glVertex3f(-300.0, spacingB, -0.5);
			glVertex3f(-330.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-280.0, spacing, -0.5);
			glVertex3f(-250.0, spacing, -0.5);
			glVertex3f(-250.0, spacingB, -0.5);
			glVertex3f(-280.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-230.0, spacing, -0.5);
			glVertex3f(-200.0, spacing, -0.5);
			glVertex3f(-200.0, spacingB, -0.5);
			glVertex3f(-230.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-180.0, spacing, -0.5);
			glVertex3f(-150.0, spacing, -0.5);
			glVertex3f(-150.0, spacingB, -0.5);
			glVertex3f(-180.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-130.0, spacing, -0.5);
			glVertex3f(-100.0, spacing, -0.5);
			glVertex3f(-100.0, spacingB, -0.5);
			glVertex3f(-130.0, spacingB, -0.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-80.0, spacing, -0.5);
			glVertex3f(-50.0, spacing, -0.5);
			glVertex3f(-50.0, spacingB, -0.5);
			glVertex3f(-80.0, spacingB, -0.5);
			glEnd();

			spacing += 20.0;
			spacingB += 20.0;
		}

		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(-400.5, 55.0, 175.0); //V
		glVertex3f(-429.9, 55.0, 85.0);
		glVertex3f(-429.9, 185.0, 85.0);
		glVertex3f(-400.5, 185.0, 175.0); //V
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-432.0, 75.0, 75.0); //V
		glVertex3f(-450.5, 75.0, 5.0);
		glVertex3f(-450.5, 120.0, 5.0);
		glVertex3f(-432.0, 120.0, 75.0); //V
		glEnd();

		float spacingC = 175.0;
		float spacingD = 185.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-432.0, spacingC, 75.0); //V
			glVertex3f(-450.5, spacingC, 5.0);
			glVertex3f(-450.5, spacingD, 5.0);
			glVertex3f(-432.0, spacingD, 75.0); //V
			glEnd();

			spacingC -= 15;
			spacingD -= 15;
		}

		float spacingE = 165.0;
		float spacingF = 170.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-403.0, spacingE, 195.0); //V
			glVertex3f(-420.0, spacingE, 125.0);
			glVertex3f(-420.0, spacingF, 125.0);
			glVertex3f(-403.0, spacingF, 195.0); //V
			glEnd();

			spacingE -= 20;
			spacingF -= 20;
		}

		//atas
		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 200.5, 125.0); //O
		glVertex3f(-375.0, 200.5, 125.0); //V
		glVertex3f(-375.0, 200.5, 25.0);
		glVertex3f(-200.0, 200.5, 25.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 210.5, 125.0); //O
		glVertex3f(-375.0, 210.5, 125.0); //V
		glVertex3f(-375.0, 210.5, 25.0);
		glVertex3f(-200.0, 210.5, 25.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 210.5, 125.0); //O
		glVertex3f(-375.0, 210.5, 125.0); //V
		glVertex3f(-375.0, 200.5, 125.0); //V
		glVertex3f(-200.0, 200.5, 125.0); //O
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-375.0, 210.5, 125.0); //V
		glVertex3f(-375.0, 210.5, 25.0);
		glVertex3f(-375.0, 200.5, 25.0);
		glVertex3f(-375.0, 200.5, 125.0); //V
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 210.5, 25.0);
		glVertex3f(-200.0, 210.5, 125.0); //O
		glVertex3f(-200.0, 200.5, 125.0); //O
		glVertex3f(-200.0, 200.5, 25.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-375.0, 210.5, 25.0);
		glVertex3f(-200.0, 210.5, 25.0);
		glVertex3f(-200.0, 200.5, 25.0);
		glVertex3f(-375.0, 200.5, 25.0);
		glEnd();
	}

	void drawBuildingH() {

		glColor3ubv(color.hardGrey);

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -100.0);
		glVertex3f(-25.0, 55.0, -300.0);
		glVertex3f(-300.0, 55.0, -300.0);
		glVertex3f(-300.0, 55.0, -100.0);
		glEnd();

		//atas
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 450.0, -100.0);
		glVertex3f(-25.0, 450.0, -300.0);
		glVertex3f(-300.0, 450.0, -300.0);
		glVertex3f(-300.0, 450.0, -100.0);
		glEnd();

		glColor3fv(color.lightGrey);
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -100.0);
		glColor3fv(color.white);
		glVertex3f(-300.0, 55.0, -100.0);
		glColor3fv(color.lightGrey);
		glVertex3f(-300.0, 450.0, -100.0);
		glVertex3f(-25.0, 450.0, -100.0);
		glEnd();

		glColor3fv(color.lightGrey);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -300.0);
		glVertex3f(-300.0, 55.0, -300.0);
		glVertex3f(-300.0, 450.0, -300.0);
		glVertex3f(-25.0, 450.0, -300.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -100.0);
		glVertex3f(-25.0, 55.0, -300.0);
		glVertex3f(-25.0, 450.0, -300.0);
		glVertex3f(-25.0, 450.0, -100.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 55.0, -300.0);
		glColor3fv(color.white);
		glVertex3f(-300.0, 55.0, -100.0);
		glColor3fv(color.lightGrey);
		glVertex3f(-300.0, 450.0, -100.0);
		glVertex3f(-300.0, 450.0, -300.0);
		glEnd();

		float Ymargin = 0;
		float Zmargin = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				glColor3fv(color.glass);
				glBegin(GL_POLYGON);
				glVertex3f(-301.0, 210.0 + Ymargin, -290.0 + Zmargin);
				glVertex3f(-301.0, 210.0 + Ymargin, -260.0 + Zmargin);
				glVertex3f(-301.0, 220.0 + Ymargin, -260.0 + Zmargin);
				glVertex3f(-301.0, 220.0 + Ymargin, -290.0 + Zmargin);
				glEnd();

				Zmargin += 50.0f;
			}
			Zmargin = 0;
			Ymargin += 20.0f;
		}

		Ymargin = 0;
		Zmargin = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				glColor3fv(color.glass);
				glBegin(GL_POLYGON);
				glVertex3f(-26.0, 210.0 + Ymargin, -290.0 + Zmargin);
				glVertex3f(-26.0, 210.0 + Ymargin, -260.0 + Zmargin);
				glVertex3f(-26.0, 220.0 + Ymargin, -260.0 + Zmargin);
				glVertex3f(-26.0, 220.0 + Ymargin, -290.0 + Zmargin);
				glEnd();

				Zmargin += 50.0f;
			}
			Zmargin = 0;
			Ymargin += 20.0f;
		}

		//detail
		glColor3fv(color.glass);
		float spacing = 390.0;
		float spacingB = 400.0;

		for (int i = 0; i < 10; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-40.0, spacing, -99.5);
			glVertex3f(-60.0, spacing, -99.5);
			glVertex3f(-60.0, spacingB, -99.5);
			glVertex3f(-40.0, spacingB, -99.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-265.0, spacing, -99.5);
			glVertex3f(-285.0, spacing, -99.5);
			glVertex3f(-285.0, spacingB, -99.5);
			glVertex3f(-265.0, spacingB, -99.5);
			glEnd();

			spacing -= 20.0;
			spacingB -= 20.0;
		}

		float spacingC = -235.0;
		float spacingD = -245.0;
		for (int i = 0; i < 7; i++) {
			//depan
			glBegin(GL_POLYGON);
			glVertex3f(spacingC, 210.0, -99.5);
			glVertex3f(spacingD, 210.0, -99.5);
			glVertex3f(spacingD, 400.0, -99.5);
			glVertex3f(spacingC, 400.0, -99.5);
			glEnd();

			spacingC += 25.0;
			spacingD += 25.0;
		}

		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 451.0, -200.0);
		glVertex3f(-100.0, 451.0, -250.0);
		glVertex3f(-200.0, 451.0, -250.0);
		glVertex3f(-200.0, 451.0, -200.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 475.0, -200.0);
		glVertex3f(-100.0, 475.0, -250.0);
		glVertex3f(-200.0, 475.0, -250.0);
		glVertex3f(-200.0, 475.0, -200.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 475.0, -200.0);
		glVertex3f(-100.0, 475.0, -250.0);
		glVertex3f(-100.0, 451.0, -250.0);
		glVertex3f(-100.0, 451.0, -200.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-200.0, 475.0, -200.0);
		glVertex3f(-200.0, 475.0, -250.0);
		glVertex3f(-200.0, 451.0, -250.0);
		glVertex3f(-200.0, 451.0, -200.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 475.0, -250.0);
		glVertex3f(-200.0, 475.0, -250.0);
		glVertex3f(-200.0, 451.0, -250.0);
		glVertex3f(-100.0, 451.0, -250.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-100.0, 475.0, -200.0);
		glVertex3f(-200.0, 475.0, -200.0);
		glVertex3f(-200.0, 451.0, -200.0);
		glVertex3f(-100.0, 451.0, -200.0);
		glEnd();

	}

	void drawBuildingI() {

		glColor3fv(color.lightGrey);

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -600.0);
		glVertex3f(-25.0, 55.0, -600.0);
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-500.0, 55.0, -400.0);
		glVertex3f(-25.0, 55.0, -400.0);
		glVertex3f(-25.0, 350.0, -400.0);
		glVertex3f(-500.0, 350.0, -400.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glVertex3f(-25.0, 350.0, -750.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-25.0, 55.0, -400.0);
		glVertex3f(-25.0, 350.0, -400.0);
		glVertex3f(-25.0, 350.0, -750.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -400.0);
		glVertex3f(-500.0, 350.0, -400.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glEnd();

		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 350.0, -750.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glVertex3f(-500.0, 350.0, -400.0);
		glVertex3f(-25.0, 350.0, -400.0);
		glEnd();

		//detail
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 100.0, -399.5);
		glVertex3f(-50.0, 100.0, -399.5);
		glVertex3f(-50.0, 300.0, -399.5);
		glVertex3f(-450.0, 300.0, -399.5);
		glEnd();

		glColor3fv(color.lightGrey);
		float spacing = -400.0;
		float spacingB = -350.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(spacing, 75.0, -399.3);
			glVertex3f(spacingB, 75.0, -399.3);
			glVertex3f(spacingB, 350.0, -399.3);
			glVertex3f(spacing, 350.0, -399.3);
			glEnd();

			spacing += 65.0;
			spacingB += 65.0;
		}

		float spacingC = 300.0;
		float spacingD = 325.0;
		for (int i = 0; i < 3; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-500.0, spacingC, -399.1);
			glVertex3f(-25.0, spacingC, -399.1);
			glVertex3f(-25.0, spacingD, -399.1);
			glVertex3f(-500.0, spacingD, -399.1);
			glEnd();

			spacingC -= 75.0;
			spacingD -= 75.0;
		}

		glColor3fv(color.glass);
		float spacingE = 275.0;
		float spacingF = 300.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-500.5, spacingE, -700.0);
			glVertex3f(-500.5, spacingE, -450.0);
			glVertex3f(-500.5, spacingF, -450.0);
			glVertex3f(-500.5, spacingF, -700.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-24.5, spacingE, -700.0);
			glVertex3f(-24.5, spacingE, -450.0);
			glVertex3f(-24.5, spacingF, -450.0);
			glVertex3f(-24.5, spacingF, -700.0);
			glEnd();

			spacingE -= 50.0;
			spacingF -= 50.0;
		}

		glColor3fv(color.darkGrey);
		float spacingG = 310.0;
		float spacingH = 300.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-375.0, spacingG, -750.5);
			glVertex3f(-425.0, spacingG, -750.5);
			glVertex3f(-425.0, spacingH, -750.5);
			glVertex3f(-375.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-275.0, spacingG, -750.5);
			glVertex3f(-325.0, spacingG, -750.5);
			glVertex3f(-325.0, spacingH, -750.5);
			glVertex3f(-275.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-175.0, spacingG, -750.5);
			glVertex3f(-225.0, spacingG, -750.5);
			glVertex3f(-225.0, spacingH, -750.5);
			glVertex3f(-175.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-75.0, spacingG, -750.5);
			glVertex3f(-125.0, spacingG, -750.5);
			glVertex3f(-125.0, spacingH, -750.5);
			glVertex3f(-75.0, spacingH, -750.5);
			glEnd();

			spacingG -= 50.0;
			spacingH -= 50.0;
		}

		//detail atas
		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glEnd();
		glColor3fv(color.lightGrey);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -700.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glVertex3f(-400.0, 360.5, -700.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, -700.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glVertex3f(-400.0, 360.5, -700.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 360.5, -700.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glEnd();

		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glEnd();
		glColor3fv(color.lightGrey);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glVertex3f(-300.0, 360.5, -550.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glVertex3f(-300.0, 360.5, -550.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 360.5, -550.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glEnd();

	}

	void drawBuildingJ() {

		glColor3fv(color.glass);

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 55.0, -750.0);
		glVertex3f(20.0, 55.0, -750.0);
		glVertex3f(20.0, 55.0, -600.0);
		glVertex3f(200.0, 55.0, -600.0);
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 55.0, -600.0);
		glVertex3f(200.0, 55.0, -600.0);
		glVertex3f(200.0, 400.0, -600.0);
		glVertex3f(20.0, 400.0, -600.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 55.0, -750.0);
		glVertex3f(20.0, 55.0, -750.0);
		glVertex3f(20.0, 400.0, -750.0);
		glVertex3f(200.0, 400.0, -750.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 55.0, -750.0);
		glVertex3f(200.0, 55.0, -600.0);
		glVertex3f(200.0, 400.0, -600.0);
		glVertex3f(200.0, 400.0, -750.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 55.0, -750.0);
		glVertex3f(20.0, 55.0, -600.0);
		glVertex3f(20.0, 400.0, -600.0);
		glVertex3f(20.0, 400.0, -750.0);
		glEnd();

		//glColor3fv(color.white);
		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(200.0, 400.0, -750.0);
		glVertex3f(20.0, 400.0, -750.0);
		glVertex3f(20.0, 400.0, -600.0);
		glVertex3f(200.0, 400.0, -600.0);
		glEnd();

		//detail
		glColor3fv(color.darkGrey);
		float xTiang;
		for (xTiang = 25.0; xTiang <= 165.0; xTiang = xTiang + 140) {
			//belakang tiang
			glBegin(GL_POLYGON);
			glVertex3f(xTiang + 30, 55.0, -755.0);
			glVertex3f(xTiang, 55.0, -755.0);
			glVertex3f(xTiang, 410.0, -755.0);
			glVertex3f(xTiang + 30, 410.0, -755.0);
			glEnd();

			//kanan
			glBegin(GL_POLYGON);
			glVertex3f(xTiang + 30, 55.0, -755.0);
			glVertex3f(xTiang + 30, 55.0, -730.0);
			glVertex3f(xTiang + 30, 410.0, -730.0);
			glVertex3f(xTiang + 30, 410.0, -755.0);
			glEnd();

			//kiri
			glBegin(GL_POLYGON);
			glVertex3f(xTiang, 55.0, -755.0);
			glVertex3f(xTiang, 55.0, -730.0);
			glVertex3f(xTiang, 410.0, -730.0);
			glVertex3f(xTiang, 410.0, -755.0);
			glEnd();

			//atas
			glBegin(GL_POLYGON);
			glVertex3f(xTiang + 30, 400.0, -755.0);
			glVertex3f(xTiang, 410.0, -755.0);
			glVertex3f(xTiang, 410.0, -730.0);
			glVertex3f(xTiang + 30, 400.0, -730.0);
			glEnd();

			//depan tiang
			glBegin(GL_POLYGON);
			glVertex3f(xTiang + 30, 55.0, -730.0);
			glVertex3f(xTiang, 55.0, -730.0);
			glVertex3f(xTiang, 410.0, -730.0);
			glVertex3f(xTiang + 30, 410.0, -730.0);
			glEnd();
		}

		//jendela
		glColor3fv(color.lightGrey);
		glLineWidth(5);
		float yGarangan;
		float xGarangan;
		float zGarangan;
		for (yGarangan = 50.0; yGarangan <= 400.0; yGarangan = yGarangan + 25.0) {
			for (zGarangan = -751; zGarangan <= -600; zGarangan = zGarangan + 151) {
				glBegin(GL_LINES);
				glVertex3f(20.0, yGarangan, zGarangan);
				glVertex3f(200.0, yGarangan, zGarangan);
				glEnd();
			}
		}


		for (yGarangan = 50.0; yGarangan <= 400.0; yGarangan = yGarangan + 25.0) {
			for (xGarangan = 20.0; xGarangan <= 200; xGarangan = xGarangan + 180) {
				glBegin(GL_LINES);
				glVertex3f(xGarangan, yGarangan, -750);
				glVertex3f(xGarangan, yGarangan, -600);
				glEnd();
			}
		}


		for (xGarangan = 80.0; xGarangan <= 140.0; xGarangan = xGarangan + 60.0) {
			glBegin(GL_LINES);
			glVertex3f(xGarangan, 55, -750);
			glVertex3f(xGarangan, 400, -750);
			glEnd();
		}

		//detail top
		glColor3fv(color.lightGrey);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(60.0, 410.0, -650.0);
		glVertex3f(40.0, 410.0, -650.0);
		glVertex3f(40.0, 410.0, -620.0);
		glVertex3f(60.0, 410.0, -620.0);
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(40.0, 55.0, -620.0);
		glVertex3f(60.0, 55.0, -620.0);
		glVertex3f(60.0, 410.0, -620.0);
		glVertex3f(40.0, 410.0, -620.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(60.0, 55.0, -650.0);
		glVertex3f(40.0, 55.0, -650.0);
		glVertex3f(40.0, 410.0, -650.0);
		glVertex3f(60.0, 410.0, -650.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(60.0, 55.0, -650.0);
		glVertex3f(60.0, 55.0, -620.0);
		glVertex3f(60.0, 410.0, -620.0);
		glVertex3f(60.0, 410.0, -650.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(40.0, 55.0, -650.0);
		glVertex3f(40.0, 55.0, -620.0);
		glVertex3f(40.0, 410.0, -620.0);
		glVertex3f(40.0, 410.0, -650.0);
		glEnd();
	}

	void myTree(float startPoint, float zPoint) {
		// Batang
		glColor3ub(139, 69, 19);
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint);
		glVertex3f(startPoint - 10, 55, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint);
		glVertex3f(startPoint, 120, zPoint);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 120, zPoint - 10);
		glVertex3f(startPoint, 120, zPoint - 10);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint - 10, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 55, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint - 10);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint - 10);
		glVertex3f(startPoint, 55, zPoint);
		glVertex3f(startPoint, 120, zPoint);
		glVertex3f(startPoint, 120, zPoint - 10);
		glEnd();

		// daun
		glColor3ub(19, 51, 17);
		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint + 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint + 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint - 40);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(27, 78, 24);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glColor3ub(19, 51, 17);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint + 40);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint - 40);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint + 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint - 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint - 40);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(27, 78, 24);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glColor3ub(19, 51, 17);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20 + treeAnimation, 180, zPoint + 40);
		glVertex3f(startPoint - 20 + treeAnimation, 180, zPoint + 40);
		glEnd();
	}

	void street() {

		glBegin(GL_QUADS);
		glColor3ubv(color.lightstreet);
		glVertex3f(-930.0, 55.0, 360.0);
		glColor3ubv(color.street);
		glVertex3f(400.0, 55.0, 400.0);
		glColor3ubv(color.street);
		glVertex3f(400.0, 55.0, 520.0);
		glColor3ubv(color.lightstreet);
		glVertex3f(-920.0, 55.0, 480.0);
		glEnd();

		float width = 35.0f;
		float margin = 80.0f;
		float deltaZ = 0.0f;
		float startPoint = -800.0f;
		for (int i = 0; i < 16; i++) {
			glBegin(GL_QUADS);
			glColor3fv(color.white);
			glVertex3f(startPoint, 56.0, 410.0 + deltaZ);
			glVertex3f(startPoint - width, 56.0, 410.0 + deltaZ);
			glVertex3f(startPoint - width, 56.0, 420.0 + deltaZ);
			glVertex3f(startPoint, 56.0, 420.0 + deltaZ);
			glEnd();

			startPoint += margin;
			deltaZ += 2.75;
		}
	}

	void anotherStreet() {

		glBegin(GL_QUADS);
		glColor3ubv(color.lightstreet);
		glVertex3f(-575.0, 56.0, 375.0);
		glVertex3f(-475.0, 56.0, 375.0);
		glColor3ubv(color.street);
		glVertex3f(-675.0, 55.0, -800.0);
		glVertex3f(-775.0, 55.0, -800.0);
		glEnd();

		float zMargin = 0;
		float xMargin = 0;

		for (int i = 0; i < 7; i++) {
			glBegin(GL_QUADS);
			glColor3fv(color.white);
			glVertex3f(-525.0 - xMargin, 57.0, 375.0 - zMargin);
			glVertex3f(-520.0 - xMargin, 57.0, 375.0 - zMargin);
			glVertex3f(-535.0 - xMargin, 57.0, 300.0 - zMargin);
			glVertex3f(-540.0 - xMargin, 57.0, 300.0 - zMargin);
			glEnd();

			zMargin += 180.0f;
			xMargin += 30.0f;
		}
	}

	void trafficLight() {

		myConfiguration config;

		glBegin(GL_QUADS);
		glColor3ubv(color.hardGrey);
		glVertex3f(-465.0, 55.0, 325.0);
		glVertex3f(-460.0, 55.0, 325.0);
		glVertex3f(-460.0, 200.0, 325.0);
		glVertex3f(-465.0, 200, 325.0);

		glVertex3f(-465.0, 55.0, 330.0);
		glVertex3f(-460.0, 55.0, 330.0);
		glVertex3f(-460.0, 200.0, 330.0);
		glVertex3f(-465.0, 200, 330.0);

		glVertex3f(-465.0, 55.0, 330.0);
		glVertex3f(-465.0, 55.0, 325.0);
		glVertex3f(-465.0, 200., 325.0);
		glVertex3f(-465.0, 200, 330.0);

		glVertex3f(-460.0, 55.0, 330.0);
		glVertex3f(-460.0, 55.0, 325.0);
		glVertex3f(-460.0, 200., 325.0);
		glVertex3f(-460.0, 200, 330.0);

		if (redOn)
			glColor3fv(color.red);

		else
			glColor3fv(color.black);

		glVertex3f(-459.0, 180, 330.0);
		glVertex3f(-459.0, 180, 325.0);
		glVertex3f(-459.0, 190., 325.0);
		glVertex3f(-459.0, 190, 330.0);

		if (yellowOn)
			glColor3fv(color.yellow);

		else
			glColor3fv(color.black);


		glVertex3f(-459.0, 175, 330.0);
		glVertex3f(-459.0, 175, 325.0);
		glVertex3f(-459.0, 165., 325.0);
		glVertex3f(-459.0, 165, 330.0);

		if (greenOn)
			glColor3fv(color.green);

		else
			glColor3fv(color.black);

		glVertex3f(-459.0, 160, 330.0);
		glVertex3f(-459.0, 160, 325.0);
		glVertex3f(-459.0, 150., 325.0);
		glVertex3f(-459.0, 150, 330.0);

		glEnd();
	}

	void starObject(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
		float Mab, Cab, Yab, Mcd, Ccd, Ycd; // rumus awal
		float px, py; // hasil

		Mab = (by - ay) / (bx - ax);
		Mcd = (dy - cy) / (dx - cx);
		Cab = ay - (Mab * ax);
		Ccd = cy - (Mcd * cx);

		px = (Ccd - Cab) / (Mab - Mcd);
		py = (Mab * px + Cab);

		myColor color;
		glColor3fv(color.star);

		glBegin(GL_POLYGON);
		glVertex3f(ax, ay, 0.0);
		glVertex3f(px, py, 10.0);
		glVertex3f(bx, by, 0.0);
		glVertex3f(px, py, -10.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(ax, ay, 0.0);
		glVertex3f(px, py + 10, 10.0);
		glVertex3f(bx, by, 0.0);
		glVertex3f(px, py - 10, -10.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(cx, cy, 0.0);
		glVertex3f(px, py, 10.0);
		glVertex3f(dx, dy, 0.0);
		glVertex3f(px, py, -10.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(cx, cy, 0.0);
		glVertex3f(px, py + 10, 10.0);
		glVertex3f(dx, dy, 0.0);
		glVertex3f(px, py - 10, -10.0);
		glEnd();
	}

	void tweening() {

		float startShape[8][3] = {
			{20, 500, 315}, {50, 500, 315}, {50, 490, 315}, {40, 490, 315}, {40, 450, 315}, {30, 450, 315},
			{30, 490, 315}, {20, 490, 315}
		};

		float finalShape[8][3] = {
			{20, 500, 315}, {50, 500, 315}, {50, 475, 315}, {50, 475, 315}, {30, 475, 315}, {30, 475, 315},
			{30, 450, 315}, {20, 450, 315}
		};

		myColor color;

		float intermediateShape[12][3];

		static float tween = 0.0 - deltat;

		if (tween < 1) {
			tween += deltat;
		}

		for (size_t i = 0; i < 8; i++) {
			intermediateShape[i][0] = (1.0 - tween) * startShape[i][0] + tween * finalShape[i][0];
			intermediateShape[i][1] = (1.0 - tween) * startShape[i][1] + tween * finalShape[i][1];
			intermediateShape[i][2] = (1.0 - tween) * startShape[i][2] + tween * finalShape[i][2];
		}

		glVertexPointer(3, GL_FLOAT, 0, intermediateShape);

		glColor3fv(color.darkGrey);

		for (size_t i = 0; i < 8000; i++) {
			glDrawArrays(GL_LINE_LOOP, 0, 8);
			glutPostRedisplay();
		}

		glEnableClientState(GL_VERTEX_ARRAY);
	}

	void carObject(float xCoord, float zCoord, int colorOption) {

		//bawah
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glEnd();

		//depan-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord);
		glEnd();

		//blkg-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glEnd();

		if (colorOption == 1)
			glColor3fv(color.orange);

		if (colorOption == 2)
			glColor3fv(color.white);

		if (colorOption == 3)
			glColor3fv(color.darkGrey);

		if (colorOption == 4)
			glColor3ubv(color.darkBlue);

		if (colorOption == 5)
			glColor3fv(color.grey);

		if (colorOption == 6)
			glColor3fv(color.glass);

		if (colorOption == 7)
			glColor3fv(color.yellow);

		if (colorOption == 8)
			glColor3fv(color.red);

		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glEnd();

		//samping-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glEnd();

		//kaca
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glEnd();
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glEnd();
	}

	void gasStation() {

		glColor3fv(color.lightGrey);
		glBegin(GL_POLYGON);
		glVertex3f(-600.0, 55.5, 300.0);
		glVertex3f(-685.0, 55.5, -200.0);
		glColor3fv(color.grey);
		glVertex3f(-985.0, 55.5, -200.0);
		glVertex3f(-900.0, 55.5, 300.0);
		glEnd();

		//atap
		{
			glColor3fv(color.lightGrey);
			glBegin(GL_POLYGON);
			glVertex3f(-600.0, 150.5, 300.0);
			glVertex3f(-685.0, 150.5, -200.0);
			glVertex3f(-985.0, 150.5, -200.0);
			glVertex3f(-900.0, 150.5, 300.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-600.0, 160.5, 300.0);
			glVertex3f(-685.0, 160.5, -200.0);
			glVertex3f(-985.0, 160.5, -200.0);
			glColor3fv(color.white);
			glVertex3f(-900.0, 160.5, 300.0);
			glEnd();

			glColor3fv(color.red);
			glBegin(GL_POLYGON);
			glVertex3f(-600.0, 150.5, 300.0);
			glVertex3f(-685.0, 150.5, -200.0);
			glVertex3f(-685.0, 160.5, -200.0);
			glVertex3f(-600.0, 160.5, 300.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-985.0, 160.5, -200.0);
			glVertex3f(-900.0, 160.5, 300.0);
			glVertex3f(-900.0, 150.5, 300.0);
			glVertex3f(-985.0, 150.5, -200.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-685.0, 150.5, -200.0);
			glVertex3f(-985.0, 150.5, -200.0);
			glVertex3f(-985.0, 160.5, -200.0);
			glVertex3f(-685.0, 160.5, -200.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-600.0, 150.5, 300.0);
			glVertex3f(-900.0, 150.5, 300.0);
			glVertex3f(-900.0, 160.5, 300.0);
			glVertex3f(-600.0, 160.5, 300.0);
			glEnd();
		}

		//pos-1
		glColor3fv(color.lightGrey);
		glBegin(GL_POLYGON);
		glVertex3f(-707.5, 55.9, 125.0);
		glVertex3f(-700.0, 55.9, 175.0);
		glVertex3f(-850.0, 55.9, 175.0);
		glVertex3f(-857.5, 55.9, 125.0);
		glEnd();
		//tiang
		{
			glColor3fv(color.white);
			glBegin(GL_POLYGON);
			glVertex3f(-707.5, 55.9, 145.0);
			glVertex3f(-700.0, 55.9, 155.0);
			glVertex3f(-700.0, 150.5, 155.0);
			glVertex3f(-707.5, 150.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-707.5, 55.9, 145.0);
			glVertex3f(-712.5, 55.9, 145.0);
			glVertex3f(-712.5, 150.5, 145.0);
			glVertex3f(-707.5, 150.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-700.0, 55.9, 155.0);
			glVertex3f(-705.0, 55.9, 155.0);
			glVertex3f(-705.0, 150.0, 155.0);
			glVertex3f(-700.0, 150.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-712.5, 55.9, 145.0);
			glVertex3f(-705.0, 55.9, 155.0);
			glVertex3f(-705.0, 150.5, 155.0);
			glVertex3f(-712.5, 150.5, 145.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-850.0, 55.9, 155.0);
			glVertex3f(-857.5, 55.9, 145.0);
			glVertex3f(-857.5, 150.5, 145.0);
			glVertex3f(-850.0, 150.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-857.5, 55.9, 145.0);
			glVertex3f(-862.5, 55.9, 145.0);
			glVertex3f(-862.5, 150.5, 145.0);
			glVertex3f(-857.5, 150.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-850.0, 55.9, 155.0);
			glVertex3f(-855.0, 55.9, 155.0);
			glVertex3f(-855.0, 150.5, 155.0);
			glVertex3f(-850.0, 150.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-862.5, 55.9, 145.0);
			glVertex3f(-855.0, 55.9, 155.0);
			glVertex3f(-855.0, 150.5, 155.0);
			glVertex3f(-862.5, 150.5, 145.0);
			glEnd();
		}

		//pom
		{
			glColor3fv(color.red);
			glBegin(GL_POLYGON);
			glVertex3f(-757.5, 55.9, 145.0);
			glVertex3f(-750.0, 55.9, 155.0);
			glVertex3f(-750.0, 100.5, 155.0);
			glVertex3f(-757.5, 100.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-757.5, 55.9, 145.0);
			glVertex3f(-762.5, 55.9, 145.0);
			glVertex3f(-762.5, 100.5, 145.0);
			glVertex3f(-757.5, 100.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-750.0, 55.9, 155.0);
			glVertex3f(-755.0, 55.9, 155.0);
			glVertex3f(-755.0, 100.0, 155.0);
			glVertex3f(-750.0, 100.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-762.5, 55.9, 145.0);
			glVertex3f(-755.0, 55.9, 155.0);
			glVertex3f(-755.0, 100.5, 155.0);
			glVertex3f(-762.5, 100.5, 145.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-800.0, 55.9, 155.0);
			glVertex3f(-807.5, 55.9, 145.0);
			glVertex3f(-807.5, 100.5, 145.0);
			glVertex3f(-800.0, 100.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-807.5, 55.9, 145.0);
			glVertex3f(-812.5, 55.9, 145.0);
			glVertex3f(-812.5, 100.5, 145.0);
			glVertex3f(-807.5, 100.5, 145.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-800.0, 55.9, 155.0);
			glVertex3f(-805.0, 55.9, 155.0);
			glVertex3f(-805.0, 100.5, 155.0);
			glVertex3f(-800.0, 100.5, 155.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-812.5, 55.9, 145.0);
			glVertex3f(-805.0, 55.9, 155.0);
			glVertex3f(-805.0, 100.5, 155.0);
			glVertex3f(-812.5, 100.5, 145.0);
			glEnd();
		}

		//pos-2
		glColor3fv(color.lightGrey);
		glBegin(GL_POLYGON);
		glVertex3f(-737.5, 55.9, -75.0);
		glVertex3f(-730.0, 55.9, -25.0);
		glVertex3f(-880.0, 55.9, -25.0);
		glVertex3f(-887.5, 55.9, -75.0);
		glEnd();
		//tiang
		{
			glBegin(GL_POLYGON);
			glVertex3f(-737.5, 55.9, -55.0);
			glVertex3f(-730.0, 55.9, -45.0);
			glVertex3f(-730.0, 150.5, -45.0);
			glVertex3f(-737.5, 150.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-737.5, 55.9, -55.0);
			glVertex3f(-742.5, 55.9, -45.0);
			glVertex3f(-742.5, 150.5, -45.0);
			glVertex3f(-737.5, 150.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-730.0, 55.9, -45.0);
			glVertex3f(-735.0, 55.9, -45.0);
			glVertex3f(-735.0, 150.5, -45.0);
			glVertex3f(-730.0, 150.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-742.5, 55.9, -45.0);
			glVertex3f(-735.0, 55.9, -45.0);
			glVertex3f(-735.0, 150.5, -55.0);
			glVertex3f(-742.5, 150.5, -55.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-880.0, 55.9, -45.0);
			glVertex3f(-887.5, 55.9, -55.0);
			glVertex3f(-887.5, 150.5, -55.0);
			glVertex3f(-880.0, 150.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-887.5, 55.9, -55.0);
			glVertex3f(-892.5, 55.9, -55.0);
			glVertex3f(-892.5, 150.5, -55.0);
			glVertex3f(-887.5, 150.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-880.0, 55.9, -45.0);
			glVertex3f(-885.0, 55.9, -55.0);
			glVertex3f(-885.0, 150.5, -55.0);
			glVertex3f(-880.0, 150.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-892.5, 55.9, -45.0);
			glVertex3f(-885.0, 55.9, -55.0);
			glVertex3f(-885.0, 150.5, -55.0);
			glVertex3f(-892.5, 150.5, -45.0);
			glEnd();
		}

		//pom
		{
			glColor3fv(color.red);
			glBegin(GL_POLYGON);
			glVertex3f(-787.5, 55.9, -55.0);
			glVertex3f(-780.0, 55.9, -45.0);
			glVertex3f(-780.0, 100.5, -45.0);
			glVertex3f(-787.5, 100.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-787.5, 55.9, -55.0);
			glVertex3f(-792.5, 55.9, -45.0);
			glVertex3f(-792.5, 100.5, -45.0);
			glVertex3f(-787.5, 100.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-780.0, 55.9, -45.0);
			glVertex3f(-785.0, 55.9, -45.0);
			glVertex3f(-785.0, 100.5, -45.0);
			glVertex3f(-780.0, 100.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-792.5, 55.9, -45.0);
			glVertex3f(-785.0, 55.9, -45.0);
			glVertex3f(-785.0, 100.5, -55.0);
			glVertex3f(-792.5, 100.5, -55.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-830.0, 55.9, -45.0);
			glVertex3f(-837.5, 55.9, -55.0);
			glVertex3f(-837.5, 100.5, -55.0);
			glVertex3f(-830.0, 100.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-837.5, 55.9, -55.0);
			glVertex3f(-842.5, 55.9, -55.0);
			glVertex3f(-842.5, 100.5, -55.0);
			glVertex3f(-837.5, 100.5, -55.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-830.0, 55.9, -45.0);
			glVertex3f(-835.0, 55.9, -55.0);
			glVertex3f(-835.0, 100.5, -55.0);
			glVertex3f(-830.0, 100.5, -45.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-842.5, 55.9, -45.0);
			glVertex3f(-835.0, 55.9, -55.0);
			glVertex3f(-835.0, 100.5, -55.0);
			glVertex3f(-842.5, 100.5, -45.0);
			glEnd();
		}
	}

	void indomaretStore() {

		glColor3fv(color.lightGrey);
		// bawah
		glBegin(GL_POLYGON);
		glVertex3f(-700.0, 55.5, -250.0);
		glVertex3f(-760.0, 55.5, -600.0);
		glVertex3f(-960.0, 55.5, -600.0);
		glVertex3f(-900.0, 55.5, -250.0);
		glEnd();

		// atas
		glBegin(GL_POLYGON);
		glVertex3f(-700.0, 150.5, -250.0);
		glVertex3f(-760.0, 150.5, -600.0);
		glVertex3f(-960.0, 150.5, -600.0);
		glVertex3f(-900.0, 150.5, -250.0);
		glEnd();

		// kanan
		glBegin(GL_POLYGON);
		glVertex3f(-700.0, 55.5, -250.0);
		glVertex3f(-760.0, 55.5, -600.0);
		glVertex3f(-760.0, 150.5, -600.0);
		glVertex3f(-700.0, 150.5, -250.0);
		glEnd();

		// kiri
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 55.5, -250.0);
		glVertex3f(-960.0, 55.5, -600.0);
		glVertex3f(-960.0, 150.5, -600.0);
		glVertex3f(-900.0, 150.5, -250.0);
		glEnd();

		// belakang
		glBegin(GL_POLYGON);
		glVertex3f(-760.0, 55.5, -600.0);
		glVertex3f(-760.0, 150.5, -600.0);
		glVertex3f(-960.0, 150.5, -600.0);
		glVertex3f(-960.0, 55.5, -600.0);
		glEnd();

		// depan
		glBegin(GL_POLYGON);
		glVertex3f(-700.0, 55.5, -250.0);
		glVertex3f(-700.0, 150.5, -250.0);
		glVertex3f(-900.0, 150.5, -250.0);
		glColor3fv(color.white);
		glVertex3f(-900.0, 55.5, -250.0);
		glEnd();

		// Atap

		glColor3fv(color.white);
		// bawah
		glBegin(GL_POLYGON);
		glVertex3f(-675.0, 150.5, -225.0);
		glVertex3f(-735.0, 150.5, -625.0);
		glVertex3f(-985.0, 150.5, -625.0);
		glVertex3f(-925.0, 150.5, -225.0);
		glEnd();

		// atas
		glColor3fv(color.lightGrey);
		glBegin(GL_POLYGON);
		glVertex3f(-675.0, 180.5, -225.0);
		glVertex3f(-735.0, 180.5, -625.0);
		glVertex3f(-985.0, 180.5, -625.0);
		glVertex3f(-925.0, 180.5, -225.0);
		glEnd();

		glColor3fv(color.white);
		// kanan
		glBegin(GL_POLYGON);
		glVertex3f(-675.0, 150.5, -225.0);
		glVertex3f(-735.0, 150.5, -625.0);
		glVertex3f(-735.0, 180.5, -625.0);
		glVertex3f(-675.0, 180.5, -225.0);
		glEnd();

		// kiri
		glBegin(GL_POLYGON);
		glVertex3f(-875.0, 150.5, -225.0);
		glVertex3f(-985.0, 150.5, -625.0);
		glVertex3f(-985.0, 180.5, -625.0);
		glVertex3f(-875.0, 180.5, -225.0);
		glEnd();

		// belakang
		glBegin(GL_POLYGON);
		glVertex3f(-735.0, 150.5, -625.0);
		glVertex3f(-735.0, 180.5, -625.0);
		glVertex3f(-985.0, 180.5, -625.0);
		glVertex3f(-985.0, 150.5, -625.0);
		glEnd();

		// depan
		glBegin(GL_POLYGON);
		glVertex3f(-675.0, 150.5, -225.0);
		glColor3fv(color.lightGrey);
		glVertex3f(-675.0, 180.5, -225.0);
		glColor3fv(color.white);
		glVertex3f(-925.0, 180.5, -225.0);
		glVertex3f(-925.0, 150.5, -225.0);
		glEnd();

		// warna - warni
		// kuning
		glColor3fv(color.yellow);
		glBegin(GL_POLYGON);
		glVertex3f(-674.0, 150.5, -225.0);
		glVertex3f(-734.0, 150.5, -625.0);
		glVertex3f(-734.0, 160.5, -625.0);
		glVertex3f(-674.0, 160.5, -225.0);
		glEnd();
		// biru
		glColor3fv(color.blue);
		glBegin(GL_POLYGON);
		glVertex3f(-674.0, 161.0, -225.0);
		glVertex3f(-734.0, 161.0, -625.0);
		glVertex3f(-734.0, 170.5, -625.0);
		glVertex3f(-674.0, 170.5, -225.0);
		glEnd();
		// merah
		glColor3fv(color.red);
		glBegin(GL_POLYGON);
		glVertex3f(-674.0, 171.0, -225.0);
		glVertex3f(-734.0, 171.0, -625.0);
		glVertex3f(-734.0, 180.0, -625.0);
		glVertex3f(-674.0, 180.0, -225.0);
		glEnd();

		// Kaca depan indomaret - kanan objek
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(-700.0, 55.5, -250);
		glVertex3f(-725.0, 55.5, -400.0);
		glVertex3f(-725.0, 150.5, -400.0);
		glVertex3f(-700.0, 150.5, -250.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-733.0, 55.5, -450.0);
		glVertex3f(-760.0, 55.5, -600.0);
		glVertex3f(-760.0, 150.5, -600.0);
		glVertex3f(-733.0, 150.5, -450.0);
		glEnd();

		float marginBottom = 0;
		for (int i = 0; i < 10; i++) {
			glColor3fv(color.lightGrey);
			glBegin(GL_POLYGON);
			glVertex3f(-699.0, 150. - marginBottom, -250.0);
			glVertex3f(-758.0, 150. - marginBottom, -600.0);
			glVertex3f(-758.0, 155. - marginBottom, -600.0);
			glVertex3f(-699.0, 155. - marginBottom, -250.0);
			glEnd();

			marginBottom += 10;
		}

	}

	void parkingArea() {

		glBegin(GL_QUADS);
		glColor3ubv(color.lightstreet);
		glVertex3f(-520, 55.0, -55);
		glColor3ubv(color.street);
		glVertex3f(-320, 55.0, -55);
		glVertex3f(-320, 55.0, -350);
		glVertex3f(-560, 55.0, -350);
		glEnd();

		glBegin(GL_QUADS);
		glColor3fv(color.white);
		glVertex3f(-520, 105.5, -55);
		glColor3fv(color.lightGrey);
		glVertex3f(-320, 105.5, -55);
		glVertex3f(-320, 155.5, -202.5);
		glVertex3f(-540, 155.5, -202.5);
		glEnd();

		glBegin(GL_QUADS);
		glColor3fv(color.lightGrey);
		glVertex3f(-540.5, 155.5, -202);
		glVertex3f(-320, 155.5, -202);
		glVertex3f(-320, 105.5, -350);
		glVertex3f(-560, 105.5, -350);
		glEnd();

		glBegin(GL_QUADS);
		glColor3fv(color.grey);
		glVertex3f(-520, 105.5, -55);
		glVertex3f(-320, 105.5, -55);
		glVertex3f(-320, 105.5, -350);
		glVertex3f(-560, 105.5, -350);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3fv(color.grey);
		glVertex3f(-520, 105.5, -55);
		glVertex3f(-540, 155.5, -202.5);
		glVertex3f(-560, 105.5, -350);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3fv(color.grey);
		glVertex3f(-320, 105.5, -55);
		glVertex3f(-320, 155.5, -202.5);
		glVertex3f(-320, 105.5, -350);
		glEnd();

		//pilar depan kiri
		glBegin(GL_QUADS);
		glColor3fv(color.grey);
		glVertex3f(-505, 55.0, -70);
		glVertex3f(-507.5, 55.0, -70);
		glVertex3f(-507.5, 105.0, -70);
		glVertex3f(-505, 105.0, -70);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-505, 55.0, -72.5);
		glVertex3f(-507.5, 55.0, -72.5);
		glVertex3f(-507.5, 105.0, -72.5);
		glVertex3f(-505, 105.0, -72.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-505, 55.0, -70);
		glVertex3f(-505, 55.0, -70);
		glVertex3f(-505, 105.0, -72.5);
		glVertex3f(-505, 105.0, -72.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-507.5, 55.0, -70);
		glVertex3f(-507.5, 55.0, -70);
		glVertex3f(-507.5, 105.0, -72.5);
		glVertex3f(-507.5, 105.0, -72.5);
		glEnd();

		// pilar depan kanan		
		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -70);
		glVertex3f(-337.5, 55.0, -70);
		glVertex3f(-337.5, 105.0, -70);
		glVertex3f(-335, 105.0, -70);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -72.5);
		glVertex3f(-337.5, 55.0, -72.5);
		glVertex3f(-337.5, 105.0, -72.5);
		glVertex3f(-335, 105.0, -72.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -70);
		glVertex3f(-335, 55.0, -72.5);
		glVertex3f(-335, 105.0, -72.5);
		glVertex3f(-335, 105.0, -70);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-337.5, 55.0, -72.5);
		glVertex3f(-337.5, 55.0, -72.5);
		glVertex3f(-337.5, 105.0, -72.5);
		glVertex3f(-337.5, 105.0, -72.5);
		glEnd();

		// Belakang kanan	
		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -335);
		glVertex3f(-337.5, 55.0, -335);
		glVertex3f(-337.5, 105.0, -335);
		glVertex3f(-335, 105.0, -335);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -337.5);
		glVertex3f(-337.5, 55.0, -337.5);
		glVertex3f(-337.5, 105.0, -337.5);
		glVertex3f(-335, 105.0, -337.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-335, 55.0, -335);
		glVertex3f(-335, 55.0, -337.5);
		glVertex3f(-335, 105.0, -337.5);
		glVertex3f(-335, 105.0, -335);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-337.5, 55.0, -337.5);
		glVertex3f(-337.5, 55.0, -337.5);
		glVertex3f(-337.5, 105.0, -337.5);
		glVertex3f(-337.5, 105.0, -337.5);
		glEnd();

		// Belakang kiri
		glBegin(GL_QUADS);
		glVertex3f(-545, 55.0, -335);
		glVertex3f(-547.5, 55.0, -335);
		glVertex3f(-547.5, 105.0, -335);
		glVertex3f(-545, 105.0, -335);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-545, 55.0, -337.5);
		glVertex3f(-547.5, 55.0, -337.5);
		glVertex3f(-547.5, 105.0, -337.5);
		glVertex3f(-545, 105.0, -337.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-545, 55.0, -335);
		glVertex3f(-545, 55.0, -337.5);
		glVertex3f(-545, 105.0, -337.5);
		glVertex3f(-545, 105.0, -335);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-547.5, 55.0, -337.5);
		glVertex3f(-547.5, 55.0, -337.5);
		glVertex3f(-547.5, 105.0, -337.5);
		glVertex3f(-547.5, 105.0, -337.5);
		glEnd();
	}
};
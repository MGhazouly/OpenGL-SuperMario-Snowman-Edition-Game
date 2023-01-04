#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "TextureBuilder.h"
#include "GLTexture.h"
#include <glut.h>
#include "Model_3DS.h"

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925);

GLTexture tex_ground;
GLTexture tex_ground1;
//GLTexture courtTexture;

// ------------------------------------------------------Round 1 Global Vars ------------------------------------------------//
int arrowCounter = 0;
float KeyX = 2.0;
float KeyY = 0.85;
float KeyZ = 0;
float x1 = 0;
//float y1 = 0;
float z1 = 0;
float ballX = 0.25;
bool finish = false;
bool found;
float rotateIce = 0.0;
float curveAngle = 90;
float speX = 0;
bool first = false;

void firstPerson(int);


float speY = 0;
float y_spe = 0;

float speZ = 0;

int arrow2_x = 0;
int arrow2_y = 0;
int arrow2_z = 0;

float BossEnemy = -25.0;
float BossEnemyZ = 0.4;

float BossEnemy2 = -45.0;
float BossEnemy2Z = 0.4;


float BossEnemy2_1 = -48.0;
float BossEnemy2_1Z = -0.4;

float PlayerArrowPosX = speX;
float PlayerArrowPosZ = speZ;



bool playerArrowState = false;
bool Enemy1Dead = false;

bool EndRound1 = false;
float EnemyObstacle1Z = -0.4;
float EnemyObstacle1_2Z = 0.4;


float EnemyObstacle2Z = 0.4;


float EnemyObstacle3Z = 0.0;
float EnemyObstacle3_2Z = -0.4;


float EnemyObstacle4Z = 0.4;
float EnemyObstacle4_2Z = -0.4;


float EnemyObstacle5X = -30.0;
float EnemyObstacle5Z = -0.4;

float EnemyObstacle6X = -30.0;
float EnemyObstacle6Z = 0.4;


float EnemyObstacle7Z = 0.0;
float EnemyObstacle7_2Z = 0.4;


float EnemyObstacle8Z = -0.4;
float EnemyObstacle8_2Z = 0.4;

float EnemyObstacle9X = -30.0;
float EnemyObstacle9Z = 0.0;

float EnemyObstacle10X = -30.0;
float EnemyObstacle10Z = 0.4;

float EnemyObstacle11Z = 0.0;

float arrow1Z = 0.0;
float arrow2Z = -0.4;
float arrow3Z = 0.4;
float arrow4Z = 0.0;
float arrow5Z = -0.4;

bool dead = false;
bool s1 = true;
bool s2 = true;
bool s3 = true;
bool s4 = true;
bool s5 = true;
bool s6 = true;
bool s7 = true;
bool s8 = true;
bool s9 = true;
bool s10 = true;
bool s11 = true;
bool s12 = true;
bool s13 = true;
bool s14 = true;
bool s15 = true;

//-----------------------------------------------------Round 2 Global Vars---------------------------------------------------//
void collisions2(int);
bool EndRound2 = false;

bool Enemy2Dead = false;
bool Enemy2_1Dead = false;

bool playerArrowState2 = false;

float PlayerArrowPosX2 = speX;
float PlayerArrowPosZ2 = speZ;

float FireObstacles1Z = 0.0;
float FireObstacles1_2Z = 0.4;

float FireObstacles2Z = 0.4;
float FireObstacles2_2Z = -0.4;

float FireObstacles3Z = 0.4;
float FireObstacles3_2Z = -0.4;

float FireObstacles4Z = 0.0;
float FireObstacles4_2Z = -0.4;

float FireObstacles5Z = 0.4;
float FireObstacles5_2Z = -0.4;

float FireObstacles6Z = 0.0;
float FireObstacles6_2Z = 0.4;

float FireObstacles7Z = 0.4;
float FireObstacles7_2Z = -0.4;

float FireObstacles8Z = 0.0;
float FireObstacles8_2Z = -0.4;

float FireObstacles9Z = -0.4;
float FireObstacles9_2Z = 0.4;

float L2Arrow1Z = -0.4;
float L2Arrow2Z = 0.0;
float L2Arrow3Z = 0.0;

float L2Arrow4Z = 0.4;
float L2Arrow5Z = 0.0;
float L2Arrow6Z = -0.4;

float L2Arrow7Z = 0.0;
float L2Arrow8Z = 0.4;
float L2Arrow9Z = 0.0;


bool change = false;



bool round1State = false;
bool jump = false;
void endRound1(int);
void drawObsticleTimer(int);

//sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

void courtTexture() {

	glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);	// Bind the ground texture

	glPushMatrix();

	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);	// Set quad normal direction.
	glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
	glVertex3f(-20, 0, -20);
	glTexCoord2f(5, 0);
	glVertex3f(20, 0, -20);
	glTexCoord2f(5, 5);
	glVertex3f(20, 0, 20);
	glTexCoord2f(0, 5);
	glVertex3f(-20, 0, 20);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

	glColor3f(1, 1, 1);	// Set material back to white instead of grey used for the ground texture.

}

void LoadAssets()
{
	//tex_ground.Load("Textures/ground.bmp");
	//loadBMP(&tex, "Textures/blu-sky-3.bmp", true);
	tex_ground.Load("Textures/pool2.bmp");
	tex_ground1.Load("Textures/FireTexture.bmp");

}


class Vector3f {
public:
	float x, y, z;

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f operator+(Vector3f& v) {
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}

	Vector3f operator-(Vector3f& v) {
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}

	Vector3f operator*(float n) {
		return Vector3f(x * n, y * n, z * n);
	}

	Vector3f operator/(float n) {
		return Vector3f(x / n, y / n, z / n);
	}

	Vector3f unit() {
		return *this / sqrt(x * x + y * y + z * z);
	}

	Vector3f cross(Vector3f v) {
		return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
};

void figure() {
	glPushMatrix();
	glTranslated(speX, y_spe, speZ);
	glRotated(curveAngle + 180, 0, 1, 0);
	glScaled(0.3 + 0.2, 0.5 + 0.2, 0.4 + 0.2);

	glPushMatrix();
	glTranslated(0, 0.15, 0);
	glScaled(0.8, 0.8, 0.8);
	glColor3f(1, 1, 1);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.18, .4, 50, 50);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0, 0.4 / 2, 0);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslated(0, 0.35, 0);
	glutSolidSphere(0.07, 15, 15);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0, .38, 0);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.06, .15, 50, 50);
	glPopMatrix();

	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslated(0, 0.53, 0);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0.05, 0.25, 0);
	glRotated(-30, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.025f, 0.025f, 0.15f, 20, 20);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(-0.18, 0.18, 0);
	glRotated(30, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.025f, 0.025f, 0.15f, 20, 20);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslated(0.03, 0.37, 0.06);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();


	glTranslated(-0.03, 0.37, 0.06);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();

	glTranslated(0.05, 0, 0);

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0, 0.05 / 2, 0);
	glScaled(1.5, 1, 1);
	glutSolidCube(0.05);
	glPopMatrix();

	glColor3f(0, 1, 0);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.025f, 0.025f, 0.15f, 20, 20);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	glTranslated(-0.05, 0, 0);

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0, 0.05 / 2, 0);
	glScaled(1.5, 1, 1);
	glutSolidCube(0.05);
	glPopMatrix();

	glColor3f(0, 1, 0);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.025f, 0.025f, 0.15f, 20, 20);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

void drawCylinder(float base, float top, float height) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, base, top, height, 32, 32);

}


void drawcylinder(float x, float y, float z) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, x, y, z, 32, 32);
}

void arrow1() {

	glPushMatrix();
	glScaled(0.01, 0.011, 0.014);
	glTranslatef(1, 6.5, 0);
	glRotated(curveAngle - 90, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();

	glTranslatef(1, 0.5, 0);
	glRotatef(0, 0.0, 1.0, 0.0); //rotate on the y axis
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);


	glPushMatrix();
	drawCylinder(0.4f, 0.4f, 6.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.8f);
	glRotatef(140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.8f);
	glRotatef(-140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}


void arrow2(int x, float y, float z) {

	glPushMatrix();


	glTranslated(x, y, z);



	glScaled(0.01, 0.011, 0.014);
	glTranslatef(arrow2_x + 9, arrow2_y + 6.5, arrow2_z);
	glRotated(curveAngle - 90, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();

	glTranslatef(arrow2_x + 1, arrow2_y + 0.5, arrow2_z);
	glRotatef(0, 0.0, 1.0, 0.0); //rotate on the y axis
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);


	glPushMatrix();
	drawCylinder(0.4f, 0.4f, 6.0f);

	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(-140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}
void arrowcollision() {
	if (speX == arrow2_x && speZ == arrow2_z) {
		arrowCounter += 1;
		arrow2(arrow2_x, arrow2_y, arrow2_z);
		glColor3f(0, 0, 255);
	}
}

void BlueArrow(int x, float y, float z) {

	glPushMatrix();


	glTranslated(x, y, z);



	glScaled(0.01, 0.011, 0.014);
	glTranslatef(arrow2_x + 9, arrow2_y + 6.5, arrow2_z);
	glRotated(curveAngle - 90, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();

	glTranslatef(arrow2_x + 1, arrow2_y + 0.5, arrow2_z);
	glRotatef(0, 0.0, 1.0, 0.0); //rotate on the y axis
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);


	glPushMatrix();
	drawCylinder(0.4f, 0.4f, 6.0f);

	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(-140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}




void present(int x, float y, float z) {
	glPushMatrix();


	glTranslated(x, y, z);
	glScalef(4, 3, 4);
	glPushMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.1 / 2, 0);
	glScaled(1, 1, 0.4);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslated(0, 0.1 / 2, 0.03);
	glScaled(1, 1, 0.2);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslated(0, 0.1 / 2, 0.03);
	glRotated(90, 0, 1, 0);
	glScaled(1, 1, 0.2);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.1 / 2, 0.06);
	glScaled(1, 1, 0.4);
	glutSolidCube(0.1);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.4, 0.5, 1);
	glTranslated(0, 0.1, 0.03);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

}
class Camera {
public:
	Vector3f eye, center, up;
	//gluLookAt(KeyX, KeyY, KeyZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Camera(float eyeX = KeyX, float eyeY = KeyY, float eyeZ = KeyZ, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
	}

	void moveX(float d) {
		Vector3f right = up.cross(center - eye).unit();
		eye = eye + right * d;
		center = center + right * d;
	}

	void moveY(float d) {
		eye = eye + up.unit() * d;
		center = center + up.unit() * d;
	}

	void moveZ(float d) {
		Vector3f view = (center - eye).unit();
		eye = eye + view * d;
		center = center + view * d;
	}

	void rotateX(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
		up = view.cross(right);
		center = eye + view;
	}

	void rotateY(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
		right = view.cross(up);
		center = eye + view;
	}

	void look() {
		gluLookAt(
			eye.x, eye.y, eye.z,
			center.x, center.y, center.z,
			up.x, up.y, up.z
		);
	}
};

Camera camera;


void gameover() {

	glPushMatrix();
	glTranslated(speX, 1, speZ);
	glPushMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0);

	char* p0s[5];
	sprintf((char*)p0s, "YOUR ARE DEAD ");
	//camera.moveX(2);
	//print(0, 0, 0, (char*)p0s);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();





}




void setupCamera() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 100);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.look();
}

void Anim() {

	std::cout << speY;
	if (jump == true && speY < 0.43) {
		speY += 0.43;
	}
	else {
		if ((speY >= 0.43)) {
			for (int i = 0; i < 8; i++) {
				std::cout << speY << "s";
				speY -= 0.05;
				std::cout << speY << "s";
				speX -= 0.1;
				PlayerArrowPosX -= 0.1;
				//camera.moveZ(0.02);
				curveAngle + 160;
				//speY -= 0.1;
				jump = false;
			}

		}
	}
	glutPostRedisplay();
}
void endRound1(int) {

	//	glutPostRedisplay();


	if (speX == 550) {

		round1State = true;
	}
	else if (speX < 550) {

		speX += -0.05;
		PlayerArrowPosX -= 0.05;
		PlayerArrowPosZ = speZ;
		camera.moveZ(0.052);
		camera.moveY(0.0217);

		//KeyY += 0.0;
	}

	if (speX == 55) {
		glutDestroyWindow(1280);
	}


	glutPostRedisplay();
	glutTimerFunc(1000 / 60, endRound1, 0);
}


void drawObsticle(int x, float y, float z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.3, 0.5, 0.3);
	glPushMatrix();

	glColor3f(0, 0.6, 0.1);
	glPushMatrix();
	glTranslated(-0.15, 0, -0.1);
	glPushMatrix();
	glColor3f(0.1786875, 0.3555625, 0.108375);
	glTranslated(0.15, 0.0, 0.15);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.15, 0.65, 30, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3000005, 0.50000125, 0.13003125);
	glTranslated(0.15, 0.25, 0.15);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.12, 0.4, 15, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3086875, 0.58803125, 0.14483125);
	glTranslated(0.15, 0.45, 0.15);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.07, 0.2, 8, 3);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 0.58984375, 0.1171875);
	glTranslated(0.15, 0.65, 0.15);
	glutSolidSphere(0.02, 50, 50);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}


void drawObsticleTimer(int) {

	//drawObsticle();
	//hena hanrandom el obstacle 
	//glutPostRedisplay();
	//glutTimerFunc(1000 / 60, drawObsticleTimer, 0);
}


void drawPoints(float x, float y, float z) {


	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.3, 0.3, 0.3);
	glPushMatrix();
	glColor3f(255, 255, 0);


	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glRotated(0, 1, 0, 0);
	glutSolidCone(0.02, .1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glRotated(72, 1, 0, 0);
	glutSolidCone(0.02, .1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glRotated(144, 1, 0, 0);
	glutSolidCone(0.02, .1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glRotated(216, 1, 0, 0);
	glutSolidCone(0.02, .1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glRotated(288, 1, 0, 0);
	glutSolidCone(0.02, .1, 50, 50);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}


void sun() {
	glPushMatrix();
	glColor3f(255, 255, 0);
	glTranslated(speX, 0.9, 0.65);
	glutSolidSphere(0.08, 10, 10);
	glPopMatrix();
}


void court() {

	glPushMatrix();
	//setupLights();
	//glColor3f(0, 0, 255);
	//glScalef(550, 0.1, 12);
	//glutSolidCube(0.1);
	//glPopMatrix();
	//glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	//glBindTexture(GL_TEXTURE_2D, tex_ground2.texture[0]);
	glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);
	glScalef(550, 0.1, 12);
	glutSolidCube(0.1);
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

}

void court2() {



	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);
	glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, tex_ground1.texture[0]);
	glTranslated(-55.0, 0.0, 0);
	glScalef(550, 0.1, 12);
	glutSolidCube(0.1);

	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}

void Bridge() {
	glPushMatrix();
	glColor3f(150, 75, 0);
	glTranslated(-27.25, 0.0, 0);
	glScalef(20, 0.1, 6);
	glutSolidCube(0.1);
	glPopMatrix();

	//glPushMatrix();
		//glColor3f(150, 75, 0);
		//glTranslated(-27.25, 0.0, -0.2);
		//glScalef(0.1, 1, 6);
		//glutSolidCube(0.1);
	//glPopMatrix();
}


void spe(int k, int x, int y) {
	if (k == GLUT_KEY_LEFT) {
		speZ += 0.4;
		camera.moveX(0.4);
	}
	if (k == GLUT_KEY_RIGHT) {
		speZ += -0.4;
		camera.moveX(-0.4);
	}
	if (k == GLUT_KEY_UP) {
		jump = true;
	}

	glutPostRedisplay();
}



void key(unsigned char k, int x, int y)
{

	if (k == 'f') {
		KeyX = 2;
		KeyY = 0.9;
		KeyZ = 0;
	}

	if (k == 's') {
		KeyX = -0.2;
		KeyY = 0.8;
		KeyZ = 2;

	}

	if (k == 't') {
		KeyX = 0;
		KeyY = 2;
		KeyZ = 1;
	}
	if (k == ' ') {
		if (arrowCounter > 0 && playerArrowState == false) {
			arrowCounter -= 1;
			playerArrowState = true;
			//playerArrowState2 = true;

			std::cout << "Arrows after shooting" << arrowCounter;
		}
	}
	//first person
	if (k == 'b') {
		change = true;
		//camera.moveX(0.1);
		camera.moveZ(speZ + 2.9);
		camera.moveY(speY + 0.4);

	}

	glutPostRedisplay();//redisplay to update the screen with the changes
}


void print(int x, int y, int z, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos3f(x, y, x);
	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
void pointCounter() {

	if (speX > -25 ) {
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(speX, speY + 1.2, 0.2);
		char* p0s[10];

		sprintf((char*)p0s, " LEVEL:1");
		print(0, 0, 0, (char*)p0s);
		glPopMatrix();
	}
	

	if (speX < -27) {


		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(speX, speY + 1.5, 0.2);
		camera.moveZ(0.006);
		camera.moveY(0.0017);
		
		//speX -= 0.0043;
		//PlayerArrowPosX -= 0.0043;
		char* p0s[10];

		sprintf((char*)p0s, " LEVEL:2");
		print(0, 0, 0, (char*)p0s);
		glPopMatrix();
	}

	if (dead == false) {
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(speX, 0.8, -0.2);
		char* p0s[10];

		sprintf((char*)p0s, "Arrow Collected : %d", arrowCounter);
		print(0, 0, 0, (char*)p0s);
		glPopMatrix();
	}



	if (dead == true) {
		glClearColor(1.f, 0.f, 1.f, 0.f);

		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(speX, 0.8, -0.2);
		char* p0s[10];

		sprintf((char*)p0s, " DEADDDDDD  Arrow Collected : %d", arrowCounter);
		print(0, 0, 0, (char*)p0s);
		glPopMatrix();
	}
	else if (dead == false && Enemy1Dead == true && Enemy2Dead == true && Enemy2_1Dead) {



		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(speX, 1, -0.2);
		char* p0s[10];

		sprintf((char*)p0s, " You Winnn");
		print(0, 0, 0, (char*)p0s);
		glPopMatrix();


		present(55, 0.0, 0.0);



	}


}




void won() {
	if (Enemy1Dead == true && Enemy2Dead == true && Enemy2_1Dead == true) {
		sndPlaySound(TEXT("win.WAV"), SND_ASYNC);

	}
}

void iceman1() {
	glPushMatrix();
	glTranslated(speX - 0.2, 0, speZ - 0.2);
	glRotated(curveAngle, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslated(0.5, 0, 0.5);
	glPushMatrix();
	glRotated(rotateIce, 0, 0, 1);
	glPushMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 0.05, 0);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 0.15, 0);
	glutSolidSphere(0.08, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 0.25, 0);
	glutSolidSphere(0.06, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.3, 0);
	glRotated(-90, 1, 0, 0);


	glutSolidCone(0.035, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.4, 0);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.26, 0);
	glutSolidCone(0.03, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0.035, 0.27, 0.04);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);


	glTranslated(-0.035, 0.27, 0.04);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void iceman2() {

	glPushMatrix();
	glTranslated(BossEnemy, 0.0, 0.80);
	glRotated(curveAngle, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslated(0.5, 0, 0.0);
	glPushMatrix();
	glRotated(rotateIce, 0, 0, 1);
	glPushMatrix();


	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.05, 0);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.15, 0);
	glutSolidSphere(0.08, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.25, 0);
	glutSolidSphere(0.06, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.3, 0);
	glRotated(-90, 1, 0, 0);


	glutSolidCone(0.035, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.4, 0);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.26, 0.0);
	glutSolidCone(0.03, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);


	glTranslated(-0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void Level2Iceman(int x) {

	glPushMatrix();
	glTranslated(x, 0.0, 0.80);
	glRotated(curveAngle, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslated(0.5, 0, 0.0);
	glPushMatrix();
	glRotated(rotateIce, 0, 0, 1);
	glPushMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0, 0.05, 0);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.15, 0);
	glutSolidSphere(0.08, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.25, 0);
	glutSolidSphere(0.06, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.3, 0);
	glRotated(-90, 1, 0, 0);


	glutSolidCone(0.035, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.4, 0);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.26, 0.0);
	glutSolidCone(0.03, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);


	glTranslated(-0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void Level2Iceman2(int x) {

	glPushMatrix();
	glTranslated(x, 0.0, 0.0);
	glRotated(curveAngle, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslated(0.5, 0, 0.0);
	glPushMatrix();
	glRotated(rotateIce, 0, 0, 1);
	glPushMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0, 0.05, 0);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.15, 0);
	glutSolidSphere(0.08, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.25, 0);
	glutSolidSphere(0.06, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(0, 0.3, 0);
	glRotated(-90, 1, 0, 0);


	glutSolidCone(0.035, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.4, 0);
	glutSolidSphere(0.02, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glTranslated(0, 0.26, 0.0);
	glutSolidCone(0.03, 0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);


	glTranslated(-0.035, 0.27, 0.0);
	glutSolidSphere(0.01, 15, 15);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}


void ice() {


	glPushMatrix();
	glColor3f(1, 1, 1);
	glutSolidSphere(.02, 15, 15);


	glPopMatrix();

}

void collisions(int) {

	glutPostRedisplay();
	glutTimerFunc(10, collisions, 0);

	std::cout << EndRound1;

	if (speX >= -5.0 && speX <= -4.9 && speZ == EnemyObstacle1Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}
	else if (speX >= -5.0 && speX <= -4.9 && speZ == EnemyObstacle1_2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -6.0 && speX <= -5.9 && speZ == EnemyObstacle2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -7.0 && speX <= -6.9 && speZ == EnemyObstacle3Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;		dead = true;
	}
	else if (speX >= -7.0 && speX <= -6.9 && speZ == EnemyObstacle3_2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -8.0 && speX <= -7.9 && speZ == EnemyObstacle4Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -8.0 && speX <= -7.9 && speZ == EnemyObstacle4_2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -9.0 && speX <= -8.9 && speZ == EnemyObstacle5Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}
	else if (speX >= -10.0 && speX <= -9.9 && speZ == EnemyObstacle6Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -11.0 && speX <= -10.9 && speZ == 0.0) { // hena msh byset el bool b true
		EndRound1 = true;

		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -11.0 && speX <= -10.9 && speZ == EnemyObstacle7_2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -12.0 && speX <= -11.9 && speZ == EnemyObstacle8_2Z) {
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -12.0 && speX <= -11.9 && speZ == EnemyObstacle8Z) {

		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;

	}

	else if (speX >= -13.0 && speX <= -12.9 && speZ == 0.0) { //hena msh byset el bool b true
		EndRound1 = true;
		std::cout << EndRound1;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		y_spe -= 2;
		dead = true;
	}

	else if (speX >= -14.0 && speX <= -13.9 && speZ == EnemyObstacle10Z) {
		EndRound1 = true;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		std::cout << EndRound1;
		y_spe -= 2;
		dead = true;
	}

}

void ArrowCollisions(int) {
	glutPostRedisplay();
	glutTimerFunc(50, ArrowCollisions, 0);

	if (speX >= -5.0 && speX <= -4.9 && speZ == arrow1Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -6.0 && speX <= -5.7 && speZ == arrow2Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -7.0 && speX <= -6.7 && speZ == arrow3Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -8.0 && speX <= -7.7 && speZ == arrow4Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -10.0 && speX <= -9.7 && speZ == arrow5Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}
}

void drawPlayerArrow() {
	glPushMatrix();


	glTranslated(PlayerArrowPosX, 0.1, PlayerArrowPosZ - 0.1);



	glScaled(0.01, 0.011, 0.014);
	glTranslatef(arrow2_x + 9, arrow2_y + 6.5, arrow2_z);
	glRotated(curveAngle + 100, curveAngle + 50, 1, 0);
	glPushMatrix();

	glPushMatrix();

	glTranslatef(arrow2_x + 1, arrow2_y + 0.5, arrow2_z);
	glRotatef(0, 0.0, 1.0, 0.0); //rotate on the y axis
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);


	glPushMatrix();
	drawCylinder(0.4f, 0.4f, 6.0f);

	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(-140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void L2drawPlayerArrow() {
	glPushMatrix();


	glTranslated(PlayerArrowPosX2, 0.1, PlayerArrowPosZ2 - 0.1);



	glScaled(0.01, 0.011, 0.014);
	glTranslatef(arrow2_x + 9, arrow2_y + 6.5, arrow2_z);
	glRotated(curveAngle + 100, curveAngle + 50, 1, 0);
	glPushMatrix();

	glPushMatrix();

	glTranslatef(arrow2_x + 1, arrow2_y + 0.5, arrow2_z);
	glRotatef(0, 0.0, 1.0, 0.0); //rotate on the y axis
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);


	glPushMatrix();
	drawCylinder(0.4f, 0.4f, 6.0f);

	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(arrow2_x, arrow2_y, arrow2_z + 5.8);
	glRotatef(-140, 1.0, 0.0, 0.0);
	drawCylinder(0.4f, 0.4f, 3.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void playerFireAnim(int) {

	glutPostRedisplay();


	if (playerArrowState == true) {
		PlayerArrowPosX -= 0.5;
		if (PlayerArrowPosX <= -60.0 && playerArrowState == true) {
			playerArrowState = false;
		}
	}

	glutTimerFunc(1, playerFireAnim, 0);
}

//||PlayerArrowPosX >= -24.0 && PlayerArrowPosX <= -55.0 && playerArrowState == true

void playerFireAnim2(int) {

	glutPostRedisplay();


	if (playerArrowState == true) {
		PlayerArrowPosX -= 0.5;
		if (PlayerArrowPosX <= -24.0 && playerArrowState == true) {
			playerArrowState = false;

		}
	}


	glutTimerFunc(1, playerFireAnim2, 0);
}




void PlayerArrowCollisions(int) {
	glutPostRedisplay();
	glutTimerFunc(10, PlayerArrowCollisions, 0);

	//std::cout << "Enemy1Dead: " << Enemy1Dead;

	if (PlayerArrowPosX >= -25.0 && PlayerArrowPosX <= -24.7 && (PlayerArrowPosZ) == (BossEnemyZ)) {
		sndPlaySound(TEXT("bullet.WAV"), SND_ASYNC);

		Enemy1Dead = true;
		BossEnemy = 500;
		playerArrowState = false;
		PlayerArrowPosX = speX;


		if (PlayerArrowPosX <= -25.0 && Enemy1Dead == false) {
			playerArrowState = false;
			PlayerArrowPosX = speX;
		}

		if (speX >= -25.0 && speX <= -24.7 && Enemy1Dead == false) {
			EndRound1 = true;
			//speX = 500;
		}
	}

	if (Enemy1Dead == true && PlayerArrowPosX >= -45.0 && PlayerArrowPosX <= -44.0 && PlayerArrowPosZ == -0.4) {
		Enemy2Dead = true;
		//playerArrowState = false;
		PlayerArrowPosX = speX;

		if (PlayerArrowPosX <= -45.0 && Enemy2Dead == false && playerArrowState == true) {
			playerArrowState = false;
			PlayerArrowPosX = speX;
		}

		if (speX >= -45.0 && speX <= -44.7 && Enemy2Dead == false) {
			EndRound2 = false;
		}
	}




}

void L2PlayerArrowCollisions(int) {
	glutPostRedisplay();
	glutTimerFunc(10, L2PlayerArrowCollisions, 0);

	//std::cout << "Enemy1Dead: " << Enemy1Dead;

	if (PlayerArrowPosX >= -45.0 && PlayerArrowPosX <= -44.0 && (PlayerArrowPosZ) == (BossEnemy2Z)) {
		sndPlaySound(TEXT("bullet.WAV"), SND_ASYNC);

		Enemy2Dead = true;
		BossEnemy2 = 500;
		playerArrowState = false;
		PlayerArrowPosX = speX;


		std::cout << "Enemy1Dead: " << Enemy1Dead;
	}

	if (PlayerArrowPosX <= -55.0 && Enemy2Dead == false) {
		playerArrowState = false;
		PlayerArrowPosX = speX;
	}

	if (speX >= -45.0 && speX <= -44.7 && Enemy2Dead == false) {
		EndRound2 = true;
		//speX = 500;
	}

	if (PlayerArrowPosX >= -48.0 && PlayerArrowPosX <= -47.0 && (PlayerArrowPosZ) == (BossEnemy2_1Z)) {
		sndPlaySound(TEXT("bullet.WAV"), SND_ASYNC);

		Enemy2_1Dead = true;
		BossEnemy2_1 = 500;
		playerArrowState = false;
		PlayerArrowPosX = speX;


		std::cout << "Enemy1Dead: " << Enemy1Dead;
	}

	if (PlayerArrowPosX <= -55.0 && Enemy2_1Dead == false) {
		playerArrowState = false;
		PlayerArrowPosX = speX;
	}

	if (speX >= -48.0 && speX <= -47.7 && Enemy2_1Dead == false) {
		EndRound2 = true;
		//speX = 500;
	}

}

void L2ArrowCollisions(int) {
	glutPostRedisplay();
	glutTimerFunc(50, L2ArrowCollisions, 0);

	if (speX >= -30.0 && speX <= -29.7 && speZ == L2Arrow1Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -31.0 && speX <= -30.7 && speZ == L2Arrow2Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -32.0 && speX <= -31.7 && speZ == L2Arrow3Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -33.0 && speX <= -32.7 && speZ == L2Arrow4Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -34.0 && speX <= -33.7 && speZ == L2Arrow5Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -35.0 && speX <= -34.7 && speZ == L2Arrow6Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -36.0 && speX <= -35.7 && speZ == L2Arrow7Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -37.0 && speX <= -36.7 && speZ == L2Arrow8Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}

	else if (speX >= -38.0 && speX <= -37.7 && speZ == L2Arrow9Z) {
		arrowCounter += 1;
		std::cout << "Arrows: " << arrowCounter;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.WAV"), SND_ASYNC);
	}
}

void collisions2(int) {

	glutPostRedisplay();
	glutTimerFunc(10, collisions2, 0);

	if (speX >= -30.0 && speX <= -29.7 && (speZ >= FireObstacles1Z && speZ <= FireObstacles1Z + 1.3 ||
		speZ == FireObstacles1_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -31.0 && speX <= -30.7 && (speZ >= FireObstacles2Z && speZ <= FireObstacles2Z + 1.3 ||
		speZ == FireObstacles2_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -32.0 && speX <= -31.7 && (speZ >= FireObstacles3Z && speZ <= FireObstacles3Z + 1.3 ||
		speZ == FireObstacles3_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -33.0 && speX <= -32.7 && (speZ == FireObstacles4Z ||
		speZ == FireObstacles4_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -34.0 && speX <= -33.7 && (speZ >= FireObstacles5Z && speZ <= FireObstacles5Z + 1.3 ||
		speZ == FireObstacles5_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -35.0 && speX <= -34.7 && (speZ >= FireObstacles6Z && speZ <= FireObstacles6Z + 1.3 ||
		speZ == FireObstacles6_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -36.0 && speX <= -35.9 && (speZ == FireObstacles7_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -37.0 && speX <= -36.7 && (speZ == FireObstacles8_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}

	else if (speX >= -38.0 && speX <= -37.7 && (speZ == FireObstacles9Z || speZ == FireObstacles9_2Z)) {
		EndRound2 = true;
		std::cout << "Round 2 Done: " << EndRound2;
		sndPlaySound(TEXT("mixkit-truck-crash-with-explosion-1616.WAV"), SND_ASYNC);
		speY -= 2;
		dead = true;
	}


}



void setupLights() {

	GLfloat mat_specular[] = { 5.0, 3.0, 4.0, 3.0 };
	GLfloat mat_shininess[] = { 70.0 };
	GLfloat light_position[] = { 12.0, 2.0, 20.0, 2.0 };
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}


void Display() {

	setupCamera();
	setupLights();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	drawObsticle(-5.0, 0.0, EnemyObstacle1Z);
	drawObsticle(-5.0, 0.0, EnemyObstacle1_2Z);
	drawObsticle(-6.0, 0.0, EnemyObstacle2Z);
	drawObsticle(-7.0, 0.0, EnemyObstacle3Z);
	drawObsticle(-7.0, 0.0, EnemyObstacle3_2Z);
	drawObsticle(-8.0, 0.0, EnemyObstacle4Z);
	drawObsticle(-8.0, 0.0, EnemyObstacle4_2Z);
	drawObsticle(-9.0, 0.0, EnemyObstacle5Z);
	drawObsticle(-10.0, 0.0, EnemyObstacle6Z);
	drawObsticle(-11.0, 0.0, EnemyObstacle7Z);
	drawObsticle(-11.0, 0.0, EnemyObstacle7_2Z);
	drawObsticle(-12.0, 0.0, EnemyObstacle8Z);
	drawObsticle(-12.0, 0.0, EnemyObstacle8_2Z);
	drawObsticle(-13.0, 0.0, EnemyObstacle9Z);
	drawObsticle(-14.0, 0.0, EnemyObstacle10Z);


	arrow2(-5.0, 0, arrow1Z);
	arrow2(-6.0, 0, arrow2Z);
	arrow2(-7.0, 0, arrow3Z);
	arrow2(-8.0, 0, arrow4Z);
	arrow2(-10.0, 0, arrow5Z);

	courtTexture();
	court();
	court2();
	Bridge();
	figure();
	iceman2();
	pointCounter();
	//	won();
	drawPlayerArrow();


	if (Enemy1Dead == true && Enemy2Dead == true && Enemy2_1Dead == true) {
		present(-52, 0, 0);
		sndPlaySound(TEXT("win.WAV"), SND_ASYNC);

	}

	sun();
	arrowcollision();
	gameover();

	//Round 2

	drawObsticle(-30.0, 0.0, FireObstacles1Z);
	drawObsticle(-30.0, 0.0, FireObstacles1_2Z);

	drawObsticle(-31.0, 0.0, FireObstacles2Z);
	drawObsticle(-31.0, 0.0, FireObstacles2_2Z);

	drawObsticle(-32.0, 0.0, FireObstacles3Z);
	drawObsticle(-32.0, 0.0, FireObstacles3_2Z);

	drawObsticle(-33.0, 0.0, FireObstacles4Z);
	drawObsticle(-33.0, 0.0, FireObstacles4_2Z);

	drawObsticle(-34.0, 0.0, FireObstacles5Z);
	drawObsticle(-34.0, 0.0, FireObstacles5_2Z);

	drawObsticle(-35.0, 0.0, FireObstacles6Z);
	drawObsticle(-35.0, 0.0, FireObstacles6_2Z);

	drawObsticle(-36.0, 0.0, FireObstacles7Z);
	drawObsticle(-36.0, 0.0, FireObstacles7_2Z);

	drawObsticle(-37.0, 0.0, FireObstacles8Z);
	drawObsticle(-37.0, 0.0, FireObstacles8_2Z);

	drawObsticle(-38.0, 0.0, FireObstacles9Z);
	drawObsticle(-38.0, 0.0, FireObstacles9_2Z);

	//Round 2 Arrows
	BlueArrow(-30.0, 0.0, L2Arrow1Z);
	BlueArrow(-31.0, 0.0, L2Arrow2Z);
	BlueArrow(-32.0, 0.0, L2Arrow3Z);

	BlueArrow(-33.0, 0.0, L2Arrow4Z);
	BlueArrow(-34.0, 0.0, L2Arrow5Z);
	BlueArrow(-35.0, 0.0, L2Arrow6Z);

	BlueArrow(-36.0, 0.0, L2Arrow7Z);
	BlueArrow(-37.0, 0.0, L2Arrow8Z);
	BlueArrow(-38.0, 0.0, L2Arrow9Z);

	Level2Iceman(BossEnemy2);
	Level2Iceman2(BossEnemy2_1);

	glFlush();
}




void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("super-boda.exe");
	glutDisplayFunc(Display);
	glutSpecialFunc(spe);
	glutTimerFunc(0, collisions, 0);
	glutTimerFunc(0, collisions2, 0);
	glutTimerFunc(0, ArrowCollisions, 0);
	glutTimerFunc(0, L2ArrowCollisions, 0);

	glutTimerFunc(0, L2PlayerArrowCollisions, 0);
	glutTimerFunc(0, playerFireAnim, 0);
	//glutTimerFunc(0, playerFireAnim2, 0);

	//glutTimerFunc(0, L2playerFireAnim, 0);
	glutTimerFunc(0, PlayerArrowCollisions, 0);
	//glutTimerFunc(0, L2PlayerArrowCollisions, 0);
	glutIdleFunc(Anim);
	LoadAssets();
	glutTimerFunc(0, endRound1, 0);

	glutTimerFunc(0, drawObsticleTimer, 0);
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glutKeyboardFunc(key);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glViewport(0, 0, 900, 600);  // x y width height
	//glutTimerFunc(0, time, 0);
	glutMainLoop();
}
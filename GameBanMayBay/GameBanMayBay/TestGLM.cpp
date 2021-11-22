#include "glm.h"
using namespace std;

#include "GL/freeglut.h"
#include <string>
#include <string.h>
#define PI 3.14159265358
#define W 640
#define H 640

const GLfloat factor = 5;

GLMmodel *pmodel;

void DrawAxis() {
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(factor, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, factor, 0);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, factor);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(50, 0, 50, 0, 0, 0, 0, 1, 0);

	DrawAxis();
	glColor3f(0, 1, 1);
	glScalef(0.05f, 0.05f, 0.05f);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);

	glutSwapBuffers();
}

void init() {
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);

	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, W * 1.0 / H, 1, 1000);

}

int main(int argc, char* agrv[]) {
	glutInit(&argc, agrv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("window");

	glutDisplayFunc(display);
	string path = "Resource/OBJ/dolphins.obj";
	char* ch = &path[0];
	pmodel = glmReadOBJ(ch);

	init();

	glutMainLoop();
}
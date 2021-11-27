#include "glm.h"
#include "GL/freeglut.h"
#include <string>
#include <string.h>
#define W 640
#define H 640

using namespace std;

GLMmodel *pmodel;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(50, 0, 50, 0, 0, 0, 0, 1, 0);


	glColor3f(0, 1, 1);
	glScalef(0.05f, 0.05f, 0.05f);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* agrv[]) {
	glutInit(&argc, agrv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("window");

	string path = "Resource/OBJ/dolphins.obj";
	char* ch = &path[0];
	pmodel = glmReadOBJ(ch);


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
}
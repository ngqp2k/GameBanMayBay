#include "GL/freeglut.h"

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Code hien thi
	glColor3f(1, 1, 1);
	glutWireTeapot(0.5);

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test freeglut");

	glutDisplayFunc(myDisplay);

	glutMainLoop();
}
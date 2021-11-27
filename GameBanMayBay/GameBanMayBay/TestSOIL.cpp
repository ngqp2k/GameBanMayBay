#include "GL/freeglut.h"
#include <stdio.h>
#include "SOIL/SOIL.h"
#pragma comment(lib, "SOIL.lib")
#define PI 3.14159265358
#define W 640
#define H 640

GLuint texture; 


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// DrawAxis();
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex2f(-1, -0.56);
		glTexCoord2f(1, 0); glVertex2f(1, -0.56);
		glTexCoord2f(1, 1); glVertex2f(1, 0.56);
		glTexCoord2f(0, 1); glVertex2f(-1, 0.56);
	glEnd();

	glutSwapBuffers();
}

void init() {
	glClearColor(0, 0, 0, 1);

	glEnable(GL_TEXTURE_2D);

	texture = SOIL_load_OGL_texture
		(
			"Resource/Image/image.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	if(!texture)
	{
		printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
	} else {
		printf( "Load thanh cong\n");
		printf("%d", texture);
	}
}


int main(int argc, char* agrv[]) {
	glutInit(&argc, agrv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test SOIL");

	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
#include<stdio.h>
#include<GL/glut.h>
#include "vec.h"
void init();
void display();
void translate();
void plotPoints();
vec1 a = vec1(30.0,40.0);
void init() {
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200,0,200);
}

void plotPoints() {
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(a.x,a.y);
	glEnd();
}

void translate() {
	GLfloat tx = 23.0,ty = 34.0;
	glColor3f(1.0,0.0,0.0);
	plotPoints();
	a.x = a.x + tx;
	a.y = a.y + ty;
	glColor3f(0.0,0.0,1.0);
	plotPoints();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	translate();
	glFlush();
}
int main(int argc, char *argv[]) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Transformation of a point");
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}

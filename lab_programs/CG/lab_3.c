#include<stdio.h>
#include<GL/glut.h>

int main(int argc, char *argv[])
{
	GLfloat vertices[][3] = 	{{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
								{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
								{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

	GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
			{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
			{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
}

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube( )
{
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygo n(0,1,5,4);
}

void display(void)
{
	/* display callback, clear frame buffer and z buffer,
	rotate cube and draw, swap buffers */glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	colorcube();
	glutSwapBuffers();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
}

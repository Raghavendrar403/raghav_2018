#include<GL/glut.h>
#include<iostream>
int n;
GLfloat vr1[4][3];
void tetrahedron(int, GLfloat*);
void myinit();
void display();
void traingle(GLfloat *, GLfloat *, GLfloat *);
void divide_traingle(GLfloat *, GLfloat *, GLfloat *, int);
void myinit() {
        glClearColor(1.0,1.0,1.0,1.0);
        glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
        GLfloat v[4][3] = {{0,0,1},{0,0.94,-0.33},{-0.81,-0.47,-0.33},{0.81,-0.47,-0.33}};
        for(int i = 0; i<4; i++)
                for(int j = 0; j<3; j++)
                        vr1[i][j] = v[i][j];
}
using namespace std;

void tetrahedron(int m, GLfloat v[4][3]) {
        glColor3f(1.0,0.0,0.0);
        divide_traingle(v[0],v[1],v[2],m-1);
        glColor3f(0.0,1.0,0.0);
        divide_traingle(v[0],v[3],v[1],m-1);
        glColor3f(0.0,0.0,1.0);
        divide_traingle(v[0],v[3],v[2],m-1);
        glColor3f(0.0,0.0,0.0);
        divide_traingle(v[3],v[2],v[1],m-1);
}
void display() {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        tetrahedron(n, vr1);
        glFlush();
}

void traingle(GLfloat *a, GLfloat *b, GLfloat *c) {
        glBegin(GL_POLYGON);
        glVertex2fv(a);
        glVertex2fv(b);
        glVertex2fv(c);
        glEnd();
}

void divide_traingle(GLfloat *a,GLfloat *b,GLfloat *c, int m) {
        GLfloat v1[3], v2[3], v3[3];
        int j=0;
        if(m>0) {
                for(j=0; j<3; j++) v1[j] = (a[j]+b[j])/2;
                for(j=0; j<3; j++) v2[j] = (a[j]+c[j])/2;
                for(j=0; j<3; j++) v3[j] = (c[j]+b[j])/2;
                divide_traingle(a,v2,v1,m-1);
                divide_traingle(b,v3,v1,m-1);
                divide_traingle(c,v3,v2,m-1);
        }
        else
                traingle(a,b,c);
}
int main(int argc, char **argv) {
        std::cout << "Enter the number of recursions: ";
        std::cin >> n;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(500,500);
        glutCreateWindow("3D Gasket");
        glutDisplayFunc(display);
        myinit();
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
}

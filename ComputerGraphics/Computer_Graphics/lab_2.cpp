#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

/* Set initial display window size*/
GLsizei winWidth = 600, winHeight = 600;

/* Set range for world coorinates*/
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D {
	public: GLfloat x,y;
};

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;
GLdouble theta;
const GLdouble pi = 3.14159;
void init(void);
void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2);
void matrix3x3SetIdentity(Matrix3x3 matIden3x3);
void translate2D(GLfloat tx, GLfloat ty);
void rotate2D(wcPt2D pivotPt, GLfloat theta);
void display();
void transformVerts2D(GLint nVerts, wcPt2D *verts);
void traingle(wcPt2D *verts);
void init(void) {
	/* Set the color of the display window to white */
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
}

/* Construct the 3x3 identity matrix */
void matrix3x3SetIdentity(Matrix3x3 matIden3x3) {
	GLint row, col;

	for(row = 0; row<3; row++) {
		for(col = 0; col<3; col++) {
			matIden3x3[row][col] = (row == col);
		}
	}
}

/* Premultiply Matrix m1 times m2 and store the result in m2.*/
void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2) {
	GLint row, col;
	Matrix3x3 matTemp;
	int k = 0;
	////printf("M1\n");
	for(k = 0; k<3; k++)
	 //printf("%f %f %f\n",m1[k][0], m1[k][1], m1[k][2]);
	//printf("M2\n");
	for(k = 0; k<3; k++)
	 //printf("%f %f %f\n",m2[k][0], m2[k][1], m2[k][2]);
	for(row = 0; row<3; row++)
		for(col = 0; col<3; col++) {
			matTemp[row][col] = m1[row][0] * m2[0][col] + m1[row][1]*m2[1][col] + m1[row][2]*m2[2][col];
			//printf("in Matrix Mul %f %d %d\n", matTemp[row][col],row,col);
		}

	
	for(row = 0; row<3; row++) {
		for(col = 0; col < 3; col++)
			m2[row][col] = matTemp[row][col];
	}
}

void translate2D(GLfloat tx, GLfloat ty) {
	Matrix3x3 matTrans1;
	matrix3x3SetIdentity(matTrans1);
	matTrans1[0][2] = tx;
	matTrans1[1][2] = ty;

	matrix3x3PreMultiply(matTrans1, matComposite);
}

void rotate2D(wcPt2D pivotPt, GLfloat theta1) {
	Matrix3x3 matRot;
	matrix3x3SetIdentity(matRot);

	matRot[0][0] = cos(theta1);
	matRot[0][1] = -sin(theta1);
	matRot[0][2] = pivotPt.x * (1-cos(theta1)) + pivotPt.y * sin(theta1);
	matRot[1][0] = sin(theta1);
	matRot[1][1] = cos(theta1);
	matRot[1][2] = pivotPt.y * (1-cos(theta1)) + pivotPt.x * sin(theta1);

	matrix3x3PreMultiply(matRot, matComposite);
}

void traingle(wcPt2D *verts) {
	GLint k;
	//printf("NIGGA\n");
	//printf("%f %f\n",verts[0].x, verts[0].y);
	//printf("%f %f\n",verts[1].x, verts[1].y);
	//printf("%f %f\n",verts[2].x, verts[2].y);
	glBegin(GL_TRIANGLES);
	glVertex2f(verts[0].x, verts[0].y);
	glVertex2f(verts[1].x, verts[1].y);
	glVertex2f(verts[2].x, verts[2].y);
	glEnd();
	//printf("CHigga\n");
}

void display() {
	/* Define the initial position for traingle*/
	wcPt2D verts[3] = {{50.0,25.0}, {75.0, 25.0}, {60.0,60.0}};
	GLint nVerts = 3;
	/* Calculate the position of the traingle centroid*/
	wcPt2D centroidPt;
	GLint k, xSum = 0, ySum = 0;
	for(k = 0; k<nVerts; k++) {
		xSum += verts[k].x;
		ySum += verts[k].y;
	}
	
	centroidPt.x = (GLfloat) xSum / (GLfloat) nVerts;
	centroidPt.y = (GLfloat) ySum / (GLfloat) nVerts;

	/* Set  geometric transformation parameters. */
	wcPt2D pivPt, fixedPt;

	GLfloat tx = 0.0, ty = 100.0;

	glClear(GL_COLOR_BUFFER_BIT);

	/* Display a blue traingle*/
	glColor3f(0.0,0.0,0.1);
	traingle(verts);
	
	/* Inititialize composite matrix to identity*/
	matrix3x3SetIdentity(matComposite);

	///* Construct the tranformed matrix*/
//	theta = pi / 2.0;
	pivPt.x = 0.0;
	pivPt.y = 0.0;
	tx = -centroidPt.x;
	ty = -centroidPt.y;
	translate2D(tx,ty);
	rotate2D(pivPt, theta);
	translate2D(-tx,-ty);


	///* The Final Matrix*/
	transformVerts2D(nVerts, verts);

	glColor3f(1.0,0.0,0.0);
	traingle(verts);
	glFlush();
}

void transformVerts2D(GLint nVerts, wcPt2D * verts) {
	GLint k;
	GLfloat temp;

	for(k = 0; k<nVerts; k++) {
		temp = matComposite[0][0] * verts[k].x + matComposite[0][1]*verts[k].y + matComposite[0][2];
		verts[k].y = matComposite[1][0] * verts[k].x + matComposite[1][1] * verts[k].y + matComposite[1][2];
		verts[k].x = temp;
	}
}


//void winReshapeFunc(GLint newWidth, newHeight) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
//	glClear(GL_COLOR_BUFFER_BIT);
//}

int main(int argc, char *argv[]) {
	GLint theta2;
	printf("Enter the angle about which you want to rotate: ");
	scanf("%d",&theta2);
	theta = (double) theta2 * pi / (double) 180.0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Lab_2 - Rotating a traingle about a fixed point");
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(winReshapeFunc);
	glutMainLoop();
	return 0;
}

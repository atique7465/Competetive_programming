#include <stdio.h>
#include<glut.h>

void display(void)
{
	glBegin(GL_TRIANGLES);
		glVertex2f(0,0);
		glVertex2f(.15,.15);
		glVertex2f(-.15,.15);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Lab-1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
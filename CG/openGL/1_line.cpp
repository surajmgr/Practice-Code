#include<GL/glut.h>

using namespace std;

void init(void){
  glClearColor(0.0,0.0,0.0,1.0); //Black Color
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,150.0);
}

void lineSegment(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINES);
  glVertex2i(180,15);
  glVertex2i(10,145);
  glEnd();
  glFlush();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("Drawing Line using GLUT OpenGL");
  init();
  glutDisplayFunc(lineSegment);
  glutMainLoop();
  return 0;
}
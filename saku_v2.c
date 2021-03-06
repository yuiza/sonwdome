//snow dome

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
#define KEY_ESC 27

double theta = 0.0;

double vertex[][3] = {

{ -0.5, -0.5, -1.0 },
  { 0.5, -0.5, -1.0 },
  { 0.5, 0.5, -1.0 },
  { -0.5, 0.5, -1.0 },
  { -0.5, -0.5, -1.5 },
  { 0.5, -0.5, -1.5 },
  { 0.5, 0.5, -1.5 },
  { -0.5, 0.5, -1.5 }

};

int edge[][2] = {
  { 0, 1 },
  { 1, 2 },
  { 2, 3 },
  { 3, 0 },
  { 4, 5 },
  { 5, 6 },
  { 6, 7 },
  { 7, 4 },
  { 0, 4 },
  { 1, 5 },
  { 2, 6 },
  { 3, 7 }
};

int face[][4] = {
  { 0, 1, 2, 3},
  { 1, 5, 6, 2},
  { 5, 4, 7, 6},
  { 4, 0, 3, 7},
  { 4, 5, 1, 0},
  { 3, 2, 6, 7}
};


void display(void){
  int i;
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
 
  glTranslatef(0.0, 0.0, -5.0);
  gluLookAt(0.8,-0.7,0.0,  0.0,0.0,0.0, 0,0,1);
  glRotatef(theta, 0.0, 0.0, 1.0);

  glEnable(GL_BLEND);
  //描写図形↓

  //外側球
  glColor4f(1.0, 1.0, 1.0, 0.3);
  glutWireSphere(1.2, 20.0, 20.0);

  glEnd();
  glDisable(GL_BLEND);


 //台座
 glBegin(GL_QUADS);
 //glBegin(GL_LINE);
  for(i=0; i<4; ++i){
	glColor4f(0.5, 0.0, 0.0, 1.0);
	glVertex3dv(vertex[face[0][i]]);
  }
  for(i=0; i<4; ++i){
	glColor4f(0.5, 0.3, 0.0, 1.0);
	glVertex3dv(vertex[face[1][i]]);
  }
  for(i=0; i<4; ++i){
	glColor4f(0.5, 0.0, 0.3, 1.0);
	glVertex3dv(vertex[face[2][i]]);
  }
  for(i=0; i<4; ++i){
	//glColor4f(0.5, 0.0, 0.0, 1.0);
	glVertex3dv(vertex[face[3][i]]);
  }
  for(i=0; i<4; ++i){
	glColor4f(0.5, 0.4, 0.1, 1.0);
	glVertex3dv(vertex[face[4][i]]);
  }
  for(i=0; i<4; ++i){
	glColor4f(0.5, 0.3, 0.7, 1.0);
	glVertex3dv(vertex[face[5][i]]);
  }
  glEnd();
  glDisable(GL_DEPTH_TEST);
 

 
  glEnable(GL_BLEND);
 
  glTranslatef(0.0, 0.0, -0.5);
  glColor4f(1.0, 1.0, 1.0, 1.3);
  glutSolidSphere(0.5, 20.0, 20.0);
  glEnd();

  glTranslatef(0.0, 0.0, 0.6);
  glColor4f(1.0, 1.0, 1.0, 1.3);
  glutSolidSphere(0.4, 20.0, 20.0);
  glEnd();

  glDisable(GL_BLEND); 

 glEnable(GL_DEPTH_TEST);
 

  
  //ここまで
  glPopMatrix();
  glutSwapBuffers();
}

void myKbd(unsigned char key, int x, int y){
  if(key == KEY_ESC)
	exit(0);
}

void idle(void){
  theta = fmod(theta + 0.1, 360.0);
  glutPostRedisplay(); 
}

void init(void){
  int width = 500, height = 500;
  float aspect = (float)width / (float)height; 
  
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//透明描写関数
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glutKeyboardFunc(myKbd); 
  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0, aspect, 1.0, 7.0); 
}

int main(int argc, char *argv[]){ 
  glutInitWindowSize(600, 600); 
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
  glutCreateWindow(argv[0]); 
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  init();
  glutMainLoop();
  
  return 0;
}

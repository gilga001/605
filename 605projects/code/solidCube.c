// solid 3D unit cube with one vertex at the origin 
#include<iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp> 
#include <glm/gtx/quaternion.hpp>

struct point {
	float x, y, z;
	};

void do_viewvolume()
{
struct point eye;
struct point view;
struct point up;

// specify size and shape of view volume 
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,1.0,0.1,20.0);

// specify position for view volume 
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
eye.x = 2.0; eye.y = 2.0; eye.z = 2.0;
view.x = 0.0; view.y = 0.0; view.z = 0.0;
up.x = 0.0; up.y = 1.0; up.z = 0.0;
gluLookAt(eye.x,eye.y,eye.z,view.x,view.y,view.z,up.x,up.y,up.z);
}

void draw_stuff()
{
int i;
struct point front[4]={{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};
struct point back[4]={{0.0,0.0,0.0},{0.0,1.0,0.0},{1.0,1.0,0.0},{1.0,0.0,0.0}};
struct point left[4]={{0.0,0.0,0.0},{0.0,0.0,1.0},{0.0,1.0,1.0},{0.0,1.0,0.0}};
struct point right[4]={{1.0,0.0,0.0},{1.0,1.0,0.0},{1.0,1.0,1.0},{1.0,0.0,1.0}};
struct point top[4]={{0.0,1.0,0.0},{0.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,0.0}};
struct point bottom[4]={{0.0,0.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,0.0,0.0}};

glEnable(GL_DEPTH_TEST);
glEnable(GL_MULTISAMPLE_ARB);

glClearColor(0.35,0.35,0.35,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glBegin(GL_QUADS); 
glNormal3f(0.0,0.0,1.0);
for(i=0;i<4;i++) glVertex3f(front[i].x,front[i].y,front[i].z);
glNormal3f(0.0,0.0,-1.0);
for(i=0;i<4;i++) glVertex3f(back[i].x,back[i].y,back[i].z);
glNormal3f(-1.0,0.0,0.0);
for(i=0;i<4;i++) glVertex3f(left[i].x,left[i].y,left[i].z);
glNormal3f(1.0,0.0,0.0);
for(i=0;i<4;i++) glVertex3f(right[i].x,right[i].y,right[i].z);
glNormal3f(0.0,1.0,0.0);
for(i=0;i<4;i++) glVertex3f(top[i].x,top[i].y,top[i].z);
glNormal3f(0.0,-1.0,0.0);
for(i=0;i<4;i++) glVertex3f(bottom[i].x,bottom[i].y,bottom[i].z);
glEnd();
glFlush();
}

void rotate_vector_by_quaternion(const glm::vec3& v, const glm::quat& q, glm::vec3& ret)
{
    glm::vec3 u(q.x, q.y, q.z);
    float s = q.w;
    ret = 2.0f * glm::dot(u, v) * u
          + (s*s - glm::dot(u, u)) * v
          + 2.0f * s * glm::cross(u, v);
}

void do_lights()
{
//     glm::vec4 vec(1.0f,0.0f,0.0f,0.0f);
//     glm::mat4 trans;
//     trans =glm::translate(trans,glm::vec3(1.0f,1.0f,0.0f));
//     vec=trans*vec;
//     std::cout<<vec.x<<vec.y<<vec.z<<std::endl;
    glm::vec3 camera(.5,.5,2.0);
    glm::vec3 center(0.5,0.5,0.5);
    glm::vec3 V=camera-center;
    glm::vec3 up(0,0.5,0);
    glm::vec3 cross=glm::normalize(glm::cross(V,up));
    
    //first rotate degree
    glm::quat q15;
    q15=glm::angleAxis(glm::degrees(45.f),cross);
    glm::vec3 keyFirstV;
    rotate_vector_by_quaternion(V,q15,keyFirstV);
    std::cout<<"keyFirstV"<<keyFirstV.x<<","<<keyFirstV.y<<","<<keyFirstV.z<<std::endl;

    glm::quat q25;
    q25=glm::angleAxis(glm::degrees(-45.f),up);
    glm::vec3 keySecondV;
    rotate_vector_by_quaternion(keyFirstV,q25,keySecondV);
    float offsetKey=1.5;
    keySecondV.z+=offsetKey;
    std::cout<<"keySecondV"<<keySecondV.x<<","<<keySecondV.y<<","<<keySecondV.z<<std::endl;
    
    
    glm::quat q5;
    q5=glm::angleAxis(glm::degrees(20.f),cross);
    glm::vec3 fillFirstV;
    rotate_vector_by_quaternion(V,q5,fillFirstV);
    std::cout<<"fillFirstV"<<fillFirstV.x<<","<<fillFirstV.y<<","<<fillFirstV.z<<std::endl;

    glm::quat q45;
    q45=glm::angleAxis(glm::degrees(30.f),up);
    glm::vec3 fillSecondV;
    rotate_vector_by_quaternion(fillFirstV,q45,fillSecondV);
    float offsetFill=2.5;
    fillSecondV.z+=offsetFill;
    std::cout<<"fillSecondV"<<fillSecondV.x<<","<<fillSecondV.y<<","<<fillSecondV.z<<std::endl;

    
    glm::quat q30;
    q30=glm::angleAxis(glm::degrees(30.f),cross);
    glm::vec3 rimFirstV;
    rotate_vector_by_quaternion(V,q30,rimFirstV);
    std::cout<<"rimFirstV"<<rimFirstV.x<<","<<rimFirstV.y<<","<<rimFirstV.z<<std::endl;

   
    glm::vec3 rimSecondV(rimFirstV.x,rimFirstV.y,-rimFirstV.z);
    float offsetRim=-1.5;
    rimSecondV.z+=offsetRim;
    std::cout<<"rimSecondV"<<rimSecondV.x<<","<<rimSecondV.y<<","<<rimSecondV.z<<std::endl;

//     glLineWidth(2.5); 
//     glColor3f(.0, .0, 1.0);
//     glBegin(GL_LINES);
//     glVertex3f(0.0, 0.0, 0.0);
//     glVertex3f(2, 2, 2);
//     glEnd();    
// 
// 
// 
 float light0_spot[]={keySecondV.x,keySecondV.y,keySecondV.z,1.0};
 
 float light1_spot[]={fillSecondV.x,fillSecondV.y,fillSecondV.z,1.0};

 float light2_spot[]={rimSecondV.x,rimSecondV.y,rimSecondV.z,1.0};

float light0_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
float light0_diffuse[] = { 1.0, 1.0, 1.0, 0.0 }; 
float light0_specular[] = { 2.25, 2.25, 2.25, 0.0 }; 
float light0_position[] = { .5, 1.0, 2.0, 0.0 };
float light0_direction[] = { 0.5, 0.5, 0.5};

float light1_diffuse[] = { 1.0, 1.0, 1.0, 0.0 }; 
float light1_specular[] = { 2.25, 2.25, 2.25, 0.0 }; 
float light1_position[] = { .5, 1.0, 2.0, 0.0 };
float light1_direction[] = { 0.5, 0.5, 0.5};

float light2_diffuse[] = { 1.0, 1.0, 1.0, 0.0 }; 
float light2_specular[] = { 2.25, 2.25, 2.25, 0.0 }; 
float light2_position[] = { .5, 1.0, 2.0, 0.0 };
float light2_direction[] = { 0.5, 0.5, 0.5};

// set scene default ambient 
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light0_ambient); 

//     glLineWidth(5.5); 
//     glColor3f(.0, .0, 1.0);
//     glBegin(GL_LINES);
//     glVertex3f(light0_position[0], light0_position[1], light0_position[2]);
//     glVertex3f(center.x,center.y,center.z);
//     glEnd();
//
// make specular correct for spots 


glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,1);

glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambient); 
glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse); 
glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular); 
glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse); 
glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular); 
glLightfv(GL_LIGHT2,GL_DIFFUSE,light2_diffuse); 
glLightfv(GL_LIGHT2,GL_SPECULAR,light2_specular); 

glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,80.0); 
glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,40.0); 
glLightf(GL_LIGHT2,GL_SPOT_EXPONENT,50.0); 
glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,180.0); 
glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,180.0); 
glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,180.0); 

glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,1.0); 
glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.2); 
glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,0.01); 
glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION,1.0); 
glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION,0.2); 
glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,0.01); 
glLightf(GL_LIGHT2,GL_CONSTANT_ATTENUATION,1.0); 
glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION,0.2); 
glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION,0.01); 

glLightfv(GL_LIGHT0,GL_POSITION,light0_spot);
glLightfv(GL_LIGHT1,GL_POSITION,light1_spot);
glLightfv(GL_LIGHT2,GL_POSITION,light2_spot);
//glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,light0_direction);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHT2);
}

void do_material()
{
float mat_ambient[] = {0.0,0.0,0.0,1.0}; 
float mat_diffuse[] = {0.9,0.9,0.1,1.0}; 
float mat_specular[] = {1.0,1.0,1.0,1.0};
float mat_shininess[] = {2.0}; 

glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_MULTISAMPLE);
glutInitWindowSize(512,512);
glutInitWindowPosition(100,50);
glutCreateWindow("my_cool_cube");
do_viewvolume();
do_lights();
do_material();
glutDisplayFunc(draw_stuff);
glutMainLoop();
return 0;
}

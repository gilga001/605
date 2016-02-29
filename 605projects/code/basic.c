//
// Phong shading, with lighting done in eye coordinates, rather than
// world coordinates.  NOTE: To get the gl_LightSource[i].position in
// eye coordinates, you have to set the ModelView matrix to the final view
// BEFORE you call glLightfv().  
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glx.h>
#include <GL/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *read_shader_program(char *filename) 
{
char *content = NULL;
int fd, count;
fd = open(filename,O_RDONLY);
count = lseek(fd,0,SEEK_END);
content = (char *)calloc(1,(count+1));
lseek(fd,0,SEEK_SET);
count = read(fd,content,count*sizeof(char));
content[count] = '\0';
close(fd);
return content;
}

// void set_light()
// {
// glLightfv(GL_LIGHT0,GL_POSITION,light0_position); 
// } 

// void set_material()
// {
// float mat_diffuse[] = {0.0,0.9,0.0,1.0};
// float mat_specular[] = {0.9,0.0,0.0,1.0};
// float mat_shininess[] = {2.0};
// 
// glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
// glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
// glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
// }
// 
// void view_volume()
// {
// glMatrixMode(GL_PROJECTION);
// glLoadIdentity();
// gluPerspective(45.0,1.0,1.0,20.0);
// glMatrixMode(GL_MODELVIEW);
// glLoadIdentity();
// gluLookAt(eye[0],eye[1],eye[2],viewpt[0],viewpt[1],viewpt[2],up[0],up[1],up[2]);
// }

void renderScene(void)
{
glClearColor(1.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT );

//draw
glColor3f(.0,.0,.0);
glBegin(GL_QUADS);
glVertex2f(-0.5,-0.5);
glVertex2f(-0.5,0.5);
glVertex2f(.5,.5);
glVertex2f(0.5,-0.5);
glEnd();
glFlush();

//glActiveTexture(GL_TEXTURE0);
//glBindTexture(GL_TEXTURE_2D,1);
//glRotatef(-25.0,1.0,0.0,0.0);
// glutSolidTorus(0.4,0.8,128,128);
//glutSolidTeapot(1.0);
// glutSwapBuffers();
}

unsigned int set_shaders()
{
GLint vertCompiled, fragCompiled;
char *vs, *fs;
GLuint v, f, p;

v = glCreateShader(GL_VERTEX_SHADER);
f = glCreateShader(GL_FRAGMENT_SHADER);
vs = read_shader_program("basic.vert");
fs = read_shader_program("basic.frag");
glShaderSource(v,1,(const char **)&vs,NULL);
glShaderSource(f,1,(const char **)&fs,NULL);
free(vs);
free(fs); 
glCompileShader(v);
glCompileShader(f);
p = glCreateProgram();
glAttachShader(p,f);
glAttachShader(p,v);
glLinkProgram(p);
glUseProgram(p);
return(p);
}

// void load_texture(char* filename){
//     FILE *fopen(),*fptr;
//     char buf[512];
//     int im_size,im_width,im_height,max_color;
//     unsigned char *texture_bytes,*parse;
// 
//     fptr=fopen(filename,"r");
//     fgets(buf,512,fptr);
//     do{
//         fgets(buf,512,fptr);
//     }while(buf[0]=='#');
//     parse=strtok(buf," \t");
//     im_width=atoi(parse);
// 
//     parse=strtok(NULL," \n");
//     im_height=atoi(parse);
// 
//     fgets(buf,512,fptr);
//     parse=strtok(buf," \n");
// 
//     max_color=atoi(parse);
// 
//     im_size=im_width*im_height;
//     texture_bytes=(unsigned char*)calloc(3,im_size);
//     fread(texture_bytes,3,im_size,fptr);
//     fclose(fptr);
// 
//     glBindTexture(GL_TEXTURE_2D,1);
//     glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,im_width,im_height,0,
//         GL_RGB,GL_UNSIGNED_BYTE,texture_bytes);
//     glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//     glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//     cfree(texture_bytes);
// }
// 
// void set_uniform(int p){
//     int location;
//     location=glGetUniformLocation(p,"mytexture");
//     glUniform1i(location,0);
// }
// 
void getout(unsigned char key, int x, int y)
{
switch(key) {
             case 'q':
                exit(1);
             default:
                break;
            }
}

int main(int argc, char **argv)
{
    unsigned int p;
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_RGBA );
glutInitWindowPosition(100, 100);
glutInitWindowSize(512, 512);
glutCreateWindow("basic GLSL demo");
// load_texture(argv[1]);
// glEnable(GL_DEPTH_TEST);
// glEnable(GL_MULTISAMPLE_ARB);
// view_volume();
// set_light();
// set_material();
//
set_shaders();
//
// p=set_shaders();
// set_uniform(p);
glutDisplayFunc(renderScene);
glutKeyboardFunc(getout);
glutMainLoop();
return 0;
}

//........................................................

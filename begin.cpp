#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#define SPEED 40.0	//speed of traffic

float i=0.0;	//movement of car
int light=1;	//1 for green-light, 0 for red-light
int day=1;	//1 for day, 0 for night

void draw_pixel(GLint cx,GLint cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);	
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h,GLint k,GLint r)
{
    GLint d=1-r , x=0 , y=r;
    while(y>x)
    {
	plotpixels(h,k,x,y);
	if(d<0)
	    d+=2*x+3;
	else
	{
	    d+=2*(x-y)+5;
	    --y;
	}
	++x;
    }
    plotpixels(h,k,x,y);
}

void draw_object()
{
    int d;
    if(day==1)
    {
	//int d;
	//sky
	glColor3f(0.15,0.86,0.88);
	glBegin(GL_POLYGON);
	glVertex2f(0,400);
	glVertex2f(0,700);
	glVertex2f(1000,700);
	glVertex2f(1000,400);
	glEnd();

	//sun
	for(d=0;d<=30;d++)
	{
	    glColor3f(0.96,0.27,0.13);
	    draw_circle(875,625,d);
	}
    }

    //grass
    glColor3f(0.24,0.79,0.27);
    glBegin(GL_POLYGON);
    glVertex2f(0,200);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,200);
    glEnd();

    //divider on the road
    for(d=0;d<1000;d+=200)
    {
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
        glVertex2f(d,90);
        glVertex2f(d,110);
        glVertex2f(125+d,110);
        glVertex2f(125+d,90);
        glEnd();
    }

    //building 1
    glColor3f(0.72,0.45,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(50,200);	
    glVertex2f(50,500);
    glVertex2f(250,500);
    glVertex2f(250,200);
    glEnd();
	
    //window 1
    glColor3f(0.52,0.63,0.60);
    glBegin(GL_POLYGON);
    glVertex2f(75,375);
    glVertex2f(75,450);
    glColor3f(0.19,0.29,0.26);
    glVertex2f(150,450);
    glVertex2f(150,375);
    glEnd();

    //door	
    glColor3f(0.52,0.63,0.60);
    glBegin(GL_POLYGON);
    glVertex2f(115,200);
    glVertex2f(115,325);
    glColor3f(0.19,0.29,0.26);
    glVertex2f(185,325);
    glVertex2f(185,200);
    glEnd();

    //building 2
    glColor3f(0.55,0.14,0.14);
    glBegin(GL_POLYGON);
    glVertex2f(325,200);
    glVertex2f(325,575);
    glVertex2f(750,575);
    glVertex2f(750,200);
    glEnd();

    //window 1,2,3
    for(d=375;d<=625;d+=125)
    {
        glColor3f(0.52,0.63,0.60);
        glBegin(GL_POLYGON);
	glVertex2f(d,450);
	glVertex2f(d,525);
        glColor3f(0.19,0.29,0.26);
	glVertex2f(75+d,525);
        glVertex2f(75+d,450);
	glEnd();
    }

    //window 4,5
    glColor3f(0.52,0.63,0.60);
    glBegin(GL_POLYGON);
    glVertex2f(375,325);
    glVertex2f(375,400);
    glColor3f(0.19,0.29,0.26);
    glVertex2f(450,400);
    glVertex2f(450,325);
    glEnd();
  
    //door
    glColor3f(0.52,0.63,0.60);
    glBegin(GL_POLYGON);
    glVertex2f(512.5,200);
    glVertex2f(512.5,350);
    glColor3f(0.19,0.29,0.26);
    glVertex2f(612.5,350);
    glVertex2f(612.5,200);
    glEnd();	
    
    //signal
    glColor3f(0.40,0.21,0.17);
    glBegin(GL_POLYGON);
    glVertex2f(900,200);
    glVertex2f(900,325);
    glVertex2f(925,325);
    glVertex2f(925,200);
    glEnd();	

    glColor3f(0.87,0.82,0.81);
    glBegin(GL_POLYGON);
    glVertex2f(875,325);
    glVertex2f(875,475);
    glVertex2f(950,475);
    glVertex2f(950,325);
    glEnd();

    for(d=0;d<=20;d++)
    {
	glColor3f(0.0,0.0,0.0);
	draw_circle(912.5,450,d);
	glColor3f(1.0,1.0,0.0);
	draw_circle(912.5,400,d);
	glColor3f(0.0,1.0,0.0);
	draw_circle(912.5,350,d);
    }	
    
    //car1
    glColor3f(0.52,0.39,0.39);
    glBegin(GL_POLYGON);
    glVertex2f(50,150);
    glVertex2f(35,165);
    glVertex2f(35,200);
    glVertex2f(125,250);
    glVertex2f(250,250);
    glVertex2f(300,200);
    glVertex2f(400,175);
    glVertex2f(400,160);
    glVertex2f(380,150);
    glEnd();

    //car1 window1
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(200,200);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(200,235);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(240,235);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(275,200);
    glEnd();
    
    //car1 window2
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(75,200);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(140,235);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(180,235);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(180,200);
    glEnd();

    //car1-lights
    //rear
    glColor3f(0.89,0.47,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(35,175);
    glVertex2f(35,200);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(50,200);
    glVertex2f(50,175);
    glEnd();

    //front
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(380,165);
    glVertex2f(380,175);
    glColor3f(0.89,0.47,0.20);
    glVertex2f(400,175);
    glVertex2f(400,165);
    glEnd();

    //car2
    glColor3f(0.14,0.42,0.55);
    glBegin(GL_POLYGON);
    glVertex2f(475,150);
    glVertex2f(475,200);
    glVertex2f(525,300);
    glVertex2f(700,300);
    glVertex2f(765,225);
    glVertex2f(825,190);
    glVertex2f(825,150);
    glEnd();

    //car2-window1
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(625,225);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(625,285);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(690,285);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(720,225);
    glEnd();
    
    //car2-window2
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(525,225);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(550,285);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(610,285);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(610,225);
    glEnd(); 
    
    //car2-lights
    //front
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(800,175);
    glVertex2f(800,195);
    glColor3f(0.89,0.47,0.20);
    glVertex2f(825,190);
    glVertex2f(825,175);
    glEnd();

    //rear
    glColor3f(0.89,0.47,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(475,175);
    glVertex2f(475,200);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(500,200);
    glVertex2f(500,175);
    glEnd();

    //car1-wheels
    for(d=0;d<=30;d++)
    {   
	glColor3f(0.075,0.075,0.075);
	draw_circle(125,150,d);
	glColor3f(0.075,0.075,0.075);
	draw_circle(250,150,d);
    }
    //car2-wheels
    for(d=0;d<=40;d++)
    {
	glColor3f(0.075,0.075,0.075);
	draw_circle(575,150,d);
        glColor3f(0.075,0.075,0.075);
	draw_circle(690,150,d);
    }
}


void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1000.0,0.0,700.0);
}

void display()
{
    draw_object();
    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000.0,700.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Traffic Signal");
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    myinit();
    glutMainLoop();
}




























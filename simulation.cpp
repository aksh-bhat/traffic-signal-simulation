#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#define SPEED 40        //speed of traffic


float x=0.0;        //movement of car
int light=1;        //1 for green-light, 0 for red-light
int day=1;        //1 for day, 0 for night
int d,flag=0;


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
    GLint D=1-r , x=0 , y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(D<0)
            D+=2*x+3;
        else
        {
            D+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}


void draw_object()
{
    //int d;
    if(day==1)
    {
        //int d;
        //day sky
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


        //clouds
        for(d=0;d<=25;d++)        
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(75,615,d);
            draw_circle(115,635,d);
            draw_circle(100,590,d);
            draw_circle(130,590,d);
            draw_circle(160,615,d);
        } 
    }
    else
    {
        //night sky
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,400);
        glVertex2f(0,700);
        glVertex2f(1000,700);
        glVertex2f(1000,400);
        glEnd();


        //moon
        for(d=0;d<=30;d++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(100,625,d);
        }
        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(520,630);
        glVertex2f(534,630);
        glVertex2f(527,644);
        glVertex2f(520,639);
        glVertex2f(534,639);
        glVertex2f(527,625);
        glEnd();


        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(250,550);
        glVertex2f(264,550);
        glVertex2f(257,564);
        glVertex2f(250,559);
        glVertex2f(264,559);
        glVertex2f(257,545);
        glEnd();


        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(320,680);
        glVertex2f(334,680);
        glVertex2f(327,694);
        glVertex2f(320,689);
        glVertex2f(334,689);
        glVertex2f(327,675);
        glEnd();


        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(640,600);
        glVertex2f(654,600);
        glVertex2f(647,614);
        glVertex2f(640,609);
        glVertex2f(654,609);
        glVertex2f(647,595);
        glEnd();


        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(770,520);
        glVertex2f(784,520);
        glVertex2f(777,534);
        glVertex2f(770,529);
        glVertex2f(784,529);
        glVertex2f(777,515);
        glEnd();


        //star 
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(900,590);
        glVertex2f(914,590);
        glVertex2f(907,604);
        glVertex2f(900,599);
        glVertex2f(914,599);
        glVertex2f(907,585);
        glEnd();
    }


    //grass
    glColor3f(0.24,0.79,0.27);
    glBegin(GL_POLYGON);
    glVertex2f(0,200);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,200);
    glEnd();


    //road
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glVertex2f(1000,0);
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
    glColor3f(0.81,0.60,0.28);
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
    glVertex2f(920,200);
    glVertex2f(920,325);
    glVertex2f(945,325);
    glVertex2f(945,200);
    glEnd();        


    glColor3f(0.87,0.82,0.81);
    glBegin(GL_POLYGON);
    glVertex2f(895,325);
    glVertex2f(895,475);
    glVertex2f(970,475);
    glVertex2f(970,325);
    glEnd();


    for(d=0;d<=20;d++)
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(932.5,450,d);
        glColor3f(1.0,1.0,0.0);
        draw_circle(932.5,400,d);
        glColor3f(0.0,1.0,0.0);
        draw_circle(932.5,350,d);
    }        
    
    //car1
    glColor3f(0.70,0.10,0.25);
    glBegin(GL_POLYGON);
    glVertex2f(50+x,150);
    glVertex2f(35+x,165);
    glVertex2f(35+x,200);
    glVertex2f(125+x,250);
    glVertex2f(250+x,250);
    glVertex2f(300+x,200);
    glVertex2f(400+x,175);
    glVertex2f(400+x,160);
    glVertex2f(380+x,150);
    glEnd();


    //car1 window1
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(200+x,200);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(200+x,235);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(240+x,235);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(275+x,200);
    glEnd();
    
    //car1 window2
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(75+x,200);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(140+x,235);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(180+x,235);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(180+x,200);
    glEnd();


    //car1-lights
    //rear
    glColor3f(0.89,0.47,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(35+x,175);
    glVertex2f(35+x,200);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(50+x,200);
    glVertex2f(50+x,175);
    glEnd();


    //front
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(380+x,165);
    glVertex2f(380+x,175);
    glColor3f(0.89,0.47,0.20);
    glVertex2f(400+x,175);
    glVertex2f(400+x,165);
    glEnd();


    //car2
    glColor3f(0.14,0.42,0.55);
    glBegin(GL_POLYGON);
    glVertex2f(480+x,150);
    glVertex2f(480+x,200);
    glVertex2f(530+x,300);
    glVertex2f(705+x,300);
    glVertex2f(770+x,225);
    glVertex2f(830+x,190);
    glVertex2f(830+x,150);
    glEnd();


    //car2-window1
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(630+x,225);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(630+x,285);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(695+x,285);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(725+x,225);
    glEnd();
    
    //car2-window2
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(530+x,225);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(555+x,285);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(615+x,285);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(615+x,225);
    glEnd(); 
    
    //car2-lights
    //front
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(805+x,175);
    glVertex2f(805+x,195);
    glColor3f(0.89,0.47,0.20);
    glVertex2f(830+x,190);
    glVertex2f(830+x,175);
    glEnd();


    //rear
    glColor3f(0.89,0.47,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(480+x,175);
    glVertex2f(480+x,200);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(505+x,200);
    glVertex2f(505+x,175);
    glEnd();


    //car1-wheels
    for(d=0;d<=30;d++)
    {   
        glColor3f(0.075,0.075,0.075);
        draw_circle(125+x,150,d);
        glColor3f(0.075,0.075,0.075);
        draw_circle(275+x,150,d);
    }


    //car2-wheels
    for(d=0;d<=40;d++)
    {
        glColor3f(0.075,0.075,0.075);
        draw_circle(565+x,150,d);
        glColor3f(0.075,0.075,0.075);
        draw_circle(730+x,150,d);
    }
}


void signal()
{
    if(light==0)
    {
        for(d=0;d<=20;d++)
        {
            glColor3f(1.0,0.0,0.0);
            draw_circle(932.5,450,d);
            glColor3f(0.0,0.0,0.0);
            draw_circle(932.5,350,d);
        }         
    }
    else
    {
        for(d=0;d<=20;d++)
        {
            glColor3f(0.0,0.0,0.0);
                draw_circle(932.5,450,d);
            glColor3f(0.0,1.0,0.0);
            draw_circle(932.5,350,d);
        }
    }
}        


void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'r':
        case 'R': light=0;
                  break;
        case 'g':
        case 'G': light=1;
                  break;
        case 13 : flag=1;
                   break;
        /*case 'm':
        case 'M':day=1;
                 break;
        case 'k':
        case 'K':day=0;
                 break;*/
    }
}


void idle()
{
    if(flag==1)
    {
        glClearColor(1.0,1.0,1.0,1.0);
        if(light==0 && (x>=100 && x<=500))
        {
            x+=SPEED/4;
        }
        if(light==0 && (x>=530 && x<=1020))
        {
            x+=SPEED/4;
        }
        if(light==1)
        {
            x+=SPEED/4;
        }
        glutPostRedisplay();
    }
}


void main_menu(int index)
{
    switch(index)
    {
    case 1: day=1;
                break;


        case 2: day=0;
                break;


        case 3: exit(0);
                break;
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


void drawstring(int x,int y,char *string)
{
    char *str;
    glRasterPos2f(x,y);
    for(str=string;*str!='\0';str++)
    {
        glColor3f(1.0,1.0,1.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*str);
    }
}


void frontscreen()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    drawstring(280,670,"SJB INSTITUTE OF TECHNOLOGY");
    drawstring(330,630,"DEPARTMENT OF CSE");
    drawstring(365,560,"A PROJECT ON");
    drawstring(280,510,"TRAFFIC SIGNAL IMPLEMENTATION");
    drawstring(30,350,"BY :");
    drawstring(30,300,"AKSHATHA  R  BHAT  [1JB14CS018]");
    drawstring(30,250,"AKSHAY  SUNKU  [1JB14CS019]");
    drawstring(800,350,"GUIDES :");
    drawstring(800,300,"DIVYASHREE  J");
    drawstring(800,250,"CHARULATA");
    drawstring(330,120,"PRESS  ENTER  TO  START");
    drawstring(345,90,"Press R for vehicles to stop");
    drawstring(335,60,"Press G for vehicles to move");
    glFlush();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
        frontscreen();
    if(flag==1)
    {
        draw_object();
        signal();
    }
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
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    myinit();
    glutCreateMenu(main_menu);
    glutAddMenuEntry("Day",1);
    glutAddMenuEntry("Night",2);
    glutAddMenuEntry("Quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}

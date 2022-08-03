
#include<windows.h> //for windows device
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include<string.h>
#define PI 3.1416
float angle=180;
float MotorAngle=0.0;
double x1=-40,x3=-40,x2=-50,x4=-50;
double lx1=-40,lx2=-40,lx3=-50,lx4=-50;
double rx1=40,rx2=40,rx3=50,rx4=50;
double rx5=40,rx6=40,rx7=50,rx8=50;
double lj1=50,lj2=50;
double rj1=-50,rj2=-50;

//Variable Robot 1
int l=0;
int m=0,n=0;
float LefthandTheta=-350,LefthandTheta1=0 , handRightTheta=-350 , LglovsX=0.5 ,LglovsY=4 , LglovsZ=4.5 , RglovsX=0 ,RglovsY=4.1 , RglovsZ= 6;
int SpAngle = 90;
int SpAngleX = 0;

int LSpAngle = 90;
int LSpAngleX = 0;
int FistAngle=0;
int CoverAngleL=0;
int CoverAngleR=0;
int Tx=-8,Ty=-5;
float PiraX1=2.5,PiraY1=2.5,PiraZ1=2.5,PiraX2=2.5,PiraY2=2.5,PiraZ2=2.5;
float RHTx=8.5,RHTy=0,RHTz=0;
int RoState=1;
float RJTx =0 , RJTy=0;
int jumpStateX = 0;
int jumpStateY = 0;
int iniTy=Ty;

//End

//Variable Robot 2
float angle2=180;
int l2=0;
int m2=0,n2=0;
float LefthandTheta2=-350,LefthandTheta12=0 , handRightTheta2=-350 , LglovsX2=0.5 ,LglovsY2=4 , LglovsZ2=4.5 , RglovsX2=0 ,RglovsY2=4.1 , RglovsZ2= 6;
int SpAngle2 = 90;
int SpAngleX2 = 0;
float MotorAngle2=0.0;
int LSpAngle2 = 90;
int LSpAngleX2 = 0;
int FistAngle2=0;
int CoverAngleL2=0;
int CoverAngleR2=0;
int Tx2=20,Ty2=-5;
float PiraX12=2.5,PiraY12=2.5,PiraZ12=2.5,PiraX22=2.5,PiraY22=2.5,PiraZ22=2.5;
float RHTx2=8.5,RHTy2=0,RHTz2=0;
bool RoState2=TRUE;
float RJTx2 =0 , RJTy2=0;
int jumpStateX2 = 0;
int jumpStateY2 = 0;
int iniTy2=Ty2;
//End
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);

}

void MyQuads(float red,float green,float blue)
{
        glColor3f(red,green,blue);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(5,0);
    glVertex2d(5,5);
    glVertex2d(0,5);
    glEnd();
}


void strips(float red,float green,float blue)
{

                   glPushMatrix();
        glTranslated(-0.7,-4.8,0);
        glScaled(0.2,0.03,1);
        MyQuads(red,green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-5.1,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-5.4,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-5.7,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();

                           glPushMatrix();
        glTranslated(-0.7,-6,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-6.3,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();

                           glPushMatrix();
        glTranslated(-0.7,-6.6,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-6.9,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-7.2,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-7.5,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
                           glPushMatrix();
        glTranslated(-0.7,-7.8,0);
        glScaled(0.2,0.03,1);
        MyQuads( red, green, blue);
        glPopMatrix();
}

void FlatS(float radiusX,float radiusY,float radiusZ){
    int i = 0;
    float angle = 0.0;
    glBegin(GL_POLYGON);
    for (i=0;i<100;i++){
        angle=2*PI*i/100;
        glVertex3d(radiusX*cos(angle),radiusY*sin(angle),radiusZ*cos(angle));
    }
    glEnd();
}

void sphere(float red,float green,float blue)
{
     int i;
  glColor3f(red,green,blue);
    for(i=0;i<200;i++)
    {

      glPushMatrix();
      glRotated(i,1,1,1);
      FlatS(4,5,3);

      glPopMatrix();
    }

}



void head()
{
      //front
    glColor3f(0.721568,0.92549,0.92549);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
     glColor3f(0.721568,0.92549,0.92549);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
     glColor3f(0.721568,0.92549,0.92549);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //left
        glColor3f(0.721568,0.92549,0.92549);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
     glColor3f(0.721568,0.92549,0.92549);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
  glColor3f(0.721568,0.92549,0.92549);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}

void box(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}


void Knife(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}


void Leftdana(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}

void Rightdana(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}

void Leftkobji(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}

void Rightkobji(float x,float y,float z,float a, float b, float c)
{
      //front
    glColor3f(x,y,z);

    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,5,0);
    glVertex3d(5,5,0);
    glVertex3d(5,0,0);
    glEnd();
              //back
   glColor3f(x,y,z);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,0,-5);
    glEnd();
                    //left
    glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(0,0,-5);
    glVertex3d(0,5,-5);
    glVertex3d(0,5,0);
    glEnd();
                    //right
        glColor3f(a,b,c);
    glBegin(GL_POLYGON);

    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(5,5,-5);
    glVertex3d(5,5,0);
    glEnd();

            //up
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(5,5,0);
    glVertex3d(0,5,0);
    glVertex3d(0,5,-5);
    glVertex3d(5,5,-5);
    glEnd();
                  //down
    glColor3f(x,y,z);
    glBegin(GL_POLYGON);

    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,-5);
    glVertex3d(0,0,-5);
    glEnd();

}

void circle(float radiusX,float radiusY)
{
    int i = 0;
    float angle = 0.0;
    glBegin(GL_POLYGON);
    for (i=0; i<100; i++)
    {
        angle=2*PI*i/100;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
    }
    glEnd();
}

void dots(float x,float y)
{
        glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(x,y,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();
}

void circle1(float radiusX,float radiusY)
{
    int i = 0;
    float angle = 0.0;
    glBegin(GL_POLYGON);
    for (i=0; i<8; i++)
    {
        angle=2*PI*i/8;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
    }
    glEnd();
}
void reshapeFunc(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(0.0,(double)width/(double)height,1.0,100.0);
}



//******************************************************Fn for stages*******************************
void chair(int x,int y)
{

    //*********CHAIR************
    glPushMatrix();
    glScaled(.25,.25,0);

    glPushMatrix();
    glTranslated(x,y,0);

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2d(-100,200);
    glVertex2d(-100,-100);
    glVertex2d(-80,-100);
    glVertex2d(-80,200);
    glEnd();


    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-150,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2d(-100,200);
    glVertex2d(-100,-100);
    glVertex2d(-80,-100);
    glVertex2d(-80,200);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-150,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2d(-100,-100);
    glVertex2d(-80,-100);
    glVertex2d(-110,-180);
    glVertex2d(-130,-180);

    glEnd();
    glPopMatrix();





    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-180,0,0);
    glRotated(-180,0,1,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2d(-100,-100);
    glVertex2d(-80,-100);
    glVertex2d(-110,-180);
    glVertex2d(-130,-180);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-240,-220,0);

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2d(0,20);
    glVertex2d(0,0);
    glVertex2d(150,0);
    glVertex2d(150,20);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-240,230,0);

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2d(0,20);
    glVertex2d(0,0);
    glVertex2d(150,0);
    glVertex2d(150,20);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-229,218,0);
    circle(22,30);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-102,218,0);
    circle(22,30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-75,-190,0);
    circle(22,30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-255,-190,0);
    circle(22,30);
    glPopMatrix();


    glColor3f(0.69,0.69,0.69);

    glPushMatrix();

    glTranslated(-240,-100,0);

    glBegin(GL_POLYGON);


    glVertex2d(0,20);
    glVertex2d(0,0);
    glVertex2d(150,0);
    glVertex2d(150,20);

    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.80,0,0);
    glVertex2d(-229,210);
    glVertex2d(-102,210);
    glVertex2d(-100,-90);
    glVertex2d(-230,-90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80,0,0);
    glVertex2d(-95,-98);
    glVertex2d(-235,-98);
    glVertex2d(-255,-190);
    glVertex2d(-75,-190);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}



//****************************************************End of Fn**************************************
//***********************************Visitors*****************************

void light(int x,int y)
{

    glPushMatrix();
    glTranslated(x,y,95);
    glPushMatrix();
    glTranslated(-507,-150,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(0,0);
    glVertex2d(10,0);
    glVertex2d(5,350);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-490,-150,0);
   glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(100,250);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslated(-450,-180,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,200);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,-200);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-510,-200,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,-400);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-500,-240,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(0,-400);

    glEnd();
    glPopMatrix();

//**************************************************************************


    glPushMatrix();
    glRotated(-180,0,1,0);
    glTranslated(1000.1,-5,0);


    glPushMatrix();
    glTranslated(-490,-150,0);
   glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
    glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(100,250);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslated(-450,-180,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,200);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-480,-250,0);
  glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,-200);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-510,-200,0);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
   glColor4f(1,1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,-400);

    glEnd();
    glPopMatrix();



    glPopMatrix();
//**********************************

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-500,-190,0);
    circle(50,90);
    glPopMatrix();


    glPopMatrix();


}




void spark(int x,int y)
{

    glPushMatrix();
    glTranslated(x,y,0);
    glPushMatrix();
    glTranslated(-507,-150,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(0,0);
    glVertex2d(10,0);
    glVertex2d(5,150);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-490,-150,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(100,150);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslated(-450,-180,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,150);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,150);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,-150);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-510,-200,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,-150);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-500,-240,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(0,-150);

    glEnd();
    glPopMatrix();

//**************************************************************************


    glPushMatrix();
    glRotated(-180,0,1,0);
    glTranslated(1000.1,-5,0);


    glPushMatrix();
    glTranslated(-490,-150,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(100,150);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslated(-450,-180,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,150);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,150);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-480,-250,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(200,-150);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-510,-200,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(-10,0);
    glVertex2d(0,-3);
    glVertex2d(150,-150);

    glEnd();
    glPopMatrix();



    glPopMatrix();
//***********************************


    glPopMatrix();


}


void visitors()
{

      //left joint
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-30,55);
   glVertex2d(-30,42);
   glVertex2d(-20,42);
   glVertex2d(-20,55);
  glEnd();
  //right joint
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(30,55);
   glVertex2d(30,42);
   glVertex2d(20,42);
   glVertex2d(20,55);
  glEnd();


  glPushMatrix();
    //left arm


    glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);

   glVertex2d(-30,55);
   glVertex2d(-30,45);
   glVertex2d(rj2,45);
   glVertex2d(rj1,55);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(lx4,70);
   glVertex2d(lx3,55);
   glVertex2d(lx2,55);
   glVertex2d(lx1,70);
  glEnd();

  //left palm
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.55, 0.55);
   glVertex2d(x4,70);
   glVertex2d(x2,77);
   glVertex2d(x3,77);
   glVertex2d(x1,70);
  glEnd();



    glPopMatrix();


  //right arm
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);

   glVertex2d(30,55);
   glVertex2d(30,45);
   glVertex2d(lj2,45);
   glVertex2d(lj1,55);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(rx4,70);
   glVertex2d(rx3,55);
   glVertex2d(rx2,55);
   glVertex2d(rx1,70);
  glEnd();

      //eye left
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(-15,82);
   glVertex2d(-15,75);
   glVertex2d(-5,75);
   glVertex2d(-5,82);
  glEnd();
  //eye right
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(15,82);
   glVertex2d(15,75);
   glVertex2d(5,75);
   glVertex2d(5,82);
  glEnd();
  //right eyebrow
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(15,85);
   glVertex2d(15,87);
   glVertex2d(5,87);
   glVertex2d(5,85);
  glEnd();
  //left eyebrow
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(-15,85);
   glVertex2d(-15,87);
   glVertex2d(-5,87);
   glVertex2d(-5,85);
  glEnd();
  //smile lips
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(-5,65);
   glVertex2d(-5,67);
   glVertex2d(5,67);
   glVertex2d(5,65);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(-5,65);
   glVertex2d(-5,70);
   glVertex2d(-4,70);
   glVertex2d(-4,65);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(5,65);
   glVertex2d(5,70);
   glVertex2d(6,70);
   glVertex2d(6,65);
  glEnd();

  //head

    glBegin(GL_POLYGON);
   glColor3f(1.0, 0.92, 0.80);
   glVertex2d(-20,90);
   glVertex2d(-20,60);
   glVertex2d(20,60);
   glVertex2d(20,90);
  glEnd();

  //right ear
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(20,80);
   glVertex2d(20,70);
   glVertex2d(23,70);
   glVertex2d(23,80);
  glEnd();
  //left ear
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-20,80);
   glVertex2d(-20,70);
   glVertex2d(-23,70);
   glVertex2d(-23,80);
  glEnd();
  //neck
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-7,60);
   glVertex2d(-7,55);
   glVertex2d(7,55);
   glVertex2d(7,60);
  glEnd();
  //body
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(-20,10);
   glVertex2d(-20,55);
   glVertex2d(20,55);
   glVertex2d(20,10);
  glEnd();



  //right palm
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.55, 0.55);
   glVertex2d(rx8,70);
   glVertex2d(rx7,77);
   glVertex2d(rx6,77);
   glVertex2d(rx5,70);
  glEnd();
  //belt
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(-22,10);
   glVertex2d(-22,00);
   glVertex2d(22,00);
   glVertex2d(22,10);
  glEnd();
  //left thigh
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(-20,00);
   glVertex2d(-30,-20);
   glVertex2d(-12,-20);
   glVertex2d(-2,00);
  glEnd();
  //right thigh
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(20,00);
   glVertex2d(30,-20);
   glVertex2d(12,-20);
   glVertex2d(2,00);
  glEnd();
  //right foot
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(27,-20);
   glVertex2d(27,-40);
   glVertex2d(14,-40);
   glVertex2d(14,-20);
  glEnd();
  //Left Foot
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(-27,-20);
   glVertex2d(-27,-40);
   glVertex2d(-14,-40);
   glVertex2d(-14,-20);
  glEnd();
  //left shoe
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(-27,-40);
   glVertex2d(-34,-43);
   glVertex2d(-34,-50);
   glVertex2d(-14,-50);
   glVertex2d(-14,-40);
  glEnd();
  //right shoe
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(27,-40);
   glVertex2d(34,-43);
   glVertex2d(34,-50);
   glVertex2d(14,-50);
   glVertex2d(14,-40);
  glEnd();
}

void normalvisitors(){


glPushMatrix();
//head
  glBegin(GL_POLYGON);

   glColor3f(1.0, 0.92, 0.80);
   glVertex2d(-20,90);
   glVertex2d(-20,60);
   glVertex2d(20,60);
   glVertex2d(20,90);
  glEnd();
  //eye left
  glPushMatrix();
  glTranslated(0,0,-1);
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(-15,82);
   glVertex2d(-15,75);
   glVertex2d(-5,75);
   glVertex2d(-5,82);
  glEnd();
  //eye right
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(15,82);
   glVertex2d(15,75);
   glVertex2d(5,75);
   glVertex2d(5,82);
  glEnd();

  //right eyebrow
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(15,85);
   glVertex2d(15,87);
   glVertex2d(5,87);
   glVertex2d(5,85);
  glEnd();
  //left eyebrow
  glBegin(GL_POLYGON);
   glColor3f(0.0, 0.0, 0.0);
   glVertex2d(-15,85);
   glVertex2d(-15,87);
   glVertex2d(-5,87);
   glVertex2d(-5,85);
  glEnd();
  //smile lips
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(-5,65);
   glVertex2d(-5,67);
   glVertex2d(5,67);
   glVertex2d(5,65);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(-5,65);
   glVertex2d(-5,70);
   glVertex2d(-4,70);
   glVertex2d(-4,65);
  glEnd();
  glBegin(GL_POLYGON);
   glColor3f(0.69, 0.19, 0.38);
   glVertex2d(5,65);
   glVertex2d(5,70);
   glVertex2d(6,70);
   glVertex2d(6,65);
  glEnd();
  //right ear
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(20,80);
   glVertex2d(20,70);
   glVertex2d(23,70);
   glVertex2d(23,80);
  glEnd();
  glPopMatrix();
  //left ear
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-20,80);
   glVertex2d(-20,70);
   glVertex2d(-23,70);
   glVertex2d(-23,80);
  glEnd();
  //neck
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-7,60);
   glVertex2d(-7,55);
   glVertex2d(7,55);
   glVertex2d(7,60);
  glEnd();
  //body
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(-20,10);
   glVertex2d(-20,55);
   glVertex2d(20,55);
   glVertex2d(20,10);
  glEnd();
  //left joint
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(-30,55);
   glVertex2d(-30,42);
   glVertex2d(-20,42);
   glVertex2d(-20,55);
  glEnd();
  //right joint
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.55, 0.51);
   glVertex2d(30,55);
   glVertex2d(30,42);
   glVertex2d(20,42);
   glVertex2d(20,55);
  glEnd();


  glPushMatrix();
    //left arm


    glBegin(GL_POLYGON);
   glColor3f(1, 1, 1);

   glVertex2d(-30,55);
   glVertex2d(-30,45);
   glVertex2d(-43,45);
   glVertex2d(-50,55);
  glEnd();

glBegin(GL_POLYGON);
   glColor3f(1, 1, 1);

   glVertex2d(-30,20);
   glVertex2d(-50,55);
   glVertex2d(-40,55);
   glVertex2d(-22,30);
  glEnd();

  //left palm
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.55, 0.55);
   glVertex2d(-30,20);
   glVertex2d(-26,14);
   glVertex2d(-18,24);
   glVertex2d(-22,30);
  glEnd();



    glPopMatrix();


  //right arm
  glBegin(GL_POLYGON);
  glColor3f(1, 1, 1);

   glVertex2d(30,55);
   glVertex2d(30,45);
   glVertex2d(43,45);
   glVertex2d(50,55);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(1, 1, 1);
   glVertex2d(30,20);
   glVertex2d(50,55);
   glVertex2d(40,55);
   glVertex2d(22,30);
  glEnd();


  //right palm
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.55, 0.55);
   glVertex2d(30,20);
   glVertex2d(26,14);
   glVertex2d(18,24);
   glVertex2d(22,30);
  glEnd();
  //belt
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(-22,10);
   glVertex2d(-22,00);
   glVertex2d(22,00);
   glVertex2d(22,10);
  glEnd();
  //left thigh
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(-20,00);
   glVertex2d(-30,-20);
   glVertex2d(-12,-20);
   glVertex2d(-2,00);
  glEnd();
  //right thigh
  glBegin(GL_POLYGON);
   glColor3f(0.00, 0.00, 0.55);
   glVertex2d(20,00);
   glVertex2d(30,-20);
   glVertex2d(12,-20);
   glVertex2d(2,00);
  glEnd();
  //right foot
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(27,-20);
   glVertex2d(27,-40);
   glVertex2d(14,-40);
   glVertex2d(14,-20);
  glEnd();
  //Left Foot
  glBegin(GL_POLYGON);
   glColor3f(0.20, 0.20, 0.20);
   glVertex2d(-27,-20);
   glVertex2d(-27,-40);
   glVertex2d(-14,-40);
   glVertex2d(-14,-20);
  glEnd();
  //left shoe
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(-27,-40);
   glVertex2d(-34,-43);
   glVertex2d(-34,-50);
   glVertex2d(-14,-50);
   glVertex2d(-14,-40);
  glEnd();
  //right shoe
  glBegin(GL_POLYGON);
   glColor3f(0.55, 0.00, 0.00);
   glVertex2d(27,-40);
   glVertex2d(34,-43);
   glVertex2d(34,-50);
   glVertex2d(14,-50);
   glVertex2d(14,-40);
  glEnd();

glPopMatrix();
}
void clapping(){


    if(x1<=0 && l==0)
        {


            x1=x1+6;
            x2=x2+6;
            x3=x3+6;
            x4=x4+6;

            lx1=lx1+6;
            lx2=lx2+6;
            lx3=lx3+6;
            lx4=lx4+6;
            rj2=rj2+6;
            rj1=rj1+6;


            rx1=rx1-6;
            rx2=rx2-6;
            rx3=rx3-6;
            rx4=rx4-6;
            rx5=rx5-6;
            rx6=rx6-6;
            rx7=rx7-6;
            rx8=rx8-6;
            lj1=lj1-6;
            lj2=lj2-6;
                         if(x1>-1)
            {
                l=1;
            }

        }
        else if(x1 > -40 && l==1)
        {

            x1=x1-6;
            x2=x2-6;
            x3=x3-6;
            x4=x4-6;

            lx1=lx1-6;
            lx2=lx2-6;
            lx3=lx3-6;
            lx4=lx4-6;
            rj2=rj2-6;
            rj1=rj1-6;


            rx1=rx1+6;
            rx2=rx2+6;
            rx3=rx3+6;
            rx4=rx4+6;
            rx5=rx5+6;
            rx6=rx6+6;
            rx7=rx7+6;
            rx8=rx8+6;
            lj1=lj1+6;
            lj2=lj2+6;
            if(x1>=-40 && x1<-39)
            {
                l=0;
            }

             }

             glutPostRedisplay();

}
//**************************************End visitors*****

void punch()
{



        if(handRightTheta<=280 && m==0)
{
    handRightTheta += 30.0f;
    RglovsX -=0 ;
    RglovsY -=2.5;
     RglovsZ += 2.5;
     SpAngleX +=30;
    if(handRightTheta>= -280)
    {
        m=1;
    }
}

else if(handRightTheta>=-350 && m==1){
    handRightTheta -=30.0f;
    RglovsY +=2.5;
    RglovsZ -= 2.5;
    SpAngleX -=30;
    if(handRightTheta>=-350 && handRightTheta<=-345)
    {
        m=0;
    }
}
}

void punchWithMotor()
{

        if(LefthandTheta<=280 && n==0)
{
    LefthandTheta += 30.0f;
    LglovsX -=0 ;
    LglovsY -=2.5;
     LglovsZ += 2.5;
     LSpAngleX +=30;
    if(LefthandTheta>= -280)
    {
        n=1;
    }
}

else if(LefthandTheta>=-350 && n==1){
    LefthandTheta -=30.0f;
    LglovsY +=2.5;
    LglovsZ -= 2.5;
    LSpAngleX -=30;
    if(LefthandTheta>=-350 && LefthandTheta<=-345)
    {
        n=0;
    }
}

glutPostRedisplay(); // Inform GLUT that the display has changed
}

void coverR()
{
    CoverAngleR =45;
    RHTx=6;
    RHTy=-7;
    RHTz=0;
    glutPostRedisplay();
}
void coverL()
{
    CoverAngleL =-45;
    glutPostRedisplay();
}
void Uncover()
{
    CoverAngleR =0;
    CoverAngleL =0;
    RHTx=8.5;
    RHTy=0;
    RHTz=0;
    glutPostRedisplay();
}

void grab()
{
    PiraX1=-5;
    PiraY1=2.5;
    PiraZ1=2.5;
    PiraX2=8;
    PiraY2=2.5;
    PiraZ2=2.5;
}

void Ungrab()
{
    PiraX1=2.5;
    PiraY1=2.5;
    PiraZ1=2.5;
    PiraX2=2.5;
    PiraY2=2.5;
    PiraZ2=2.5;
}

void RotMotor(int value)
{
    MotorAngle=MotorAngle+500;
    LefthandTheta1=-20;
    glutPostRedisplay();
    if(RoState)
    {
       glutTimerFunc(2,RotMotor,0);
    }
}

void MotorStop()
{
    LefthandTheta1=0;
    RoState=0;
    glutPostRedisplay();
}
void MotorStartState()
{
    RoState=1;

    glutPostRedisplay();
}

//Fn for 2nd Robot
void punch2()
{



        if(handRightTheta2<=280 && m2==0)
{
    handRightTheta2 += 30.0f;
    RglovsX2 -=0 ;
    RglovsY2 -=2.5;
     RglovsZ2 += 2.5;
     SpAngleX2 +=30;
    if(handRightTheta2>= -280)
    {
        m2=1;
    }
}

else if(handRightTheta2>=-350 && m2==1){
    handRightTheta2 -=30.0f;
    RglovsY2 +=2.5;
    RglovsZ2 -= 2.5;
    SpAngleX2 -=30;
    if(handRightTheta2>=-350 && handRightTheta2<=-345)
    {
        m2=0;
    }
}
}

void punchWithMotor2()
{

        if(LefthandTheta2<=280 && n2==0)
{
    LefthandTheta2 += 30.0f;
    LglovsX2 -=0 ;
    LglovsY2 -=2.5;
     LglovsZ2 += 2.5;
     LSpAngleX2 +=30;
    if(LefthandTheta2>= -280)
    {
        n2=1;
    }
}

else if(LefthandTheta2>=-350 && n2==1){
    LefthandTheta2 -=30.0f;
    LglovsY2 +=2.5;
    LglovsZ2 -= 2.5;
    LSpAngleX2 -=30;
    if(LefthandTheta2>=-350 && LefthandTheta2<=-345)
    {
        n2=0;
    }
}

glutPostRedisplay(); // Inform GLUT that the display has changed
}

void coverR2()
{
    CoverAngleR2 =45;
    RHTx2=6;
    RHTy2=-7;
    RHTz2=0;
    glutPostRedisplay();
}
void coverL2()
{
    CoverAngleL2 =-45;
    glutPostRedisplay();
}
void Uncover2()
{
    CoverAngleR2 =0;
    CoverAngleL2 =0;
    RHTx2=8.5;
    RHTy2=0;
    RHTz2=0;
    glutPostRedisplay();
}

void grab2()
{
    PiraX12=-5;
    PiraY12=2.5;
    PiraZ12=2.5;
    PiraX22=8;
    PiraY22=2.5;
    PiraZ22=2.5;
}

void Ungrab2()
{
    PiraX12=2.5;
    PiraY12=2.5;
    PiraZ12=2.5;
    PiraX22=2.5;
    PiraY22=2.5;
    PiraZ22=2.5;
}

void RotMotor2(int value)
{
    MotorAngle2=MotorAngle2+500;
    LefthandTheta12=-20;
    glutPostRedisplay();
    if(RoState2)
    {
        glutTimerFunc(1,RotMotor2,0);
    }
}

void MotorStop2()
{
    LefthandTheta12=0;
    RoState2=FALSE;
    glutPostRedisplay();
}
void MotorStartState2()
{
    RoState2=TRUE;

    glutPostRedisplay();
}

//Fn end

void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state==GLUT_DOWN)
    {
            coverL();
            coverR();
    }
    else if(state==GLUT_UP)
    {
        Uncover();
    }
        break;

    case GLUT_RIGHT_BUTTON:
                if(state==GLUT_DOWN)
    {
        grab();
    }
     else if(state==GLUT_UP)
    {
        Ungrab();
    }
        break;

    default:

        break;
    }
}

void rotateobj()
{
    angle = angle + 1;
    glutPostRedisplay();
}

void jump(int iniTy)
{

        if(jumpStateY==0)
        {
            Ty+=5;
        }

         if(Ty>=15)
        {
            jumpStateY=1;
        }
        if(jumpStateY==1)
        {
            Ty-=5;
        }
        if(Ty<=iniTy)
        {
            jumpStateY=0;
        }


glutPostRedisplay();

}
void jump2(int iniTy2)
{

        if(jumpStateY2==0)
        {
            Ty2+=5;
        }

         if(Ty2>=15)
        {
            jumpStateY2=1;
        }
        if(jumpStateY2==1)
        {
            Ty2-=5;
        }
        if(Ty2<=iniTy2)
        {
            jumpStateY2=0;
        }


glutPostRedisplay();

}

void my_keyboard(unsigned char key,int x, int y)
{

	switch (key) {

		case 'e':
		       angle=angle+20;

			break;
			case 'q':
		       angle=angle-20;
			break;
        case ' ':
                punch();
                break;
        case 'r':
               glutTimerFunc(25,RotMotor,0);
                break;
          case 't':

                MotorStop();
                break;
          case 'y':

                MotorStartState();
                break;

        case 'f':
                jump(iniTy);
                break;

        case 'c':
                punchWithMotor();
                break;

        //Robot 2

            case 'p':
                coverL2();
                coverR2();
            break;

            case 'o':
                Uncover2();
            break;
            case 'l':
                grab2();
            break;
            case 'k':
                Ungrab2();
            break;

		case 'u':
		       angle2=angle2+20;

			break;
			case 'i':
		       angle2=angle2-20;
			break;
        case 'j':
                punch2();
                break;
        case 'h':

               glutTimerFunc(25,RotMotor2,1);
                break;
          case 'g':

                MotorStop2();
                break;
          case 'm':

                MotorStartState2();
                break;

        case 'n':
                jump2(iniTy2);
                break;

        case 'b':
                punchWithMotor2();
                break;


                case '8':
            if(Ty2<=1)
            Ty2++;
            glutPostRedisplay();
        break;


        case '2':
            if(Ty2>=-18)
            Ty2--;
              glutPostRedisplay();
            break;
        case '4':
            if(Tx2>=-45)
            {
                Tx2--;
            }
            glutPostRedisplay();
                  break;

        case '6':
            if(Tx2<= 45)
            Tx2++;
              glutPostRedisplay();
            break;



	  default:
			break;
	}
}







void specialKey(int key,int x,int y){
    switch(key){

        case GLUT_KEY_UP:
            if(Ty<=1)
            Ty++;
            glutPostRedisplay();
        break;


        case GLUT_KEY_DOWN:
            if(Ty>=-18)
            Ty--;
              glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            if(Tx>=-45)
            {
                Tx--;
            }
            glutPostRedisplay();
                  break;

        case GLUT_KEY_RIGHT:
            if(Tx<= 45)
            Tx++;
              glutPostRedisplay();
            break;


        default:
            break;

    }
}


void rock()
{
    glTranslated(0,0,-20);
    glRotated(angle,1,1,0);
    glScaled(0.1,0.3,0.1);


    //bottom pyramid++++++++++++++++++++++++++++++++
    glPushMatrix();
    glTranslated(0,0,-6);
    glRotated(180,1,0,0);

     glPushMatrix();
    glColor3f(1,0,0);//front
    glBegin(GL_TRIANGLES);
    glVertex3d(0,3,-3);
    glVertex3d(3,0,0);
    glVertex3d(-3,0,0);
    glEnd();
    glPopMatrix();

        glPushMatrix();
    glColor3f(0,1,0);//back
    glBegin(GL_TRIANGLES);
    glVertex3d(0,3,-3);
    glVertex3d(3,0,-6);
    glVertex3d(-3,0,-6);
    glEnd();
    glPopMatrix();

        glPushMatrix();
    glColor3f(0,0,1);//left
    glBegin(GL_TRIANGLES);
    glVertex3d(0,3,-3);
    glVertex3d(-3,0,0);
    glVertex3d(-3,0,-6);
    glEnd();
    glPopMatrix();

            glPushMatrix();
    glColor3f(0.5,0.32,0.455);//right
    glBegin(GL_TRIANGLES);
    glVertex3d(0,3,-3);
    glVertex3d(3,0,0);
    glVertex3d(3,0,-6);
    glEnd();
    glPopMatrix();





                glPushMatrix();
    glColor3f(0.4,0.5,0);//Bottom
    glBegin(GL_QUADS);
    glVertex3d(+3,0,0);
    glVertex3d(-3,0,0);
    glVertex3d(-3,0,-6);
    glVertex3d(3,0,-6);
    glEnd();
    glPopMatrix();


    glPopMatrix();


    glPopMatrix();


    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0,0);
    glVertex2d(0,5);
    glVertex2d(5,0);
    glVertex2d(-5,0);
    glVertex2d(0,5);

    glEnd();
}



void stage()
{
    glPushMatrix();

    glScaled(0.002,0.002,0.002);
    glTranslated(0,0,0);


//***************stages******



    glPushMatrix();
    glScaled(1.2,0.7,1);
    glTranslated(0,-250,0);

        //ropes of front right+ front left piller

    glPushMatrix();
    glRotated(180,0,1,0);
    glTranslated(0,0,100);
    //rope FF1
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();

        //rope FF2
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-130,0);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

            //rope FF3
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-264,0);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    //*******************Front rope end

    //pilar front left
    glColor3f(0.25098,0.23529,0.23529);
    glBegin(GL_POLYGON);
    glVertex2d(-360,-400);
    glVertex2d(-380,-400);
    glVertex2d(-380,0);
    glVertex2d(-360,0);
    glEnd();
    glPushMatrix();
    glTranslated(-370,0,0);
    circle(10,10);
    glPopMatrix();

    //piler back left
    glBegin(GL_POLYGON);
    glVertex2d(-129,25);
    glVertex2d(-140,7);
    glVertex2d(-140,200);
    glVertex2d(-129,200);
    glEnd();
    glPushMatrix();
    glTranslated(-134.5,200,0);
    circle(5.5,5.5);
    glPopMatrix();

    //piller front right
    glBegin(GL_POLYGON);
    glVertex2d(360,-400);
    glVertex2d(380,-400);
    glVertex2d(380,0);
    glVertex2d(360,0);
    glEnd();
    glPushMatrix();
    glTranslated(370,0,0);
    circle(10,10);
    glPopMatrix();



    //piller back right
    glBegin(GL_POLYGON);
    glVertex2d(129,25);
    glVertex2d(140,7);
    glVertex2d(140,200);
    glVertex2d(129,200);
    glEnd();
    glPushMatrix();
    glTranslated(134.5,200,0);
    circle(5.5,5.5);
    glPopMatrix();

    //rope connectors of piller 1 front left
    //rope connector 1
    glPushMatrix();
    glTranslated(-360,-20,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-320,-15,0);
    circle1(15,20);
    glPopMatrix();

    //rope connector 2

    glPushMatrix();
    glTranslated(-360,-150,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-320,-145,0);
    circle1(15,20);
    glPopMatrix();

    //rope connector 3

    glPushMatrix();
    glTranslated(-360,-285,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-320,-280,0);
    circle1(15,20);
    glPopMatrix();

        //rope connectors of piller 2 front right
    //rope connector 1

    glPushMatrix();

    glTranslated(320,-20,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(320,-15,0);
    circle1(15,20);
    glPopMatrix();

    //rope connector 2

    glPushMatrix();
    glTranslated(320,-150,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(320,-145,0);
    circle1(15,20);
    glPopMatrix();

    //rope connector 3

    glPushMatrix();
    glTranslated(320,-285,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,15);
    glVertex2d(40,15);
    glVertex2d(40,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(320,-280,0);
    circle1(15,20);
    glPopMatrix();


        //rope connectors of piller 3 back left
    //rope connector 1

    glPushMatrix();
    glTranslated(-129,185,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-111,190,0);
    circle1(10,10);
    glPopMatrix();

    //rope connector 2

    glPushMatrix();
    glTranslated(-129,120,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-111,125,0);
    circle1(10,10);
    glPopMatrix();


    //rope connector 3

    glPushMatrix();
    glTranslated(-129,60,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-111,65,0);
    circle1(10,10);
    glPopMatrix();


            //rope connectors of piller 4 back right


    //rope connector 1

    glPushMatrix();
    glTranslated(111,185,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(111,190,0);
    circle1(10,10);
    glPopMatrix();

    //rope connector 2

    glPushMatrix();
    glTranslated(111,120,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(111,125,0);
    circle1(10,10);
    glPopMatrix();


    //rope connector 3

    glPushMatrix();
    glTranslated(111,60,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0,10);
    glVertex2d(18,10);
    glVertex2d(18,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(111,65,0);
    circle1(10,10);
    glPopMatrix();



            //rope 2 of Front left + back left piller
    glPushMatrix();
    glTranslated(0,-130,0);
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-105,255);
    glVertex2d(-111,255);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

            //rope 3 of Front left + back left piller
    glPushMatrix();
    glTranslated(0,-265,0);
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-105,332);
    glVertex2d(-111,332);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();



                //rope 2 of Front right + back right piller
    glPushMatrix();
    glRotated(180,0,1,0);
    glTranslated(0,-130,0);
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-105,255);
    glVertex2d(-111,255);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

            //rope 3 of Front right + back right piller
    glPushMatrix();
    glRotated(180,0,1,0);
    glTranslated(0,-265,0);
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-105,332);
    glVertex2d(-111,332);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();





    //rope Front right + back right piller


    //rope 1
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-103,190);
    glVertex2d(-111,190);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();


        //rope Front right + back right piller


    //rope 1
    glPushMatrix();
    glRotated(180,0,1,0);
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-315,3);
    glVertex2d(-310,0);
    glVertex2d(-103,190);
    glVertex2d(-111,190);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    glColor3f(0,0,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslated(0,200,0);
    glScaled(.32,0.6,0);

     //ropes of back right+ back left piller

    //rope BB1
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();

        //ropeBB2
    glPushMatrix();
    glTranslated(0,20,0);
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-130,0);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

            //rope BB3
    glPushMatrix();
    glTranslated(0,50,0);
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-264,0);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();




    glPopMatrix();
    //ground
    glColor3f(0.9098,0.92549,0.9412);
    glBegin(GL_POLYGON);
    glVertex2d(-350,-350);
    glVertex2d(350,-350);
    glVertex2d(120,25);
    glVertex2d(-120,25);
    glEnd();

    //border1
    //bottom
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(-350,-350);
    glVertex2d(-350,-357);
    glVertex2d(350,-357);
    glVertex2d(350,-350);
    glEnd();
    //right
    glBegin(GL_POLYGON);
    glVertex2d(350,-350);
    glVertex2d(120,25);
    glVertex2d(121,25);
    glVertex2d(351,-350);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex2d(-350,-350);
    glVertex2d(-120,25);
    glVertex2d(-121,25);
    glVertex2d(-351,-350);
    glEnd();

    //border 2
    //bottom
    glColor3f(0.47,0.47,0.4392);
    glBegin(GL_POLYGON);
    glVertex2d(-360,-357);
    glVertex2d(-360,-370);
    glVertex2d(360,-370);
    glVertex2d(360,-357);
    glEnd();
    //right
    glColor3f(0.47,0.47,0.4392);
    glBegin(GL_POLYGON);
    glVertex2d(350,-360);
    glVertex2d(120,25);
    glVertex2d(130,25);
    glVertex2d(360,-360);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex2d(-350,-360);
    glVertex2d(-120,25);
    glVertex2d(-130,25);
    glVertex2d(-360,-360);
    glEnd();
    //top
    glBegin(GL_POLYGON);

    glVertex2d(129,25);
    glVertex2d(-129,25);
    glVertex2d(-124,35);
    glVertex2d(124,35);
    glEnd();

        //border 3 bottom

    glColor3f(0.15686,0.1098,0.141176);
    glBegin(GL_POLYGON);
    glVertex2d(-360,-370);
    glVertex2d(-360,-400);
    glVertex2d(360,-400);
    glVertex2d(360,-370);
    glEnd();

        //ropes of front right+ front left piller

    glPushMatrix();
    glTranslated(0,0,-1000);
    //rope FF1
    glColor3f(0.643137,0.172549,0.20392);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();

        //rope FF2
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-130,-1000);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

            //rope FF3
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(0,-264,-1000);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(320,-19);
    glVertex2d(320,-9);
    glEnd();
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-320,-9);
    glVertex2d(-320,-19);
    glVertex2d(150,-19);
    glVertex2d(150,-9);
    glEnd();
    glPushMatrix();
    glTranslated(-320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glColor3f(0.643137,0.172549,0.20392);
    glPushMatrix();
    glTranslated(320,-14,0);
    circle(5,5.5);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    //*******************Front rope end

    glPopMatrix();
}


//**********************Function of SpikeFist********************


void spike()
{
    glPushMatrix();
    glTranslated(0,0.15,-0.014);
    glScaled(0.003,0.05,0.003);
    //Bottom
    glColor3f(1,0.456,0.78);
    glBegin(GL_QUADS);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glVertex3d(0,0,5);
    glEnd();

        //front
    glColor3f(0.6,1,0.9);
    glBegin(GL_TRIANGLES);
    glVertex3d(2.5,2.5,2.5);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glEnd();

            //left
    glColor3f(0.7,0.4,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(2.5,2.5,2.5);
    glVertex3d(0,0,0);
    glVertex3d(0,0,5);
    glEnd();

            //back
    glColor3f(1,0.5,0);
    glBegin(GL_TRIANGLES);
    glVertex3d(2.5,2.5,2.5);
    glVertex3d(0,0,5);
    glVertex3d(5,0,5);
    glEnd();

            //Right
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(2.5,2.5,2.5);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glEnd();
    glPopMatrix();
}

void RotateSpike()
{
    FistAngle = FistAngle + 1;
    glutPostRedisplay();
}
void SpikeFist()
{
    glPushMatrix();
    glRotated(FistAngle,0,1,0);

    //top Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glTranslated(i,0,j);
    spike();
    glPopMatrix();
    }
    }

    //Top spike end

    //bottom Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(180,1,0,0);
    glTranslated(i,-0.15,-j+0.016);
    spike();
    glPopMatrix();
    }
    }
    //bottom spike end

        //back Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(i,-0.15,-j-0.12);
    spike();
    glPopMatrix();
    }
    }
    //back spike end

            //Front Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(-90,1,0,0);
    glTranslated(i,0,-j+0.02);
    spike();
    glPopMatrix();
    }
    }
    //Front spike end

                //Right Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(-90,0,0,1);
    glTranslated(i-0.15,0,-j-0.13);
    spike();
    glPopMatrix();
    }
    }
    //Right spike end

    //Fist
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(0.03,0.03,0.03);
    box(0.4,0.4,0.4,0.6,0.6,0.6);
    glPopMatrix();

    glPopMatrix();

}



void RotateSpike2()
{
    FistAngle = FistAngle + 1;
    glutPostRedisplay();
}
void SpikeFist2()
{
    glPushMatrix();
    glRotated(FistAngle,0,1,0);

    //top Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glTranslated(i,0,j);
    spike();
    glPopMatrix();
    }
    }

    //Top spike end

    //bottom Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(180,1,0,0);
    glTranslated(i,-0.15,-j+0.016);
    spike();
    glPopMatrix();
    }
    }
    //bottom spike end

        //back Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(i,-0.15,-j-0.12);
    spike();
    glPopMatrix();
    }
    }
    //back spike end

            //Front Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(-90,1,0,0);
    glTranslated(i,0,-j+0.02);
    spike();
    glPopMatrix();
    }
    }
    //Front spike end

                //Right Spike
    for(float j=0.0;j>-0.12;j-=0.04){
    for(float i=0.0;i<0.15;i+=0.02)
    {
    glPushMatrix();
    glRotated(-90,0,0,1);
    glTranslated(i-0.15,0,-j-0.13);
    spike();
    glPopMatrix();
    }
    }
    //Right spike end

    //Fist
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(0.03,0.03,0.03);
    box(0.4,0.4,0.4,0.6,0.6,0.6);
    glPopMatrix();

    glPopMatrix();

}



void spike1()
{
    glPushMatrix();
    glTranslated(0,0.15,-0.014);
    glScaled(0.003,0.05,0.003);
    //Bottom
    glColor3f(1,0.456,0.78);
    glBegin(GL_QUADS);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glVertex3d(0,0,5);
    glEnd();

        //front
    glColor3f(0.6,1,0.9);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX1,PiraY1,PiraZ1);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glEnd();

            //left
    glColor3f(0.7,0.4,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX1,PiraY1,PiraZ1);
    glVertex3d(0,0,0);
    glVertex3d(0,0,5);
    glEnd();

            //back
    glColor3f(1,0.5,0);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX1,PiraY1,PiraZ1);
    glVertex3d(0,0,5);
    glVertex3d(5,0,5);
    glEnd();

            //Right
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX1,PiraY1,PiraZ1);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glEnd();
    glPopMatrix();
}
void spike2()
{
    glPushMatrix();
    glTranslated(0,0.15,-0.014);
    glScaled(0.003,0.05,0.003);
    //Bottom
    glColor3f(1,0.4,0.8);
    glBegin(GL_QUADS);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glVertex3d(0,0,5);
    glEnd();

        //front
    glColor3f(0.6,1,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX2,PiraY2,PiraZ2);
    glVertex3d(0,0,0);
    glVertex3d(5,0,0);
    glEnd();

            //left
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX2,PiraY2,PiraZ2);
    glVertex3d(0,0,0);
    glVertex3d(0,0,5);
    glEnd();

            //back
    glColor3f(0.5,1,0.3);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX2,PiraY2,PiraZ2);
    glVertex3d(0,0,5);
    glVertex3d(5,0,5);
    glEnd();

            //Right
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);
    glVertex3d(PiraX2,PiraY2,PiraZ2);
    glVertex3d(5,0,0);
    glVertex3d(5,0,5);
    glEnd();
    glPopMatrix();
}

void motor()
{
        glPushMatrix();
        glRotated(MotorAngle,1,0,0);
    //spike 1
    glPushMatrix();
    glScaled(1.5,3,2);
    glRotated(-90,0,0,1);
    glTranslated(-0.016,-0.05,-0.005);
    spike1();
    glPopMatrix();
    //spike 2
    glPushMatrix();
    glScaled(1.5,3,2);
    glRotated(-90,0,0,1);
    glTranslated(-0.05,-0.05,-0.005);
    spike2();
    glPopMatrix();

    //spike side

        //spike 2
    glPushMatrix();
    glScaled(4,4,1);
    glRotated(-90,1,0,0);
    glTranslated(0.01,-0.1,0.025);
    spike2();
    glPopMatrix();

    glPushMatrix();
    glScaled(4,4,1);
    glRotated(90,1,0,0);
    glTranslated(0.012,-0.15,-0.012);
    spike1();
    glPopMatrix();

    //box
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(0.03,0.03,0.01);
    box(0.9,0.8,0.45,0.5,0.7,0.4);
    glPopMatrix();
    glPopMatrix();
}

void motor2()
{
        glPushMatrix();
        glRotated(MotorAngle2,1,0,0);
    //spike 1
    glPushMatrix();
    glScaled(1.5,3,2);
    glRotated(-90,0,0,1);
    glTranslated(-0.016,-0.05,-0.005);
    spike1();
    glPopMatrix();
    //spike 2
    glPushMatrix();
    glScaled(1.5,3,2);
    glRotated(-90,0,0,1);
    glTranslated(-0.05,-0.05,-0.005);
    spike2();
    glPopMatrix();

    //spike side

        //spike 2
    glPushMatrix();
    glScaled(4,4,1);
    glRotated(-90,1,0,0);
    glTranslated(0.01,-0.1,0.025);
    spike2();
    glPopMatrix();

    glPushMatrix();
    glScaled(4,4,1);
    glRotated(90,1,0,0);
    glTranslated(0.012,-0.15,-0.012);
    spike1();
    glPopMatrix();

    //box
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(0.03,0.03,0.01);
    box(0.9,0.8,0.45,0.5,0.7,0.4);
    glPopMatrix();
    glPopMatrix();
}

//**********************Func End********************
void robot()
{
    glPushMatrix();

     glTranslated(RJTx,RJTy,0);

     glPushMatrix();
    //head

    //eye 1
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(1.5,3.5,0);
    circle(0.5,0.8);
    glColor3f(0,0,0);
    circle(0.59,0.9);
    glPopMatrix();

        //eye 2
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(3.5,3.5,0);
    circle(0.5,0.8);
    glColor3f(0,0,0);
    circle(0.59,0.9);
    glPopMatrix();

    glColor3b(128, 50, 100);
    glBegin(GL_QUADS);
    glVertex2d(1.5,3.5);
    glVertex2d(3.5,3.5);
    glVertex2d(3.5,2);
    glVertex2d(1.5,2);
    glEnd();

    glColor3b(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(1,3.5);
    glVertex2d(1.4,3.5);
    glVertex2d(1.4,0);
    glVertex2d(1,0);
    glEnd();

    glColor3b(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(3.6,3.5);
    glVertex2d(4,3.5);
    glVertex2d(4,0);
    glVertex2d(3.6,0);
    glEnd();

        glPushMatrix();
    glScaled(1,1,0.5);
    head();
    glPopMatrix();
        glPushMatrix();
    glScaled(0.6,0.3,0.4);
    glTranslated(4.3,15,-3);
    sphere(0.721568,0.92549,0.92549);
    glPopMatrix();

    //**************mouth
            glPushMatrix();
    glTranslated(2.5,1.4,0.1);
    glColor3f(0.721568,0.92549,0.92549);
    circle(0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,1.2,0.1);
    glColor3f(0,0,0);
    circle(0.7,0.7);
    glPopMatrix();

    glPopMatrix();
//******************************* end of face



        //body


        //*****************************dots

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(-0.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

        glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(0,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

        glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(0.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(1.6,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(2.2,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(3,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

      glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(3.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(4.6,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    dots(5.4,-3);
        //*************************************Strips

                   glPushMatrix();
        glTranslated(-0.7,-4.5,0);
        glScaled(1.2,0.03,1);
        MyQuads(0,1,0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.2,-0.5,0);
        strips(0,1,0);
        glPopMatrix();

                glPushMatrix();
        glTranslated(4.8,-0.5,0);
        strips(0,1,0);
        glPopMatrix();
            //********************************Cross
            glPushMatrix();
            glTranslated(1.5,-7.5,0);

            glPushMatrix();
            glTranslated(0,0,0);
            glBegin(GL_QUADS);
            glVertex2d(0,0);
            glVertex2d(0.4,0);
            glVertex2d(1.5,1.5);
            glVertex2d(1.1,1.5);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(0,0,0);
            glBegin(GL_QUADS);
            glVertex2d(1.5,0);
            glVertex2d(1.1,0);
            glVertex2d(0,1.5);
            glVertex2d(0.4,1.5);
            glEnd();
            glPopMatrix();
            glPopMatrix();

                        glPushMatrix();
            glTranslated(1.5,-7.5,0);

            glPushMatrix();
            glTranslated(0,0,-3.5);
            glBegin(GL_QUADS);
            glVertex2d(0,0);
            glVertex2d(0.4,0);
            glVertex2d(1.5,1.5);
            glVertex2d(1.1,1.5);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(0,0,-3.5);
            glBegin(GL_QUADS);
            glVertex2d(1.5,0);
            glVertex2d(1.1,0);
            glVertex2d(0,1.5);
            glVertex2d(0.4,1.5);
            glEnd();
            glPopMatrix();
            glPopMatrix();
            //***************************Cross End



                   glPushMatrix();
        glTranslated(-0.7,-9,0);
        glScaled(1.2,0.03,1);
        MyQuads(0,1,0);
        glPopMatrix();


           glPushMatrix();
        glTranslated(-0.95,-9,0);
        glScaled(1.3,1,1);
        MyQuads(0.2,0.2,0.2);
        glPopMatrix();



        //*********************





        //**********mainboady
    glPushMatrix();
    glColor3f(0.13,0.12,0.14);
    glTranslated(-1.4,-10,0);
    glScaled(1.5,1.7,0.7);
    box(0.6, 0.6, 0.6,0.4,0.4,0.4);
    glPopMatrix();




        //throat
    glPushMatrix();
    glTranslated(1.7,-3,0);
    glScaled(0.3,0.8,0.3);
    box(0.3,0.2,0.4,0.4,0.4,0.4);
    glPopMatrix();

    glPushMatrix();
    glRotated(CoverAngleL,0,0,1);
    //*************************hand left

//*********************************Dana

    glPushMatrix();
    glTranslated(-2.5,-2,3);
    glRotated(-100,1,0,0);

    glScaled(0.2,0.9,0.3);
    Leftdana(0.2,0.2,0.2,0.6, 0.6, 0.6);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-2,-2.6,3.6);
    glScaled(0.17,0.17,0.17);
    sphere(0.5,0.3,0.4);
    glPopMatrix();
//******************************Kobji

        glPushMatrix();
        glRotated(LefthandTheta1,0,0,1);
        glPushMatrix();
    glTranslated(-2.5,-3.2,4.5);
    glRotated(LefthandTheta,1,0,0);
    glScaled(0.5,1.5,0.5);
    Rightkobji(0.5,0.5,0.5,0.6, 0.6, 0.6);
    glPopMatrix();
    glPopMatrix();

    //********************************Musti
            glPushMatrix();
    glTranslated(LglovsX,LglovsY,LglovsZ);
    glRotated(LSpAngle,0,0,1);
    glRotated(-LSpAngleX,0,1,0);
    glScaled(20,20,20);
    motor();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotated(CoverAngleR,0,0,1);
        //*************************Right hand

    glPushMatrix();

    glTranslated(RHTx,RHTy,RHTz);
//*********************************Dana
    glPushMatrix();
    glTranslated(-2.5,-2,3);
    glRotated(-100,1,0,0);

    glScaled(0.2,0.9,0.3);
    Rightdana(0.2,0.2,0.2,0.6, 0.6, 0.6);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-2,-2.6,3.6);
    glScaled(0.17,0.17,0.17);
    sphere(1, 0, 0);
    glPopMatrix();
//******************************Kobji
        glPushMatrix();
    glTranslated(-2.5,-3.2,4.5);
    glRotated(handRightTheta,1,0,0);
    glScaled(0.5,1.5,0.5);
    Rightkobji(0.5,0.5,0.5,0.6, 0.6, 0.6);
    glPopMatrix();



    //********************************Musti
            glPushMatrix();
    glTranslated(RglovsX,RglovsY,RglovsZ);
    glRotated(SpAngle,0,0,1);
    glRotated(-SpAngleX,0,1,0);

    glScaled(20,20,20);
    SpikeFist();
    glPopMatrix();
    glPopMatrix();
    //*******************************************

    glPopMatrix();

    //***************************************leg left

    glPushMatrix();
    glTranslated(-1,-15,-1);
    glScaled(0.4,1,0.2);
    box(0.2,0.3,0.1,0.4,0.5,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.1,-6,-0.9);
    strips(0.5,0.5,0.7);
    glPopMatrix();

                glPushMatrix();
    glTranslated(0,-15,-1);
    glScaled(0.3,0.1,0.5);
    sphere(0.5,0.3,0.4);
    glPopMatrix();

        //***************************************leg right

    glPushMatrix();
    glTranslated(3.5,-15,-1);
    glScaled(0.4,1,0.2);
    box(0.2,0.3,0.1,0.4,0.5,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.6,-6,-0.9);
    strips(0.5,0.5,0.7);
    glPopMatrix();

                    glPushMatrix();
    glTranslated(4.5,-15,-1);
    glScaled(0.3,0.1,0.5);
    sphere(0.5,0.3,0.4);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}


void robot2()
{
    glPushMatrix();

     glTranslated(RJTx2,RJTy2,0);

     glPushMatrix();
    //head

    //eye 1
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(1.5,3.5,0);
    circle(0.5,0.8);
    glColor3f(0,0,0);
    circle(0.59,0.9);
    glPopMatrix();

        //eye 2
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslated(3.5,3.5,0);
    circle(0.5,0.8);
    glColor3f(0,0,0);
    circle(0.59,0.9);
    glPopMatrix();

    glColor3b(128, 50, 100);
    glBegin(GL_QUADS);
    glVertex2d(1.5,3.5);
    glVertex2d(3.5,3.5);
    glVertex2d(3.5,2);
    glVertex2d(1.5,2);
    glEnd();

    glColor3b(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(1,3.5);
    glVertex2d(1.4,3.5);
    glVertex2d(1.4,0);
    glVertex2d(1,0);
    glEnd();

    glColor3b(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(3.6,3.5);
    glVertex2d(4,3.5);
    glVertex2d(4,0);
    glVertex2d(3.6,0);
    glEnd();

        glPushMatrix();
    glScaled(1,0.3,0.5);
    head();
    glPopMatrix();
        glPushMatrix();
    glScaled(0.6,0.3,0.4);
    glTranslated(4.3,15,-3);
    sphere(0.721568,0.92549,0.92549);
    glPopMatrix();

    //**************mouth
            glPushMatrix();
    glTranslated(2.5,1.4,0.1);
    glColor3f(0.721568,0.92549,0.92549);
    circle(0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,1.2,0.1);
    glColor3f(0,0,0);
    circle(0.7,0.7);
    glPopMatrix();

    glPopMatrix();
//******************************* end of face



        //body


        //*****************************dots

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(-0.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

        glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(0,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

        glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(0.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(1.6,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(2.2,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(3,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

      glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(3.8,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslated(4.6,-3,0);
    circle(0.2,0.4);
    glColor3f(0,0,0);
    circle(0.25,0.45);
    glPopMatrix();

    dots(5.4,-3);
        //*************************************Strips

                   glPushMatrix();
        glTranslated(-0.7,-4.5,0);
        glScaled(1.2,0.03,1);
        MyQuads(0,1,0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.2,-0.5,0);
        strips(1,0,0);
        glPopMatrix();

                glPushMatrix();
        glTranslated(4.8,-0.5,0);
        strips(1,0,0);
        glPopMatrix();
            //********************************Cross
            glPushMatrix();
            glTranslated(1.5,-7.5,0);

            glPushMatrix();
            glTranslated(0,0,0);
            glBegin(GL_QUADS);
            glVertex2d(0,0);
            glVertex2d(0.4,0);
            glVertex2d(1.5,1.5);
            glVertex2d(1.1,1.5);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(0,0,0);
            glBegin(GL_QUADS);
            glVertex2d(1.5,0);
            glVertex2d(1.1,0);
            glVertex2d(0,1.5);
            glVertex2d(0.4,1.5);
            glEnd();
            glPopMatrix();
            glPopMatrix();

                        glPushMatrix();
            glTranslated(1.5,-7.5,0);

            glPushMatrix();
            glTranslated(0,0,-3.5);
            glBegin(GL_QUADS);
            glVertex2d(0,0);
            glVertex2d(0.4,0);
            glVertex2d(1.5,1.5);
            glVertex2d(1.1,1.5);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(0,0,-3.5);
            glBegin(GL_QUADS);
            glVertex2d(1.5,0);
            glVertex2d(1.1,0);
            glVertex2d(0,1.5);
            glVertex2d(0.4,1.5);
            glEnd();
            glPopMatrix();
            glPopMatrix();
            //***************************Cross End



                   glPushMatrix();
        glTranslated(-0.7,-9,0);
        glScaled(1.2,0.03,1);
        MyQuads(0,1,0);
        glPopMatrix();


           glPushMatrix();
        glTranslated(-0.95,-9,0);
        glScaled(1.3,1,1);
        MyQuads(0.2,0.2,0.2);
        glPopMatrix();



        //*********************





        //**********mainboady
    glPushMatrix();
    glColor3f(0.13,0.12,0.14);
    glTranslated(-1.4,-10,0);
    glScaled(1.5,1.7,0.7);
    box(0.7, 0.5, 0.5,0.4,0.4,0.4);
    glPopMatrix();




        //throat
    glPushMatrix();
    glTranslated(1.7,-3,0);
    glScaled(0.3,0.8,0.3);
    box(0.3,0.2,0.4,0.4,0.4,0.4);
    glPopMatrix();

    glPushMatrix();
    glRotated(CoverAngleL2,0,0,1);
    //*************************hand left

//*********************************Dana

    glPushMatrix();
    glTranslated(-2.5,-2,3);
    glRotated(-100,1,0,0);

    glScaled(0.2,0.9,0.3);
    Leftdana(0.2,0.2,0.2,0.6, 0.6, 0.6);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-2,-2.6,3.6);
    glScaled(0.17,0.17,0.17);
    sphere(0.5,0.3,0.4);
    glPopMatrix();
//******************************Kobji

        glPushMatrix();
        glRotated(LefthandTheta12,0,0,1);
        glPushMatrix();
    glTranslated(-2.5,-3.2,4.5);
    glRotated(LefthandTheta2,1,0,0);
    glScaled(0.5,1.5,0.5);
    Rightkobji(0.7, 0.5, 0.5,0.4,0.4,0.4);
    glPopMatrix();
    glPopMatrix();

    //********************************Musti
            glPushMatrix();
    glTranslated(LglovsX2,LglovsY2,LglovsZ2);
    glRotated(LSpAngle2,0,0,1);
    glRotated(-LSpAngleX2,0,1,0);
    glScaled(20,20,20);
    motor2();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotated(CoverAngleR2,0,0,1);
        //*************************Right hand

    glPushMatrix();

    glTranslated(RHTx2,RHTy2,RHTz2);
//*********************************Dana
    glPushMatrix();
    glTranslated(-2.5,-2,3);
    glRotated(-100,1,0,0);

    glScaled(0.2,0.9,0.3);
    Rightdana(0.2,0.2,0.2,0.6, 0.6, 0.6);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-2,-2.6,3.6);
    glScaled(0.17,0.17,0.17);
    sphere(1, 0, 0);
    glPopMatrix();
//******************************Kobji
        glPushMatrix();
    glTranslated(-2.5,-3.2,4.5);
    glRotated(handRightTheta2,1,0,0);
    glScaled(0.5,1.5,0.5);
    Rightkobji(0.7, 0.5, 0.5,0.4,0.4,0.4);
    glPopMatrix();



    //********************************Musti
            glPushMatrix();
    glTranslated(RglovsX2,RglovsY2,RglovsZ2);
    glRotated(SpAngle2,0,0,1);
    glRotated(-SpAngleX2,0,1,0);

    glScaled(20,20,20);
    SpikeFist2();
    glPopMatrix();
    glPopMatrix();
    //*******************************************

    glPopMatrix();

    //***************************************leg left

    glPushMatrix();
    glTranslated(-1,-15,-1);
    glScaled(0.4,1,0.2);
    box(0.2,0.3,0.1,0.4,0.5,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.1,-6,-0.9);
    strips(0.5,0.5,0.7);
    glPopMatrix();

                glPushMatrix();
    glTranslated(0,-15,-1);
    glScaled(0.3,0.1,0.5);
    sphere(0.5,0.3,0.4);
    glPopMatrix();

        //***************************************leg right

    glPushMatrix();
    glTranslated(3.5,-15,-1);
    glScaled(0.4,1,0.2);
    box(0.2,0.3,0.1,0.4,0.5,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.6,-6,-0.9);
    strips(0.5,0.5,0.7);
    glPopMatrix();

                    glPushMatrix();
    glTranslated(4.5,-15,-1);
    glScaled(0.3,0.1,0.5);
    sphere(0.5,0.3,0.4);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void sides()
{
            glPushMatrix();
        glRotated(120,1,1,0);
        glTranslated(0,0,-10);
        glColor3f(0,1,0.5);
        glBegin(GL_QUADS);
        glVertex3d(0,0,0);
        glVertex3d(500,0,0);
        glVertex3d(500,300,50);
        glVertex3d(0,300,50);
        glEnd();
        glPopMatrix();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    //Text
        char text1[]="Player 1 Score:";
        char text2[]="Player 1 Health:100";
        char text3[]="Player 1 situation: Attacking";
        glPushMatrix();
        glTranslated(-0.95,-0.08,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text1);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text1[i]);
        }
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.95,-0.2,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text2);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text2[i]);
        }
        glPopMatrix();


        glPushMatrix();
        glTranslated(-0.95,-0.31,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text3);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text3[i]);
        }
        glPopMatrix();

        //

        char text4[]="Player 2 Score:";
        char text5[]="Player 2 Health:100";
        char text6[]="Player 2 situation: Attacking";
        glPushMatrix();
        glTranslated(0.7,-0.08,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text1);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text4[i]);
        }
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.7,-0.2,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text2);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text5[i]);
        }
        glPopMatrix();


        glPushMatrix();
        glTranslated(0.7,-0.31,0);
        glColor3f(1,1,1);
        glRasterPos3f(0,0,0);

        for(int i=0;i<strlen(text3);i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text6[i]);
        }
        glPopMatrix();
    //end


    //*******************Light*******************

     glPushMatrix();
    glScaled(0.0005,0.0005,0.0005);

    light(-1300,1800);
    light(500,1800);
    light(2300,1900);

    glPopMatrix();




    //*****************Light End****************

    glPushMatrix();
    glScaled(0.015,0.025,0.015);
    glTranslated(Tx,Ty,-5);
    glRotated(angle,0,1,0);
    //***********************Robot*********************
    robot();
    glPopMatrix();

    //**************************************Robot 1 End*******************

        glPushMatrix();
    glScaled(0.015,0.025,0.015);
    glTranslated(Tx2,Ty2,-5);
    glRotated(angle2,0,1,0);
    //***********************Robot*********************
    robot2();
    glPopMatrix();
    //**************************************Robot 2 End*******************



    //**********************************Stage*****************************

    stage();


    //***********************stage end

    //******************Chair code*********************
    glTranslated(0,100,90);

    //*******************visitors****************
    for(int i=-413;i<322;i+=70)
    {
    glPushMatrix();
    glTranslated(i,-50,0);
    glScaled(0.5,0.7,1);
    visitors();
    glPopMatrix();
    }




    //visitor end*******************





            glPushMatrix();

    glScaled(0.7,0.7,1);
    glTranslated(0,-200,0);

        chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);




for(int i=-580;i<322;i+=100)
    {
    glPushMatrix();

    glTranslated(i,200,0);
    glScaled(0.7,0.8,1);
    normalvisitors();
    glPopMatrix();
    }



   glPushMatrix();
    glTranslated(10,70,0);
    chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);
    glPopMatrix();



for(int i=-422;i<250;i+=100)
    {
    glPushMatrix();
    glTranslated(i,300,0);
    glScaled(0.7,0.8,1);
    visitors();
    glPopMatrix();
    }

for(int i=280;i<650;i+=100)
    {
    glPushMatrix();
    glTranslated(i,300,0);
    glScaled(0.7,0.8,1);
    normalvisitors();
    glPopMatrix();
    }



         glPushMatrix();
    glTranslated(20,140,0);
    chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);
    glPopMatrix();

         glPushMatrix();
    glTranslated(30,210,0);
    chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);
    glPopMatrix();




for(int i=-455;i<250;i+=100)
    {
    glPushMatrix();
    glTranslated(i,400,0);
    glScaled(0.7,0.8,1);
    visitors();
    glPopMatrix();
    }

for(int i=300;i<650;i+=100)
    {

    glPushMatrix();

    glTranslated(i,400,0);
    glScaled(0.7,0.8,1);
    normalvisitors();
    glPopMatrix();
    }





        glPushMatrix();
        glTranslated(40,280,0);
    chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);
    glPopMatrix();



for(int i=-445;i<250;i+=100)
    {
    glPushMatrix();
    glTranslated(i,500,0);
    glScaled(0.7,0.8,1);
    visitors();
    glPopMatrix();
    }

for(int i=310;i<650;i+=100)
    {

    glPushMatrix();

    glTranslated(i,500,0);
    glScaled(0.7,0.8,1);
    normalvisitors();
    glPopMatrix();
    }


        glPushMatrix();
    glTranslated(50,350,0);
    chair(-200,600);
    chair(-400,600);
    chair(-600,600);
    chair(-800,600);
    chair(-1000,600);
    chair(-1200,600);
    chair(-1400,600);
    chair(-1600,600);
    chair(-1800,600);
    chair(-2000,600);
    chair(-2200,600);
    chair(0,600);
    chair(200,600);
    chair(400,600);
    chair(600,600);
    chair(800,600);
    chair(1000,600);
    chair(1200,600);
    chair(1400,600);
    chair(1600,600);
    chair(1800,600);
    chair(2000,600);
    chair(2200,600);
    chair(2400,600);
    glPopMatrix();

glPopMatrix();

    //Chair end********
  glPopMatrix();

    //*********************************Stage code end***********************
    glutSwapBuffers();
}



int main()
{
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Robot");
    init();
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshapeFunc);
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(my_keyboard);
    glutIdleFunc(clapping);
    PlaySound("ST.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);



    glutMainLoop();
    return 0;
}

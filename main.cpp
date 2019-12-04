#include <windows.h>
#include <GL/glut.h>
#include <math.h>

bool depan = true;

GLuint texid;
GLuint texwidth=2;
GLuint texheight=2;
GLubyte texData[16] =
{
	0xFF,0x00,0x00,0xFF, // red
	0x00,0xFF,0x00,0xFF, // rgreen
	0x00,0x00,0xFF,0xFF, // blue
	0xFF,0xFF,0xFF,0xFF  // white
};

void InitTexture()
{
   glEnable(GL_TEXTURE_2D);
   glGenTextures(1,&texid);
   glBindTexture(GL_TEXTURE_2D,texid);
   glTexImage2D (GL_TEXTURE_2D,0,4,texwidth,texheight,0,GL_RGBA,GL_UNSIGNED_BYTE,texData);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void initGL() {
   glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   InitTexture();
    glLineWidth(3.0);
}
////////////////////////////////////////////////////////////////////////////////////////
void horizontalz(float X, float Y, float Z, float z, float R, float G, float B)
{
   glBegin(GL_QUADS);
     glColor3f(R, G, B);
// Dasar
      glVertex3f( X, -Y,  Z);
      glVertex3f(-X, -Y,  Z);
      glVertex3f(-X, -Y, -Z);
      glVertex3f( X, -Y, -Z);
//DEPAN
	glVertex3f( X,  Y, Z);
	glVertex3f(-X,  Y, Z);
	glVertex3f(-X, -Y, Z);
	glVertex3f( X, -Y, Z);
// belakang
      glVertex3f( X, -Y, z);
      glVertex3f(-X, -Y, z);
      glVertex3f(-X,  Y, z);
      glVertex3f( X,  Y, z);
// kiri
      glVertex3f(-X,  Y,  Z);
      glVertex3f(-X,  Y, z);
      glVertex3f(-X, -Y, z);
      glVertex3f(-X, -Y,  Z);
 // kanan
      glVertex3f(X,  Y, z);
      glVertex3f(X,  Y,  Z);
      glVertex3f(X, -Y,  Z);
      glVertex3f(X, -Y, z);
	glEnd();
}
////////////////////////////////////////////////////////////////////////////////////
void horizontalx(float x, float y, float z, float panjang, float tinggi, float lebar) {
	//Depan
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
	glEnd();
	//Belakang
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
	//Atap
	if (x == -25.0, y ==-10.0, z == -70.0){
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 0.5f, 0.7f);
	glVertex3f(x, y + tinggi, z);
	glColor4f(0.5f, 1.0f, 1.0f, 0.7f);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glColor4f(0.0f, 0.0f, 0.5f, 0.7f);
	glVertex3f(x, y + tinggi, z - lebar);
	glEnd();
	}
	//Alas
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
	//Kiri
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
	//Kanan
	glBegin(GL_POLYGON);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
}
//////////////////////////////////////////////////////////////////////////////////////
void kotakFB(float x, float y, float z, float panjang, float tinggi) {
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
	glEnd();
}
void kotakLR(float x, float y, float z, float tinggi,float lebar) {
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
}
void garistunggal(float n, float z,float i,float j, float k)
{int l;
while ( n > z){
        glBegin(GL_LINES);
        glLineWidth(100.0);
        glVertex3f(i,n,j);
        glVertex3f(k,n,j);
          glEnd();
          n++;
          n -= 2;
}return;}

void lingkaran(float xp, float yp, float r, float n,float z){
    float a,x,y;
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex3f(x,y,z);
        }
    glEnd();
}
void meja(float xp, float y, float r, float n,float zp){
    float a,x,z;
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            z= zp+r * sin(i*a);
            glVertex3f(x,y,z);
        }
    glEnd();
    glColor3f(0.5f, 0.5f, 0.0f);
          glBegin(GL_LINE_LOOP);
       glVertex3f( xp-r,  y-0.1, zp);
     glVertex3f( xp-r,  y-4, zp);
    glVertex3f( xp+r,  y-4, zp);
     glVertex3f( xp+r,  y-0.1, zp);
       glEnd();
       glBegin(GL_LINE_LOOP);
     glVertex3f( xp,  y-0.1, zp-r);
     glVertex3f( xp,  y-4, zp-r);
    glVertex3f( xp,  y-4, zp+r);
     glVertex3f( xp,  y-0.1, zp+r);
     glEnd();
}
/////////////////////////////////////////////////////////////////////////////////////
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   //////DASAR
      glBegin(GL_QUADS);
     glColor3f(0.0f, 0.4f, 0.0f);      // atas
      glVertex3f( 40.0f, -10.1f,  50.0f);
      glVertex3f(-60.0f, -10.1f,  50.0f);
     glColor3f(0.0f, 0.6f, 0.0f);
      glVertex3f(-60.0f, -10.1f, -125.0f);
      glColor3f(0.0f, 0.0f, 0.8f);
      glVertex3f( 40.0f, -10.1f, -125.0f);
      glColor3f(0.1f, 0.1f, 0.1f);      // semen
      glVertex3f( 11.0f, -10.0f,  9.0f);
      glVertex3f(11.0f, -10.0f,  40.0f);
      glVertex3f(-11.0f, -10.0f,40.0f);
      glVertex3f( -11.0f, -10.0f, 9.0f);
      glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////Gedung depan
horizontalz(10.0,10.0,10.0,-20.0,0.2,0.0,0.2);
glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
kotakFB(-8.5,-6.5,10.2,4.0,8.0);//jendela
kotakFB(4.5,-6.5,10.2,4.0,8.0);
kotakLR(10.2, -6.5, 5.2, 8.5, 5.0);
kotakLR(10.2, -6.5, -2.6, 8.5, 5.0);
kotakLR(10.2, -6.5, -10.2, 8.5, 5.0);
kotakLR(-10.2, -7.0, 7.1 , 10.0, 23.5);
glColor4f(1.0f, 0.5f, 0.0f, 0.7f);
lingkaran(0.0,6.0,2.0,100.0,10.1);
glColor3f(0.5f, 0.2f, 0.0f);
kotakFB(-3.0,-9.9,10.2,6.0,11.4);//pintu
/////////////////MOTIF/////////////////////////
glColor3f(0.1f, 0.0f, 0.0f);
kotakFB(-10.0,-9.9,10.1,20.0,4.9);//dpn
kotakLR(-10.1, -9.9, 10.0 , 4.9, 30.0);//kiri
kotakLR(10.1, -9.9, 10.0 , 4.9, 30.0);//kanan
kotakFB(-50.0,-9.9,-19.9,54.8,4.9);//dpn gdg blkng
kotakFB(-50.0,-9.9,-60.1,54.5,4.9);
kotakLR(-50.1, -9.9, -20.0 , 4.9, 90.0);
kotakFB(-50.0,-9.9,-110.1,15.0,4.9);
kotakLR(-34.9, -9.9, -60.0 , 4.9, 50.0);
kotakLR(4.7, -9.9, -21.0 , 4.9, 39.2);
//////////garasi///////////////
horizontalx(-50.0,-10.0,10.0,20.0,20.0,30.0);
glBegin(GL_QUADS);
glVertex3f( -50.0f,  10.0f, 10.0f);
glVertex3f(-50.0f,  10.0f, -20.0f);
glVertex3f(-30.0f, 10.0f, -20.0f);
glVertex3f(-30.0f, 10.0f, 10.0f);
glEnd();
glColor3f(0.4f, 0.2f, 0.0f);
kotakFB(-49.0,-9.9,10.1,18.0,19.0);
glColor3f(0.6f, 0.6f, 0.6f);
garistunggal(8.9, -10.0,-49.0,10.2, -31.0);
///////////////////////////////
glBegin(GL_LINES); //gagang pintu
      glColor3f(0.0f,0.0f,0.0f);
     glVertex3f( 0.5f,  -3.0f, 10.3f);
    glVertex3f( 0.5f,  -5.0f, 10.3f);///
    glVertex3f( -0.5f,  -3.0f, 10.3f);
    glVertex3f( -0.5f,  -5.0f, 10.3f);//
     glVertex3f( 0.0f,  1.5f, 10.3f);
     glVertex3f( 0.0f,  -9.9f, 10.3f);
    glEnd();
    glBegin(GL_LINE_LOOP);
     glColor3f(0.0f, 0.0f, 0.0f);  // pintu
       glVertex3f( -3.0f,  1.5f, 10.2f);
       glVertex3f(3.0f,  1.5f, 10.2f);
      glVertex3f(3.0f, -9.9f, 10.2f);
      glVertex3f( -3.0f, -9.9f, 10.2f);
       glEnd();
////////////////////////////////////tiang ///////////////////////////////////////////////////////////
 glColor3f(0.2f, 0.2f, 0.2f);
  horizontalx(8.0,-10.0,37.0,2.0,20.0,2.0);//front
  horizontalx(-10.0,-10.0,37.0,2.0,20.0,2.0);
    horizontalx(30.0,-10.0,-21.0,3.0,40.0,2.0);//right
 horizontalx(30.0,-10.0,-56.5,3.0,40.0,2.0);
//////////////////////////////////Atap rumah depan////////////////////////////////////////////////////////////
      glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.2f, 0.2f);     //atap
      glVertex3f(-12.0f, 10.0f,  40.0f);
      glVertex3f( 12.0f, 10.0f,  40.0f);
      glColor3f(0.8f, 0.2f, 0.7f);
        glVertex3f( 0.0f, 18.0f,  10.0f);
 //atap samping kiri
      glVertex3f( 0.0f, 18.0f,  10.0f);
       glColor3f(0.1f, 0.2f, 0.2f);
    glVertex3f(-12.0f, 10.0f,  -20.0f);
     glVertex3f(-12.0f, 10.0f, 40.0f);
 //atap belakang
      glVertex3f(-12.0f, 10.0f,  -20.0f);
      glVertex3f(12.0f, 10.0f, -20.0f);
      glColor3f(0.8f, 0.2f, 0.7f);
     glVertex3f( 0.0f, 18.0f,  10.0f);
 //atap samping kanan
      glVertex3f( 0.0f, 18.0f,  10.0f);
   glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(12.0f, 10.0f,  -20.0f);
      glVertex3f(12.0f, 10.0f, 40.0f);
glEnd();
//////////////////////////////////////////////////
  glBegin(GL_QUADS);
    //kap
      glVertex3f( 12.0f,  10.0f, -20.0f);
       glVertex3f(12.0f,  10.0f, 40.0f);
      glVertex3f(-12.0f, 10.0f, 40.0f);
      glVertex3f( -12.0f, 10.0f, -20.0f);
    //kap2
glVertex3f( -51.0f,  30.0f, -19.0f);
glVertex3f(-51.0f,  30.0f, -61.0f);
glVertex3f(35.0f, 30.0f, -61.0f);
glVertex3f( 35.0f, 30.0f, -19.0f);
    //kap3
glVertex3f( -51.0f,  10.0f, -59.0f);
glVertex3f(-51.0f,  10.0f, -111.0f);
glVertex3f(-34.0f, 10.0f, -111.0f);
glVertex3f(-34.0f, 10.0f, -59.0f);

   glEnd();
   ///////////////////////////////////GEDUNG 2///////////////////////////////////////////////////////
glColor3f(0.0f, 0.2f, 0.2f);
horizontalx(-50.0,-10.0,-20.0,54.5,20.0,40.0);
glColor3f(0.0f, 0.5f, 0.5f);
horizontalx(2.5, -10.0,-21.0,30.5,1.0,37.5);
glColor3f(0.6f, 0.0f, 0.2f);
horizontalx(-49.0,10.0,-21.0,51.5,20.0,37.5);//tingkat 2
glColor3f(0.4f, 0.0f, 0.0f);
horizontalx(2.5, 9.0,-21.0,30.5,1.0,37.5);
glColor4f(1.0f, 0.8f, 0.8f, 0.7f);
kotakFB(2.8,10.0,-22.0,30.0,6.0);////barier1//////
kotakFB(2.8,10.0,-57.0,30.0,6.0);
kotakLR(32.0, 10.0, -22.0, 6.0, 35.0);
glColor4f(0.5f, 0.8f, 0.5f, 0.7f);
kotakFB(4.8,-9.0,-22.0,28.0,6.0);////barier2/////////
kotakLR(32.0, -9.0, -22.0, 6.0, 35.0);
kotakFB(2.8,-10.0,-57.0,10.0,6.0);
kotakFB(22.8,-10.0,-57.0,10.0,6.0);
glColor3f(0.6f, 0.2f, 0.0f);
horizontalx(-50.0,-10.0,-60.0,15.0,20.0,50.0);//back
glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
kotakLR(4.9, -6.5, -24.0, 8.5, 5.0);//kanan
kotakLR(4.9, -6.5, -50.0, 8.5, 5.0);
kotakLR(2.8, 14.5, -24.0, 8.5, 5.0);//kanan lt2
kotakLR(2.8, 14.5, -50.0, 8.5, 5.0);
kotakFB(-45.0,15.0,-20.9,44.0,10.0);// jendela depan
kotakFB(-27.0,-7.0,-19.9,5.0,10.0);
kotakFB(-18.0,-7.0,-19.9,5.0,10.0);
kotakFB(-45.0,15.0,-58.6,44.0,10.0);//jendela belakang
kotakFB(-30.0,-6.5,-60.2,4.0,8.0);//jendela bwh
kotakFB(-22.0,-6.5,-60.2,4.0,8.0);
kotakLR(-34.8, -6.5, -63.0 , 8.0, 4.0);//jendela bwh bck
kotakLR(-34.8, -6.5, -71.0 , 8.0, 4.0);
kotakLR(-34.8, -6.5, -94.0 , 8.0, 4.0);
kotakLR(-34.8, -6.5, -102.0 , 8.0, 4.0);
kotakLR(-50.2, -6.5, -62.0 , 10.0, 20.0);//jendela kiri bck
kotakLR(-50.2, -6.5, -86.0 , 10.0, 20.0);
kotakLR(-34.8, -9.9, -78.0 , 12.0, 12.0);//pintu
kotakFB(-10.0,-9.9,-60.2,12.0,12.0);
horizontalx(-25.0,-10.0,-70.0,60.0,0.2,50.0);//kolam renang
glColor3f(0.5f, 0.2f, 0.0f);
kotakLR(4.8, -8.9, -33.0 , 14.0, 14.0);
kotakLR(2.7, 10.1, -33.0 , 14.0, 14.0);
horizontalx(-30,-10.0,-65.0,60.0,0.2,50.0);//kolam renang
meja(20.0,-5.0,5.0,100.0,-40.0);//meja
meja(20.0,15.5,5.0,100.0,-40.0);//meja
///////////////////////////////////////////////////////////////
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);  // pintu
       glVertex3f( -4.0f,  2.0f, -60.3f);
     glVertex3f( -4.0f,  -9.9f, -60.3f);
       glEnd();
    glBegin(GL_LINES); // pintu2
       glVertex3f( -34.7f,  2.0f, -84.0f);
     glVertex3f( -34.7f,  -9.9f, -84.0f);
       glEnd();
    glBegin(GL_LINES); // pintu3
       glVertex3f( 4.9f,  5.1f, -40.0f);
     glVertex3f( 4.9f,  -9.9f, -40.0f);
       glVertex3f( 4.9f,  -1.0f, -39.0f);//
    glVertex3f( 4.9f,  -3.0f, -39.0f);
       glVertex3f( 4.9f,  -1.0f, -41.0f);
    glVertex3f( 4.9f,  -3.0f, -41.0f);
       glEnd();
     glBegin(GL_LINE_LOOP);
     glColor3f(0.0f, 0.0f, 0.0f);  // pintu
       glVertex3f( 4.9f,  5.1f, -33.0f);
       glVertex3f(4.9f,  5.1f, -46.9f);
      glVertex3f(4.9f, -8.9f, -46.9f);
      glVertex3f( 4.9f, -8.9f, -33.0f);
       glEnd();
     glBegin(GL_LINE_LOOP);
     glColor3f(0.0f, 0.0f, 0.0f);  // pintu4
       glVertex3f( 2.8f,  24.1f, -33.0f);
       glVertex3f(2.8f,  24.1f, -46.9f);
      glVertex3f(2.8f, 10.1f, -46.9f);
      glVertex3f( 2.8f, 10.1f, -33.0f);
       glEnd();
           glBegin(GL_LINES); //
       glVertex3f( 2.8f,  24.1f, -40.0f);
     glVertex3f( 2.8f,  10.1f, -40.0f);
       glVertex3f( 2.8f,  18.0f, -39.0f);//
    glVertex3f( 2.8f,  16.0f, -39.0f);
       glVertex3f( 2.8f,  18.0f, -41.0f);
    glVertex3f( 2.8f,  16.0f, -41.0f);
       glEnd();
////////////////////////////////////////////////////////////
     glBegin(GL_TRIANGLES);
 glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(-51.0f, 30.0f,  -61.0f);
        glVertex3f(-51.0f, 30.0f,  -19.0f);
    glColor3f(0.8f, 0.2f, 0.7f);
      glVertex3f(-30.0f, 40.0f,  -40.0f);
//
      glVertex3f(-5.0f, 40.0f,  -40.0f);
glColor3f(0.1f, 0.2f, 0.2f);
            glVertex3f(35.0f, 30.0f,  -61.0f);
            glVertex3f(35.0f, 30.0f, -19.0f);
glEnd();
 glBegin(GL_QUADS);
	glVertex3f(-51.0, 30.0,-61.0);
glColor3f(0.8f, 0.2f, 0.7f);
      glVertex3f(-30.0, 40.0, -40.0);
      glVertex3f(10.0, 40.0, -40.0);
glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(35.0, 30.0, -61.0);
 //
	glVertex3f(-51.0, 30.0,-19.0);
glColor3f(0.8f, 0.2f, 0.7f);
      glVertex3f(-35.0, 40.0, -40.0);
      glVertex3f(10.0, 40.0, -40.0);
 glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(35.0, 30.0, -19.0);
glEnd();
///////////////////////
     glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(-51.0f, 10.0f, -59.0f);
      glVertex3f( -34.0f, 10.0f, -59.0f);
      glColor3f(0.8f, 0.2f, 0.7f);
      glVertex3f(-48.0f, 18.0f,  -85.0f);
 //atap samping kiri
      glVertex3f( -48.0f, 18.0f,  -85.0f);
       glColor3f(0.1f, 0.2f, 0.2f);
    glVertex3f(-51.0f, 10.0f,  -59.0f);
     glVertex3f(-51.0f, 10.0f, -111.0f);
 //atap belakang
      glVertex3f(-51.0f, 10.0f,  -111.0f);
      glVertex3f(-34.0f, 10.0f, -111.0f);
      glColor3f(0.8f, 0.2f, 0.7f);
      glVertex3f(-48.0f, 18.0f,  -85.0f);
 //atap samping kanan
       glVertex3f( -48.0f, 18.0f,  -85.0f);
       glColor3f(0.1f, 0.2f, 0.2f);
      glVertex3f(-34.0f, 10.0f,  -59.0f);
     glVertex3f(-34.0f, 10.0f, -111.0f);
     glEnd();
/////////////////////////////////////////////////////////////////////////////

   glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
			 //gerak ke kiri
		case 'b':
		case 'B':
			depan = false;
			break;
			 //gerak ke kiri
		case 'v':
		case 'V':
			depan = true;
			break;
			 //gerak ke kiri
		case 'a':
		case 'A':
			glTranslatef(-1.0, 0.0, 0.0);
			break;
			 //gerak ke kanan
		case 'd':
		case 'D':
			glTranslatef(1.0, 0.0, 0.0);
			break;
			 //gerak ke depan
		case 'w':
		case 'W':
			glTranslatef(0.0, 0.0, 1.0);
			break;
			 //gerak ke belakang
		case 's':
		case 'S':
			glTranslatef(0.0, 0.0, -1.0);
			break;
			 //gerak ke atas
		case 'q':
		case 'Q':
			glTranslatef(0.0, 1.0, 0.0);
			break;
			 //gerak ke bawah
		case 'e':
		case 'E':
			glTranslatef(0.0, -1.0, 0.0);
			break;
			 //rotate ke kiri
		case 'j':
		case 'J':
			glRotatef(1.0, 0.0, -5.0, 0.0);
			break;
			//rotate ke kanan
		case 'l':
		case 'L':
			glRotatef(1.0, 0.0, 5.0, 0.0);
			break;
			//rotate ke samping kanan
		case 'i':
		case 'I':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case 'k':
		case 'K':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case 'o':
		case 'O':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case 'u':
		case 'U':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
   }
   display();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("672017081");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   initGL();
   glutMainLoop();
   return 0;
}

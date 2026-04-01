#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#define PI 3.141516

float sunPosition=0.2;
float sunSpeed=0.01;
float cloud1position=-1.0;
float cloud1speed=0.02;
float cloud2position=1.0;
float cloud2speed=0.02;
float ambulance_position=0;
float ambulance_speed=0.03;
float policecar_position=0;
float policecar_speed=0.007;
//float human1_Position=0.3f;
//float human1_Speed=0.008;
//float human2_Position=0.8f;
//float human2_Speed=0.01;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}



void Circle(GLfloat x, GLfloat y, GLfloat radius) {  ///circle code
    int i;
    int triangleAmount = 100; // # of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // Center of circle
        for(i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}


void update_cloud1(int value) {    ///left update cloud

    if(cloud1position <-1.0)
        cloud1position = 2.0f;

    cloud1position -= cloud1speed;

	glutPostRedisplay();


	glutTimerFunc(100, update_cloud1, 0);
}

void update_cloud2(int value1) {    ///right update cloud

    if(cloud2position <-1.0)
        cloud2position= 3.0f;

    cloud2position -= cloud2speed;

	glutPostRedisplay();


	glutTimerFunc(100, update_cloud2, 0);
}



void update_Sun(int value)///update sun
    {
    sunPosition+=sunSpeed;
    if(sunPosition>1.0)
    {
        sunPosition=-0.5;
    }

    glutPostRedisplay();
    glutTimerFunc(80, update_Sun, 0);
    }

    void update_ambulance(int value) {    ///update ambulance

    if(ambulance_position >=2.5)
        ambulance_position = -1.0f;

    ambulance_position += ambulance_speed;

	glutPostRedisplay();
glutTimerFunc(100, update_ambulance, 0);
    }


    void update_policecar(int value) {    ///update police car

    if(policecar_position >=2.5)
        policecar_position = -1.0f;

    policecar_position += policecar_speed;

	glutPostRedisplay();
glutTimerFunc(100, update_policecar, 0);
}


/*void update_human1(int value)                 ///AFID-6
{
    human1_Position+=human1_Speed;
    if(human1_Position>1.0)
    {
        human1_Position=-1.0;
    }


        glutPostRedisplay();
    glutTimerFunc(100, update_human1, 0);
}

void update_human2(int value)                 ///AFID-6
{
     human2_Position-=human2_Speed;
    if(human2_Position<-1.0)
    {
        human2_Position=+1.0;
    }

        glutPostRedisplay();
    glutTimerFunc(100, update_human2, 0);
}*/


void display1() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glPointSize (5.0);


   /* glBegin (GL_POINTS);
    glColor3f(0.0f , 0.0f , 0.0f);
    glVertex2f (-0.0f, -0.0f);
     glEnd();




*/




       ///sky

glBegin(GL_QUADS);

glColor3f(0.4f, 0.4f, 0.4f); // Sky color using glColor3f

glVertex2f(-1.0f, 0.1f);

glVertex2f(1.0f, 0.1f);

glColor3f(0.1f, 0.1f, 0.1f);

glVertex2f(1.0f, 1.0f);

glVertex2f(-1.0f, 1.0f);

glEnd();

///star
glPointSize(3);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);

glVertex2f(-0.9f, 0.9f);
glVertex2f(-0.85f, 0.85f);
glVertex2f(-0.8f, 0.75f);
glVertex2f(-0.75f, 0.85f);
glVertex2f(-0.78f, 0.75f);
glVertex2f(-0.65f, 0.75f);
glVertex2f(-0.6f, 0.9f);
glVertex2f(-0.55f, 0.85f);
glVertex2f(-0.45f, 0.85f);
glVertex2f(-0.38f, 0.75f);
glVertex2f(-0.2f, 0.9f);
glVertex2f(-0.15f, 0.85f);
glVertex2f(-0.1f, 0.85f);
glVertex2f(-0.0f, 0.75f);
glVertex2f(-0.7f, 0.9f);
glVertex2f(-0.3f, 0.85f);
glVertex2f(-0.48f, 0.85f);
glVertex2f(-0.25f, 0.75f);
glVertex2f(-0.32f, 0.75f);
glVertex2f(-0.18f, 0.75f);

glVertex2f(0.32f, 0.75f);
glVertex2f(0.18f, 0.75f);
glVertex2f(0.9f, 0.9f);
glVertex2f(0.85f, 0.85f);
glVertex2f(0.75f, 0.85f);
glVertex2f(0.78f, 0.75f);
glVertex2f(0.6f, 0.9f);
glVertex2f(0.55f, 0.85f);
glVertex2f(0.45f, 0.85f);
glVertex2f(0.38f, 0.75f);
glVertex2f(0.2f, 0.9f);
glVertex2f(0.15f, 0.85f);
glVertex2f(0.1f, 0.85f);
glVertex2f(0.0f, 0.75f);
glVertex2f(0.7f, 0.9f);
glVertex2f(0.3f, 0.85f);
glVertex2f(0.48f, 0.85f);
glVertex2f(0.25f, 0.75f);
glVertex2f(-0.25f, 0.75f);
glVertex2f(-0.35f, 0.75f);
glEnd();



    ///sky 2
    /*glBegin(GL_QUADS);
glColor3f(0.988f, 0.639f, 0.239f); // sky
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glColor3f(0.0f, 0.522f, 1.0f); // sky transition
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.451f, 0.451f, 0.451f); // line
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glEnd();*/




    //moon
    glColor3f(0.89,0.84,0.67);
    Circle(-0.65, 0.85, 0.07);






 /// Draw cloud 1 right
 glPushMatrix();
 glTranslatef(cloud1position,0,0);
    glColor3f(0.6f, 0.6f, 0.6f); // White color for cloud

    /// Base circles1
    Circle(-0.7f, 0.8f, 0.1f); // First circle
    Circle(-0.6f, 0.8f, 0.13f); // Second circle
    Circle(-0.5f, 0.8f, 0.1f); // Third circle

    /// Top circles 1
    Circle(-0.65f, 0.85f, 0.1f); // Fourth circle
    Circle(-0.55f, 0.85f, 0.1f);  // Fifth circle

      glPopMatrix();



    ///cloud 2 left
    glPushMatrix();
 glTranslatef(-cloud2position,0,0);
      glColor3f(0.6f, 0.6f, 0.6f); // White color for cloud

    /// Base circles
    Circle(0.5f, 0.65f, 0.1f); // First circle
    Circle(0.4f, 0.65f, 0.13f); // Second circle
    Circle(0.3f, 0.65f, 0.1f); // Third circle

    /// Top circles
    Circle(0.46f, 0.7f, 0.1f); // Fourth circle
    Circle(0.35f, 0.7f, 0.1f);  // Fifth circle

    glPopMatrix();

    ///green quads

 glBegin(GL_QUADS);
            glColor3f(1.0f,1.0f,1.0f);
             glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
   glColor3f(0.40f, 0.65f, 0.19f);

    glVertex2f(1.0f, 0.25f);
    glVertex2f(-1.0f, 0.25f);
    glEnd();
        glBegin(GL_LINES);
   glColor3f(0.45f, 0.45f, 0.45f);
   glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glEnd();


///building behind 3 with updated building color

/*glBegin(GL_QUADS);
glColor3f(0.9f, 0.4f, 0.2f); // Deep orange and light red mixed color
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.3f, 0.1f); // Deep orange and light red mixed color
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glEnd();

///windows remain the same color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.60f);
glVertex2f(-0.87f, 0.60f);
glVertex2f(-0.87f, 0.66f);
glVertex2f(-0.90f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.60f);
glVertex2f(-0.85f, 0.60f);
glVertex2f(-0.85f, 0.66f);
glVertex2f(-0.82f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.68f);
glVertex2f(-0.87f, 0.68f);
glVertex2f(-0.87f, 0.74f);
glVertex2f(-0.90f, 0.74f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.68f);
glVertex2f(-0.85f, 0.68f);
glVertex2f(-0.85f, 0.74f);
glVertex2f(-0.82f, 0.74f);
glEnd();


///building behind 4 moved down by 0.2 on y-axis and building color changed
glColor3f(0.74,0.17,0.23);
renderBitmapString(-0.763f, 0.654f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOTEL");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.3f, 0.7f); // Changed color
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glVertex2f(-0.65f, 0.2f);
glVertex2f(-0.77f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.1f, 0.2f, 0.6f); // Changed color
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glVertex2f(-0.62f, 0.2f);
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.62f, 0.62f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.2f);
glEnd();

///windows (no color change, only y-axis shift)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.75f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.72f, 0.54f);
glVertex2f(-0.72f, 0.60f);
glVertex2f(-0.75f, 0.60f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.67f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.70f, 0.54f);
glVertex2f(-0.70f, 0.60f);
glVertex2f(-0.67f, 0.60f);
glEnd();

///building behind 5 with updated position and golden yellow color
    glColor3f(0.16,0.23,0.43);
renderBitmapString(-0.40f, 0.733f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AIUB");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.7f, 0.1f); // Golden yellow
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glVertex2f(-0.30f, 0.2f);
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.6f, 0.1f); // Golden yellow (darker shade)
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glVertex2f(-0.27f, 0.2f);
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.27f, 0.70f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.5 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.55f);
glVertex2f(-0.37f, 0.61f);
glVertex2f(-0.40f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.55f);
glVertex2f(-0.35f, 0.61f);
glVertex2f(-0.32f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.63f);
glVertex2f(-0.37f, 0.69f);
glVertex2f(-0.40f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.63f);
glVertex2f(-0.35f, 0.69f);
glVertex2f(-0.32f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.47f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.47f);
glVertex2f(-0.37f, 0.53f);
glVertex2f(-0.40f, 0.53f);
glEnd();

/// Updated Building Code behind 11
glColor3f(0.72,0.13,0.37);
renderBitmapString(0.05f, 0.59f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CMH");

// Building structure (shifted 0.76 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Green color for building
glVertex2f(0.02f, 0.59f); // Shifted by 0.76 on x-axis
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.0f, 0.0f); // Darker green for the side
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glVertex2f(0.14f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.14f, 0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glEnd();

// Windows (shifted by 0.13 x-axis)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.08f, 0.41f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.05f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.05f, 0.49f);
glVertex2f(0.08f, 0.49f);
glVertex2f(0.08f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.13f, 0.49f);
glVertex2f(0.10f, 0.49f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.13f, 0.55f);
glEnd();




/// Updated Building Code behind 10

// Building structure (shifted 0.63 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // Green color for building
glVertex2f(-0.11f, 0.65f); // Shifted by 0.63 on x-axis
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.8f, 0.0f); // Darker green for the side
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glVertex2f(0.01f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(0.01f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.08f, 0.47f);
glVertex2f(-0.05f, 0.47f);
glVertex2f(-0.05f, 0.53f);
glVertex2f(-0.08f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.00f, 0.47f);
glVertex2f(-0.03f, 0.47f);
glVertex2f(-0.03f, 0.53f);
glVertex2f(0.00f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.08f, 0.55f);
glVertex2f(-0.05f, 0.55f);
glVertex2f(-0.05f, 0.61f);
glVertex2f(-0.08f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.00f, 0.55f);
glVertex2f(-0.03f, 0.55f);
glVertex2f(-0.03f, 0.61f);
glVertex2f(0.00f, 0.61f);
glEnd();

/// Updated Building Code behind 9

// Building structure (shifted 0.5 on x-axis, changed color to blue)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // Blue color for building
glVertex2f(-0.24f, 0.60f); // Shifted by 0.5 on x-axis
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.8f); // Darker color for the side
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glVertex2f(-0.12f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.12f, 0.60f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.21f, 0.42f);
glVertex2f(-0.18f, 0.42f);
glVertex2f(-0.18f, 0.48f);
glVertex2f(-0.21f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.13f, 0.42f);
glVertex2f(-0.16f, 0.42f);
glVertex2f(-0.16f, 0.48f);
glVertex2f(-0.13f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.21f, 0.50f);
glVertex2f(-0.18f, 0.50f);
glVertex2f(-0.18f, 0.56f);
glVertex2f(-0.21f, 0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.13f, 0.50f);
glVertex2f(-0.16f, 0.50f);
glVertex2f(-0.16f, 0.56f);
glVertex2f(-0.13f, 0.56f);
glEnd();






///building behind 8 moved by 0.07 on x-axis and 0.2 on y-axis with cyan-red mixed color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.8f, 0.7f); // Cyan-red mixed
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glVertex2f(-0.45f, 0.2f);
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.7f, 0.6f); // Cyan-red mixed (darker shade)
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glVertex2f(-0.42f, 0.2f);
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.42f, 0.62f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.07 and y-axis shift by 0.2)


glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.545f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.515f, 0.56f);
glVertex2f(-0.515f, 0.62f);
glVertex2f(-0.545f, 0.62f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.47f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.50f, 0.56f);
glVertex2f(-0.50f, 0.62f);
glVertex2f(-0.47f, 0.62f);
glEnd();


///building behind 7 moved down by 0.2 on y-axis and shifted by 0.1 on x-axis with red-yellow mixed color
    glColor3f(0.70,0.29,0.15);
renderBitmapString(-0.61f, 0.553f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SCHOOL");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.5f, 0.2f); // Red-yellow mixed
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glVertex2f(-0.49f, 0.2f);
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.4f, 0.1f); // Red-yellow mixed (lighter shade)
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glVertex2f(-0.46f, 0.2f);
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.46f, 0.52f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.1 and y-axis shift by -0.2)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.44f);
glVertex2f(-0.555f, 0.50f);
glVertex2f(-0.585f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.44f);
glVertex2f(-0.54f, 0.50f);
glVertex2f(-0.51f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.36f);
glVertex2f(-0.555f, 0.42f);
glVertex2f(-0.585f, 0.42f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.36f);
glVertex2f(-0.54f, 0.42f);
glVertex2f(-0.51f, 0.42f);
glEnd();




///building behind 6 with updated position and blue-yellow mixed color
    glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.34f, 0.533f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "OFFICE");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.5f, 0.0f); // Blue-yellow mixed (dominantly blue)
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glVertex2f(-0.23f, 0.2f);
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.4f, 0.1f); // Blue-yellow mixed (lighter shade)
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glVertex2f(-0.20f, 0.2f);
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.20f, 0.50f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.07 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.35f);
glVertex2f(-0.30f, 0.41f);
glVertex2f(-0.33f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.35f);
glVertex2f(-0.28f, 0.41f);
glVertex2f(-0.25f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.43f);
glVertex2f(-0.30f, 0.49f);
glVertex2f(-0.33f, 0.49f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.43f);
glVertex2f(-0.28f, 0.49f);
glVertex2f(-0.25f, 0.49f);
glEnd();

   ///building behind 2
       glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.88f, 0.603f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "POLICE");
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.77f,0.2f);
    glVertex2f(-0.89f,0.2f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.3f,0.3f,0.3f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.74f,0.57f);
    glVertex2f(-0.74f,0.2f);
    glVertex2f(-0.77f,0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.89f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.77f, 0.60f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.77f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.74f, 0.57f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.74f, 0.57f);
    glVertex2f(-0.74f, 0.2f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.86f, 0.42f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.83f, 0.48f);
    glVertex2f(-0.86f, 0.48f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.78f, 0.42f);
    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.78f, 0.48f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.86f, 0.50f);
    glVertex2f(-0.83f, 0.50f);
    glVertex2f(-0.83f, 0.56f);
    glVertex2f(-0.86f, 0.56f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.81f, 0.50f);
    glVertex2f(-0.81f, 0.56f);
    glVertex2f(-0.78f, 0.56f);
    glEnd();






///building
     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);

    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.31f);
    glVertex2f(-0.95f, 0.31f);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.98f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.31f);
    glVertex2f(-0.91f, 0.31f);
    glVertex2f(-0.91f, 0.35f);
    glVertex2f(-0.94f, 0.35f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.37f);
    glVertex2f(-0.95f, 0.37f);
    glVertex2f(-0.95f, 0.41f);
    glVertex2f(-0.98f, 0.41f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.37f);
    glVertex2f(-0.91f, 0.37f);
    glVertex2f(-0.91f, 0.41f);
    glVertex2f(-0.94f, 0.41f);
    glEnd();

    ///p3

       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.43f);
    glVertex2f(-0.95f, 0.43f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.98f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.43f);
    glVertex2f(-0.91f, 0.43f);
    glVertex2f(-0.91f, 0.47f);
    glVertex2f(-0.94f, 0.47f);
    glEnd();



    ///1 building

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.26f);
    glVertex2f(-0.96f, 0.26f);
    glVertex2f(-0.96f, 0.22f);
    glVertex2f(-0.99f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.95f, 0.26f);
    glVertex2f(-0.92f, 0.26f);
    glVertex2f(-0.92f, 0.22f);
    glVertex2f(-0.95f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();*/




    ///2 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glEnd();




    ///windows
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.81f, 0.22f);
    glVertex2f(-0.81f, 0.26f);
    glVertex2f(-0.84f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.77f, 0.22f);
    glVertex2f(-0.77f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.81f, 0.28f);
    glVertex2f(-0.81f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.77f, 0.28f);
    glVertex2f(-0.77f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.81f, 0.34f);
    glVertex2f(-0.81f, 0.38f);
    glVertex2f(-0.84f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.77f, 0.34f);
    glVertex2f(-0.77f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();

    ///3 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.70f, 0.22f);
    glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.67f, 0.26f);
    glVertex2f(-0.70f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.22f);
    glVertex2f(-0.63f, 0.22f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.66f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.67f, 0.28f);
    glVertex2f(-0.67f, 0.32f);
    glVertex2f(-0.7f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.66f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.34f);
    glVertex2f(-0.67f, 0.34f);
    glVertex2f(-0.67f, 0.38f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.34f);
    glVertex2f(-0.63f, 0.34f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.66f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.67f, 0.40f);
    glVertex2f(-0.67f, 0.44f);
    glVertex2f(-0.7f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.40f);
    glVertex2f(-0.63f, 0.40f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.66f, 0.44f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.46f);
    glVertex2f(-0.67f, 0.46f);
    glVertex2f(-0.67f, 0.50f);
    glVertex2f(-0.7f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.46f);
    glVertex2f(-0.63f, 0.46f);
    glVertex2f(-0.63f, 0.50f);
    glVertex2f(-0.66f, 0.50f);
    glEnd();

    ///4 building 4

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glEnd();


    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.22f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.53f, 0.26f);
    glVertex2f(-0.56f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.49f, 0.22f);
    glVertex2f(-0.49f, 0.26f);
    glVertex2f(-0.52f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.28f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.49f, 0.32f);
    glVertex2f(-0.52f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.56f, 0.32f);
    glEnd();

    ///5 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.4f, 0.22f);
    glVertex2f(-0.4f, 0.26f);
    glVertex2f(-0.43f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.22f);
    glVertex2f(-0.36f, 0.22f);
    glVertex2f(-0.36f, 0.26f);
    glVertex2f(-0.39f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.28f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.43f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.28f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.36f, 0.32f);
    glVertex2f(-0.39f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.34f);
    glVertex2f(-0.4f, 0.34f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.43f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.36f, 0.38f);
    glVertex2f(-0.39f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(-0.43f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.40f);
    glVertex2f(-0.36f, 0.40f);
    glVertex2f(-0.36f, 0.44f);
    glVertex2f(-0.39f, 0.44f);
    glEnd();

    ///6 building

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.22f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.24f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.32f);
    glVertex2f(-0.28f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.21f, 0.28f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glEnd();

    ///7 building
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.0f);
    glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.0f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.22f);
    glVertex2f(-0.13f, 0.22f);
    glVertex2f(-0.13f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.12f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.28f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.13f, 0.32f);
    glVertex2f(-0.16f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.28f);
    glVertex2f(-0.09f, 0.28f);
    glVertex2f(-0.09f, 0.32f);
    glVertex2f(-0.12f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.13f, 0.34f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.16f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.12f, 0.38f);
    glEnd();

    ///8 building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.04f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.22f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.03f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.22f);
    glVertex2f(0.03f, 0.22f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.01f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.28f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.03f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.28f);
    glVertex2f(0.03f, 0.28f);
    glVertex2f(0.03f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(-0.03f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.34f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.01f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 0.44f);
    glVertex2f(-0.03f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(0.03f, 0.40f);
    glVertex2f(0.03f, 0.44f);
    glVertex2f(0.01f, 0.44f);
    glEnd();

    ///9 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glEnd();




    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.26f);
    glVertex2f(0.09f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.16f, 0.22f);
    glVertex2f(0.16f, 0.26f);
    glVertex2f(0.13f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.32f);
    glVertex2f(0.09f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.32f);
    glVertex2f(0.13f, 0.32f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.34f);
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.38f);
    glVertex2f(0.09f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.38f);
    glVertex2f(0.13f, 0.38f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.44f);
    glVertex2f(0.09f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.44f);
    glVertex2f(0.13f, 0.44f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.12f, 0.46f);
    glVertex2f(0.12f, 0.50f);
    glVertex2f(0.09f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.46f);
    glVertex2f(0.16f, 0.46f);
    glVertex2f(0.16f, 0.50f);
    glVertex2f(0.13f, 0.50f);
    glEnd();


    ///tree

   ///leaf

 glColor3f(0.0f, 0.5f, 0.0f); // White color for cloud

    /// Base circles
    Circle(0.98f, 0.53f, 0.08f); // First circle
    Circle(0.88f, 0.51f, 0.10f); // Second circle
    Circle(0.78f, 0.53f, 0.08f); // Third circle

    /// Top circles
    Circle(0.94f, 0.65f, 0.08f); // Fourth circle
    Circle(0.83f, 0.65f, 0.08f);  // Fifth circle
    Circle(0.88f, 0.75f, 0.08f);


glColor3f(0.545f, 0.271f, 0.075f); // Brown color for the trunk

// Polygon 1
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.83f, 0.64f);
glVertex2f(0.8f, 0.64f);
glEnd();

// Polygon 2
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.93f, 0.68f);
glVertex2f(0.925f, 0.63f);
glEnd();

// Polygon 3
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.3f);
glVertex2f(0.905f, 0.575f);

glVertex2f(0.86f, 0.575f);
glVertex2f(0.86f, 0.3f);
glVertex2f(0.882f,0.2f);
glEnd();

// Polygon 4
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.95f, 0.25f);
glVertex2f(0.82f, 0.25f);
glVertex2f(0.86f, 0.30f);
glVertex2f(0.905f, 0.30f);
glEnd();

// triangle 1
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.905f, 0.575f);
glEnd();

// triangle 2
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.445f);
glVertex2f(0.84f, 0.420f);
glVertex2f(0.86f, 0.470f);
glEnd();


    ///bench 1



     /* glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.334f, 0.20f);
    glVertex2f(0.338f, 0.20f);
    glVertex2f(0.338f, 0.30f);
    glVertex2f(0.334f, 0.30f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.458f, 0.20f);
    glVertex2f(0.462f, 0.20f);
    glVertex2f(0.462f, 0.30f);
    glVertex2f(0.458f, 0.30f);
    glEnd();





    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.32f, 0.22f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.47f, 0.21f);
    glVertex2f(0.32f, 0.21f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);

    glVertex2f(0.31f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glEnd();

           glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.30f, 0.24f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.49f, 0.24f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.26f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.48f, 0.26f);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.304f, 0.25f);
    glVertex2f(0.486f, 0.25f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.32f, 0.23f);
    glVertex2f(0.325f, 0.23f);
    glVertex2f(0.325f, 0.20f);
    glVertex2f(0.32f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.47f, 0.23f);
    glVertex2f(0.475f, 0.23f);
    glVertex2f(0.475f, 0.20f);
    glVertex2f(0.47f, 0.20f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.28f);
    glVertex2f(0.48f, 0.28f);
    glVertex2f(0.48f, 0.27f);
    glVertex2f(0.31f, 0.27f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.285f);
    glVertex2f(0.48f, 0.285f);
    glVertex2f(0.48f, 0.295f);
    glVertex2f(0.31f, 0.295f);
    glEnd();

            glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.30f);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.48f, 0.310f);
    glVertex2f(0.31f, 0.310f);
    glEnd();


     ///bench 2

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.634f, 0.20f);
    glVertex2f(0.638f, 0.20f);
    glVertex2f(0.638f, 0.30f);
    glVertex2f(0.634f, 0.30f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.758f, 0.20f);
    glVertex2f(0.762f, 0.20f);
    glVertex2f(0.762f, 0.30f);
    glVertex2f(0.758f, 0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.62f, 0.22f);
    glVertex2f(0.77f, 0.22f);
    glVertex2f(0.77f, 0.21f);
    glVertex2f(0.62f, 0.21f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);

    glVertex2f(0.61f, 0.24f);
    glVertex2f(0.78f, 0.24f);
    glVertex2f(0.78f, 0.23f);
    glVertex2f(0.61f, 0.23f);
    glEnd();

           glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.60f, 0.24f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.79f, 0.24f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.26f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.78f, 0.26f);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.604f, 0.25f);
    glVertex2f(0.786f, 0.25f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.62f, 0.23f);
    glVertex2f(0.625f, 0.23f);
    glVertex2f(0.625f, 0.20f);
    glVertex2f(0.62f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.77f, 0.23f);
    glVertex2f(0.775f, 0.23f);
    glVertex2f(0.775f, 0.20f);
    glVertex2f(0.77f, 0.20f);
    glEnd();///

       glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.28f);
    glVertex2f(0.78f, 0.28f);
    glVertex2f(0.78f, 0.27f);
    glVertex2f(0.61f, 0.27f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.285f);
    glVertex2f(0.78f, 0.285f);
    glVertex2f(0.78f, 0.295f);
    glVertex2f(0.61f, 0.295f);
    glEnd();

            glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.30f);
    glVertex2f(0.78f, 0.30f);
    glVertex2f(0.78f, 0.310f);
    glVertex2f(0.61f, 0.310f);
    glEnd();*/


///lamp post 1

  /* glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.285f, 0.22f);
    glVertex2f(0.285f, 0.20f);
    glVertex2f(0.26f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.269f, 0.21f);
    glVertex2f(0.277f, 0.21f);
    glVertex2f(0.277f, 0.28f);
    glVertex2f(0.269f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.271f, 0.37f);
    glVertex2f(0.275f, 0.37f);
    glVertex2f(0.275f, 0.28f);
    glVertex2f(0.271f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.285f, 0.37f);
    glVertex2f(0.285f, 0.377f);
    glVertex2f(0.26f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.377f);
    glVertex2f(0.28f, 0.377f);
    glVertex2f(0.28f, 0.385f);
    glVertex2f(0.265f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.385f);
   glVertex2f(0.262f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.28f, 0.385f);
   glVertex2f(0.283f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.272f, 0.385f);
   glVertex2f(0.272f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.255f, 0.41f);
   glVertex2f(0.289f,0.41f);
   glVertex2f(0.272f,0.43f);
    glEnd();



///lamp post 2


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.22f);
    glVertex2f(0.835f, 0.22f);
    glVertex2f(0.835f, 0.20f);
    glVertex2f(0.81f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.819f, 0.21f);
    glVertex2f(0.827f, 0.21f);
    glVertex2f(0.827f, 0.28f);
    glVertex2f(0.819f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.821f, 0.37f);
    glVertex2f(0.825f, 0.37f);
    glVertex2f(0.825f, 0.28f);
    glVertex2f(0.821f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.37f);
    glVertex2f(0.835f, 0.37f);
    glVertex2f(0.835f, 0.377f);
    glVertex2f(0.81f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.377f);
    glVertex2f(0.83f, 0.377f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.385f);
   glVertex2f(0.812f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.83f, 0.385f);
   glVertex2f(0.833f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.822f, 0.385f);
   glVertex2f(0.822f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.805f, 0.41f);
   glVertex2f(0.839f,0.41f);
   glVertex2f(0.822f,0.43f);
    glEnd();


    ///double lamp post

    ///left


       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.535f, 0.22f);
    glVertex2f(0.560f, 0.22f);
    glVertex2f(0.560f, 0.20f);
    glVertex2f(0.535f, 0.20f);
    glEnd();


      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.544f, 0.21f);
    glVertex2f(0.552f, 0.21f);
    glVertex2f(0.552f, 0.28f);
    glVertex2f(0.544f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.546f, 0.37f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.55f, 0.28f);
    glVertex2f(0.546f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.515f, 0.37f);
    glVertex2f(0.580f, 0.37f);
    glVertex2f(0.580f, 0.377f);
    glVertex2f(0.515f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.377f);
    glVertex2f(0.535f, 0.377f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.385f);
   glVertex2f(0.517f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.535f, 0.385f);
   glVertex2f(0.538f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.527f, 0.385f);
   glVertex2f(0.527f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.509f, 0.41f);
   glVertex2f(0.544f,0.41f);
   glVertex2f(0.527f,0.43f);
    glEnd();

    ///right

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.377f);
    glVertex2f(0.560f, 0.377f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.560f, 0.385f);
   glVertex2f(0.557f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.385f);
   glVertex2f(0.578f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.567f, 0.385f);
   glVertex2f(0.567f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.549f, 0.41f);
   glVertex2f(0.585f,0.41f);
   glVertex2f(0.567f,0.43f);
    glEnd();*/

    ///boarder
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f,0.2f);
    glVertex2f(-1.0f,0.19f);
    glVertex2f(1.0f,0.19f);
    glVertex2f(1.0f,0.2f);
    glEnd();




    ///footpath

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.19f);
    glVertex2f(-1.0f, 0.19f);
    glEnd();

  /*  ///human 2
glPushMatrix();
glTranslatef(human2_Position, 0, 0);
glRotatef(65, 0, 1, 0);

///body
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for the body (new dress color)
glVertex2f(0.0f, 0.17f);  // Shifted by +0.03
glVertex2f(0.07f, 0.17f);
glVertex2f(0.07f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.16f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.16f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.0f, 0.19f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.19f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.16f);  // Shifted by +0.03
glVertex2f(0.085f, 0.16f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.07f, 0.19f);  // Shifted by +0.03
glVertex2f(0.085f, 0.19f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for left leg (new pant color)
glVertex2f(0.0f, 0.12f);  // Shifted by +0.03
glVertex2f(0.02f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.0f, 0.17f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for right leg (new pant color)
glVertex2f(0.05f, 0.12f);  // Shifted by +0.03
glVertex2f(0.07f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.03f, 0.17f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.11f);  // Shifted by +0.03
glVertex2f(0.02f, 0.11f);
glVertex2f(0.02f, 0.12f);
glVertex2f(0.0f, 0.12f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.11f);  // Shifted by +0.03
glVertex2f(0.07f, 0.11f);
glVertex2f(0.07f, 0.12f);
glVertex2f(0.05f, 0.12f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.22f);  // Shifted by +0.03
glVertex2f(0.045f, 0.22f);
glVertex2f(0.045f, 0.24f);
glVertex2f(0.025f, 0.24f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.24f);  // Shifted by +0.03
glVertex2f(0.06f, 0.24f);
glVertex2f(0.06f, 0.27f);
glVertex2f(0.01f, 0.27f);
glEnd();

///hair
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // Black for the hair (new hair color)
glVertex2f(0.01f, 0.27f);  // Shifted by +0.03
glVertex2f(0.06f, 0.27f);
glVertex2f(0.05f, 0.29f);
glVertex2f(0.02f, 0.29f);
glEnd();

glPopMatrix();




    ///human 1
     glPushMatrix();
    glTranslatef(human1_Position,0,0);
    glRotatef(65, 0,1,0);
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Dark green for body
glVertex2f(0.0f, 0.09f);  // Shifted by +0.04
glVertex2f(0.07f, 0.09f);
glVertex2f(0.07f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.08f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.08f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Red for sleeve
glVertex2f(0.0f, 0.11f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.11f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.08f);  // Shifted by +0.04
glVertex2f(0.085f, 0.08f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Blue for sleeve
glVertex2f(0.07f, 0.11f);  // Shifted by +0.04
glVertex2f(0.085f, 0.11f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Navy blue for left leg
glVertex2f(0.0f, 0.04f);  // Shifted by +0.04
glVertex2f(0.02f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.0f, 0.09f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Slightly lighter navy blue for right leg
glVertex2f(0.05f, 0.04f);  // Shifted by +0.04
glVertex2f(0.07f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.03f, 0.09f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.03f);  // Shifted by +0.04
glVertex2f(0.02f, 0.03f);
glVertex2f(0.02f, 0.04f);
glVertex2f(0.0f, 0.04f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.03f);  // Shifted by +0.04
glVertex2f(0.07f, 0.03f);
glVertex2f(0.07f, 0.04f);
glVertex2f(0.05f, 0.04f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.14f);  // Shifted by +0.04
glVertex2f(0.045f, 0.14f);
glVertex2f(0.045f, 0.16f);
glVertex2f(0.025f, 0.16f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.16f);  // Shifted by +0.04
glVertex2f(0.06f, 0.16f);
glVertex2f(0.06f, 0.19f);
glVertex2f(0.01f, 0.19f);
glEnd();

///head
glBegin(GL_QUADS);
glColor3f(0.58f, 0.36f, 0.31f); // Black for hat
glVertex2f(0.01f, 0.19f);  // Shifted by +0.04
glVertex2f(0.06f, 0.19f);
glVertex2f(0.05f, 0.21f);
glVertex2f(0.02f, 0.21f);
glEnd();
glPopMatrix();*/




///lamp(road)
///lamp 1 left

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.1f); // Bottom-left
    glVertex2f(-0.808f, -0.1f); // Top-left
    glVertex2f(-0.808f, 0.3f); // Top-right
    glVertex2f(-0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.808f, 0.27f); // Bottom-left
    glVertex2f(-0.88f, 0.27f); // Top-left
    glVertex2f(-0.88f, 0.285f); // Top-right
    glVertex2f(-0.808f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, 0.27f); // Bottom-left
    glVertex2f(-0.875f, 0.27f); // Bottom-right
    glVertex2f(-0.875f, 0.255f); // Top-right
    glVertex2f(-0.85f, 0.255f); // Top-left
    glEnd();


      ///lamp 2

    /// Light pole
   /* glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f, -0.1f); // Bottom-left
    glVertex2f(-0.608f, -0.1f); // Top-left
    glVertex2f(-0.608f, 0.3f); // Top-right
    glVertex2f(-0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.608f, 0.27f); // Bottom-left
    glVertex2f(-0.68f, 0.27f); // Top-left
    glVertex2f(-0.68f, 0.285f); // Top-right
    glVertex2f(-0.608f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.27f); // Bottom-left
    glVertex2f(-0.675f, 0.27f); // Bottom-right
    glVertex2f(-0.675f, 0.255f); // Top-right
    glVertex2f(-0.65f, 0.255f); // Top-left
    glEnd();*/


      ///lamp 3

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.1f); // Bottom-left
    glVertex2f(-0.408f, -0.1f); // Top-left
    glVertex2f(-0.408f, 0.3f); // Top-right
    glVertex2f(-0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.408f, 0.27f); // Bottom-left
    glVertex2f(-0.48f, 0.27f); // Top-left
    glVertex2f(-0.48f, 0.285f); // Top-right
    glVertex2f(-0.408f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.27f); // Bottom-left
    glVertex2f(-0.475f, 0.27f); // Bottom-right
    glVertex2f(-0.475f, 0.255f); // Top-right
    glVertex2f(-0.45f, 0.255f); // Top-left
    glEnd();

    ///lamp 4

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.1f); // Bottom-left
    glVertex2f(-0.208f, -0.1f); // Top-left
    glVertex2f(-0.208f, 0.3f); // Top-right
    glVertex2f(-0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.208f, 0.27f); // Bottom-left
    glVertex2f(-0.28f, 0.27f); // Top-left
    glVertex2f(-0.28f, 0.285f); // Top-right
    glVertex2f(-0.208f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.27f); // Bottom-left
    glVertex2f(-0.275f, 0.27f); // Bottom-right
    glVertex2f(-0.275f, 0.255f); // Top-right
    glVertex2f(-0.25f, 0.255f); // Top-left
    glEnd();*/

    ///lamp 5

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.00f, -0.1f); // Bottom-left
    glVertex2f(-0.008f, -0.1f); // Top-left
    glVertex2f(-0.008f, 0.3f); // Top-right
    glVertex2f(-0.00f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.27f); // Bottom-left
    glVertex2f(-0.08f, 0.27f); // Top-left
    glVertex2f(-0.08f, 0.285f); // Top-right
    glVertex2f(-0.008f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.27f); // Bottom-left
    glVertex2f(-0.075f, 0.27f); // Bottom-right
    glVertex2f(-0.075f, 0.255f); // Top-right
    glVertex2f(-0.05f, 0.255f); // Top-left
    glEnd();

        ///lamp 6

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.1f); // Bottom-left
    glVertex2f(0.208f, -0.1f); // Top-left
    glVertex2f(0.208f, 0.3f); // Top-right
    glVertex2f(0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, 0.27f); // Bottom-left
    glVertex2f(0.112f, 0.27f); // Top-left
    glVertex2f(0.112f, 0.285f); // Top-right
    glVertex2f(0.20f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.142f, 0.27f); // Bottom-left
    glVertex2f(0.117f, 0.27f); // Bottom-right
    glVertex2f(0.117f, 0.255f); // Top-right
    glVertex2f(0.142f, 0.255f); // Top-left
    glEnd();*/

          ///lamp 7

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.1f); // Bottom-left
    glVertex2f(0.408f, -0.1f); // Top-left
    glVertex2f(0.408f, 0.3f); // Top-right
    glVertex2f(0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, 0.27f); // Bottom-left
    glVertex2f(0.312f, 0.27f); // Top-left
    glVertex2f(0.312f, 0.285f); // Top-right
    glVertex2f(0.40f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.342f, 0.27f); // Bottom-left
    glVertex2f(0.317f, 0.27f); // Bottom-right
    glVertex2f(0.317f, 0.255f); // Top-right
    glVertex2f(0.342f, 0.255f); // Top-left
    glEnd();

      ///lamp 8

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.1f); // Bottom-left
    glVertex2f(0.608f, -0.1f); // Top-left
    glVertex2f(0.608f, 0.3f); // Top-right
    glVertex2f(0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, 0.27f); // Bottom-left
    glVertex2f(0.512f, 0.27f); // Top-left
    glVertex2f(0.512f, 0.285f); // Top-right
    glVertex2f(0.60f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.542f, 0.27f); // Bottom-left
    glVertex2f(0.517f, 0.27f); // Bottom-right
    glVertex2f(0.517f, 0.255f); // Top-right
    glVertex2f(0.542f, 0.255f); // Top-left
    glEnd();*/

       ///lamp 9

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.1f); // Bottom-left
    glVertex2f(0.808f, -0.1f); // Top-left
    glVertex2f(0.808f, 0.3f); // Top-right
    glVertex2f(0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, 0.27f); // Bottom-left
    glVertex2f(0.712f, 0.27f); // Top-left
    glVertex2f(0.712f, 0.285f); // Top-right
    glVertex2f(0.80f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.742f, 0.27f); // Bottom-left
    glVertex2f(0.717f, 0.27f); // Bottom-right
    glVertex2f(0.717f, 0.255f); // Top-right
    glVertex2f(0.742f, 0.255f); // Top-left
    glEnd();


  ///road

   glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.05f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.05f);
    glVertex2f(-0.80f, -0.05f);
    glVertex2f(-0.80f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.05f);
    glVertex2f(-0.40f, -0.05f);
    glVertex2f(-0.40f, 0.0f);
    glVertex2f(-0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.05f);
    glVertex2f(0.00f, -0.05f);
    glVertex2f(0.00f, 0.0f);
    glVertex2f(-0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.05f);
    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.40f, 0.0f);
    glVertex2f(0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.05f);
    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.80f, 0.0f);
    glVertex2f(0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.37f);
    glVertex2f(-0.80f, -0.37f);
    glVertex2f(-0.80f, -0.4f);
    glVertex2f(-1.0f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.37f);
    glVertex2f(-0.40f, -0.37f);
    glVertex2f(-0.40f, -0.4f);
    glVertex2f(-0.60f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.37f);
    glVertex2f(0.00f, -0.37f);
    glVertex2f(0.00f, -0.4f);
    glVertex2f(-0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.37f);
    glVertex2f(0.40f, -0.37f);
    glVertex2f(0.40f, -0.4f);
    glVertex2f(0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.37f);
    glVertex2f(0.80f, -0.37f);
    glVertex2f(0.80f, -0.4f);
    glVertex2f(0.60f, -0.4f);
    glEnd();






     /// ambulance
     glPushMatrix();
     glTranslatef(ambulance_position,0,0);


    glBegin(GL_QUADS);/// white ambulance down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.35f, -0.15f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.39f, -0.05f);
    glVertex2f(-0.39f, -0.07f);
    glVertex2f(-0.357f, -0.07f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance start
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.71f, -0.13f);
    glVertex2f(-0.71f, -0.15f);
    glVertex2f(-0.69f, -0.15f);
    glVertex2f(-0.69f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance end
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.36f, -0.13f);
    glVertex2f(-0.36f, -0.15f);
    glVertex2f(-0.34f, -0.15f);
    glVertex2f(-0.34f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.36f, -0.05f);
    glVertex2f(-0.363f, -0.043f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance middle body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.363f, -0.043f);
    glVertex2f(-0.39f, -0.01f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle body end
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.69f, -0.043f);
    glVertex2f(-0.69f, -0.01f);
    glEnd();



    glBegin(GL_QUADS);/// white ambulance up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.65f, 0.13f);
    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.39f, -0.01f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();


    glBegin(GL_QUADS);   ///ambulance up body alarm
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.13f);
    glVertex2f(-0.53f, 0.13f);
    glVertex2f(-0.53f, 0.15f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue right quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.49f, 0.11f);
    glVertex2f(-0.49f, -0.01f);
    glVertex2f(-0.41f, -0.01f);
    glVertex2f(-0.45f, 0.11f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue left quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.57f, 0.11f);
    glVertex2f(-0.57f, -0.01f);
    glVertex2f(-0.5f, -0.01f);
    glVertex2f(-0.5f, 0.11f);
    glEnd();


    glBegin(GL_QUADS);/// ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.65f, 0.06f);
    glVertex2f(-0.65f, 0.04f);
    glVertex2f(-0.58f, 0.04f);
    glVertex2f(-0.58f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);///  ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.62f, 0.11f);
    glVertex2f(-0.62f, -0.01f);
    glVertex2f(-0.61f, -0.01f);
    glVertex2f(-0.61f, 0.11f);
    glEnd();

    /// ambulance wheels

      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.62f, -0.15f, 0.05f); // First circl
      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.44f, -0.15f, 0.05f); // second circl

      glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.62f, -0.15f, 0.03f);

     glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.44f, -0.15f, 0.03f);
    glPopMatrix();



    ///police car

      glPushMatrix();
     glTranslatef(-ambulance_position,0,0);
    glBegin(GL_QUADS);/// white policeCar down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.37f, -0.47f);
    glVertex2f(0.35f, -0.59f);
    glVertex2f(0.7f, -0.59f);
    glVertex2f(0.69f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down start line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.34f, -0.57f);
    glVertex2f(0.34f, -0.59f);
    glVertex2f(0.37f, -0.59f);
    glVertex2f(0.37f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down end line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.68f, -0.57f);
    glVertex2f(0.68f, -0.59f);
    glVertex2f(0.72f, -0.59f);
    glVertex2f(0.72f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);    ///policeCar middle line
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(0.366f, -0.49f);
    glVertex2f(0.363f, -0.51f);
    glVertex2f(0.39f, -0.51f);
    glVertex2f(0.39f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar middle line
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.4f, -0.49f);
    glVertex2f(0.4f, -0.51f);
    glVertex2f(0.66f, -0.51f);
    glVertex2f(0.66f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);   ///policeCar middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.67f, -0.49f);
    glVertex2f(0.67f, -0.51f);
    glVertex2f(0.695f, -0.51f);
    glVertex2f(0.693f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// white policeCar up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.46f, -0.4f);
    glVertex2f(0.41f, -0.47f);
    glVertex2f(0.65f, -0.47f);
    glVertex2f(0.62f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.465f, -0.415f);
    glVertex2f(0.42f, -0.47f);
    glVertex2f(0.52f, -0.47f);
    glVertex2f(0.52f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.53f, -0.415f);
    glVertex2f(0.53f, -0.47f);
    glVertex2f(0.64f, -0.47f);
    glVertex2f(0.615f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.475f, -0.38f);
    glVertex2f(0.475f, -0.4f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.49f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar upper light
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.49f, -0.38f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.505f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.505f, -0.38f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.52f, -0.4f);
    glVertex2f(0.52f, -0.38f);
    glEnd();

    ///police car wheels
    glColor3f(0.0f,0.0f,0.0f);

     Circle(0.44f, -0.61f, 0.05f); // Black outer circle (tire)
     glColor3f(0.5f,0.5f,0.5f);
    Circle(0.44f, -0.61f, 0.03f); // Gray inner circle (rim)

    // Front wheel
      glColor3f(0.0f,0.0f,0.0f);
    Circle(0.62f, -0.61f, 0.05f); // Black outer circle (tire)
    glColor3f(0.5f,0.5f,0.5f);
    Circle(0.62f, -0.61f, 0.03f); // Gray inner circle (rim)
    glPopMatrix();


     /// down footpath

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.72f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    glBegin(GL_QUADS);///black boarder
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();


     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-0.80f, -0.70f);
    glVertex2f(-0.80f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.70f);
    glVertex2f(-0.40f, -0.70f);
    glVertex2f(-0.40f, -0.72f);
    glVertex2f(-0.60f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.70f);
    glVertex2f(0.00f, -0.70f);
    glVertex2f(0.00f, -0.72f);
    glVertex2f(-0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.70f);
    glVertex2f(0.40f, -0.70f);
    glVertex2f(0.40f, -0.72f);
    glVertex2f(0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.70f);
    glVertex2f(0.80f, -0.70f);
    glVertex2f(0.80f, -0.72f);
    glVertex2f(0.60f, -0.72f);
    glEnd();


   glFlush(); // Render now
}

void display(int b)
{
    glutDisplayFunc(display1);
}






void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glPointSize (5.0);


   /* glBegin (GL_POINTS);
    glColor3f(0.0f , 0.0f , 0.0f);
    glVertex2f (-0.0f, -0.0f);
     glEnd();




*/




       ///sky 1
    glBegin(GL_QUADS);
            glColor3f(1.0f,1.0f,1.0f);
             glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
   glColor3f(0.10f, 0.63f, 0.97f);

    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    ///sky 2
    /*glBegin(GL_QUADS);
glColor3f(0.988f, 0.639f, 0.239f); // sky
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glColor3f(0.0f, 0.522f, 1.0f); // sky transition
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.451f, 0.451f, 0.451f); // line
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glEnd();*/




     ///sun
    glColor3f(1,0.80,0);
    glPushMatrix();
    glTranslatef(0,sunPosition,0);
    Circle(0.7, 0.8, 0.07);
    glPopMatrix();






 /// Draw cloud 1 right
 glPushMatrix();
 glTranslatef(cloud1position,0,0);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud

    /// Base circles1
    Circle(-0.7f, 0.8f, 0.1f); // First circle
    Circle(-0.6f, 0.8f, 0.13f); // Second circle
    Circle(-0.5f, 0.8f, 0.1f); // Third circle

    /// Top circles 1
    Circle(-0.65f, 0.85f, 0.1f); // Fourth circle
    Circle(-0.55f, 0.85f, 0.1f);  // Fifth circle

      glPopMatrix();



    ///cloud 2 left
    glPushMatrix();
 glTranslatef(-cloud2position,0,0);
      glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud

    /// Base circles
    Circle(0.5f, 0.65f, 0.1f); // First circle
    Circle(0.4f, 0.65f, 0.13f); // Second circle
    Circle(0.3f, 0.65f, 0.1f); // Third circle

    /// Top circles
    Circle(0.46f, 0.7f, 0.1f); // Fourth circle
    Circle(0.35f, 0.7f, 0.1f);  // Fifth circle

    glPopMatrix();

    ///green quads

 glBegin(GL_QUADS);
            glColor3f(1.0f,1.0f,1.0f);
             glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
   glColor3f(0.40f, 0.65f, 0.19f);

    glVertex2f(1.0f, 0.25f);
    glVertex2f(-1.0f, 0.25f);
    glEnd();
        glBegin(GL_LINES);
   glColor3f(0.45f, 0.45f, 0.45f);
   glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glEnd();


///building behind 3 with updated building color

/*glBegin(GL_QUADS);
glColor3f(0.9f, 0.4f, 0.2f); // Deep orange and light red mixed color
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.3f, 0.1f); // Deep orange and light red mixed color
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glEnd();

///windows remain the same color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.60f);
glVertex2f(-0.87f, 0.60f);
glVertex2f(-0.87f, 0.66f);
glVertex2f(-0.90f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.60f);
glVertex2f(-0.85f, 0.60f);
glVertex2f(-0.85f, 0.66f);
glVertex2f(-0.82f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.68f);
glVertex2f(-0.87f, 0.68f);
glVertex2f(-0.87f, 0.74f);
glVertex2f(-0.90f, 0.74f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.68f);
glVertex2f(-0.85f, 0.68f);
glVertex2f(-0.85f, 0.74f);
glVertex2f(-0.82f, 0.74f);
glEnd();


///building behind 4 moved down by 0.2 on y-axis and building color changed
glColor3f(0.74,0.17,0.23);
renderBitmapString(-0.763f, 0.654f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOTEL");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.3f, 0.7f); // Changed color
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glVertex2f(-0.65f, 0.2f);
glVertex2f(-0.77f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.1f, 0.2f, 0.6f); // Changed color
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glVertex2f(-0.62f, 0.2f);
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.62f, 0.62f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.2f);
glEnd();

///windows (no color change, only y-axis shift)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.75f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.72f, 0.54f);
glVertex2f(-0.72f, 0.60f);
glVertex2f(-0.75f, 0.60f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.67f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.70f, 0.54f);
glVertex2f(-0.70f, 0.60f);
glVertex2f(-0.67f, 0.60f);
glEnd();

///building behind 5 with updated position and golden yellow color
    glColor3f(0.16,0.23,0.43);
renderBitmapString(-0.40f, 0.733f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AIUB");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.7f, 0.1f); // Golden yellow
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glVertex2f(-0.30f, 0.2f);
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.6f, 0.1f); // Golden yellow (darker shade)
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glVertex2f(-0.27f, 0.2f);
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.27f, 0.70f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.5 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.55f);
glVertex2f(-0.37f, 0.61f);
glVertex2f(-0.40f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.55f);
glVertex2f(-0.35f, 0.61f);
glVertex2f(-0.32f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.63f);
glVertex2f(-0.37f, 0.69f);
glVertex2f(-0.40f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.63f);
glVertex2f(-0.35f, 0.69f);
glVertex2f(-0.32f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.47f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.47f);
glVertex2f(-0.37f, 0.53f);
glVertex2f(-0.40f, 0.53f);
glEnd();

/// Updated Building Code behind 11
glColor3f(0.72,0.13,0.37);
renderBitmapString(0.05f, 0.59f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CMH");

// Building structure (shifted 0.76 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Green color for building
glVertex2f(0.02f, 0.59f); // Shifted by 0.76 on x-axis
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.0f, 0.0f); // Darker green for the side
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glVertex2f(0.14f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.14f, 0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glEnd();

// Windows (shifted by 0.13 x-axis)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.08f, 0.41f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.05f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.05f, 0.49f);
glVertex2f(0.08f, 0.49f);
glVertex2f(0.08f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.13f, 0.49f);
glVertex2f(0.10f, 0.49f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.13f, 0.55f);
glEnd();




/// Updated Building Code behind 10

// Building structure (shifted 0.63 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // Green color for building
glVertex2f(-0.11f, 0.65f); // Shifted by 0.63 on x-axis
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.8f, 0.0f); // Darker green for the side
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glVertex2f(0.01f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(0.01f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.08f, 0.47f);
glVertex2f(-0.05f, 0.47f);
glVertex2f(-0.05f, 0.53f);
glVertex2f(-0.08f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.00f, 0.47f);
glVertex2f(-0.03f, 0.47f);
glVertex2f(-0.03f, 0.53f);
glVertex2f(0.00f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.08f, 0.55f);
glVertex2f(-0.05f, 0.55f);
glVertex2f(-0.05f, 0.61f);
glVertex2f(-0.08f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.00f, 0.55f);
glVertex2f(-0.03f, 0.55f);
glVertex2f(-0.03f, 0.61f);
glVertex2f(0.00f, 0.61f);
glEnd();

/// Updated Building Code behind 9

// Building structure (shifted 0.5 on x-axis, changed color to blue)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // Blue color for building
glVertex2f(-0.24f, 0.60f); // Shifted by 0.5 on x-axis
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.8f); // Darker color for the side
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glVertex2f(-0.12f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.12f, 0.60f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.21f, 0.42f);
glVertex2f(-0.18f, 0.42f);
glVertex2f(-0.18f, 0.48f);
glVertex2f(-0.21f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.13f, 0.42f);
glVertex2f(-0.16f, 0.42f);
glVertex2f(-0.16f, 0.48f);
glVertex2f(-0.13f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.21f, 0.50f);
glVertex2f(-0.18f, 0.50f);
glVertex2f(-0.18f, 0.56f);
glVertex2f(-0.21f, 0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.13f, 0.50f);
glVertex2f(-0.16f, 0.50f);
glVertex2f(-0.16f, 0.56f);
glVertex2f(-0.13f, 0.56f);
glEnd();






///building behind 8 moved by 0.07 on x-axis and 0.2 on y-axis with cyan-red mixed color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.8f, 0.7f); // Cyan-red mixed
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glVertex2f(-0.45f, 0.2f);
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.7f, 0.6f); // Cyan-red mixed (darker shade)
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glVertex2f(-0.42f, 0.2f);
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.42f, 0.62f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.07 and y-axis shift by 0.2)


glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.545f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.515f, 0.56f);
glVertex2f(-0.515f, 0.62f);
glVertex2f(-0.545f, 0.62f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.47f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.50f, 0.56f);
glVertex2f(-0.50f, 0.62f);
glVertex2f(-0.47f, 0.62f);
glEnd();


///building behind 7 moved down by 0.2 on y-axis and shifted by 0.1 on x-axis with red-yellow mixed color
    glColor3f(0.70,0.29,0.15);
renderBitmapString(-0.61f, 0.553f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SCHOOL");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.5f, 0.2f); // Red-yellow mixed
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glVertex2f(-0.49f, 0.2f);
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.4f, 0.1f); // Red-yellow mixed (lighter shade)
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glVertex2f(-0.46f, 0.2f);
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.46f, 0.52f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.1 and y-axis shift by -0.2)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.44f);
glVertex2f(-0.555f, 0.50f);
glVertex2f(-0.585f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.44f);
glVertex2f(-0.54f, 0.50f);
glVertex2f(-0.51f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.36f);
glVertex2f(-0.555f, 0.42f);
glVertex2f(-0.585f, 0.42f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.36f);
glVertex2f(-0.54f, 0.42f);
glVertex2f(-0.51f, 0.42f);
glEnd();




///building behind 6 with updated position and blue-yellow mixed color
    glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.34f, 0.533f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "OFFICE");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.5f, 0.0f); // Blue-yellow mixed (dominantly blue)
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glVertex2f(-0.23f, 0.2f);
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.4f, 0.1f); // Blue-yellow mixed (lighter shade)
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glVertex2f(-0.20f, 0.2f);
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.20f, 0.50f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.07 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.35f);
glVertex2f(-0.30f, 0.41f);
glVertex2f(-0.33f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.35f);
glVertex2f(-0.28f, 0.41f);
glVertex2f(-0.25f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.43f);
glVertex2f(-0.30f, 0.49f);
glVertex2f(-0.33f, 0.49f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.43f);
glVertex2f(-0.28f, 0.49f);
glVertex2f(-0.25f, 0.49f);
glEnd();

   ///building behind 2
       glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.88f, 0.603f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "POLICE");
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.77f,0.2f);
    glVertex2f(-0.89f,0.2f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.3f,0.3f,0.3f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.74f,0.57f);
    glVertex2f(-0.74f,0.2f);
    glVertex2f(-0.77f,0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.89f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.77f, 0.60f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.77f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.74f, 0.57f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.74f, 0.57f);
    glVertex2f(-0.74f, 0.2f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.86f, 0.42f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.83f, 0.48f);
    glVertex2f(-0.86f, 0.48f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.78f, 0.42f);
    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.78f, 0.48f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.86f, 0.50f);
    glVertex2f(-0.83f, 0.50f);
    glVertex2f(-0.83f, 0.56f);
    glVertex2f(-0.86f, 0.56f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.81f, 0.50f);
    glVertex2f(-0.81f, 0.56f);
    glVertex2f(-0.78f, 0.56f);
    glEnd();






///building
     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);

    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.31f);
    glVertex2f(-0.95f, 0.31f);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.98f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.31f);
    glVertex2f(-0.91f, 0.31f);
    glVertex2f(-0.91f, 0.35f);
    glVertex2f(-0.94f, 0.35f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.37f);
    glVertex2f(-0.95f, 0.37f);
    glVertex2f(-0.95f, 0.41f);
    glVertex2f(-0.98f, 0.41f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.37f);
    glVertex2f(-0.91f, 0.37f);
    glVertex2f(-0.91f, 0.41f);
    glVertex2f(-0.94f, 0.41f);
    glEnd();

    ///p3

       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, 0.43f);
    glVertex2f(-0.95f, 0.43f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.98f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.94f, 0.43f);
    glVertex2f(-0.91f, 0.43f);
    glVertex2f(-0.91f, 0.47f);
    glVertex2f(-0.94f, 0.47f);
    glEnd();



    ///1 building

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.26f);
    glVertex2f(-0.96f, 0.26f);
    glVertex2f(-0.96f, 0.22f);
    glVertex2f(-0.99f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.95f, 0.26f);
    glVertex2f(-0.92f, 0.26f);
    glVertex2f(-0.92f, 0.22f);
    glVertex2f(-0.95f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();*/




    ///2 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glEnd();




    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.81f, 0.22f);
    glVertex2f(-0.81f, 0.26f);
    glVertex2f(-0.84f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.77f, 0.22f);
    glVertex2f(-0.77f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.81f, 0.28f);
    glVertex2f(-0.81f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.77f, 0.28f);
    glVertex2f(-0.77f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.81f, 0.34f);
    glVertex2f(-0.81f, 0.38f);
    glVertex2f(-0.84f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.77f, 0.34f);
    glVertex2f(-0.77f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();

    ///3 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.70f, 0.22f);
    glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.67f, 0.26f);
    glVertex2f(-0.70f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.22f);
    glVertex2f(-0.63f, 0.22f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.66f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.67f, 0.28f);
    glVertex2f(-0.67f, 0.32f);
    glVertex2f(-0.7f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.66f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.34f);
    glVertex2f(-0.67f, 0.34f);
    glVertex2f(-0.67f, 0.38f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.34f);
    glVertex2f(-0.63f, 0.34f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.66f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.67f, 0.40f);
    glVertex2f(-0.67f, 0.44f);
    glVertex2f(-0.7f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.40f);
    glVertex2f(-0.63f, 0.40f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.66f, 0.44f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.46f);
    glVertex2f(-0.67f, 0.46f);
    glVertex2f(-0.67f, 0.50f);
    glVertex2f(-0.7f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.46f);
    glVertex2f(-0.63f, 0.46f);
    glVertex2f(-0.63f, 0.50f);
    glVertex2f(-0.66f, 0.50f);
    glEnd();

    ///4 building 4

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glEnd();


    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.22f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.53f, 0.26f);
    glVertex2f(-0.56f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.49f, 0.22f);
    glVertex2f(-0.49f, 0.26f);
    glVertex2f(-0.52f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.28f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.49f, 0.32f);
    glVertex2f(-0.52f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.56f, 0.32f);
    glEnd();

    ///5 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.4f, 0.22f);
    glVertex2f(-0.4f, 0.26f);
    glVertex2f(-0.43f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.22f);
    glVertex2f(-0.36f, 0.22f);
    glVertex2f(-0.36f, 0.26f);
    glVertex2f(-0.39f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.28f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.43f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.28f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.36f, 0.32f);
    glVertex2f(-0.39f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.34f);
    glVertex2f(-0.4f, 0.34f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.43f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.36f, 0.38f);
    glVertex2f(-0.39f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(-0.43f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.40f);
    glVertex2f(-0.36f, 0.40f);
    glVertex2f(-0.36f, 0.44f);
    glVertex2f(-0.39f, 0.44f);
    glEnd();

    ///6 building

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.22f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.24f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.32f);
    glVertex2f(-0.28f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.21f, 0.28f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glEnd();

    ///7 building
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.0f);
    glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.0f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.22f);
    glVertex2f(-0.13f, 0.22f);
    glVertex2f(-0.13f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.12f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.28f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.13f, 0.32f);
    glVertex2f(-0.16f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.28f);
    glVertex2f(-0.09f, 0.28f);
    glVertex2f(-0.09f, 0.32f);
    glVertex2f(-0.12f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.13f, 0.34f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.16f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.12f, 0.38f);
    glEnd();

    ///8 building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.04f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.22f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.03f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.22f);
    glVertex2f(0.03f, 0.22f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.01f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.28f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.03f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.28f);
    glVertex2f(0.03f, 0.28f);
    glVertex2f(0.03f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(-0.03f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.34f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.01f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 0.44f);
    glVertex2f(-0.03f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(0.03f, 0.40f);
    glVertex2f(0.03f, 0.44f);
    glVertex2f(0.01f, 0.44f);
    glEnd();

    ///9 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glEnd();




    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.26f);
    glVertex2f(0.09f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.16f, 0.22f);
    glVertex2f(0.16f, 0.26f);
    glVertex2f(0.13f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.32f);
    glVertex2f(0.09f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.32f);
    glVertex2f(0.13f, 0.32f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.34f);
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.38f);
    glVertex2f(0.09f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.38f);
    glVertex2f(0.13f, 0.38f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.44f);
    glVertex2f(0.09f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.44f);
    glVertex2f(0.13f, 0.44f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.12f, 0.46f);
    glVertex2f(0.12f, 0.50f);
    glVertex2f(0.09f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.46f);
    glVertex2f(0.16f, 0.46f);
    glVertex2f(0.16f, 0.50f);
    glVertex2f(0.13f, 0.50f);
    glEnd();


    ///tree

   ///leaf

 glColor3f(0.0f, 0.5f, 0.0f); // White color for cloud

    /// Base circles
    Circle(0.98f, 0.53f, 0.08f); // First circle
    Circle(0.88f, 0.51f, 0.10f); // Second circle
    Circle(0.78f, 0.53f, 0.08f); // Third circle

    /// Top circles
    Circle(0.94f, 0.65f, 0.08f); // Fourth circle
    Circle(0.83f, 0.65f, 0.08f);  // Fifth circle
    Circle(0.88f, 0.75f, 0.08f);


glColor3f(0.545f, 0.271f, 0.075f); // Brown color for the trunk

// Polygon 1
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.83f, 0.64f);
glVertex2f(0.8f, 0.64f);
glEnd();

// Polygon 2
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.93f, 0.68f);
glVertex2f(0.925f, 0.63f);
glEnd();

// Polygon 3
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.3f);
glVertex2f(0.905f, 0.575f);

glVertex2f(0.86f, 0.575f);
glVertex2f(0.86f, 0.3f);
glVertex2f(0.882f,0.2f);
glEnd();

// Polygon 4
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.95f, 0.25f);
glVertex2f(0.82f, 0.25f);
glVertex2f(0.86f, 0.30f);
glVertex2f(0.905f, 0.30f);
glEnd();

// triangle 1
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.905f, 0.575f);
glEnd();

// triangle 2
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.445f);
glVertex2f(0.84f, 0.420f);
glVertex2f(0.86f, 0.470f);
glEnd();


    ///bench 1



     /* glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.334f, 0.20f);
    glVertex2f(0.338f, 0.20f);
    glVertex2f(0.338f, 0.30f);
    glVertex2f(0.334f, 0.30f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.458f, 0.20f);
    glVertex2f(0.462f, 0.20f);
    glVertex2f(0.462f, 0.30f);
    glVertex2f(0.458f, 0.30f);
    glEnd();





    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.32f, 0.22f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.47f, 0.21f);
    glVertex2f(0.32f, 0.21f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);

    glVertex2f(0.31f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glEnd();

           glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.30f, 0.24f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.49f, 0.24f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.26f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.48f, 0.26f);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.304f, 0.25f);
    glVertex2f(0.486f, 0.25f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.32f, 0.23f);
    glVertex2f(0.325f, 0.23f);
    glVertex2f(0.325f, 0.20f);
    glVertex2f(0.32f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.47f, 0.23f);
    glVertex2f(0.475f, 0.23f);
    glVertex2f(0.475f, 0.20f);
    glVertex2f(0.47f, 0.20f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.28f);
    glVertex2f(0.48f, 0.28f);
    glVertex2f(0.48f, 0.27f);
    glVertex2f(0.31f, 0.27f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.285f);
    glVertex2f(0.48f, 0.285f);
    glVertex2f(0.48f, 0.295f);
    glVertex2f(0.31f, 0.295f);
    glEnd();

            glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.31f, 0.30f);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.48f, 0.310f);
    glVertex2f(0.31f, 0.310f);
    glEnd();


     ///bench 2

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.634f, 0.20f);
    glVertex2f(0.638f, 0.20f);
    glVertex2f(0.638f, 0.30f);
    glVertex2f(0.634f, 0.30f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.758f, 0.20f);
    glVertex2f(0.762f, 0.20f);
    glVertex2f(0.762f, 0.30f);
    glVertex2f(0.758f, 0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.62f, 0.22f);
    glVertex2f(0.77f, 0.22f);
    glVertex2f(0.77f, 0.21f);
    glVertex2f(0.62f, 0.21f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);

    glVertex2f(0.61f, 0.24f);
    glVertex2f(0.78f, 0.24f);
    glVertex2f(0.78f, 0.23f);
    glVertex2f(0.61f, 0.23f);
    glEnd();

           glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.60f, 0.24f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.79f, 0.24f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.26f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.78f, 0.26f);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.604f, 0.25f);
    glVertex2f(0.786f, 0.25f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.62f, 0.23f);
    glVertex2f(0.625f, 0.23f);
    glVertex2f(0.625f, 0.20f);
    glVertex2f(0.62f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.77f, 0.23f);
    glVertex2f(0.775f, 0.23f);
    glVertex2f(0.775f, 0.20f);
    glVertex2f(0.77f, 0.20f);
    glEnd();///

       glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.28f);
    glVertex2f(0.78f, 0.28f);
    glVertex2f(0.78f, 0.27f);
    glVertex2f(0.61f, 0.27f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.285f);
    glVertex2f(0.78f, 0.285f);
    glVertex2f(0.78f, 0.295f);
    glVertex2f(0.61f, 0.295f);
    glEnd();

            glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);

    glVertex2f(0.61f, 0.30f);
    glVertex2f(0.78f, 0.30f);
    glVertex2f(0.78f, 0.310f);
    glVertex2f(0.61f, 0.310f);
    glEnd();*/


///lamp post 1

  /* glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.285f, 0.22f);
    glVertex2f(0.285f, 0.20f);
    glVertex2f(0.26f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.269f, 0.21f);
    glVertex2f(0.277f, 0.21f);
    glVertex2f(0.277f, 0.28f);
    glVertex2f(0.269f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.271f, 0.37f);
    glVertex2f(0.275f, 0.37f);
    glVertex2f(0.275f, 0.28f);
    glVertex2f(0.271f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.285f, 0.37f);
    glVertex2f(0.285f, 0.377f);
    glVertex2f(0.26f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.377f);
    glVertex2f(0.28f, 0.377f);
    glVertex2f(0.28f, 0.385f);
    glVertex2f(0.265f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.385f);
   glVertex2f(0.262f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.28f, 0.385f);
   glVertex2f(0.283f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.272f, 0.385f);
   glVertex2f(0.272f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.255f, 0.41f);
   glVertex2f(0.289f,0.41f);
   glVertex2f(0.272f,0.43f);
    glEnd();



///lamp post 2


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.22f);
    glVertex2f(0.835f, 0.22f);
    glVertex2f(0.835f, 0.20f);
    glVertex2f(0.81f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.819f, 0.21f);
    glVertex2f(0.827f, 0.21f);
    glVertex2f(0.827f, 0.28f);
    glVertex2f(0.819f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.821f, 0.37f);
    glVertex2f(0.825f, 0.37f);
    glVertex2f(0.825f, 0.28f);
    glVertex2f(0.821f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.37f);
    glVertex2f(0.835f, 0.37f);
    glVertex2f(0.835f, 0.377f);
    glVertex2f(0.81f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.377f);
    glVertex2f(0.83f, 0.377f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.385f);
   glVertex2f(0.812f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.83f, 0.385f);
   glVertex2f(0.833f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.822f, 0.385f);
   glVertex2f(0.822f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.805f, 0.41f);
   glVertex2f(0.839f,0.41f);
   glVertex2f(0.822f,0.43f);
    glEnd();


    ///double lamp post

    ///left


       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.535f, 0.22f);
    glVertex2f(0.560f, 0.22f);
    glVertex2f(0.560f, 0.20f);
    glVertex2f(0.535f, 0.20f);
    glEnd();


      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.544f, 0.21f);
    glVertex2f(0.552f, 0.21f);
    glVertex2f(0.552f, 0.28f);
    glVertex2f(0.544f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.546f, 0.37f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.55f, 0.28f);
    glVertex2f(0.546f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.515f, 0.37f);
    glVertex2f(0.580f, 0.37f);
    glVertex2f(0.580f, 0.377f);
    glVertex2f(0.515f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.377f);
    glVertex2f(0.535f, 0.377f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.385f);
   glVertex2f(0.517f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.535f, 0.385f);
   glVertex2f(0.538f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.527f, 0.385f);
   glVertex2f(0.527f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.509f, 0.41f);
   glVertex2f(0.544f,0.41f);
   glVertex2f(0.527f,0.43f);
    glEnd();

    ///right

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.377f);
    glVertex2f(0.560f, 0.377f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.560f, 0.385f);
   glVertex2f(0.557f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.385f);
   glVertex2f(0.578f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.567f, 0.385f);
   glVertex2f(0.567f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.549f, 0.41f);
   glVertex2f(0.585f,0.41f);
   glVertex2f(0.567f,0.43f);
    glEnd();*/

    ///boarder
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f,0.2f);
    glVertex2f(-1.0f,0.19f);
    glVertex2f(1.0f,0.19f);
    glVertex2f(1.0f,0.2f);
    glEnd();




    ///footpath

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.19f);
    glVertex2f(-1.0f, 0.19f);
    glEnd();

  /*  ///human 2
glPushMatrix();
glTranslatef(human2_Position, 0, 0);
glRotatef(65, 0, 1, 0);

///body
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for the body (new dress color)
glVertex2f(0.0f, 0.17f);  // Shifted by +0.03
glVertex2f(0.07f, 0.17f);
glVertex2f(0.07f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.16f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.16f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.0f, 0.19f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.19f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.16f);  // Shifted by +0.03
glVertex2f(0.085f, 0.16f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.07f, 0.19f);  // Shifted by +0.03
glVertex2f(0.085f, 0.19f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for left leg (new pant color)
glVertex2f(0.0f, 0.12f);  // Shifted by +0.03
glVertex2f(0.02f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.0f, 0.17f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for right leg (new pant color)
glVertex2f(0.05f, 0.12f);  // Shifted by +0.03
glVertex2f(0.07f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.03f, 0.17f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.11f);  // Shifted by +0.03
glVertex2f(0.02f, 0.11f);
glVertex2f(0.02f, 0.12f);
glVertex2f(0.0f, 0.12f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.11f);  // Shifted by +0.03
glVertex2f(0.07f, 0.11f);
glVertex2f(0.07f, 0.12f);
glVertex2f(0.05f, 0.12f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.22f);  // Shifted by +0.03
glVertex2f(0.045f, 0.22f);
glVertex2f(0.045f, 0.24f);
glVertex2f(0.025f, 0.24f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.24f);  // Shifted by +0.03
glVertex2f(0.06f, 0.24f);
glVertex2f(0.06f, 0.27f);
glVertex2f(0.01f, 0.27f);
glEnd();

///hair
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // Black for the hair (new hair color)
glVertex2f(0.01f, 0.27f);  // Shifted by +0.03
glVertex2f(0.06f, 0.27f);
glVertex2f(0.05f, 0.29f);
glVertex2f(0.02f, 0.29f);
glEnd();

glPopMatrix();




    ///human 1
     glPushMatrix();
    glTranslatef(human1_Position,0,0);
    glRotatef(65, 0,1,0);
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Dark green for body
glVertex2f(0.0f, 0.09f);  // Shifted by +0.04
glVertex2f(0.07f, 0.09f);
glVertex2f(0.07f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.08f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.08f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Red for sleeve
glVertex2f(0.0f, 0.11f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.11f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.08f);  // Shifted by +0.04
glVertex2f(0.085f, 0.08f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Blue for sleeve
glVertex2f(0.07f, 0.11f);  // Shifted by +0.04
glVertex2f(0.085f, 0.11f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Navy blue for left leg
glVertex2f(0.0f, 0.04f);  // Shifted by +0.04
glVertex2f(0.02f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.0f, 0.09f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Slightly lighter navy blue for right leg
glVertex2f(0.05f, 0.04f);  // Shifted by +0.04
glVertex2f(0.07f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.03f, 0.09f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.03f);  // Shifted by +0.04
glVertex2f(0.02f, 0.03f);
glVertex2f(0.02f, 0.04f);
glVertex2f(0.0f, 0.04f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.03f);  // Shifted by +0.04
glVertex2f(0.07f, 0.03f);
glVertex2f(0.07f, 0.04f);
glVertex2f(0.05f, 0.04f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.14f);  // Shifted by +0.04
glVertex2f(0.045f, 0.14f);
glVertex2f(0.045f, 0.16f);
glVertex2f(0.025f, 0.16f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.16f);  // Shifted by +0.04
glVertex2f(0.06f, 0.16f);
glVertex2f(0.06f, 0.19f);
glVertex2f(0.01f, 0.19f);
glEnd();

///head
glBegin(GL_QUADS);
glColor3f(0.58f, 0.36f, 0.31f); // Black for hat
glVertex2f(0.01f, 0.19f);  // Shifted by +0.04
glVertex2f(0.06f, 0.19f);
glVertex2f(0.05f, 0.21f);
glVertex2f(0.02f, 0.21f);
glEnd();
glPopMatrix();*/




///lamp(road)
///lamp 1 left

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.1f); // Bottom-left
    glVertex2f(-0.808f, -0.1f); // Top-left
    glVertex2f(-0.808f, 0.3f); // Top-right
    glVertex2f(-0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.808f, 0.27f); // Bottom-left
    glVertex2f(-0.88f, 0.27f); // Top-left
    glVertex2f(-0.88f, 0.285f); // Top-right
    glVertex2f(-0.808f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, 0.27f); // Bottom-left
    glVertex2f(-0.875f, 0.27f); // Bottom-right
    glVertex2f(-0.875f, 0.255f); // Top-right
    glVertex2f(-0.85f, 0.255f); // Top-left
    glEnd();


      ///lamp 2

    /// Light pole
   /* glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f, -0.1f); // Bottom-left
    glVertex2f(-0.608f, -0.1f); // Top-left
    glVertex2f(-0.608f, 0.3f); // Top-right
    glVertex2f(-0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.608f, 0.27f); // Bottom-left
    glVertex2f(-0.68f, 0.27f); // Top-left
    glVertex2f(-0.68f, 0.285f); // Top-right
    glVertex2f(-0.608f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.27f); // Bottom-left
    glVertex2f(-0.675f, 0.27f); // Bottom-right
    glVertex2f(-0.675f, 0.255f); // Top-right
    glVertex2f(-0.65f, 0.255f); // Top-left
    glEnd();*/


      ///lamp 3

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.1f); // Bottom-left
    glVertex2f(-0.408f, -0.1f); // Top-left
    glVertex2f(-0.408f, 0.3f); // Top-right
    glVertex2f(-0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.408f, 0.27f); // Bottom-left
    glVertex2f(-0.48f, 0.27f); // Top-left
    glVertex2f(-0.48f, 0.285f); // Top-right
    glVertex2f(-0.408f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.27f); // Bottom-left
    glVertex2f(-0.475f, 0.27f); // Bottom-right
    glVertex2f(-0.475f, 0.255f); // Top-right
    glVertex2f(-0.45f, 0.255f); // Top-left
    glEnd();

    ///lamp 4

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.1f); // Bottom-left
    glVertex2f(-0.208f, -0.1f); // Top-left
    glVertex2f(-0.208f, 0.3f); // Top-right
    glVertex2f(-0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.208f, 0.27f); // Bottom-left
    glVertex2f(-0.28f, 0.27f); // Top-left
    glVertex2f(-0.28f, 0.285f); // Top-right
    glVertex2f(-0.208f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.27f); // Bottom-left
    glVertex2f(-0.275f, 0.27f); // Bottom-right
    glVertex2f(-0.275f, 0.255f); // Top-right
    glVertex2f(-0.25f, 0.255f); // Top-left
    glEnd();*/

    ///lamp 5

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.00f, -0.1f); // Bottom-left
    glVertex2f(-0.008f, -0.1f); // Top-left
    glVertex2f(-0.008f, 0.3f); // Top-right
    glVertex2f(-0.00f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.27f); // Bottom-left
    glVertex2f(-0.08f, 0.27f); // Top-left
    glVertex2f(-0.08f, 0.285f); // Top-right
    glVertex2f(-0.008f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.27f); // Bottom-left
    glVertex2f(-0.075f, 0.27f); // Bottom-right
    glVertex2f(-0.075f, 0.255f); // Top-right
    glVertex2f(-0.05f, 0.255f); // Top-left
    glEnd();

        ///lamp 6

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.1f); // Bottom-left
    glVertex2f(0.208f, -0.1f); // Top-left
    glVertex2f(0.208f, 0.3f); // Top-right
    glVertex2f(0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, 0.27f); // Bottom-left
    glVertex2f(0.112f, 0.27f); // Top-left
    glVertex2f(0.112f, 0.285f); // Top-right
    glVertex2f(0.20f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.142f, 0.27f); // Bottom-left
    glVertex2f(0.117f, 0.27f); // Bottom-right
    glVertex2f(0.117f, 0.255f); // Top-right
    glVertex2f(0.142f, 0.255f); // Top-left
    glEnd();*/

          ///lamp 7

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.1f); // Bottom-left
    glVertex2f(0.408f, -0.1f); // Top-left
    glVertex2f(0.408f, 0.3f); // Top-right
    glVertex2f(0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, 0.27f); // Bottom-left
    glVertex2f(0.312f, 0.27f); // Top-left
    glVertex2f(0.312f, 0.285f); // Top-right
    glVertex2f(0.40f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.342f, 0.27f); // Bottom-left
    glVertex2f(0.317f, 0.27f); // Bottom-right
    glVertex2f(0.317f, 0.255f); // Top-right
    glVertex2f(0.342f, 0.255f); // Top-left
    glEnd();

      ///lamp 8

    /// Light pole
    /*glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.1f); // Bottom-left
    glVertex2f(0.608f, -0.1f); // Top-left
    glVertex2f(0.608f, 0.3f); // Top-right
    glVertex2f(0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, 0.27f); // Bottom-left
    glVertex2f(0.512f, 0.27f); // Top-left
    glVertex2f(0.512f, 0.285f); // Top-right
    glVertex2f(0.60f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.542f, 0.27f); // Bottom-left
    glVertex2f(0.517f, 0.27f); // Bottom-right
    glVertex2f(0.517f, 0.255f); // Top-right
    glVertex2f(0.542f, 0.255f); // Top-left
    glEnd();*/

       ///lamp 9

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.1f); // Bottom-left
    glVertex2f(0.808f, -0.1f); // Top-left
    glVertex2f(0.808f, 0.3f); // Top-right
    glVertex2f(0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, 0.27f); // Bottom-left
    glVertex2f(0.712f, 0.27f); // Top-left
    glVertex2f(0.712f, 0.285f); // Top-right
    glVertex2f(0.80f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.742f, 0.27f); // Bottom-left
    glVertex2f(0.717f, 0.27f); // Bottom-right
    glVertex2f(0.717f, 0.255f); // Top-right
    glVertex2f(0.742f, 0.255f); // Top-left
    glEnd();


  ///road

   glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.05f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.05f);
    glVertex2f(-0.80f, -0.05f);
    glVertex2f(-0.80f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.05f);
    glVertex2f(-0.40f, -0.05f);
    glVertex2f(-0.40f, 0.0f);
    glVertex2f(-0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.05f);
    glVertex2f(0.00f, -0.05f);
    glVertex2f(0.00f, 0.0f);
    glVertex2f(-0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.05f);
    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.40f, 0.0f);
    glVertex2f(0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.05f);
    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.80f, 0.0f);
    glVertex2f(0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.37f);
    glVertex2f(-0.80f, -0.37f);
    glVertex2f(-0.80f, -0.4f);
    glVertex2f(-1.0f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.37f);
    glVertex2f(-0.40f, -0.37f);
    glVertex2f(-0.40f, -0.4f);
    glVertex2f(-0.60f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.37f);
    glVertex2f(0.00f, -0.37f);
    glVertex2f(0.00f, -0.4f);
    glVertex2f(-0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.37f);
    glVertex2f(0.40f, -0.37f);
    glVertex2f(0.40f, -0.4f);
    glVertex2f(0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.37f);
    glVertex2f(0.80f, -0.37f);
    glVertex2f(0.80f, -0.4f);
    glVertex2f(0.60f, -0.4f);
    glEnd();






     /// ambulance
     glPushMatrix();
     glTranslatef(ambulance_position,0,0);


    glBegin(GL_QUADS);/// white ambulance down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.35f, -0.15f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.39f, -0.05f);
    glVertex2f(-0.39f, -0.07f);
    glVertex2f(-0.357f, -0.07f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance start
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.71f, -0.13f);
    glVertex2f(-0.71f, -0.15f);
    glVertex2f(-0.69f, -0.15f);
    glVertex2f(-0.69f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance end
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.36f, -0.13f);
    glVertex2f(-0.36f, -0.15f);
    glVertex2f(-0.34f, -0.15f);
    glVertex2f(-0.34f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.36f, -0.05f);
    glVertex2f(-0.363f, -0.043f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance middle body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.363f, -0.043f);
    glVertex2f(-0.39f, -0.01f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle body end
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.69f, -0.043f);
    glVertex2f(-0.69f, -0.01f);
    glEnd();



    glBegin(GL_QUADS);/// white ambulance up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.65f, 0.13f);
    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.39f, -0.01f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();


    glBegin(GL_QUADS);   ///ambulance up body alarm
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.13f);
    glVertex2f(-0.53f, 0.13f);
    glVertex2f(-0.53f, 0.15f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue right quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.49f, 0.11f);
    glVertex2f(-0.49f, -0.01f);
    glVertex2f(-0.41f, -0.01f);
    glVertex2f(-0.45f, 0.11f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue left quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.57f, 0.11f);
    glVertex2f(-0.57f, -0.01f);
    glVertex2f(-0.5f, -0.01f);
    glVertex2f(-0.5f, 0.11f);
    glEnd();


    glBegin(GL_QUADS);/// ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.65f, 0.06f);
    glVertex2f(-0.65f, 0.04f);
    glVertex2f(-0.58f, 0.04f);
    glVertex2f(-0.58f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);///  ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.62f, 0.11f);
    glVertex2f(-0.62f, -0.01f);
    glVertex2f(-0.61f, -0.01f);
    glVertex2f(-0.61f, 0.11f);
    glEnd();

    /// ambulance wheels

      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.62f, -0.15f, 0.05f); // First circl
      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.44f, -0.15f, 0.05f); // second circl

      glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.62f, -0.15f, 0.03f);

     glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.44f, -0.15f, 0.03f);
    glPopMatrix();



    ///police car

      glPushMatrix();
     glTranslatef(-ambulance_position,0,0);
    glBegin(GL_QUADS);/// white policeCar down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.37f, -0.47f);
    glVertex2f(0.35f, -0.59f);
    glVertex2f(0.7f, -0.59f);
    glVertex2f(0.69f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down start line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.34f, -0.57f);
    glVertex2f(0.34f, -0.59f);
    glVertex2f(0.37f, -0.59f);
    glVertex2f(0.37f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down end line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.68f, -0.57f);
    glVertex2f(0.68f, -0.59f);
    glVertex2f(0.72f, -0.59f);
    glVertex2f(0.72f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);    ///policeCar middle line
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(0.366f, -0.49f);
    glVertex2f(0.363f, -0.51f);
    glVertex2f(0.39f, -0.51f);
    glVertex2f(0.39f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar middle line
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.4f, -0.49f);
    glVertex2f(0.4f, -0.51f);
    glVertex2f(0.66f, -0.51f);
    glVertex2f(0.66f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);   ///policeCar middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.67f, -0.49f);
    glVertex2f(0.67f, -0.51f);
    glVertex2f(0.695f, -0.51f);
    glVertex2f(0.693f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// white policeCar up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.46f, -0.4f);
    glVertex2f(0.41f, -0.47f);
    glVertex2f(0.65f, -0.47f);
    glVertex2f(0.62f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.465f, -0.415f);
    glVertex2f(0.42f, -0.47f);
    glVertex2f(0.52f, -0.47f);
    glVertex2f(0.52f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.53f, -0.415f);
    glVertex2f(0.53f, -0.47f);
    glVertex2f(0.64f, -0.47f);
    glVertex2f(0.615f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.475f, -0.38f);
    glVertex2f(0.475f, -0.4f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.49f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar upper light
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.49f, -0.38f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.505f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.505f, -0.38f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.52f, -0.4f);
    glVertex2f(0.52f, -0.38f);
    glEnd();

    ///police car wheels
    glColor3f(0.0f,0.0f,0.0f);

     Circle(0.44f, -0.61f, 0.05f); // Black outer circle (tire)
     glColor3f(0.5f,0.5f,0.5f);
    Circle(0.44f, -0.61f, 0.03f); // Gray inner circle (rim)

    // Front wheel
      glColor3f(0.0f,0.0f,0.0f);
    Circle(0.62f, -0.61f, 0.05f); // Black outer circle (tire)
    glColor3f(0.5f,0.5f,0.5f);
    Circle(0.62f, -0.61f, 0.03f); // Gray inner circle (rim)
    glPopMatrix();


     /// down footpath

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.72f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    glBegin(GL_QUADS);///black boarder
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();


     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-0.80f, -0.70f);
    glVertex2f(-0.80f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.70f);
    glVertex2f(-0.40f, -0.70f);
    glVertex2f(-0.40f, -0.72f);
    glVertex2f(-0.60f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.70f);
    glVertex2f(0.00f, -0.70f);
    glVertex2f(0.00f, -0.72f);
    glVertex2f(-0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.70f);
    glVertex2f(0.40f, -0.70f);
    glVertex2f(0.40f, -0.72f);
    glVertex2f(0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.70f);
    glVertex2f(0.80f, -0.70f);
    glVertex2f(0.80f, -0.72f);
    glVertex2f(0.60f, -0.72f);
    glEnd();


   glFlush(); // Render now
}


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
    {
    case 'a':
        glutDisplayFunc(display);
        //
        break;
         case 'b':
        glutDisplayFunc(display1);//
        break;




    glutPostRedisplay();

	}
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1520, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("MAGICAL CITY"); // Create a window with the given title
    glutDisplayFunc(display1); // Register display callback handler for window re-paint
glutDisplayFunc(display);
    glutTimerFunc(80, update_Sun, 0);
    glutTimerFunc(100, update_cloud1, 0);
    glutTimerFunc(100, update_cloud2, 0);
    glutTimerFunc(100, update_ambulance, 0);
    glutKeyboardFunc(handleKeypress);
    //glutTimerFunc(100, update_human1, 0);
    //glutTimerFunc(100, update_human2, 0);

    glutMainLoop(); // Enter the event-processing loop
    return 0;
}



---------------------------------------------------------------------

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
// Display flag to toggle between objects
int currentDisplay = 1;
// Display for Object 1
void displayObject1() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the axis (orthographic projection) for Object 1
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);
    // Draw Object 1 (Red Triangle)
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_TRIANGLES);
        glVertex2i(-20, -20);
        glVertex2i(20, -20);
        glVertex2i(0, 30);
    glEnd();
    glFlush();
}
// Display for Object 2
void displayObject2() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the axis (orthographic projection) for Object 2
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    // Draw Object 2 (Blue Square)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
        glVertex2i(30, 30);
        glVertex2i(70, 30);
        glVertex2i(70, 70);
        glVertex2i(30, 70);
    glEnd();
    glFlush();
}
// Keyboard input function to switch between displays
void keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentDisplay = 1; // Switch to Object 1
        glutPostRedisplay();
    } else if (key == '2') {
        currentDisplay = 2; // Switch to Object 2
        glutPostRedisplay();
    }
}
// Main display function
void display() {
    if (currentDisplay == 1) {
        displayObject1();
    } else if (currentDisplay == 2) {
        displayObject2();
    }
}
// Initialization
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Keyboard-Controlled Displays");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

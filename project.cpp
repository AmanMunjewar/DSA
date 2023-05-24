#include <GL/glut.h>
#include <math.h>

int i = 0; // Global variable for animation

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color for the car body
    glColor3f(0.8, 0.4, 0.1);

    // Draw the car body
    glBegin(GL_POLYGON);
    glVertex2f(30 + i, 350);
    glVertex2f(180 + i, 350);
    glVertex2f(170 + i, 425);
    glVertex2f(40 + i, 425);
    glEnd();

    // Set the color for the windows
    glColor3f(0.1, 0.4, 0.6);

    // Draw the windows
    glBegin(GL_QUADS);
    glVertex2f(55 + i, 365);
    glVertex2f(155 + i, 365);
    glVertex2f(155 + i, 400);
    glVertex2f(55 + i, 400);
    glEnd();

    // Set the color for the wheels
    glColor3f(0.2, 0.2, 0.2);

    // Draw the back wheels
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(140 + i, 340);
    for (int angle = 0; angle <= 360; angle += 10)
    {
        float x = 140 + i + 12 * cos(angle * 3.14159 / 180);
        float y = 340 + 12 * sin(angle * 3.14159 / 180);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(70 + i, 340);
    for (int angle = 0; angle <= 360; angle += 10)
    {
        float x = 70 + i + 12 * cos(angle * 3.14159 / 180);
        float y = 340 + 12 * sin(angle * 3.14159 / 180);
        glVertex2f(x, y);
    }
    glEnd();


    // Increase the value of i for animation
    i++;

    glFlush();
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(25, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Car Animation");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 640, 0, 480);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}


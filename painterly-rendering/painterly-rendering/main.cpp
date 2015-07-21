
#include "main.h"

#include <iostream>
#include <GL/glut.h>
#include <GL/glui.h>

Global g;

/// <summary>
/// glut keyboard function
/// </summary>
/// <param name="key">The key pressed.</param>
/// <param name="x">The x position where the mouse was when the key was pressed.</param>
/// <param name="y">The y position where the mouse was when the key was pressed.</param>
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':
        glutLeaveMainLoop();
        glutDestroyWindow(g.glut_window);
        break;
    }
}

/// <summary>
/// glut display function
/// </summary>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


int main(int argc, char** argv) {
    g.window_width = 600;
    g.window_height = 600;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(g.window_width, g.window_height);
    glutInitWindowPosition(30, 30);
    g.glut_window = glutCreateWindow("painterly rendering");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, g.window_width, g.window_height, 0, 0, 1);

    glutDisplayFunc(display);
    glutKeyboardUpFunc(keyboard);

    GLUI* glui = GLUI_Master.create_glui_subwindow(g.glut_window, GLUI_SUBWINDOW_RIGHT);

    glutMainLoop();
    return 0;
}

#ifndef CUSTOMQTOPENGLWIDGET_H
#define CUSTOMQTOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QtGlobal>

class customqtopenglwidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    customqtopenglwidget(QWidget* parent = nullptr){Q_UNUSED(parent)};

    void drawPseudoPixel(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b);
    void DDA(GLfloat xs, GLfloat ys, GLfloat xe, GLfloat ye, GLfloat r, GLfloat g, GLfloat b);
    void BLA(GLint xs, GLint ys, GLint xe, GLint ye, GLfloat r, GLfloat g, GLfloat b);
protected:
    void initializeGL() override
    {
        glClearColor(1,1,1,1);
    }
    void paintGL() override
    {
        BLA(-99, -99, 0, 101, 0.80, 0.20, 0.25);
        BLA(99, -99, 0, 101, 0.80, 0.20, 0.25);
        DDA(-0.99, -0.99, 0.99, -0.99, 0.17, 0.30, 0.20);
    }
};

#endif // CUSTOMQTOPENGLWIDGET_H

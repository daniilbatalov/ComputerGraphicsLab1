#include <customqtopenglwidget.h>
#include <iostream>

void swap(int *a, int *b)
{
    (*a) = (*a) ^ (*b);
    (*b) = (*b) ^ (*a);
    (*a) = (*a) ^ (*b);
}

void customqtopenglwidget::drawPseudoPixel(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b)
{
    glColor3f(r, g, b);
    glRectf(x - 0.01, y - 0.01, x + 0.01, y + 0.01);
}
void customqtopenglwidget::DDA(GLfloat xs, GLfloat ys, GLfloat xe, GLfloat ye, GLfloat r, GLfloat g, GLfloat b)
{
    bool direction; //true - vertical, false - horizontal
    float dx, dy, d;
    dx = xe - xs;
    dy = ye - ys;
    if (dx == 0.0)
    {
        d = 0.0;
        direction = true;
    }
    else if (dy == 0.0)
    {
        d = 0.0;
        direction = false;
    }
    else if (dx >= dy)
    {
        d = dy /(50 * dx);
        direction = false;
    }
    else
    {
        d = dx /(50 * dy);
        direction = true;

    }
    drawPseudoPixel(xs, ys, r, g, b);
    float x = xs;
    float y = ys;
    if (direction)
    {
        do
        {
            y += 0.02;
            x += d;
            drawPseudoPixel(x, y, r, g, b);
        }
        while (y <= ye);
    }
    else
    {
        do
        {
            x += 0.02;
            y += d;
            drawPseudoPixel(x, y, r, g, b);
        }
        while (x <= xe);
    }
}
void customqtopenglwidget::BLA(GLint xs, GLint ys, GLint xe, GLint ye, GLfloat r, GLfloat g, GLfloat b)
{
    if (ys > ye)
    {
        swap(&xs, &xe);
        swap(&ys, &ye);
    }
    int dx, d, deltax, deltay;
    unsigned int t, delta;
    deltax = xe - xs;
    deltay = ye - ys;
    if (deltax > 0)
    {
        dx = 1;
    }
    else
    {
        dx = -1;
        deltax = -deltax;
    }
    d = 0;
    if (deltay >= deltax)
    {
        t = deltax;
        t <<= 1;
        delta = deltay;
        delta <<= 1;
        do
        {
            drawPseudoPixel((GLfloat)xs / 100.0, (GLfloat)ys / 100.0, r, g, b);
            ys++;
            d += t;
            if (d > deltay)
            {
                xs += dx;
                d -= delta;
            }
        }
        while (xs != xe);
    }
    else
    {
        t = deltay;
        t <<= 1;
        delta = deltax;
        delta <<= 1;
        do
        {
            drawPseudoPixel((GLfloat)xs / 100.0, (GLfloat)ys / 100.0, r, g, b);
            xs++;
            d += t;
            if (d > deltax)
            {
                ys += 1;
                d -= delta;
            }
        }
        while (ys != ye);
    }
}

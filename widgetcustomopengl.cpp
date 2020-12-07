#include "widgetcustomopengl.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QDebug>
#include <iostream>


WidgetCustomOpenGL::WidgetCustomOpenGL(QString imageFile, QWidget *parent)
{
    source = imageFile;
    image = new QImage();
    image->load(imageFile);

    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
}

void WidgetCustomOpenGL::initializeGL()
{
    initializeOpenGLFunctions();
}

void WidgetCustomOpenGL::paintGL()
{
     // Clear buffer with blue color
     glClearColor(0, 0, 1, 0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw Texture
    glEnable(GL_TEXTURE_2D); // Enable texturing
    glActiveTexture(GL_TEXTURE1);
    GLuint textureID;
    glGenTextures(1, &textureID); // Obtain an id for the texture
    glBindTexture(GL_TEXTURE_2D, textureID); // Set as the current texture
    QImage tex = QGLWidget::convertToGLFormat(*image);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glDisable(GL_TEXTURE_2D);
    glDrawPixels(tex.width(), tex.height(), GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

}

void WidgetCustomOpenGL::mousePressEvent(QMouseEvent *event)
{
    emit this->clicked(this);
}

void WidgetCustomOpenGL::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width) / 2, (height) / 2, side, side);
}

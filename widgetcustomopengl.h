#ifndef WidgetCustomOpenGL_H
#define WidgetCustomOpenGL_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

#include <QtOpenGL/QGLWidget>
#include <QLabel>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram);
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)

class WidgetCustomOpenGL : public QGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit WidgetCustomOpenGL(QString imageFile, QWidget *parent = nullptr);

    QString source;

    void resizeGL(int width, int height) override;

private:
    QImage *image;

protected:
    void initializeGL() override;
    void paintGL() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void clicked(WidgetCustomOpenGL * oglw);

public slots:
    void mousePressEvent(QMouseEvent * event) override;

};

#endif // WidgetCustomOpenGL_H

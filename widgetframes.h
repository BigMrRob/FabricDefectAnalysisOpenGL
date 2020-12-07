#ifndef WIDGETFRAMES_H
#define WIDGETFRAMES_H

#include <QWidget>
#include "widgetcustomopengl.h"
#include "widgetdisplayframe.h"

class WidgetFrames : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrames(QWidget *parent = nullptr);
    ~WidgetFrames();

    WidgetDisplayFrame *widgetDisplayFrame;

    WidgetCustomOpenGL *oglFrame1;
    WidgetCustomOpenGL *oglFrame2;
    WidgetCustomOpenGL *oglFrame3;
    WidgetCustomOpenGL *oglFrame4;
    WidgetCustomOpenGL *oglFrame5;
    WidgetCustomOpenGL *oglFrame6;
    WidgetCustomOpenGL *oglFrame7;
    WidgetCustomOpenGL *oglFrame8;

    QLabel *labelFrame1;
    QLabel *labelFrame2;
    QLabel *labelFrame3;
    QLabel *labelFrame4;
    QLabel *labelFrame5;
    QLabel *labelFrame6;
    QLabel *labelFrame7;
    QLabel *labelFrame8;

protected slots:
    void displayWidgetCustomOpenGL(WidgetCustomOpenGL *oglw);
};

#endif // WIDGETFRAMES_H

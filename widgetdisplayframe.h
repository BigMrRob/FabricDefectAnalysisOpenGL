#ifndef WIDGETDISPLAYFRAME_H
#define WIDGETDISPLAYFRAME_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "widgetcustomopengl.h"

class WidgetDisplayFrame : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDisplayFrame(QWidget *parent = nullptr);
    ~WidgetDisplayFrame();

    void setCurrentDisplay(QString source, QLabel *label);

private:
    WidgetCustomOpenGL * currentOgl;
    QGridLayout *gridLayout = new QGridLayout();
};

#endif // WIDGETDISPLAYFRAME_H

#include "widgetdisplayframe.h"
#include "ui_widgetdisplayframe.h"
#include <QStyle>
#include <QDesktopWidget>

WidgetDisplayFrame::WidgetDisplayFrame(QWidget *parent) :
    QWidget(parent)
{
    currentOgl = nullptr;

    setGeometry(QStyle::alignedRect(
                     Qt::LeftToRight,
                     Qt::AlignCenter,
                     size(),
                     qApp->desktop()->availableGeometry()
                 ));

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    setLayout(gridLayout);

    setBaseSize(QSize(512, 512));
}

WidgetDisplayFrame::~WidgetDisplayFrame()
{
}

void WidgetDisplayFrame::setCurrentDisplay(QString source, QLabel *label)
{
    QLayoutItem *wItem;

    while( (wItem = gridLayout->takeAt(0)) != 0)
    {
        delete wItem->widget();
        delete wItem;
    }
    label->setAlignment(Qt::AlignCenter);
    currentOgl = new WidgetCustomOpenGL(source);
    gridLayout->addWidget(currentOgl, 0, 0);
    gridLayout->addWidget(label, 1, 0);
    show();
}

#include "widgetframes.h"
#include "ui_widgetframes.h"
#include <iostream>
#include <QLabel>
#include <QSizePolicy>
#include <QSize>
#include <QLayoutItem>
#include <QStyle>
#include <QDesktopWidget>

WidgetFrames::WidgetFrames(QWidget *parent) :
    QWidget(parent)
{
    this->setMinimumSize(QSize(730, 329));

    setGeometry(QStyle::alignedRect(
                     Qt::LeftToRight,
                     Qt::AlignCenter,
                     size(),
                     qApp->desktop()->availableGeometry()
                 ));

    QGridLayout *gridLayout = new QGridLayout();

    this->widgetDisplayFrame = new WidgetDisplayFrame();

    this->oglFrame1 = new WidgetCustomOpenGL(QString(":/samples/samples/0003.jpg"));
    this->labelFrame1 = new QLabel("A");
    this->labelFrame1->setAlignment(Qt::AlignCenter);
    this->labelFrame1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame1, 0, 0);
    gridLayout->addWidget(this->labelFrame1, 1, 0);
    connect(this->oglFrame1, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));

    this->oglFrame2 = new WidgetCustomOpenGL(QString(":/samples/samples/0010.jpg"));
    this->labelFrame2= new QLabel("B");
    this->labelFrame2->setAlignment(Qt::AlignCenter);
    this->labelFrame2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame2, 0, 1);
    gridLayout->addWidget(this->labelFrame2, 1, 1);
    connect(this->oglFrame2, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame3 = new WidgetCustomOpenGL(QString(":/samples/samples/0033.jpg"));
    this->labelFrame3 = new QLabel("C");
    this->labelFrame3->setAlignment(Qt::AlignCenter);
    this->labelFrame3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame3, 0, 2);
    gridLayout->addWidget(this->labelFrame3, 1, 2);
    connect(this->oglFrame3, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame4 = new WidgetCustomOpenGL(QString(":/samples/samples/0065.jpg"));
    this->labelFrame4 = new QLabel("D");
    this->labelFrame4->setAlignment(Qt::AlignCenter);
    this->labelFrame4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame4, 0, 3);
    gridLayout->addWidget(this->labelFrame4, 1, 3);
    connect(this->oglFrame4, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame5 = new WidgetCustomOpenGL(QString(":/samples/samples/0074F.jpg"));
    this->labelFrame5 = new QLabel("E");
    this->labelFrame5->setAlignment(Qt::AlignCenter);
    this->labelFrame5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame5, 2, 0);
    gridLayout->addWidget(this->labelFrame5, 3, 0);
    connect(this->oglFrame5, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame6 = new WidgetCustomOpenGL(QString(":/samples/samples/0117.jpg"));
    this->labelFrame6 = new QLabel("F");
    this->labelFrame6->setAlignment(Qt::AlignCenter);
    this->labelFrame6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame6, 2, 1);
    gridLayout->addWidget(this->labelFrame6, 3, 1);
    connect(this->oglFrame6, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame7 = new WidgetCustomOpenGL(QString(":/samples/samples/0187.jpg"));
    this->labelFrame7 = new QLabel("G");
    this->labelFrame7->setAlignment(Qt::AlignCenter);
    this->labelFrame7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame7, 2, 2);
    gridLayout->addWidget(this->labelFrame7, 3, 2);
    connect(this->oglFrame7, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->oglFrame8 = new WidgetCustomOpenGL(QString(":/samples/samples/0190.jpg"));
    this->labelFrame8 = new QLabel("H");
    this->labelFrame8->setAlignment(Qt::AlignCenter);
    this->labelFrame8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gridLayout->addWidget(this->oglFrame8, 2, 3);
    gridLayout->addWidget(this->labelFrame8, 3, 3);
    connect(this->oglFrame8, SIGNAL(clicked(WidgetCustomOpenGL*)), this, SLOT(displayWidgetCustomOpenGL(WidgetCustomOpenGL*)));


    this->setLayout(gridLayout);
}

WidgetFrames::~WidgetFrames()
{
}

void WidgetFrames::displayWidgetCustomOpenGL(WidgetCustomOpenGL *oglw)
{
    QLabel *label = new QLabel();
    if (oglw->source == oglFrame1->source)
        label->setText(labelFrame1->text());
    else if (oglw->source == oglFrame2->source)
        label->setText(labelFrame2->text());
    else if (oglw->source == oglFrame3->source)
        label->setText(labelFrame3->text());
    else if (oglw->source == oglFrame4->source)
        label->setText(labelFrame4->text());
    else if (oglw->source == oglFrame5->source)
        label->setText(labelFrame5->text());
    else if (oglw->source == oglFrame6->source)
        label->setText(labelFrame6->text());
    else if (oglw->source == oglFrame7->source)
        label->setText(labelFrame7->text());
    else
        label->setText(labelFrame8->text());

    this->widgetDisplayFrame->setCurrentDisplay(oglw->source, label);
}

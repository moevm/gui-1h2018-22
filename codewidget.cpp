#include "codewidget.h"

CodeWidget::CodeWidget(QWidget *parent) : QWidget(parent)
{
    QPalette Pal(palette());

    // устанавливаем цвет фона
    Pal.setColor(QPalette::Background, QColor(0,255,0));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    setMaximumHeight(100);
    setMinimumSize(QSize(800, 100));

}

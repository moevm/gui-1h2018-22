#ifndef CODEBLOCKBUTTON_H
#define CODEBLOCKBUTTON_H

#include <QPushButton>
#include "action.h"

class CodeBlockButton : public QPushButton
{
    Q_OBJECT
    Action act;
    bool selected = false;
public:
    explicit CodeBlockButton(QWidget *parent = nullptr);
    void setAct(Action act);
    void setSelected(bool selected);
    void drawSelect();
    void drawAct();
    bool isSelected();

signals:

public slots:
    void on_codeBlockButton_clicked();
};

#endif // CODEBLOCKBUTTON_H

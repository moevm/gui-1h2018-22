#ifndef CODEBLOCKBUTTON_H
#define CODEBLOCKBUTTON_H

#include <QPushButton>
#include "action.h"

class CodeBlockButton : public QPushButton
{
    Q_OBJECT
    Action act = NOTHING;
    bool selected = false;
    Action changeAct = NOTHING;

public:
    explicit CodeBlockButton(QWidget *parent = nullptr);
    void setAct(Action act);
    void setChangeAct(Action act);
    void setSelected(bool selected);
    void drawSelect();
    void removeSelect();
    void drawAct();
    bool isSelected();
    Action getAct();

signals:

public slots:
    void on_codeBlockButton_clicked();
    void changeAction();
};

#endif // CODEBLOCKBUTTON_H

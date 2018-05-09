#ifndef CODEBLOCKBUTTON_H
#define CODEBLOCKBUTTON_H

#include <QPushButton>
#include <QTextEdit>
#include "action.h"

class CodeBlockButton : public QPushButton
{
    Q_OBJECT
    Action act = NOTHING;
    bool selected = false;
    Action changeAct = NOTHING;
    QTextEdit* iterations;

public:
    explicit CodeBlockButton(QWidget *parent = nullptr);
    void setAct(Action act);
    void setChangeAct(Action act);
    void setSelected(bool selected);
    void setIterations(QTextEdit* iterations);
    void drawSelect();
    void removeSelect();
    void drawAct();
    bool isSelected();
    Action getAct();
    QTextEdit* getIterations();
    void clean();

signals:

public slots:
    void on_codeBlockButton_clicked();
    void changeAction();
};

#endif // CODEBLOCKBUTTON_H

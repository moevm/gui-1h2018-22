#ifndef LEVELFIELD_H
#define LEVELFIELD_H

#include <QWidget>
#include "fieldstate.h"

class LevelField : public QWidget
{
    Q_OBJECT
    FieldState fs;
    bool hasCoin = false;
public:
    explicit LevelField(QWidget *parent = nullptr);
    void setField(FieldState fs);
    void putCoin();
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // LEVELFIELD_H

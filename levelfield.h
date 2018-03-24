#ifndef LEVELFIELD_H
#define LEVELFIELD_H

#include <QWidget>

class LevelField : public QWidget
{
    Q_OBJECT
public:
    explicit LevelField(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // LEVELFIELD_H

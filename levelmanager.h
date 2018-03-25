#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <QVector>
#include "fieldstate.h"

class LevelManager
{
    QVector<QVector<QVector<QChar>>> levels;
    QVector<QVector<FieldState>> currentLevel;

public:
    LevelManager();
    void setLevel(int level);
    QVector<QVector<FieldState>> getCurrentLevel();

};

#endif // LEVELMANAGER_H

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <QVector>
#include "fieldstate.h"
#include "player.h"
#include "action.h"


class LevelManager
{
    QVector<QVector<QVector<QChar>>> levels;
    QVector<QVector<FieldState>> currentLevel;
    Player player;
public:
    LevelManager();
    void setLevel(int level);
    QVector<QVector<FieldState>> getCurrentLevel();
    void start();
    void updateLevel(Action act);
    void setCode(QVector<Action>* code);
    bool isAvailibaleMove();
};

#endif // LEVELMANAGER_H

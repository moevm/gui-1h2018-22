#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <QVector>
#include "fieldstate.h"
#include "player.h"
#include "action.h"
#include "coin.h"

class LevelManager
{
    QVector<QVector<QVector<QChar>>> levels;
    int level;
    QVector<QVector<FieldState>> currentLevel;
    QPoint prevPlayersPos;
    Player player;
    QVector<Coin> coins;
public:
    LevelManager();
    void setLevel(int level);
    void setLevel();
    int nextLevel();
    QVector<QVector<FieldState>> getCurrentLevel();
    void start();
    void updateLevel(Action act);
    void setCode(QVector<Action>* code);
    bool isAvailibaleMove();
    bool hasCoin(int x, int y);
    bool removeCoin(int x, int y);
    int coinsSize();
    Player getPlayer();
    QPoint getPrevPlayersPos();

};

#endif // LEVELMANAGER_H

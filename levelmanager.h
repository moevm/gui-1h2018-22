#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <QVector>

class LevelManager
{
    QVector<QVector<QVector<bool>>> levels;
public:
    LevelManager();
    QVector<QVector<bool>> getLevel(int level);
};

#endif // LEVELMANAGER_H

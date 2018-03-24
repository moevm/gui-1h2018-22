#include "levelmanager.h"
#include <QDebug>
#include <QFile>

LevelManager::LevelManager()
{
    levels = QVector<QVector<QVector<bool>>>(1);
    QFile sizes("D:/game/GUI/levels/sizes.txt");
    if (sizes.exists())
    {
        qDebug() << "Good";
    }else{
        qDebug() << "Ошибка открытия для чтения";
    }
    sizes.open(QIODevice::ReadWrite);
    QString str = sizes.readLine();
    int w, h;
    str.remove(0, 3);
    QStringList list = str.split(" x ");
    w =((QString) list.at(0)).toInt();
    h =((QString) list.at(1)).toInt();
    QFile levelFile("D:/game/GUI/levels/level1.txt");
    levelFile.open(QIODevice::ReadWrite);

    levels[0] = QVector<QVector<bool>>(w);
    for(int i = 0; i < w; i++) {
        levels[0][i] = QVector<bool>(h);
    }
     qDebug() << "level init";
    for(int i = 0; i < w; i++){
        str = levelFile.readLine();
        list = str.split(" ");
        for(int j = 0; j < h; j++){
            levels[0][i][j] = ((QString) list.at(j)).toInt();
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            //qDebug() << levels[0][i][j];
        }
    }
    levelFile.close();
    sizes.close();
}

QVector<QVector<bool> > LevelManager::getLevel(int level)
{
    return levels[level];
}

#include "levelmanager.h"
#include <QDebug>
#include <QFile>

LevelManager::LevelManager()
{
    levels = QVector<QVector<QVector<QChar>>>(1);
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

    levels[0] = QVector<QVector<QChar>>(h);
    for(int i = 0; i < h; i++) {
        levels[0][i] = QVector<QChar>(w);
    }
     qDebug() << "level init";
    for(int i = 0; i < h; i++){
        str = levelFile.readLine();
        list = str.split(" ");
        for(int j = 0; j < w; j++){
            levels[0][i][j] = list.at(j).at(0);
        }
    }
    qDebug() << "level end";

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            //qDebug() << levels[0][i][j];
        }
    }
    levelFile.close();
    sizes.close();
}

void LevelManager::setLevel(int level)
{
    int height = levels[level].size();
    int width = levels[level][0].size();
    currentLevel = QVector<QVector<FieldState>>(height);
    for(int i = 0; i < height; i++) {
        currentLevel[i] = QVector<FieldState>(width);
    }
    qDebug() << "start set";
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            QChar field = levels[level][i][j];
            if(field == '0'){
                currentLevel[i][j] = CELL;
            } else if(field == '1'){
                currentLevel[i][j] = WALL;
            }else if(field == 'p'){
                currentLevel[i][j] = PLAYER_RIGHT;
            }
        }
    }
    qDebug() << "end set";

}

QVector<QVector<FieldState>> LevelManager::getCurrentLevel()
{
    return currentLevel;
}


























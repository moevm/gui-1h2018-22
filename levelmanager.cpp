#include "levelmanager.h"
#include <QDebug>
#include <QFile>

static int LEVEL_COUNT = 4;
LevelManager::LevelManager()
{
    levels = QVector<QVector<QVector<QChar>>>(LEVEL_COUNT);
    QFile sizes("D:/game/GUI/levels/sizes.txt");
    if (sizes.exists())
    {
        qDebug() << "Good";
    }else{
        qDebug() << "Ошибка открытия для чтения";
    }
    sizes.open(QIODevice::ReadWrite);
    for(int l = 0; l < LEVEL_COUNT; l++){
        QString str = sizes.readLine();
        int w, h;
        str.remove(0, 3);
        QStringList list = str.split(" x ");
        w =((QString) list.at(0)).toInt();
        h =((QString) list.at(1)).toInt();
        best[l] =((QString) list.at(2)).toInt();
        QFile levelFile(QStringLiteral("D:/game/GUI/levels/level%1.txt").arg(l+1));

        levelFile.open(QIODevice::ReadWrite);

        levels[l] = QVector<QVector<QChar>>(h);
        for(int i = 0; i < h; i++) {
            levels[l][i] = QVector<QChar>(w);
        }
        for(int i = 0; i < h; i++){
            str = levelFile.readLine();
            list = str.split(" ");
            for(int j = 0; j < w; j++){
                levels[l][i][j] = list.at(j).at(0);
            }
        }
        levelFile.close();
    }
    sizes.close();
}

void LevelManager::setLevel()
{
    setLevel(level);
}

void LevelManager::setLevel(int level)
{
    this->level = level;
    int height = levels[level].size();
    int width = levels[level][0].size();
    currentLevel = QVector<QVector<FieldState>>(height);
    for(int i = 0; i < height; i++) {
        currentLevel[i] = QVector<FieldState>(width);
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            QChar field = levels[level][i][j];
            if(field == '0'){
                currentLevel[i][j] = CELL;
            } else if(field == '1'){
                currentLevel[i][j] = WALL;
            }else if(field == 'p'){
                player.setPos(i, j);
                player.setTurn(PLAYER_RIGHT);
                prevPlayersPos = player.getPos();
                currentLevel[i][j] = PLAYER_RIGHT;
            }else if(field == 'c'){
                coins.append(Coin(i, j));
                currentLevel[i][j] = CELL;
            }
        }
    }
}

int LevelManager::nextLevel()
{
    if(level < LEVEL_COUNT){
        return ++level;
    }
}

QVector<QVector<FieldState>> LevelManager::getCurrentLevel()
{
    return currentLevel;
}



void LevelManager::updateLevel(Action act)
{
    switch (act) {
    case TURN_RIGHT:
    {
        player.turnRight();
        currentLevel[player.getX()][player.getY()] = player.getTurn();
        break;
    }
    case TURN_LEFT:
    {
        player.turnLeft();
        currentLevel[player.getX()][player.getY()] = player.getTurn();
        break;
    }
    case MOVE:
    {
        prevPlayersPos = player.getPos();
        if(isAvailibaleMove()){
            currentLevel[player.getX()][player.getY()] = CELL;
            player.move();
            int px = player.getX();
            int py = player.getY();
            while(this->hasCoin(px, py)){
                this->removeCoin(px, py);
            }
            currentLevel[px][py] = player.getTurn();
        }
        break;
    }

    }

}

bool LevelManager::isAvailibaleMove()
{
    int nx = player.getNextPos().x();
    int ny = player.getNextPos().y();
    return nx >= 0
        && nx < currentLevel.size()
        && ny >= 0
        && ny < currentLevel[0].size()
            && currentLevel[nx][ny] != WALL;
}

bool LevelManager::hasCoin(int x, int y)
{
    for(int i = 0; i < coins.size(); i++){
        if(coins[i].getPos() == QPoint(x,y)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::removeCoin(int x, int y)
{
    for(int i = 0; i < coins.size(); i++){
        if(coins[i].getPos() == QPoint(x,y)) {
            coins.remove(i);
            return true;
        }
    }
    return false;
}

int LevelManager::coinsSize()
{
    return coins.size();
}

Player LevelManager::getPlayer()
{
    return player;
}

QPoint LevelManager::getPrevPlayersPos()
{
    return prevPlayersPos;
}

int LevelManager::getbest(int i)
{
    return best[i];
}

int LevelManager::getLevel()
{
    return level;
}




























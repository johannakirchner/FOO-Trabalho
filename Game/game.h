#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTextEdit>
#include <QMouseEvent>

#include "player.h"
#include "score.h"
#include "health.h"


class Game: public QGraphicsView {
public:

    Game(QWidget * parent=0);
    // game possui a cena, player, score e health
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

};

#endif // GAME_H

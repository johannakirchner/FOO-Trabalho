#include "enemy.h"
#include "game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() retorna um int grandao

extern Game * game;

Enemy::Enemy()
{

    // set randompos
    // resto de 700 pq dai nao fica maior que o tamanho da tela
    int random_number = rand() % 700;
    setPos(random_number,0);

    // desenhou o rect
    setRect(0,0,50,50);

    // conectar
    QTimer * timer = new QTimer();
    // a cada timeout() tempos o move vai ser chamado
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // a cada 50ms o metodo timeout da sua classe vai ser chamado
    timer->start(50);

}

void Enemy::move(){
    setPos(x(),y()+7);

    if(this->pos().y() > 600 - 50) {
        // diminuir a vida
        game->health->altera();

        scene()->removeItem(this);
        delete this;
    }
}

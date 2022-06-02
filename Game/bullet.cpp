#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <vector>

extern Game * game; // existe uma variavel global desse tipo

Bullet::Bullet()
{
    // desenhou o rect
    setRect(45,0,10,50);

    // conectar
    QTimer * timer = new QTimer();
    // a cada timeout() tempos o move vai ser chamado
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // a cada 50ms o metodo timeout da sua classe vai ser chamado
    timer->start(50);

}

void Bullet::move(){
    // se a bala colidir com o inimigo destruir os dois
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            // aumentar o score
            game->score->altera();

            // remover os dois
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // deletar da heap
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-20);

    if(this->pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsRectItem>
// qualquer coisa que usa signass e slots tem que derivar de qobject
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
    //public slots metodos que pode ser conectado a um sinal
public slots:
    void move();
};

#endif // ENEMY_H

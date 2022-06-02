#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
    //member function que pode ser conectado a um sinal
public slots:
    void move();
};

#endif // BULLET_H

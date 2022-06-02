#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    // evento de apertar teclas
    void keyPressEvent(QKeyEvent * event);
    // evento de mouse
    void mousePressEvent(QGraphicsSceneMouseEvent  * event);
public slots:
    // evento para spawnar inimigo
    void spawn();
};

#endif // PLAYER_H

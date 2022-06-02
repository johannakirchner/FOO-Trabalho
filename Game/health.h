#ifndef HEALTH_H
#define HEALTH_H

#include "texto.h"

#include <QGraphicsTextItem>

// herda de texto
class Health: public Texto
{
public:
    Health();
    // sobrescreve ambos
    void altera();
    void setAtributo(int x);
};

#endif // HEALTH_H

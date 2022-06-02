#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "texto.h"

// herda de texto
class Score: public Texto
{
public:
    Score();
    // sobrescreve ambos
    void altera();
    void setAtributo(int x);
};

#endif // SCORE_H

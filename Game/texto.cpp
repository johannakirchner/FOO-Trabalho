#include "texto.h"

Texto::Texto(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    // apenas atribui parent ao QGraphicsTextItem
}

int Texto::getAtributo()
{
    // retorna o atributo
    return atributo;
}




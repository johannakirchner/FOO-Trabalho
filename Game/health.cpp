#include "health.h"

Health::Health()
{
    atributo = 3;
    // inicializar a vida em 3
    // fazer o texto na tela como Health:
    setPlainText(QString("Health: ") + QString::number(atributo));
    setDefaultTextColor(Qt::black);
}

// sobrescreve
void Health::altera()
{
    // no caso de health o atributo diminui seu valor
    atributo--;
    // escreve na tela de novo
    setPlainText(QString("Health: ") + QString::number(atributo));
}

// sobrescreve
void Health::setAtributo(int x)
{
    // atribui o atributo
    atributo = x;
    // escreve na tela de novo
    setPlainText(QString("Health: ") + QString::number(atributo));
}


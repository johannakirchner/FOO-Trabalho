#include "score.h"

Score::Score()
{
    atributo = 0;
    // inicializar o score em zero
    // fazer o texto na tela como Score:
    setPlainText(QString("Score: ") + QString::number(atributo));
    setDefaultTextColor(Qt::black);
}

// sobrescreve
void Score::altera()
{
    // no caso de score o atributo aumenta seu valor
    atributo++;
    // escreve na tela de novo
    setPlainText(QString("Score: ") + QString::number(atributo));
}

// sobrescreve
void Score::setAtributo(int x)
{
    // atribui o atributo
    atributo = x;
    // escreve na tela de novo
    setPlainText(QString("Score: ") + QString::number(atributo));
}


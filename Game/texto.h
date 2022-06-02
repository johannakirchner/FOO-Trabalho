#ifndef TEXTO_H
#define TEXTO_H

#include <QGraphicsTextItem>

class Texto: public QGraphicsTextItem
{
public:
    Texto(QGraphicsItem * parent = 0);
    virtual void altera() = 0;
    // nao precisa ser sobrescrito pois eh sempre igual, apenas um return
    int getAtributo();
    // set atributo eh sobrescrito pois precisa ser reescrito na tela
    virtual void setAtributo(int x) = 0;
protected:
    // protected para as herancas tenham acesso para poder alturar
    int atributo;
};

#endif // TEXTO_H

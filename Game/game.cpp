#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTextEdit>
#include <vector>
#include <string>
#include <fstream>

#include "enemy.h"




Game::Game(QWidget *parent){
    // cria a cena
    scene = new QGraphicsScene();
    // faz a cena ter 800 por 600
    scene->setSceneRect(0,0,800,600);

    // faz a faz a cena ser vizualizavel
    setScene(scene);
    // desativa as barras de scroll lateral e inferior
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // deixa o tamanho da janela fixo
    setFixedSize(800,600);

    // cria o player
    player = new Player();
    player->setRect(0,0,100,100); // seta o player como 100x100 pixels
    player->setPos(400,500); // seta a posicao no meio da tela

    // fazer o score / health e adiciona ambos na tela
    // score fica auto no cantinho e entao coloca o health 20 pixels para baixo
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y() + 20);
    scene->addItem(health);

    // faz o player focavel e ser o foco
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // adiciona o player na cena
    scene->addItem(player);

    // spawna os inimigos
    QTimer * timer = new QTimer();
    // conecta o timer com a funcao spawnar
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    // a cada 2000 ms spawna um inimigo
    timer->start(2000);

    show();
}

#include <QApplication>
#include "game.h"

// cria um game como global para outros objetos terem acesso
Game * game;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    // cria um novo game e deixa ele mostravel

    game = new Game();
    game->show();

    return a.exec();
}

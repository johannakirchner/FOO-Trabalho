#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"

#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <fstream>
#include <vector>
#include <string>
#include <QMessageBox>

// puxa a variavel game global para poder ser usada
extern Game * game;

void Player::keyPressEvent(QKeyEvent *event)
{
    // cada setinha faz o player se mover na direcao dada
    if(event->key() == Qt::Key_Left) {
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right) {
        if(pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up) {
        if(pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down) {
        if(pos().y() + 100 < 600)
        setPos(x(),y()+10);
    }
}

// o motivo de ser necessario clicar dentro do player com o mouse
// eh que o evento de mouse esta dentro do player, se clicar
// fora do player ele nao reconhece
void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // atirar com botao esquerdo
    if(event->button() == Qt::LeftButton) {
        // cria a bala
        Bullet * bullet = new Bullet();
        // posiciona a bala na posicao do player
        bullet->setPos(x(),y());
        // adiciona na cena
        scene()->addItem(bullet);
    }

    // salvar o estado do arquivo com o botao direito
    if(event->button() == Qt::RightButton) {
        // cria um vector para guardar as infos em string para poder escrever no arquivo
        std::vector<std::string> infos;

        infos.push_back(std::to_string(game->score->getAtributo()));
        infos.push_back(std::to_string(game->health->getAtributo()));

        // manda para o arquivo as infos com um espaco separando
        std::fstream f("pontuacao.txt", std::fstream::out);
        f << infos[0] << " " << infos[1];
        f.close();
        QMessageBox::warning(game, "Sucesso", "Estado salvo.");
    }

    // carregar o arquivo salvo com o botao do meio
    if(event->button() == Qt::MiddleButton) {
        // abre o arquivo pontuacao.txt
        std::fstream f("pontuacao.txt", std::fstream::in);
        try {
        // se o arquivo estiver aberto (significa que existe) E olha (peek) dentro do
        // arquivo e retorna true caso a primeira coisa que olha eh o eof - end of file
        // o que siginifica que nao tem nada dentro
        if(f.is_open() && !(f.peek() == std::ifstream::traits_type::eof())) {
            std::string texto;
            // salva a linha na var texto
            std::getline(f, texto);
            // salva o valor convertendo para int do comeco da string ate encontrar o espaco
            game->score->setAtributo(stoi(texto.substr(0, texto.find(" "))));
            // salva o valor convertendo para int do espaco ate o final
            game->health->setAtributo(stoi(texto.substr(texto.find(" "))));
            f.close();
            QMessageBox::warning(game, "Sucesso", "Estado carregado.");
        }
        // caso o arquivo nao exista ou o arquivo exista mas esteja vazio
        else
            throw -1;
        }
        catch(int) {
            // nao existem estados salvos. Crie um primeiro.
            QMessageBox::warning(game, "Erro", "Não existem estados salvos. Salve um primeiro.");
        }
    }
}

void Player::spawn() {
  // spawna um inimigo
  Enemy *enemy = new Enemy();
  // adicionar na cena
  scene()->addItem(enemy);
}

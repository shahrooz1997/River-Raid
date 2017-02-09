#include <QApplication>
#include "game.h"

Game *game;
Game *game1;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game1 = game;
    game->show();
    game->dispalyMenu();

    return a.exec();
}

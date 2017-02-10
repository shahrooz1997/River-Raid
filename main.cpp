#include <QApplication>
#include "game.h"

Game *game;
Game *game1;
int yspeed;
int max_speed;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game1 = game;
    game->show();
    max_speed = 15;
    game->dispalyMenu();

    return a.exec();
}

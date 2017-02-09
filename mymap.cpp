#include "mymap.h"
#include "game.h"

extern Game *game;

MyMap::MyMap(int help)
{
    int a;
    if(help == 1)
    {
        a = ((int)qrand())%2;
    }
    else
        a = ((int)qrand()) % 4;
    if(a == 0)
    {
        _left = new Wall(100);
        _left->setPos(0,-680);
        _right = new Wall(100);
        _right->setPos(700,-680);
        _mid = 0;
        for(int i=0;i<4;i++)
        {
            _smoother_mid_s[i] = 0;
//            _smoother_mid_s[i]->setPos(400-(10+23*i),-280+(3-i)*19);
            _smoother_mid_e[i] = 0;
//            _smoother_mid_e[i]->setPos(400-(10+23*i),-480-(19-19*i));
        }
    }
    else if(a == 1)
    {
        _left = new Wall(200);
        _left->setPos(0,-680);
        _right = new Wall(200);
        _right->setPos(600,-680);
        _mid = 0;
        for(int i=0;i<4;i++)
        {
            _smoother_mid_s[i] = 0;
//            _smoother_mid_s[i]->setPos(400-(10+23*i),-280+(3-i)*19);
            _smoother_mid_e[i] = 0;
//            _smoother_mid_e[i]->setPos(400-(10+23*i),-480-(19-19*i));
        }
    }
    else if(a == 2)
    {
        _left = new Wall(100);
        _left->setPos(0,-680);
        _right = new Wall(100);
        _right->setPos(700,-680);
        _mid = new Wall(200,200);
        _mid->setPos(300, -480);
        for(int i=0;i<4;i++)
        {
            _smoother_mid_s[i] = new Wall(20+46*i,19);
            _smoother_mid_s[i]->setPos(400-(10+23*i),-280+(3-i)*19);
            _smoother_mid_e[i] = new Wall(20+46*i,19);
            _smoother_mid_e[i]->setPos(400-(10+23*i),-480-(4*19-19*i));
        }
    }
    else if(a == 3)
    {
        _left = new Wall(100);
        _left->setPos(0,-680);
        _right = new Wall(100);
        _right->setPos(700,-680);
        _mid = new Wall(100,200);
        _mid->setPos(350, -480);
        for(int i=0;i<4;i++)
        {
            _smoother_mid_s[i] = new Wall(20+22*i,19);
            _smoother_mid_s[i]->setPos(400-(10+11*i),-280+(3-i)*19);
            _smoother_mid_e[i] = new Wall(20+22*i,19);
            _smoother_mid_e[i]->setPos(400-(10+11*i),-480-(4*19-19*i));
        }
    }
    set_smooth(a);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    before_state = a;
    new_map = 0;
}

Wall *MyMap::right()
{
    return _right;
}

Wall *MyMap::left()
{
    return _left;
}

Wall *MyMap::mid()
{
    return _mid;
}

Wall **MyMap::smoother_left()
{
    return _smoother_left;
}

Wall **MyMap::smoother_right()
{
    return _smoother_right;
}

Wall **MyMap::smoother_mid_e()
{
    return _smoother_mid_e;
}

Wall **MyMap::smoother_mid_s()
{
    return _smoother_mid_s;
}

void MyMap::start_timer()
{
    timer->start(50);
}

void MyMap::stop_timer()
{
    timer->stop();
}

MyMap::~MyMap()
{
    delete timer;
    if(_left != 0)
        delete _left;
    if(_right != 0)
        delete _right;
    if(_mid != 0)
        delete _mid;

    for(int i=0;i<4;i++)
    {
        if(_smoother_left[i]!=0)
            delete _smoother_left[i];
        if(_smoother_right[i]!=0)
            delete _smoother_right[i];
        if(_smoother_mid_e[i]!=0)
            delete _smoother_mid_e[i];
        if(_smoother_mid_s[i]!=0)
            delete _smoother_mid_s[i];
    }
}

void MyMap::set_before_state(bool a)
{
    before_state = a;
}

int MyMap::get_before_state()
{
    return before_state;
}

void MyMap::set_smooth(int now)
{
    if(before_state == now)
    {
        if(now == 0)
        {
            for(int i = 0; i < 4; i++)
            {
                _smoother_left[i] = new Wall(100, 19);
                _smoother_left[i]->setPos(0,-23-19*i);
                _smoother_right[i] = new Wall(100, 19);
                _smoother_right[i]->setPos(700, -23-19*i);
            }
        }
        else if(now == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                _smoother_left[i] = new Wall(200, 19);
                _smoother_left[i]->setPos(0,-23-19*i);
                _smoother_right[i] = new Wall(200, 19);
                _smoother_right[i]->setPos(600, -23-19*i);
            }
        }
        else if(now == 2)
        {
            for(int i=0;i<4;i++)
            {
                _smoother_left[i] = new Wall(100, 19);
                _smoother_left[i]->setPos(0,-23-19*i);
                _smoother_right[i] = new Wall(100, 19);
                _smoother_right[i]->setPos(700, -23-19*i);
            }
        }
        else if(now == 3)
        {
            for(int i=0;i<4;i++)
            {
                _smoother_left[i] = new Wall(100, 19);
                _smoother_left[i]->setPos(0,-23-19*i);
                _smoother_right[i] = new Wall(100, 19);
                _smoother_right[i]->setPos(700, -23-19*i);
//                _smoother_mid[i] = new Wall(100,19);
//                _smoother_mid[i]->setPos(350,-23-19*i);
            }
        }
        return;
    }
    else if(before_state == 0 && now == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(120 + i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(120 + i * 20, 19);
            _smoother_right[i]->setPos(680-i*20, -23-19*i);
//            _smoother_mid[i] = 0;
        }
    }
    else if(before_state == 0 && now == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(100, 19);
            _smoother_left[i]->setPos(0,-23-19*i);
            _smoother_right[i] = new Wall(100, 19);
            _smoother_right[i]->setPos(700, -23-19*i);
//            _smoother_mid[i] = new Wall(20+i*46,19);
//            _smoother_mid[i]->setPos(390-i*23,-23-19*i);
        }
    }
    else if(before_state == 0 && now == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(100, 19);
            _smoother_left[i]->setPos(0,-23-19*i);
            _smoother_right[i] = new Wall(100, 19);
            _smoother_right[i]->setPos(700, -23-19*i);
//            _smoother_mid[i] = new Wall(10+i*22,19);
//            _smoother_mid[i]->setPos(395-i*11,-23-19*i);
        }
    }
    else if(before_state == 1 && now == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(180 - i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(180 - i * 20, 19);
            _smoother_right[i]->setPos(620+i*20, -23-19*i);
//            _smoother_mid[3-i] = 0;
        }
    }
    else if(before_state == 1 && now == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(180 - i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(180 - i * 20, 19);
            _smoother_right[i]->setPos(620+i*20, -23-19*i);
//            _smoother_mid[i] = new Wall(20+i*46,19);
//            _smoother_mid[i]->setPos(390-i*23,-23-19*i);
        }
    }
    else if(before_state == 1 && now == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(180 - i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(180 - i * 20, 19);
            _smoother_right[i]->setPos(620+i*20, -23-19*i);
//            _smoother_mid[i] = new Wall(10+i*22,19);
//            _smoother_mid[i]->setPos(395-i*11,-23-19*i);
        }
    }
    else if(before_state == 2 && now == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[3-i] = new Wall(100, 19);
            _smoother_left[3-i]->setPos(0,-23-19*i);
            _smoother_right[3-i] = new Wall(100, 19);
            _smoother_right[3-i]->setPos(700, -23-19*i);
//            _smoother_mid[3-i] = new Wall(20+i*46,19);
//            _smoother_mid[3-i]->setPos(390-i*23,-23-19*i);
        }
    }
    else if(before_state == 2 && now == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(120 + i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(120 + i * 20, 19);
            _smoother_right[i]->setPos(680-i*20, -23-19*i);
//            _smoother_mid[3-i] = new Wall(20+i*46,19);
//            _smoother_mid[3-i]->setPos(390-i*23,-23-19*i);
        }
    }
    else if(before_state == 2 && now == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[3-i] = new Wall(100, 19);
            _smoother_left[3-i]->setPos(0,-23-19*i);
            _smoother_right[3-i] = new Wall(100, 19);
            _smoother_right[3-i]->setPos(700, -23-19*i);
//            _smoother_mid[3-i] = new Wall(110+i*22,19);
//            _smoother_mid[3-i]->setPos(345-i*11,-23-19*i);
        }
    }
    else if(before_state == 3 && now == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(100, 19);
            _smoother_left[i]->setPos(0,-23-19*i);
            _smoother_right[i] = new Wall(100, 19);
            _smoother_right[i]->setPos(700, -23-19*i);
//            _smoother_mid[3-i] = new Wall(10+i*22,19);
//            _smoother_mid[3-i]->setPos(395-i*11,-23-19*i);
        }
    }
    else if(before_state == 3 && now == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(120 + i * 20, 19);
            _smoother_left[i]->setPos(0,-23 - 19 * i);
            _smoother_right[i] = new Wall(120 + i * 20, 19);
            _smoother_right[i]->setPos(680-i*20, -23-19*i);
//            _smoother_mid[3-i] = new Wall(10+i*22,19);
//            _smoother_mid[3-i]->setPos(395-i*11,-23-19*i);
        }
    }
    else if(before_state == 3 && now == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            _smoother_left[i] = new Wall(100, 19);
            _smoother_left[i]->setPos(0,-23-19*i);
            _smoother_right[i] = new Wall(100, 19);
            _smoother_right[i]->setPos(700, -23-19*i);
//            _smoother_mid[i] = new Wall(110+i*22,19);
//            _smoother_mid[i]->setPos(345-i*11,-23-19*i);
        }
    }
    return;
}

void MyMap::move()
{
    if(left()!=0)
        this->left()->setPos(this->left()->x(),this->left()->y()+5);
    if(right()!=0)
        this->right()->setPos(this->right()->x(),this->right()->y()+5);
    if(mid()!=0)
        this->mid()->setPos(this->mid()->x(), this->mid()->y()+5);
    for(int i=0; i<4; i++)
    {
        if(smoother_left()[i]!=0)
            this->smoother_left()[i]->setPos(this->smoother_left()[i]->x(),this->smoother_left()[i]->y()+5);
        if(smoother_right()[i]!=0)
            this->smoother_right()[i]->setPos(this->smoother_right()[i]->x(),this->smoother_right()[i]->y()+5);
        if(smoother_mid_s()[i]!=0)
            this->smoother_mid_s()[i]->setPos(this->smoother_mid_s()[i]->x(),this->smoother_mid_s()[i]->y()+5);
        if(smoother_mid_e()[i]!=0)
            this->smoother_mid_e()[i]->setPos(this->smoother_mid_e()[i]->x(),this->smoother_mid_e()[i]->y()+5);
    }
    if(this->left()->y()>-6 && new_map == 0)
    {
        new_map = 1;
        game->create_map();
    }
    if(this->left()->y()>1200)
    {
        delete this;
    }
    return;
}

int MyMap::before_state;

#include "cell.h"
#include "main.h"
#include "mainwindow.h"

#include <QImage>

int Cell::lifes[cellNum]={1,1,1000,0,0};
//老王=1 墙=2 铁墙=10000 水=0 地=0
bool Cell::penetrations_of_tank[cellNum] = {false,false,false,false,true};
bool Cell::penetrations_of_missile[cellNum] = {false,false,false,true,true};

Cell::Cell()
{

}

Cell::Cell(int row,int col,int cur_kind)
{

    this->kind = cur_kind;

    this->pos.setX(row * CELLWIDTH);
    this->pos.setY(col * CELLHEIGHT);
    this->calSphere();
    this->disappear = false;
    this->life = lifes[this->kind];

}

void Cell::display(QPainter &paint)
{

    if(this->isDisappear() == true)
        return;

    switch(this->kind)
    {
    /*
     * 0 老王
     * 1 墙
     * 2 铁墙
     * 3 水
     * 4 地
     * */
    case 0:
        paint.drawImage(rectSphere, info.bossPic);
        break;
    case 1:
        paint.drawImage(rectSphere, info.cellImages[0]);//墙
        break;
    case 2:
        paint.drawImage(rectSphere, info.cellImages[1]);//铁墙
        break;
    case 3:
        paint.drawImage(rectSphere, info.cellImages[2]);//水
        break;
    case 4:
        break;
    default:
        break;
    }


}

void Cell::move()
{
    //can't move, do nothing
    return;
}

void Cell::calSphere()
{
    this->rectSphere.setRect(pos.x(), pos.y(),
                               CELLWIDTH,CELLHEIGHT);
}

void Cell::beAttacked(int attack)
{
    if(this->kind == BOSS)
    {
        info.boss->beAttacked(attack);
    }

    if(life > 0)
        life -= attack;

    if(life <= 0)
    {
        this->disappear = true;
        life = 0;
    }

}

bool Cell::is_penetration_of_tank()
{

    return penetrations_of_tank[this->kind];
}

bool Cell::is_penetration_of_missile()
{

    return penetrations_of_missile[this->kind];
}

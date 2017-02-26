#include "Cell.h"

Cell::Cell()
    :visited(false)
{
    for(int i = 0; i < 4; ++i)
        isOpen[i] = false;
}

Coord Cell::getPos() const
{
    return pos;
}

void Cell::setPos(Coord pos)
{
    this->pos = pos;
}

bool Cell::isVisited() const
{
    return visited;
}

void Cell::setVisited(bool visited){
    this->visited = visited;
}

void Cell::open(E_Direction direction)
{
    isOpen[direction] = true;
}

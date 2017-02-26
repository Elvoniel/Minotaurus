#ifndef CELL_H
#define CELL_H

#include "Coord.h"

class Cell
{
protected:
    bool visited;
    Coord pos;

    bool isOpen[4];
public:
    enum E_Direction {E_RIGHT = 0,E_LEFT,E_UP,E_DOWN};

    Cell();

    Coord getPos() const;
    void setPos(Coord pos);

    bool isVisited() const;
    void setVisited(bool visited = true);
    void open(E_Direction direction);
};

#endif // CELL_H

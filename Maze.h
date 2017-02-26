#ifndef MAZE_H
#define MAZE_H

#include <vector>

#include "Coord.h"
#include "Cell.h"
#include "AbstractGeneratingStrategy.h"


class Maze
{
private:
    int width;
    int height;

    Cell** cellTab;
    const AbstractGeneratingStrategy* generatingStrategy;
public:
    Maze(int width, int height);
    ~Maze();

    void getDimensions(int& width, int& height);
    Cell* getCell(Coord pos) const;

    bool getUnvisitedNeightbourgsDirection(const Cell& currentCell, std::vector<Cell::E_Direction> unvisitedNeightbourgs) const;
    Cell* getNeightbourgWithDirection(const Cell& currentCell, Cell::E_Direction direction) const;

    void setGeneratingStrategy(AbstractGeneratingStrategy::E_Strategy strategy);

    Cell& getCell(int x, int y);

};

#endif // MAZE_H

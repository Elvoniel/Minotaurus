#ifndef GENERATINGSTRATEGY_H
#define GENERATINGSTRATEGY_H

#include <vector>

class Maze;
class AbstractNextCellSelectionStrategy;
class Cell;

class AbstractGeneratingStrategy
{
protected:
    Maze& maze;
    std::vector<Cell*> cells;

    AbstractNextCellSelectionStrategy* nextCellSelectionStrategy;
public:
    enum E_Strategy {E_GROWING_TREE};

    AbstractGeneratingStrategy(Maze& maze, AbstractNextCellSelectionStrategy* nextCellSelectionStrategy);
    virtual ~AbstractGeneratingStrategy();

    virtual void generateMaze() = 0;
};

#endif // GENERATINGSTRATEGY_H

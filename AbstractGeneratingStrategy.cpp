#include "AbstractGeneratingStrategy.h"
#include "AbstractNextCellSelectionStrategy.h"


AbstractGeneratingStrategy::AbstractGeneratingStrategy(Maze& maze, AbstractNextCellSelectionStrategy *nextCellSelectionStrategy)
    :maze(maze), nextCellSelectionStrategy(nextCellSelectionStrategy)
{

}

AbstractGeneratingStrategy::~AbstractGeneratingStrategy()
{
    delete nextCellSelectionStrategy;
}


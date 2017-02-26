#include <cstdlib>

#include "GrowingTree.h"
#include "Cell.h"
#include "AbstractNextCellSelectionStrategy.h"
#include "MostRecentSelectionStrategy.h"
#include "Maze.h"

using namespace std;

GrowingTree::GrowingTree(Maze& maze)
    :AbstractGeneratingStrategy(maze, new MostRecentSelectionStrategy())
{

}

void GrowingTree::generateMaze()
{
    vector<Cell::E_Direction> unvisitedNeightbourgs;

    int width;
    int height;

    Coord currentPos;
    Cell::E_Direction processingDirection;
    Cell* neightbourg;

    vector<Cell*>::iterator currentCellItr;

    maze.getDimensions(width, height);

    currentPos.x = rand() % width;
    currentPos.y = rand() % height;

    cells.push_back(maze.getCell(currentPos));

    currentCellItr = cells.begin();

    (*currentCellItr)->setVisited();

    while(!cells.empty())
    {
        unvisitedNeightbourgs.clear();

        if(maze.getUnvisitedNeightbourgsDirection(*(*currentCellItr), unvisitedNeightbourgs))
        {
            processingDirection = unvisitedNeightbourgs[rand() % unvisitedNeightbourgs.size()];
            (*currentCellItr)->open(processingDirection);

            neightbourg = maze.getNeightbourgWithDirection(*(*currentCellItr), processingDirection);
            neightbourg->setVisited();

            cells.push_back(neightbourg);
        }
        else
        {
            cells.erase(currentCellItr);
        }

        currentCellItr = nextCellSelectionStrategy->selectNextCellToProcess(cells);
    }
}

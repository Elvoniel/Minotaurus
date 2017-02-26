#include "Maze.h"
#include "Cell.h"
#include "GrowingTree.h"

using namespace std;

Maze::Maze(int width, int height)
    :width(width), height(height), cellTab(new Cell*[height])
{
    Coord pos;

    for(int i = 0; i < height; ++i)
    {
        cellTab[i] = new Cell[width];

        for(int e = 0; e < width; ++e)
        {
            pos.x = e;
            pos.y = i;

            cellTab[i][e].setPos(pos);
        }
    }
}

void Maze::getDimensions(int& width, int& height)
{
    width = this->width;
    height = this->height;
}

Cell* Maze::getCell(Coord pos) const
{
    return &cellTab[pos.x][pos.y];
}

bool Maze::getUnvisitedNeightbourgsDirection(const Cell& currentCell, vector<Cell::E_Direction> unvisitedNeightbourgs) const
{
    Coord coord = currentCell.getPos();

    if((coord.x - 1) >= 0 && (!cellTab[coord.y][coord.x - 1].isVisited()))
       unvisitedNeightbourgs.push_back(Cell::E_LEFT);

    if((coord.x + 1) < width && (!cellTab[coord.y][coord.x + 1].isVisited()))
       unvisitedNeightbourgs.push_back(Cell::E_RIGHT);

    if((coord.y - 1) >= 0 && (!cellTab[coord.y - 1][coord.x].isVisited()))
       unvisitedNeightbourgs.push_back(Cell::E_UP);

    if((coord.y + 1) < height && (!cellTab[coord.y + 1][coord.x].isVisited()))
       unvisitedNeightbourgs.push_back(Cell::E_DOWN);

    return (unvisitedNeightbourgs.size() != 0);
}

Cell* Maze::getNeightbourgWithDirection(const Cell& currentCell, Cell::E_Direction direction) const
{
    Cell* neightbourg;
    Coord coord = currentCell.getPos();

    switch (direction) {
    case Cell::E_DOWN:
        neightbourg = &cellTab[coord.y + 1][coord.x];
        break;
    case Cell::E_LEFT:
        neightbourg = &cellTab[coord.y][coord.x - 1];
        break;
    case Cell::E_RIGHT:
        neightbourg = &cellTab[coord.y][coord.x + 1];
        break;
    default:
        neightbourg = &cellTab[coord.y - 1][coord.x];
        break;
    }

    return neightbourg;
}

void Maze::setGeneratingStrategy(AbstractGeneratingStrategy::E_Strategy strategy)
{
    switch (strategy) {
    default:
        generatingStrategy = new GrowingTree(*this);
        break;
    }
}

Cell& Maze::getCell(int x, int y)
{
    return cellTab[x][y];
}

Maze::~Maze()
{
    for(int i = 0; i < height; ++i)
        delete[] cellTab[i];

    delete[] cellTab;

    delete generatingStrategy;
}


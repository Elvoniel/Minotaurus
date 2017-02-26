#ifndef GROWINGTREE_H
#define GROWINGTREE_H

#include "AbstractGeneratingStrategy.h"

class GrowingTree: public AbstractGeneratingStrategy
{
public:
    GrowingTree(Maze &maze);
    void generateMaze();
};

#endif // GROWINGTREE_H

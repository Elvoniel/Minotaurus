#ifndef MOSTRECENTSELECTIONSTRATEGY_H
#define MOSTRECENTSELECTIONSTRATEGY_H

#include "AbstractNextCellSelectionStrategy.h"


class MostRecentSelectionStrategy: public AbstractNextCellSelectionStrategy
{
public:
    MostRecentSelectionStrategy();

    std::vector<Cell*>::iterator selectNextCellToProcess(std::vector<Cell*>& cellsToProcess);
};

#endif // MOSTRECENTSELECTIONSTRATEGY_H

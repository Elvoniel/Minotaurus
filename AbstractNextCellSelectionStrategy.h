#ifndef NEXTCELLSELECTIONSTRATEGY
#define NEXTCELLSELECTIONSTRATEGY

#include <vector>

class Cell;

class AbstractNextCellSelectionStrategy
{
public:
    virtual ~AbstractNextCellSelectionStrategy(){}
    virtual std::vector<Cell*>::iterator selectNextCellToProcess(std::vector<Cell*>& cellsToProcess) = 0;
};

#endif // NEXTCELLSELECTIONSTRATEGY


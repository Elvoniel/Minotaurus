#include "MainWindow.h"
#include "Maze.h"
#include "GrowingTree.h"

#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    std::srand(std::time(0));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Maze theMaze(10, 10);
    theMaze.setGeneratingStrategy(AbstractGeneratingStrategy::E_GROWING_TREE);

    return a.exec();
}

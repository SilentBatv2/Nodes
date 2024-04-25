#include "Nodes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nodes w;
    w.showMaximized();
    return a.exec();
}

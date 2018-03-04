#include "box.h"
#include <DApplication>
#include "util/dwidgetutil.h"

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    Box w;
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}

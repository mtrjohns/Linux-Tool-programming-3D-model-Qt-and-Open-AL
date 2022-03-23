#include "OpenALWithQT.h"
#include <QApplication>
#include "OpenAL.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenALwithQT OpenALWindow;

    OpenALWindow.setWindowTitle("OpenAL Tool");












    OpenALWindow.show();

    return a.exec();
}

#include <QApplication>
#include<QLabel>
int main( int argc, char*argv[])
{
    QApplication app(argc, argv);
    QLabel* label = new QLabel("Hello world");
    label->setWindowTitle("MY Label");
    label->resize(640,480);
    label->show();
    return app.exec();
}

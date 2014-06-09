#include "firstwindow.h"
#include <QApplication>



int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    FirstWindow w;

    w.show();

    return a.exec();
}



/*
 *-сделать отметку о прохождении игры
 *  и отображать пройденные игры серым
 *
 *-написать функцию проверки и подсчета побед
 *
 *-реализовать использование объекта QSettings
 *
 *-реализовать общие настройки
 *
 *-реализовать настройки цветов и тем
 */

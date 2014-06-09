#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>

#include "tfield.h"
#include "tgamebase.h"
#include "infowindow.h"

namespace Ui {
class FirstWindow;
}



class FirstWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FirstWindow( QWidget *parent = 0 );
    ~FirstWindow();
    
private slots:
    void startGame( uint col, uint row ); // начало игры при выборе клетки
    void on_pbBegin_clicked(); // кнопка "Начать игру"
    void on_pbExit_clicked(); // кнопка "Выход"
    void on_tableGames_cellDoubleClicked( int row, int column); // двойной клик по таблице
    void on_pbRules_clicked(); // кнопка "Информация"

private:
    Ui::FirstWindow *ui;
    TField *field;
    InfoWindow *infoWindow;
    TGameBase gameBase;
};

#endif // FIRSTWINDOW_H

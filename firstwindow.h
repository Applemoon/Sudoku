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
    void startGame( uint col, uint row ); // ������ ���� ��� ������ ������
    void on_pbBegin_clicked(); // ������ "������ ����"
    void on_pbExit_clicked(); // ������ "�����"
    void on_tableGames_cellDoubleClicked( int row, int column); // ������� ���� �� �������
    void on_pbRules_clicked(); // ������ "����������"

private:
    Ui::FirstWindow *ui;
    TField *field;
    InfoWindow *infoWindow;
    TGameBase gameBase;
};

#endif // FIRSTWINDOW_H

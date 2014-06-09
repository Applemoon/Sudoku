#ifndef TFIELD_H
#define TFIELD_H

#include <QDialog>
#include <vector>
#include <QStringList>
#include <QMouseEvent>

#include "tcell.h"

namespace Ui {
class TField;
}



class TField : public QDialog
{
    Q_OBJECT
    
public:
    TField( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~TField();

    void setField( QStringList fieldVector, QString title );
    
private:
    Ui::TField *ui;
    uint cellSize; // размер клетки в пикселах
    uint gapSize; // расстояние от поля до панели чисел
    uint panelWidth; // ширина панели чисел
    uint panelCellHeight; // высота ячейки панели чисел
    QVector< QVector<TCell *> > cells; // массив клеток
    QPoint selectedCell;

    void drawField(); // отрисовка фона поля
    void drawCell( unsigned short col, unsigned short row );
    void mousePressEvent( QMouseEvent *event );
    void paintEvent( QPaintEvent * );
    bool checkWin() const;
};

#endif // TFIELD_H

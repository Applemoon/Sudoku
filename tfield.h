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
    uint cellSize; // ������ ������ � ��������
    uint gapSize; // ���������� �� ���� �� ������ �����
    uint panelWidth; // ������ ������ �����
    uint panelCellHeight; // ������ ������ ������ �����
    QVector< QVector<TCell *> > cells; // ������ ������
    QPoint selectedCell;

    void drawField(); // ��������� ���� ����
    void drawCell( unsigned short col, unsigned short row );
    void mousePressEvent( QMouseEvent *event );
    void paintEvent( QPaintEvent * );
    bool checkWin() const;
};

#endif // TFIELD_H

#include "tfield.h"
#include "ui_tfield.h"
#include <QPainter>
#include <QMessageBox>



TField :: TField( QWidget *parent, Qt::WindowFlags f ) :
    QDialog( parent, f ), ui( new Ui::TField )
{
    // заполнение клетками
    cells.resize( 9 );
    for ( uint i = 0; i < 9; ++i )
    {
        cells[i].resize( 9 );
        for ( uint j = 0; j < 9; ++j )
        {
            cells[i][j] = new TCell();
        }
    }

    // настройки GUI
    ui->setupUi( this );
    cellSize = 70;
    gapSize = 30;
    panelWidth = cellSize*9/10;
    panelCellHeight = panelWidth;
    resize( cellSize*9 + gapSize + panelWidth, cellSize*9 );
    setFixedSize( size() );
    selectedCell.setX( -1 );
    selectedCell.setY( -1 );
}



TField :: ~TField()
{
    cells.clear();
    delete ui;
}



void TField :: drawField()
{
    QPainter painter( this );
    painter.setPen( QPen( Qt::white ) );
    painter.setBrush( QBrush( Qt::white ) );
    painter.drawRect( 0, 0, width()-1, height()-1 );

    painter.setPen( QPen( Qt::black ) );
    painter.drawLine( 0, cellSize, cellSize*9, cellSize );
    painter.drawLine( 0, 2*cellSize, cellSize*9, 2*cellSize );
    painter.drawLine( 0, 4*cellSize, cellSize*9, 4*cellSize );
    painter.drawLine( 0, 5*cellSize, cellSize*9, 5*cellSize );
    painter.drawLine( 0, 7*cellSize, cellSize*9, 7*cellSize );
    painter.drawLine( 0, 8*cellSize, cellSize*9, 8*cellSize );
    painter.drawLine( cellSize, 0, cellSize, height() );
    painter.drawLine( 2*cellSize, 0, 2*cellSize, height() );
    painter.drawLine( 4*cellSize, 0, 4*cellSize, height() );
    painter.drawLine( 5*cellSize, 0, 5*cellSize, height() );
    painter.drawLine( 7*cellSize, 0, 7*cellSize, height() );
    painter.drawLine( 8*cellSize, 0, 8*cellSize, height() );

    painter.setPen( QPen( Qt::black, 3 ) );
    painter.drawLine( 0, 3*cellSize, cellSize*9, 3*cellSize );
    painter.drawLine( 0, 6*cellSize, cellSize*9, 6*cellSize );
    painter.drawLine( 3*cellSize, 0, 3*cellSize, height() );
    painter.drawLine( 6*cellSize, 0, 6*cellSize, height() );
    painter.drawLine( 9*cellSize, 0, 9*cellSize, height() );

    painter.setPen( QPen( Qt::black, 1 ) );
    painter.drawLine( 9*cellSize + gapSize, 0, 9*cellSize + gapSize, height() );
    for ( int i = 1; i < 10; ++i )
    {
        painter.drawLine( cellSize*9 + gapSize, i*panelCellHeight, width(), i*panelCellHeight );
    }

    const uint h = panelCellHeight*0.7;
    const uint x = cellSize*9 + gapSize + panelWidth/6;
    painter.setFont( QFont( "Times", h ) );
    for ( int i = 1; i < 10; ++i)
    {
        const uint y = (i-1)*panelCellHeight + panelCellHeight/5;
        painter.drawText( x, y, h, h, Qt::AlignCenter, QString::number( i ));
    }
}



void TField :: drawCell( const unsigned short col, const unsigned short row )
{
    QPainter painter( this );
    if ( cells[col][row]->getValue() != 0 ) // рисуем цифру
    {
        const unsigned short value = cells[col][row]->getValue();
        const uint x = col*cellSize + cellSize/6;
        const uint y = row*cellSize + cellSize/5;
        const uint h = cellSize*0.7;
        painter.setPen( cells[col][row]->changeable() ? Qt::darkGray : Qt::black );
        painter.setFont( QFont( "Times", h ) );
        painter.drawText( x, y, h, h, Qt::AlignCenter, QString::number( value ));
    }
    else // рисуем варианты
    {
        const uint h = cellSize*0.7/3;
        const uint w = h;
        painter.setFont( QFont( "Times", h ) );
        for ( int i = 1; i < 10; i++ )
        {
            const uint x = col*cellSize + ( (i-1)%3 )*( cellSize/3 ) + cellSize/18;
            const uint y = row*cellSize + ( (i-1)/3 )*( cellSize/3 ) + cellSize/10;
            painter.setPen( cells[col][row]->getVariant( i ) ? Qt::black : Qt::lightGray );
            painter.drawText( x, y, w, h, Qt::AlignCenter, QString::number( i ));
        }
    }

    // рисуем рамку
    if ( ( selectedCell.x() == col ) && ( selectedCell.y() == row ) )
    {
        const uint x = col*cellSize + 2;
        const uint y = row*cellSize + 2;
        const uint h = cellSize - 4;
        painter.setPen( QPen( Qt::gray, 3 ) );
        painter.drawRoundedRect( x, y, h, h, 2, 2 );
    }
}



void TField :: paintEvent( QPaintEvent * )
{
    drawField();
    for ( uint i = 0; i < 9; ++i )
    {
        for ( uint j = 0; j < 9; ++j )
        {
            drawCell( i, j );
        }
    }
}



void TField :: setField( QStringList fieldVector , const QString title )
{
    for ( int i = 0; i < cells.size(); ++i )
    {
        QString str = fieldVector.first();
        fieldVector.pop_front();
        for ( int j = 0; j < cells[i].size(); ++j )
        {
            unsigned short number = str.left( 1 ).toInt();
            str.remove( 0, 1 );
            cells[i][j]->setValue( number, true );
        }
    }
    setWindowTitle( title );
}



void TField :: mousePressEvent( QMouseEvent *event )
{
    const uint x = event->x();
    const uint y = event->y();

    if ( x < cellSize*9 ) // клик по полю
    {
        const unsigned short col = x/cellSize;
        const unsigned short row = y/cellSize;
        if ( ( ( selectedCell.x() != col ) || ( selectedCell.y() != row ) )
             && cells[col][row]->changeable() )
        {
            selectedCell.setX( col );
            selectedCell.setY( row );
        }
        else if ( cells[col][row]->changeable() )
        {
            int localX = x - cellSize*col - 4;
            if ( localX < 0 ) localX = 0;
            int localY = y - cellSize*row - 4;
            if ( localY < 0 ) localY = 0;
            const uint localSize = cellSize/3;
            const unsigned short variant = (int)(localX/localSize)
                    + 3*(int)(localY/localSize) + 1;
            cells[col][row]->changeVariant( variant );
        }
    }
    else if ( (uint)event->x() > cellSize*9 + gapSize ) // клик по панели
    {
        unsigned short number = y/panelCellHeight + 1;
        if ( number == 10 ) number = 0;
        if ( ( selectedCell.x() != -1 ) && ( selectedCell.y() != -1 ) &&
             cells[selectedCell.x()][selectedCell.y()]->changeable() )
        {
            cells[selectedCell.x()][selectedCell.y()]->setValue( number );
            if ( checkWin() )
            {
                QMessageBox msg;
                msg.setText( QString::fromLocal8Bit( "Победа!" ) );
                msg.exec();
                close();
            }
        }
    }

    update();
}



bool TField :: checkWin() const
{
    for ( uint i = 0; i < 9; i++ )
        for ( uint j = 0; j < 9; j++ ) // обходим каждую клетку
        {
            // проверка на пустоту
            if ( cells[i][j]->getValue() == 0 )
            {
                return false;
            }

            // проверка по линии
            for ( uint k = 0; k < 9; k++ )
            {
                if ( ( cells[i][j]->getValue() == cells[k][j]->getValue() )
                     && ( i != k ) )
                {
                    return false;
                }
            }

            // проверка по столбцу
            for ( uint k = 0; k < 9; k++ )
            {
                if ( ( cells[i][j]->getValue() == cells[i][k]->getValue() )
                     && ( j != k ) )
                {
                    return false;
                }
            }

            // проверка по блоку
            const unsigned short blockCol = i/3;
            const unsigned short blockRow = j/3;
            const unsigned short x1 = blockCol*3;
            const unsigned short x2 = x1 + 1;
            const unsigned short x3 = x2 + 1;
            const unsigned short y1 = blockRow*3;
            const unsigned short y2 = y1 + 1;
            const unsigned short y3 = y2 + 1;

            for ( unsigned short x = x1; x < x3+1; x++ )
            {
                for ( unsigned short y = y1; y < y3+1; y++ )
                {
                    if ( cells[i][j]->getValue() == cells[x][y]->getValue()
                         && ( ( i != x ) || ( j != y ) ) )
                    {
                        return false;
                    }
                }
            }
        }

    return true;
}

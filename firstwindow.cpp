#include "firstwindow.h"
#include "ui_firstwindow.h"
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QDir>
using namespace std;



FirstWindow :: FirstWindow( QWidget *parent ) :
    QMainWindow( parent ), ui( new Ui::FirstWindow )
{
    ui->setupUi( this );

    // инициализация таблицы
    QVector<uint> gamesCount = gameBase.getGamesCount();
    for ( uint i = 0; i < gamesCount.at( 0 ); ++i )
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(
                    QString( "Easy " )
                    + QString::number(i+1) );
        ui->tableGames->setItem( i, 0, newItem );
    }

    for ( uint i = 0; i < gamesCount.at( 1 ); ++i )
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(
                    QString( "Medium " )
                    + QString::number(i+1) );
        ui->tableGames->setItem( i, 1, newItem );
    }

    for ( uint i = 0; i < gamesCount.at( 2 ); ++i )
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(
                    QString( "Hard " )
                    + QString::number(i+1) );
        ui->tableGames->setItem( i, 2, newItem );
    }

    ui->tableGames->setCurrentCell( 0, 0 );
}



FirstWindow :: ~FirstWindow()
{
    delete ui;
}



// начало игры при выборе клетки
void FirstWindow :: startGame( const uint col, const uint row )
{
    QStringList gameList;
    bool gameFound = false;
    switch ( col )
    {
    case 0:
    {
        gameList = gameBase.getEasyGame( row, gameFound );
        if ( !gameFound ) goto def;
        break;
    }
    case 1:
    {
        gameList = gameBase.getMediumGame( row, gameFound );
        if ( !gameFound ) goto def;
        break;
    }
    case 2:
    {
        gameList = gameBase.getHardGame( row, gameFound );
        if ( !gameFound ) goto def;
        break;
    }
    default:
    {
        def:
        QMessageBox errorBox;
        errorBox.setText( QString( "Can't find chosen game." ) );
        errorBox.exec();
        return;
    }
    }


    field = new TField( this );
    QString fieldTitle = ui->tableGames->item( row, col )->text();
    field->setField( gameList, fieldTitle );
    field->exec();
    delete field;
}



// кнопка "Начать игру"
void FirstWindow::on_pbBegin_clicked()
{
    const uint col = ui->tableGames->currentColumn();
    const uint row = ui->tableGames->currentRow();
    startGame( col, row );
}



// кнопка "Выход"
void FirstWindow::on_pbExit_clicked()
{
    close();
}



// двойной клик по таблице
void FirstWindow::on_tableGames_cellDoubleClicked( const int row, const int column )
{
    startGame( column, row );
}



// кнопка "Информация"
void FirstWindow::on_pbRules_clicked()
{
    infoWindow = new InfoWindow( this );
    infoWindow->exec();
    delete infoWindow;
}

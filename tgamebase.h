#ifndef TGAMEBASE_H
#define TGAMEBASE_H

#include <QVector>
#include <QStringList>
#include <QSettings>



class TGameBase
{
public:
    TGameBase();

    QStringList getEasyGame( uint num, bool &gameFound ) const;
    QStringList getMediumGame( uint num, bool &gameFound ) const;
    QStringList getHardGame( uint num, bool &gameFound ) const;
    QVector<uint> getGamesCount() const;

private:
    QVector<QStringList> easyGames;
    QVector<QStringList> mediumGames;
    QVector<QStringList> hardGames;
};



#endif // TGAMEBASE_H

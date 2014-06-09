#ifndef TCELL_H
#define TCELL_H

#include <QWidget>
#include <QVector>



class TCell : public QWidget
{
    Q_OBJECT
public:
    explicit TCell( QWidget *parent = 0 );

    unsigned short getValue() const
        { return value; }
    void setValue( unsigned short v, bool fistTime = false );
    bool getVariant( unsigned short v ) const
        { return variants[v-1]; }
    void changeVariant( unsigned short v );
    bool changeable() const
        { return chngbl; }

private:
    unsigned short value; // число, стоящее в клетке
    bool chngbl; // если false - клетка стоит с начала игры,
                     // нельзя изменить ее цифру
    QVector<bool> variants;
};

#endif // TCELL_H

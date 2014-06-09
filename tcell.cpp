#include "tcell.h"



TCell :: TCell( QWidget *parent ) : QWidget( parent )
{
    variants.resize( 9 );
    variants.fill( false );
    chngbl = true;
}



void TCell :: setValue( const unsigned short v , const bool fistTime )
{
    value = v;
    if ( fistTime && ( v != 0 ) )
    {
        chngbl = false;
    }
}



void TCell :: changeVariant( const unsigned short v )
{
    if ( variants[v-1] == true )
    {
        variants[v-1] = false;
    }
    else
    {
        variants[v-1] = true;
    }
}

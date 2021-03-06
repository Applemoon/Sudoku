#include "tgamebase.h"



TGameBase :: TGameBase()
{
    QStringList game;

    // ������� ����
    game << "450860020"
         << "160027000"
         << "089035047"
         << "500290803"
         << "978510000"
         << "004000159"
         << "001306290"
         << "800701506"
         << "635082010";
    easyGames.push_back( game );

    game.clear();
    game << "070968040"
         << "001040839"
         << "804103607"
         << "065030418"
         << "980504006"
         << "407602090"
         << "530820060"
         << "026005183"
         << "048300900";
    easyGames.push_back( game );

    game.clear();
    game << "902340006"
         << "536000810"
         << "001680003"
         << "800017239"
         << "050208601"
         << "023069500"
         << "007026195"
         << "290054060"
         << "605703002";
    easyGames.push_back( game );

    game.clear();
    game << "940050803"
         << "601704020"
         << "580309160"
         << "368400700"
         << "009035481"
         << "010897032"
         << "150278006"
         << "150278006"
         << "073060048";
    easyGames.push_back( game );

    game.clear();
    game << "400168980"
         << "053000641"
         << "106080050"
         << "034706508"
         << "060450130"
         << "521800076"
         << "309628005"
         << "010503092"
         << "205001304";
    easyGames.push_back( game );

    game.clear();
    game << "615900080"
         << "000802569"
         << "008650304"
         << "059400600"
         << "407030851"
         << "380000097"
         << "900581230"
         << "526000070"
         << "001726905";
    easyGames.push_back( game );

    game.clear();
    game << "050472806"
         << "872050900"
         << "306801020"
         << "628007050"
         << "000526483"
         << "504018067"
         << "003769500"
         << "460280301"
         << "085000692";
    easyGames.push_back( game );

    game.clear();
    game << "030741205"
         << "674050300"
         << "205609040"
         << "729006050"
         << "000195672"
         << "106027083"
         << "002564800"
         << "560210409"
         << "081000526";
    easyGames.push_back( game );

    game.clear();
    game << "070359604"
         << "695020100"
         << "204607090"
         << "957003060"
         << "000246579"
         << "402075018"
         << "006728900"
         << "380490706"
         << "049000283";
    easyGames.push_back( game );

    game.clear();
    game << "208430006"
         << "739000420"
         << "006820001"
         << "600012794"
         << "070903205"
         << "025046100"
         << "002091647"
         << "460058010"
         << "301604002";
    easyGames.push_back( game );

//---------------------------------------

    // ������� ����
    game.clear();
    game << "090040005"
         << "600852700"
         << "251700000"
         << "002087104"
         << "070914000"
         << "400000397"
         << "020070840"
         << "709608001"
         << "500400076";
    mediumGames.push_back( game );

    game.clear();
    game << "040305900"
         << "802009060"
         << "150600700"
         << "000180429"
         << "003470850"
         << "018050000"
         << "090030210"
         << "006091008"
         << "200500097";
    mediumGames.push_back( game );

    game.clear();
    game << "123960000"
         << "040200500"
         << "700034201"
         << "050608307"
         << "000150400"
         << "062009015"
         << "014000003"
         << "009302050"
         << "507090002";
    mediumGames.push_back( game );

    game.clear();
    game << "206003800"
         << "030720100"
         << "000501423"
         << "002800010"
         << "650300700"
         << "300094050"
         << "103000547"
         << "020435000"
         << "500076030";
    mediumGames.push_back( game );

    game.clear();
    game << "100035060"
         << "234007050"
         << "007049003"
         << "649050001"
         << "000060295"
         << "000700600"
         << "076004002"
         << "820500910"
         << "000928706";
    mediumGames.push_back( game );

    game.clear();
    game << "020070006"
         << "400123900"
         << "375600000"
         << "001057203"
         << "040962000"
         << "200000694"
         << "080010360"
         << "506708002"
         << "900300058";
    mediumGames.push_back( game );

    game.clear();
    game << "040270010"
         << "052061700"
         << "601300005"
         << "090048000"
         << "000700134"
         << "400036050"
         << "084010060"
         << "200403007"
         << "730002081";
    mediumGames.push_back( game );

    game.clear();
    game << "004700100"
         << "000910870"
         << "010850002"
         << "076000540"
         << "201000680"
         << "003068010"
         << "005203700"
         << "000190026"
         << "420080001";
    mediumGames.push_back( game );

    game.clear();
    game << "100054090"
         << "475003080"
         << "002087005"
         << "569070001"
         << "000060954"
         << "000300200"
         << "098001003"
         << "210500760"
         << "000826109";
    mediumGames.push_back( game );

    game.clear();
    game << "700039000"
         << "108200009"
         << "094800050"
         << "800060920"
         << "040081360"
         << "009502100"
         << "080100003"
         << "002058091"
         << "013690080";
    mediumGames.push_back( game );

//---------------------------------------

    // ������� ����
    game.clear();
    game << "050704100"
         << "003008097"
         << "012090400"
         << "500801020"
         << "001207000"
         << "000000701"
         << "300070800"
         << "400300070"
         << "106080040";
    hardGames.push_back( game );

    game.clear();
    game << "700000080"
         << "000027530"
         << "600100070"
         << "900030850"
         << "007069000"
         << "002000907"
         << "004000683"
         << "200004000"
         << "090085002";
    hardGames.push_back( game );

    game.clear();
    game << "001027009"
         << "090000072"
         << "000900010"
         << "008009200"
         << "000000038"
         << "030280100"
         << "900060000"
         << "005000403"
         << "060540900";
    hardGames.push_back( game );

    game.clear();
    game << "130000000"
         << "050007300"
         << "002010060"
         << "007630000"
         << "005004073"
         << "300050000"
         << "040008700"
         << "500000002"
         << "703041000";
    hardGames.push_back( game );

    game.clear();
    game << "090002000"
         << "034780000"
         << "007004805"
         << "000940008"
         << "300000107"
         << "509078000"
         << "000830000"
         << "070000086"
         << "980400000";
    hardGames.push_back( game );

    game.clear();
    game << "006092010"
         << "580003060"
         << "009700080"
         << "100050008"
         << "800000305"
         << "004608001"
         << "025080000"
         << "090310000"
         << "000500830";
    hardGames.push_back( game );

    game.clear();
    game << "006070305"
         << "082010000"
         << "900300002"
         << "000003701"
         << "205060800"
         << "870000600"
         << "000430070"
         << "008700034"
         << "740000010";
    hardGames.push_back( game );

    game.clear();
    game << "050708000"
         << "298000000"
         << "000200045"
         << "006012000"
         << "000080102"
         << "302007080"
         << "000070214"
         << "041800060"
         << "720160000";
    hardGames.push_back( game );

    game.clear();
    game << "000805010"
         << "060100300"
         << "001000504"
         << "850002000"
         << "000000052"
         << "204000800"
         << "048000005"
         << "500091006"
         << "100503700";
    hardGames.push_back( game );

    game.clear();
    game << "041000003"
         << "000430009"
         << "700000410"
         << "100500300"
         << "004006090"
         << "050210007"
         << "000060200"
         << "600000038"
         << "000890700";
    hardGames.push_back( game );
}



QStringList TGameBase :: getEasyGame( const uint num, bool &gameFound ) const
{
    if ( num < (uint)easyGames.size() )
    {
        gameFound = true;
        return easyGames[num];
    }
    else
    {
        gameFound = false;
        return QStringList();
    }
}



QStringList TGameBase :: getMediumGame( const uint num, bool &gameFound ) const
{
    if ( num < (uint)mediumGames.size() )
    {
        gameFound = true;
        return mediumGames[num];
    }
    else
    {
        gameFound = false;
        return QStringList();
    }
}



QStringList TGameBase :: getHardGame( const uint num, bool &gameFound ) const
{
    if ( num < (uint)hardGames.size() )
    {
        gameFound = true;
        return hardGames[num];
    }
    else
    {
        gameFound = false;
        return QStringList();
    }
}



QVector<uint> TGameBase :: getGamesCount() const
{
    QVector<uint> gamesCount;
    gamesCount.push_back( easyGames.size() );
    gamesCount.push_back( mediumGames.size() );
    gamesCount.push_back( hardGames.size() );
    return gamesCount;
}

#include "Game.h"
#include <iostream>

int main()
{
    /*
    Gridsquare gsquare;
    std::cout << gsquare.print() << "\n";
    
    gsquare.setMarker(Marker::X);
    std::cout << gsquare.print() << "\n";

    gsquare.setMarker(Marker::O);
    std::cout << gsquare.print() << "\n";
    */  

    Game game;
    game.printGrid();
    game.startGame();

    return 0;
}

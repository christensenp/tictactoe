#include "Game.h"

void Game::startGame()
{
    for (int i = 0; i < 9; ++i)
    {
        if (i%2 == 0)
        {   
            std::cout << "Player 1, place your marker." << "\n";
            grid.placeMarker(Marker::X);
        }    
        else 
        {   
        std::cout << "Player 2, place your marker." << "\n"; 
        grid.placeMarker(Marker::O);
        }
        printGrid(); 

       if ( i > 3)
       {
           if(grid.checkWinner())
           {
               printf("Winner Winner Chicken Dinner. Player %d wins\n",
                       i%2 == 0 ? 1 : 2);
               break;
           }
       }

       if (i == 8 && !(grid.checkWinner()))
           printf("Who would have expected this.... It's a tie. \n");

    }
}

void Game::printGrid()
{
    grid.printGrid();
}

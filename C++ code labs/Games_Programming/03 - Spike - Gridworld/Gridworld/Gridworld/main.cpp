//
//  main.cpp
//  Gridworld
//
//  Created by Hayden Flynn Whiteford on 7/8/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <experimental/iterator>
#include <iterator>

//creating a 2D array by making a vector full of character vectors
std::vector<std::vector<char>> grid = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'G', ' ', 'D', '#', 'D', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', 'D', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', 'S', '#', '#', '#', '#', '#'}
    };
// Player's initial position
   int playerRow = 7; // Row index
   int playerCol = 2; // Column index
   
// Print the grid
void render()
{
    // Print the grid with player's position
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if ((i == playerRow && j == playerCol) && grid[i][j] != 'S') {
                std::cout << 'P'; // Display 'P' for player's position
            } else {
                std::cout << grid[i][j];
            }
        }
        std::cout << std::endl;
    }
}

std::vector<char> checkMoves()
{
    std::vector<char> moves;
    
    if (grid[playerRow - 1][playerCol] != '#')
    {
        moves.push_back('N');
    }
    if (playerRow != 7 && grid[playerRow + 1][playerCol] != '#')
    {
        moves.push_back('S');
    }
    if (grid[playerRow][playerCol + 1] != '#')
    {
        moves.push_back('E');
    }
    if (grid[playerRow][playerCol - 1] != '#')
    {
        moves.push_back('W');
    }
    
    std::cout <<"You Can Move ";
    //just a splitter I found online to format the vector output with commas
    std::copy(moves.begin(),
              moves.end(),
              std::experimental::make_ostream_joiner(std::cout, ", "));
    std::cout <<": \n";
    
    return moves;
}

bool update(char aMove, std::vector<char> aMoves)
{
    //affect player position by move variable
    if (std::find(aMoves.begin(), aMoves.end(), aMove) != aMoves.end() || aMove == 'Q')
    {
        if (aMove == 'N')
        {
            playerRow--;
        }
        else if (aMove == 'S')
        {
            playerRow++;
        }
        else if (aMove == 'E')
        {
            playerCol++;
        }
        else if (aMove == 'W')
        {
            playerCol--;
        }
        else if (aMove == 'Q')
        {
            return false;
        }
    }
    else
    {
        std::cout<< "Invalid Move! \n";
    }
    //check if player position then matches interactable variables
    //if so run appropriate output
    if (grid[playerRow][playerCol] == 'D')
    {
        std::cout<< "Arrrrgh... you’ve fallen down a pit. \nYOU HAVE DIED! \nThanks for playing. Maybe next time. \n";
        return false;
    }
    else if (grid[playerRow][playerCol] == 'G')
    {
        std::cout << "Wow - you’ve discovered a large chest filled with GOLD coins! \nYOU WIN! \nThanks for playing. There probably won’t be a next time. \n";
        return false;
    }
    return true;
}



int main(int argc, const char * argv[]) {
    
    std::cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You! \nValid commands: N, S, E and W for direction. Q to quit the game. \n";
    //main game loop
    while (true) {
        //render the game board
        render();
        
        //ask player what move to make (list available moves)
        std::vector<char> fMoves = checkMoves();
        
        //text input of player
        char fMove;
        std::cin >> fMove;
        
        //run update (update responds with interactable )
        if (!update(fMove, fMoves))
        {
            break;
        }
    }
        return 0;
}

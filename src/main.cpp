#include <iostream>
#include <string>

#include "game.h"

class Menu {
private:
    char choice;
    std::string name1;
    std::string name2;

public:
    void game(Play& play)
    {
        play.playLoop = true;
        play.main();
    }
    void edit_names(Play& play)
    {
        std::cout << "\n> " << play.player1Name << " = ";
        std::cin >> name1;

        std::cout << "> " << play.player2Name << " = ";
        std::cin >> name2;

        play.player1Name = name1;
        play.player2Name = name2;
    }
    void statistics(Play& play)
    {
        std::cout << "###################\n";
        std::cout << "### TIC-TAC-TOE ###\n";
        std::cout << "###################\n";

        std::cout << "\n>>> " << play.player1Name << " Wins: " << play.player1Win << "\n";
        std::cout << ">>> " << play.player2Name << " Wins: " << play.player2Win << "\n";
        std::cout << ">>> Draw: " << play.draw << "\n\n";

        std::cout << "###################\n";
        std::cout << "# [1] Reset       #\n";
        std::cout << "# [Any] Menu      #\n";
        std::cout << "###################\n";
        std::cout << "> Select: ";
        std::cin >> choice;

        if (choice == '1') {
            play.player1Win = 0;
            play.player2Win = 0;
            play.draw = 0;
            std::cout << "\033[2J\033[H";
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
};

int main()
{
    Menu menu;
    Play play;

    int gameLoop = true;
    char choice;

    while (gameLoop) {
        std::cout << "\033[2J\033[H";
        std::cout << "###################\n";
        std::cout << "### TIC-TAC-TOE ###\n";
        std::cout << "###################\n";
        std::cout << "# [1] Game        #\n";
        std::cout << "# [2] Edit Names  #\n";
        std::cout << "# [3] Statistics  #\n";
        std::cout << "# [4] Exit        #\n";
        std::cout << "###################\n";
        std::cout << "> Select: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "\033[2J\033[H";
            menu.game(play);
        } else if (choice == '2') {
            menu.edit_names(play);
        } else if (choice == '3') {
            std::cout << "\033[2J\033[H";
            menu.statistics(play);
        } else if (choice == '4') {
            gameLoop = false;
        } else {
            std::cout << "\033[2J\033[H";
        }
    }

    return 0;
}

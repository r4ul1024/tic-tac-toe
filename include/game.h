#ifndef GAME
#define GAME

#include <string>
#include <vector>

class Play {
private:
    std::vector<char> areaVector = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    char choice;
    int move;
    char result;
    char player1 = 'X';
    char player2 = '0';

public:
    bool playLoop = true;
    int player1Win = 0;
    int player2Win = 0;
    int draw = 0;
    std::string player1Name = "Player1";
    std::string player2Name = "Player2";

    char currentPlayer;
    std::string currentPlayerName;

    void area_display();
    void main();
    char check(char currentPlayer);
    void ask_replay();
};

#endif

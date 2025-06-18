#include "game.h"

#include <iostream>
#include <string>

void Play::area_display()
{
    std::cout << "###################\n";
    std::cout << "### TIC-TAC-TOE ###\n";
    std::cout << "###################\n";
    std::cout << "###             ###\n";

    for (int i = 0; i < areaVector.size(); i++) {
        if (i == 2 || i == 5 || i == 8) {
            std::cout << "|" << areaVector[i] << "|   ###\n";
        } else if (i == 0 || i == 3 || i == 6) {
            std::cout << "###   |" << areaVector[i];
        } else {
            std::cout << "|" << areaVector[i];
        }
    }
    std::cout << "###             ###\n";
    std::cout << "###################\n";
}

void Play::main()
{
    currentPlayer = player1;
    currentPlayerName = player1Name;

    while (playLoop) {
        Play::area_display();

        std::cout << "> " << currentPlayerName << "'s move: ";
        std::cin >> move;

        if (move > 0 && move < 10 && areaVector[move - 1] == '-') {
            areaVector[move - 1] = currentPlayer;

            result = Play::check(currentPlayer);

            if (result == 'w') {
                std::cout << "\033[2J\033[H";
                Play::area_display();
                std::cout << "\n>>> WINNER: " << currentPlayerName << "\n\n";
                if (currentPlayer == player1) {
                    player1Win++;
                } else {
                    player2Win++;
                }
                Play::ask_replay();
            } else if (result == 'd') {
                std::cout << "\033[2J\033[H";
                Play::area_display();
                std::cout << "\n>>> DRAW\n\n";
                draw++;
                if (currentPlayer == player1) {
                    currentPlayer = player2;
                    currentPlayerName = player2Name;
                } else {
                    currentPlayer = player1;
                    currentPlayerName = player1Name;
                }
                Play::ask_replay();
            } else {
                if (currentPlayer == player1) {
                    currentPlayer = player2;
                    currentPlayerName = player2Name;
                } else {
                    currentPlayer = player1;
                    currentPlayerName = player1Name;
                }
                std::cout << "\033[2J\033[H";
            }
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

char Play::check(char currentPlayer)
{
    if (areaVector[0] == currentPlayer && areaVector[1] == currentPlayer && areaVector[2] == currentPlayer || areaVector[3] == currentPlayer && areaVector[4] == currentPlayer && areaVector[5] == currentPlayer || areaVector[6] == currentPlayer && areaVector[7] == currentPlayer && areaVector[8] == currentPlayer || areaVector[0] == currentPlayer && areaVector[3] == currentPlayer && areaVector[6] == currentPlayer || areaVector[1] == currentPlayer && areaVector[4] == currentPlayer && areaVector[7] == currentPlayer || areaVector[2] == currentPlayer && areaVector[5] == currentPlayer && areaVector[8] == currentPlayer || areaVector[0] == currentPlayer && areaVector[4] == currentPlayer && areaVector[8] == currentPlayer || areaVector[2] == currentPlayer && areaVector[4] == currentPlayer && areaVector[6] == currentPlayer) {
        return 'w'; // WIN
    } else if (areaVector[0] != '-' && areaVector[1] != '-' && areaVector[2] != '-' && areaVector[3] != '-' && areaVector[4] != '-' && areaVector[5] != '-' && areaVector[6] != '-' && areaVector[7] != '-' && areaVector[8] != '-') {
        return 'd'; // DRAW
    } else {
        return 'n'; // NEXT
    }
}

void Play::ask_replay()
{
    std::cout << "###################\n";
    std::cout << "## [1] Replay    ##\n";
    std::cout << "## [Any] Menu    ##\n";
    std::cout << "###################\n";
    std::cout << "> Select: ";
    std::cin >> choice;

    if (choice == '1') {
        for (int i = 0; i < areaVector.size(); i++) {
            areaVector[i] = '-';
        }
        std::cout << "\033[2J\033[H";
    } else {
        for (int i = 0; i < areaVector.size(); i++) {
            areaVector[i] = '-';
        }
        playLoop = false;
    }
}

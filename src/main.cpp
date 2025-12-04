#include <iostream>
#include <string>
#include "Game.h"

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <fichier> <iterations>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Erreur arguments" << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    std::string inputFile = argv[1];
    int iterations = std::stoi(argv[2]);

    if (iterations <= 0) {
        std::cerr << "Erreur iterations" << std::endl;
        return 1;
    }

    try {
        Game game(iterations, 0, inputFile);
        game.loadGame();
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
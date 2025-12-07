#include <iostream>
#include <string>
#include "Game.h"
 
void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <fichier> <mode> <itérations>" << std::endl;
    std::cout << "  <fichier>     : Chemin vers le fichier" << std::endl;
    std::cout << "  <mode>        : 0 = console, 1 = graphique" << std::endl;
    std::cout << "  <itérations>  : Nombre max" << std::endl;
}
 
int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Erreur arguments" << std::endl;
        printUsage(argv[0]);
        return 1;
    }
 
    std::string inputFile = argv[1]; // "grid_glider.txt"
    int mode = std::stoi(argv[2]); // Mode 
    int iterations = std::stoi(argv[3]); // Itération(s)
 
    if (mode != 0 && mode != 1) {
        std::cerr << "Mode doit être 0 (Console) ou 1 (Graphique)" << std::endl;
        return 1;
    }
 
    if (iterations <= 0) {
        std::cerr << "Itération(s) doit être au moins 1" << std::endl;
        return 1;
    }
 
    try {
        Game game(iterations, mode, inputFile); 
        game.loadGame();
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return 1;
    }
 
    return 0;
}

// ./build/game_of_life grid_glider.txt 1 4
#include <iostream>
#include <string>
#include "Game.h"

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName 
              << " <fichier> <mode> <iterations> <vitesse_ms>" << std::endl;
    std::cout << "  <fichier>     : Chemin vers le fichier d'entrée" << std::endl;
    std::cout << "  <mode>        : 0 = console, 1 = graphique" << std::endl;
    std::cout << "  <iterations>  : Nombre maximum d'itérations" << std::endl;
    std::cout << "  <vitesse_ms>  : Temps entre chaque iteration (en millisecondes)" << std::endl;
}

int main(int argc, char* argv[]) {

    // On attend 4 arguments
    if (argc != 5) {
        std::cerr << "Erreur : nombre d'arguments incorrect." << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    std::string inputFile = argv[1];

    int mode = std::stoi(argv[2]);
    if (mode != 0 && mode != 1) {
        std::cerr << "Erreur : le mode doit être 0 (console) ou 1 (graphique)." << std::endl;
        return 1;
    }

    int iterations = std::stoi(argv[3]);
    if (iterations <= 0) {
        std::cerr << "Erreur : les iterations doivent être > 0." << std::endl;
        return 1;
    }

    int vitesseMS = std::stoi(argv[4]);
    if (vitesseMS < 0) {
        std::cerr << "Erreur : la vitesse doit être >= 0 ms." << std::endl;
        return 1;
    }

    try {
        // On passe maintenant la vitesse en plus
        Game game(iterations, mode, inputFile, vitesseMS);
        game.loadGame();
        game.run();
    } 
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

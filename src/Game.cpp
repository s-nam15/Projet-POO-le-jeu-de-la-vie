#include "Game.h"
#include "ConwayRule.h"
#include "ConsoleView.h"
#include <iostream>
#include <filesystem>
#include "GUIView.h"

namespace fs = std::filesystem;
 
//Initialisation des variables membres
Game::Game(int iter, int mode, const std::string& input, int speed)
    : grid(nullptr), previousGrid(nullptr), rule(nullptr),
      iterations(iter), currentIteration(0),
      mode(mode), inputFile(input), speedMS(speed)
{
    rule = new ConwayRule();
}

// Nettoyage des objets 
Game::~Game() {
    delete grid;
    delete rule;
    delete previousGrid;
}

//chargement de l'état initial du jeu à partir du fichier spécifique 
void Game::loadGame() {
    grid = new Grid();
    grid->loadFile(inputFile);
    std::cout << "Grille chargee: " << grid->getRows() << "x" << grid->getCols() << std::endl;
}

//Execution en mode console 
void Game::runConsole() {
    ConsoleView view;
    view.setGame(this);
    
    std::string baseName = inputFile.substr(inputFile.find_last_of("/\\") + 1);
    size_t dotPos = baseName.find_last_of('.');
    if (dotPos != std::string::npos) {
        baseName = baseName.substr(0, dotPos);
    }
    
    std::string outputDir = baseName + "_out";
    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }
    
    std::cout << "Mode console - Simulation de " << iterations << " iterations" << std::endl;
    
    std::string filename = outputDir + "/iteration_0.txt";
    grid->saveToFile(filename);
    view.printToConsole();
    
    while (!isFinished()) {
        currentIteration++;
        
        if (previousGrid) delete previousGrid;
        previousGrid = grid->clone();
        
        grid->applyRules(rule);
        grid->update();
        
        std::string filename = outputDir + "/iteration_" + std::to_string(currentIteration) + ".txt";
        grid->saveToFile(filename);
        view.printToConsole();
        
        if (previousGrid && grid->isEqual(*previousGrid)) {
            std::cout << "Grille stabilisee a l'iteration " << currentIteration << std::endl;
            break;
        }
    }
    
    std::cout << "Simulation terminee apres " << currentIteration << " iterations" << std::endl;
    std::cout << "Resultats sauvegardes dans: " << outputDir << std::endl;
}

//Execution en mode graphique
void Game::runGraphic() {
    GUIView view;
    view.setGame(this);
    std::cout << "Mode graphique - Appuyez sur Echap pour quitter" << std::endl;
    view.render();
}

void Game::run() {
    if (mode == 0) {
        runConsole();
    } else {
        runGraphic();
    }
}

bool Game::isFinished() const {
    return currentIteration >= iterations;
}

Grid* Game::getGrid() const {
    return grid;
}

int Game::getCurrentIteration() const {
    return currentIteration;
}

Rule* Game::getRule() const {
    return rule;
}

void Game::incrementIteration() {
    currentIteration++;
}
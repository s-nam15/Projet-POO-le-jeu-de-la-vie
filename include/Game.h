#ifndef GAME_H
#define GAME_H

#include <string>
#include "Grid.h"
#include "Rule.h"

class Game {
private:
    Grid* grid;
    Grid* previousGrid;
    Rule* rule;

    int iterations;
    int currentIteration;
    int mode;
    std::string inputFile;

    int speedMS;  // <-- AJOUT

public:
    // Nouveau constructeur avec vitesse
    Game(int iter, int mode, const std::string& input, int speedMS);

    ~Game();

    void loadGame();
    void run();
    void runConsole();
    void runGraphic();

    bool isFinished() const;
    Grid* getGrid() const;
    int getCurrentIteration() const;
    Rule* getRule() const;

    int getSpeed() const { return speedMS; }  // <-- AJOUT
    void setSpeed(int speed);

    void incrementIteration();
};

#endif

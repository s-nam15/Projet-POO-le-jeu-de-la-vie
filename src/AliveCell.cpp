#include "AliveCell.h"

AliveCell::AliveCell() : Cell(true) {}

Cell* AliveCell::clone() const {
    return new AliveCell(*this); // *this = soi-même
}
#ifndef DEADCELL_H
#define DEADCELL_H

#include "Cell.h"

class DeadCell : public Cell {
public:
    DeadCell();
    ~DeadCell() override = default;

    // Deep copy (Créer-en une nouvelle en dupliquant AliveCell pour éviter la grille originale change lorsque on calcule la prochaine génération)
    Cell* clone() const override;
};

#endif // DEADCELL_H

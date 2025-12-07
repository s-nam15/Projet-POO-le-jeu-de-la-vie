
#ifndef ALIVECELL_H
#define ALIVECELL_H

#include "Cell.h"

class AliveCell : public Cell {
public:
    AliveCell();
    ~AliveCell() override = default;

    // Deep copy (Créer-en une nouvelle en dupliquant AliveCell pour éviter la grille originale change lorsque on calcule la prochaine génération)
    Cell* clone() const override;
};

#endif // ALIVECELL_H
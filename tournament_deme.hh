#include "deme.hh"

class TournamentDeme: private Deme {
    public:
        // Perform tournament selection to select a parent.
        Chromosome* select_parent() override;
};
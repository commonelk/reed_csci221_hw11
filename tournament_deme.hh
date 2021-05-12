#include "deme.hh"

class TournamentDeme: public Deme {
    public:
        // TournamentDeme constructor calls Deme constructor
        TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate);

        // Perform tournament selection to select a parent.
        Chromosome* select_parent() override;
};
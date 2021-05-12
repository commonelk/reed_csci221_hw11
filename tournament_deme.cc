#include "tournament_deme.hh"
#include <algorithm>

// Auxillary function that returns the greatest integral power of two less than or equal to positive n.
int floor_power_2(int n) {
    if(n <= 0) { return 0; } // If n is not positive, return 0.
    int prev_power = 1, latter_power = 2;
    while(latter_power <= n) {
        prev_power *= 2;
        latter_power *= 2;
    }
    return prev_power;
}

// Perform tournament selection to select a parent.
Chromosome* TournamentDeme::select_parent() {
    std::random_shuffle(pop_.begin(), pop_.end(), generator_); // First, shuffle pop_
    std::vector<Chromosome*> tournament_pool;
    int P = floor_power_2(pop_.size()); // Determine P value
    std::copy(pop_.begin(), pop_.begin() + P, std::back_inserter(tournament_pool)); // Randomly choose P Chromosome*'s from pop_

    while(true) {
        if(tournament_pool.size() == 1) { break; } // Stop looping once a winning Chromosome* has been selected.

        int index = 0;
        int final_pool_size = tournament_pool.size() / 2;
        while(tournament_pool.size() != final_pool_size) { // Loop until all pairs of Chromosome*'s have "fought"
            auto competitor1 = tournament_pool[index];
            auto competitor2 = tournament_pool[index+1];
            if(competitor1 -> get_fitness() > competitor2 -> get_fitness()) { tournament_pool.erase(tournament_pool.begin() + index+1); }
            else { tournament_pool.erase(tournament_pool.begin() + index); }
            index++; // Increment index so that next pair can be chosen.
        }
    }
    return tournament_pool[0]; // Return winning Chromosome*
}
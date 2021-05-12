## **Homework 11: Travelling Salesperson Project, Part 3**
### By Quinn Hargrove & Evan Sieden

<hr />

#### **Compiling & Usage Instructions:**
+ To compile, execute `make` command in the base directory.
    + Adjust `NUM_ITER` in `tsp.cc` as desired (set to 100,000 by default).
+ To use, execute `./tsp <filename> <population size> <mutation rate>` command.
+ A population size of 100 and a mutation rate of .3 were used in the creation of `comparison.gif`.

#### **Design Decisions:**
1. <u>ClimbChromosome class.</u>
    + type here.
2. <u>TournamentDeme class.</u>
    + In the overridden `select_parent()` in `TournamentDeme`, `std::shuffle()` was used to randomly select `P` members of `pop_`. Essentially, after shuffling `pop_`, choosing the first `P` elements gives us `P` randomly selected `Chromosome*`s. This method is slightly inefficient, but it is not too bad considering `P` is typically not much lower than `pop_.size()`.
    + To calculate `P` in `select_parent()`, we created an auxillary function called `floor_power_2` which returns the greatest integral power of two that is less than or equal to the given integer. 
    + One minor detail in the tournament selection algorithm itself: to ensure that each pair of `Chromosome*`s chosen to "fight" in a given tournament are unique, the `index` was incremented by 1. Essentially, after two `Chromosome*`s "fight", one of the two `Chromosome*`s is discarded, so there are 1 fewer `Chromosome*`s in the `tournament_pool`. Hence, we increment the `index` by 1 instead of 2.
    + Remaining details can be found within documentation in `tournament_deme.cc`.

#### **Attributions:**
+ Base HW10 files provided by Eitan via Slack.
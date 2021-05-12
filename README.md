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
    + ClimbChromosome.cc could definitely be cleaner, as the repeated swaps cause a lot of repetition in the code, but what matters most is that it works. Other than that, the instructions made it mostly straightforward to write.
2. <u>TournamentDeme class.</u>
    + type here.

#### **Attributions:**
+ Base HW10 files provided by Eitan via Slack.

#include "climb_chromosome.hh"


void
ClimbChromosome::mutate(){
  auto p = dist(generator_); //Untested. This *might* give a random number.
  if (p == 0) {
    std::swap(order_[p], order_[order_.size() - 1]); //swap p and N-1 (where N = total cities)
  } else {
    std::swap(order_[p], order_[p - 1]);
  }
} //UNFINISHED

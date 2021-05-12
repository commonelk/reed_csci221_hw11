#include "climb_chromosome.hh"

ClimbChromosome::ClimbChromosome()
  : ChromosomeChromosome(const Cities* cities_ptr)
  {

  } //I don't have the constructor finished. I'll take another look after my test.


void
ClimbChromosome::mutate(){

  std::uniform_int_distribution<int> dist(0, order_.size() - 1);

  double a =  Chromosome::get_fitness(); //Fitness from original

  auto p = dist(generator_);

  if (p == 0) { //FIRST SWAP
    std::swap(order_[p], order_[order_.size() - 1]); //swap p and N-1 (where N = total cities)
  } else {
    std::swap(order_[p], order_[p - 1]);
  }

  double b =  Chromosome::get_fitness(); //Fitness from first swap

  if (p == 0) { //Swap back to original ordering
    std::swap(order_[p], order_[order_.size() - 1]);
  } else {
    std::swap(order_[p], order_[p - 1]);
  }

  if (p == order_.size() - 1) { //SECOND SWAP
    std::swap(order_[p], order_[0]); //swap p and 0
  } else {
    std::swap(order_[p], order_[p + 1]);
  }

  double c =  Chromosome::get_fitness(); //Fitness from second swap

  if (c < b || c < a) { //If c is worse than a or b...
    if (p == order_.size() - 1) { //...swap back to first
      std::swap(order_[p], order_[0]);
    } else {
      std::swap(order_[p], order_[p + 1]);
    }

    if (a < b) { //If the original order isn't as good as the first swap was...
      if (p == 0) { //...redo first swap
        std::swap(order_[p], order_[order_.size() - 1]);
      } else {
        std::swap(order_[p], order_[p - 1]);
      }
    }
  }
  return; //Return, with the object's order now in the best configuration of the three.
}

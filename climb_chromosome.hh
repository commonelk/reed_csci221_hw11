#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
public:

  virtual void mutate();

  virtual Chromosome* clone() const
  {
    return new ClimbChromosome(*this); //original: return new Chromosome(*this);
  }
}

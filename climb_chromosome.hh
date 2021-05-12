#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
    public:

        ClimbChromosome(const Cities* c);

        virtual Chromosome* clone() const {
            return new ClimbChromosome(*this); //original: return new Chromosome(*this);
        }

        virtual void mutate() override;
};

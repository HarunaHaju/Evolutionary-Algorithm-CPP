#ifndef POPULATION_H
#define POPULATION_H

#include "DNA.h"

class Population
{
public:
	Population();
	Population(int index);
	~Population();

	DNA& getDNA();
	int getIndex();

	void crossover(Population& parent1, Population& parent2);
	void mutate();

private:
	DNA dna;
	int index;
};

#endif
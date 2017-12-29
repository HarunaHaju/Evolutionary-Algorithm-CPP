#ifndef POPULATION_H
#define POPULATION_H

#include "DNA.h"

class Population
{
public:
	Population();
	Population(int index);
	Population(Population &pop);
	~Population();

	DNA& getDNA();
	int getIndex();
	int getGen();
	void setGen(int gen);
	void setIndex(int index);

	void crossover(Population& parent1, Population& parent2);
	void crossover(Population& parent1);
	void mutate();

	char operator[] (int i);
	Population& operator=(Population& pop);
private:
	DNA dna;
	int index;
	int gen;
};

#endif
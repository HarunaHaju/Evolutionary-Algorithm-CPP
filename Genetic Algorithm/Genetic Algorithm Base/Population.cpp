#include "Population.h"

Population::Population()
{
	index = -1;
	cout << dna;
}

Population::Population(int index)
{
	this->index = index;
}

Population::~Population(){}

int Population::getIndex()
{
	return index;
}

DNA& Population::getDNA()
{
	return dna;
}

void Population::crossover(Population& parent1, Population& parent2)
{

}

void Population::mutate()
{
	dna.mutateDNA();
}
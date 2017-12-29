#include <iostream>

#include "GA.h"
#include "DNA.h"
#include "Setting.h"

double getFitness(double x)
{
	return F(x);
}

double getFitness(DNA &dna)
{
	return F(dna.translateDNA());
}

int select(Population * pops)
{
	int result = 0;
	double bestFit = getFitness(pops[0].getDNA());
	for (int i = 0; i < POP_SIZE; i++)
	{
		if (getFitness(pops[i].getDNA()) >= bestFit)
		{
			bestFit = getFitness(pops[i].getDNA());
			result = i;
		}
	}
	return result;
}

using namespace std;
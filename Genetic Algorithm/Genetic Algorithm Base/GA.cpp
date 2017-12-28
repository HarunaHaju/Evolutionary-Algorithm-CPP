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

using namespace std;
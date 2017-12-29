#ifndef GA_H
#define GA_H

#include "Population.h"
#include <vector>

using namespace std;

double getFitness(DNA &dna);

double getFitness(double x);

int select(Population *pops);

#endif
#include "DNA.h"
#include "Setting.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

DNA::DNA()
{
	dnaChain = new char[DNA_SIZE];
	srand((unsigned)time(0));
	for (int i = 0; i < DNA_SIZE; i++)
	{
		dnaChain[i] = rand() % 2;//0 or 1
	}
}

DNA::~DNA()
{
	delete[] dnaChain;
}

double DNA::translateDNA()
{
	double result = 0;
	for (int i = 0; i < DNA_SIZE; i++)
	{
		result += dnaChain[i] * pow(2, DNA_SIZE - 1 - i);
	}
	result = result / pow(2, DNA_SIZE - 1) * (X_MAX - X_MIN) + X_MIN;
	return result;
}

void DNA::mutateDNA()
{
	for (int i = 0; i < DNA_SIZE; i++)
	{
		if (rand() / double(RAND_MAX) < MUTATION_RATE)
		{
			dnaChain[i] = 1 - dnaChain[i];
		}
	}
}

char DNA::operator[](int index)
{
	return dnaChain[index];
}

ostream& operator<<(ostream &out, DNA& dna)
{
	out << "[";
	for (int i = 0; i < DNA_SIZE; i++)
	{
		out << (int)dna[i];
		if (i != DNA_SIZE - 1)
			out << " ";
	}
	out << "]";
	return out;
}
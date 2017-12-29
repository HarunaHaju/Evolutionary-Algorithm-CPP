#include "Population.h"
#include "Setting.h"
#include <vector>

Population::Population()
{
	index = -1;
	gen = 1;
}

Population::Population(int index)
{
	this->index = index;
	gen = 1;
}

Population::Population(Population &pop)
{
	this->index = pop.getIndex();
	gen = pop.getGen();
	dna = pop.dna;
}

Population::~Population(){}

int Population::getIndex()
{
	return index;
}

int Population::getGen()
{
	return gen;
}

DNA& Population::getDNA()
{
	return dna;
}

void Population::setGen(int gen)
{
	this->gen = gen;
}

void Population::setIndex(int index)
{
	this->index = index;
}

void Population::crossover(Population& parent1, Population& parent2)
{
	if (rand() / double(RAND_MAX) < CROSS_RATE)
	{
		int crossCount = 0;
		vector<int> indexs;
		for (int i = 0; i < DNA_SIZE; i++)
		{
			indexs.push_back(i);
		}
		while (crossCount != DNA_SIZE / 2)
		{
			int index = rand() % (indexs.size());
			dna.setDNA(index, parent1[indexs[index]]);
			vector<int>::iterator it = indexs.begin();
			for (; it != indexs.end(); it++)
			{
				if (*it == index)
					it = indexs.erase(it);
			}
			crossCount++;
		}
		for (int i = 0; i < indexs.size(); i++)
		{
			dna.setDNA(indexs[i], parent2[indexs[i]]);
		}
	}
}

void Population::crossover(Population& parent1)
{
	if (rand() / double(RAND_MAX) < CROSS_RATE)
	{
		int crossCount = 0;
		vector<int> indexs;
		for (int i = 0; i < DNA_SIZE; i++)
		{
			indexs.push_back(i);
		}
		while (crossCount != DNA_SIZE / 2)
		{
			int index = rand() % (indexs.size() - 1);
			dna.setDNA(indexs[index], parent1[indexs[index]]);
			vector<int>::iterator it = indexs.begin();
			for (; it != indexs.end(); it++)
			{
				if (*it == index)
					it = indexs.erase(it);
			}
			crossCount++;
		}
	}
}

void Population::mutate()
{
	dna.mutateDNA();
}

char Population::operator[](int i)
{
	return dna[i];
}

Population& Population::operator=(Population& pop)
{
	if (this != &pop)
	{
		this->index = pop.getIndex();
		gen = pop.getGen();
		dna = pop.dna;
	}
	return *this;
}
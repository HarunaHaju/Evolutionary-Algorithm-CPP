#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Population.h"
#include "Setting.h"
#include "GA.h"
#include <vector>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	//init
	Population pops[POP_SIZE];
	for (int i = 0; i < POP_SIZE; i++)
	{
		pops[i].setGen(1);
		pops[i].setIndex(i);
	}

	//train and evaluate
	for (int i = 0; i < ITERATION_TIME; i++)
	{
		cout << "gen " << i + 1 << endl;
		int bestIndex = select(pops);
		cout << "best index:" << bestIndex << endl;
		cout << "best fit:" << getFitness(pops[bestIndex].getDNA()) << endl;
		cout << "best dna:" << pops[bestIndex].getDNA() << endl;

		//evolution crossover
		for (int i = 0; i < POP_SIZE; i++)
		{
			pops[i].crossover(pops[bestIndex]);
		}

		//mutate and update gen
		for (int i = 0; i < POP_SIZE; i++)
		{
			pops[i].mutate();
			pops[i].setGen(pops[i].getGen() + 1);
		}
	}
	return 0;
}
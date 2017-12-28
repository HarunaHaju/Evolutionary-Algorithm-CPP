#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DNA.h"

using namespace std;

int main()
{
	DNA dna;
	for (int i = 0; i < 200; i++)
	{
		dna.mutateDNA();
		//cout << dna << endl;
	}
	return 0;
}
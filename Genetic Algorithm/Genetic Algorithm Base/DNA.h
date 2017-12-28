#ifndef DNA_H
#define DNA_H

#include <iostream>
using namespace std;

class DNA
{
public:
	DNA();
	~DNA();

	double translateDNA();
	void mutateDNA();

	friend ostream& operator<<(ostream &out, DNA& dna);
	char operator[](int index);
private:
	char* dnaChain;
};

#endif
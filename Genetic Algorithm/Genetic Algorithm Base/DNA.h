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
	void setDNA(int index, char ch);

	friend ostream& operator<<(ostream &out, DNA& dna);
	char operator[](int index);
	DNA& operator=(DNA& dna);
private:
	char* dnaChain;
};

#endif
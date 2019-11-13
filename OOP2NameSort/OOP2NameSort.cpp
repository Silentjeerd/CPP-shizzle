#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getNames()
{
	return{
		"g",
		"f",
		"e",
		"a",
		"aap",
		"aab",
		"g",
		"f",
		"e",
		"a",
		"b",
		"x",
		"wat"
	};
}


int main()
{

	vector<string> alfabet = getNames();

	vector<string> opvolgorde(1);

	opvolgorde[0] = alfabet[0];
	alfabet.erase(alfabet.begin());

	for (unsigned i = 0; i < alfabet.size(); i++) {

		for (unsigned j = 0; j < opvolgorde.size(); j++) {
			if (alfabet[i] <= opvolgorde[j]) {
				opvolgorde.insert((opvolgorde.begin() + j), alfabet[i]);
				j = opvolgorde.size() + 3;
			}

			else

				if (alfabet[i] > opvolgorde[j] && opvolgorde.size() == j + 1) {
					opvolgorde.insert(opvolgorde.end(), alfabet[i]);
					j = opvolgorde.size() + 3;
				}
		}
	}

	for (unsigned x = 0; x < opvolgorde.size(); x++) {
		cout << opvolgorde[x] << endl;
	}

}
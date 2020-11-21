#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{
	Pair p1("Apple", "Alma");
	Pair p2("Mythical", "Efsanevi");
	Pair p3("Scar", "Yara izi");
	Pair p4("Philantrophic", "Xeyir-Sever");
	Pair p5("Raving", "Cilgin");
	Pair p6("Sacrosant", "Muqeddes");
	
	Pair* words = new Pair[6]{ p1, p2, p3, p4, p5, p6 };
	
	Dictionary<string, string> english_to_azerbaijani(words, 6);
	
	cout << "All Dictionary\n\n";
	cout << english_to_azerbaijani << endl;
	
	cout << "=============\n\n";
	cout << english_to_azerbaijani["Philantrophic"];
	
	english_to_azerbaijani["Philantrophic"] = "Insanlara komek eden";
	
	cout << "============After Change==========\n\n";
	
	cout << english_to_azerbaijani["Philantrophic"];
	cout << "=============\n\n\n\n";
	
	cout << "All Dictionary\n\n";
	
	cout << english_to_azerbaijani << "\n\n\n";


	//This add Words which not in the Dictionary
	Dictionary<string, string> new_dict;
	new_dict["Obvious"] = "Aciq-aydin";
	new_dict["Renowned"] = "Meshur";
	new_dict["Culprit"] = "Gunahkar";
	
	cout << "\n\n==========\n\n\n\n\n";
	cout << new_dict << endl;



	system("pause");
	return 0;
}
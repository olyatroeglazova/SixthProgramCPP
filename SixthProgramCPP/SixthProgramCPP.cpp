#include "stdafx.h"
#include <vector>
#include <iostream>
#include "DictionaryTree.h"

using namespace std;

int main()
{
	DictionaryTree* tree = new DictionaryTree("take");
	tree->add("add");
	tree->add("z");
	tree->add("math");
	tree->add("olga");
	tree->add("program");
	tree->add("void");
	tree->add("program");
	tree->add("university");

	cout << "Tree: \n" << endl;
	tree->write();
	cout << endl;

	cout << "Count of words in Dictionary = " << tree->countOfWords() << endl;
	cout << endl;

	tree->remove("university");
	tree->remove("take");

	cout << "Tree after remove two words: \n" << endl;
	tree->write();
	cout<<endl;

	cout << "Find word 'take'. Amount = " << tree->searchOfWord("take") << endl;
	cout << endl;
	cout << "Find word 'imit'. Amount = " << tree->searchOfWord("imit") << endl;
	cout << endl;

	tree->remove("take");

	cout << "After remove 'take'. Find word 'take'. Amount = " << tree->searchOfWord("take") << endl;
	cout << endl;

	cout << "Count of words in Dictionary = " << tree->countOfWords() << endl;
	cout << endl;

	system("pause");
	return 0;
}


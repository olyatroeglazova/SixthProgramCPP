#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class DictionaryTree
{
private:
	struct TreeElem
	{
		string info;
		TreeElem* left;
		TreeElem* right;
		int count;
		TreeElem() :left(nullptr), right(nullptr), count(0) {}
		TreeElem(string word)
		{
			info = word;
			count = 1;
			left = nullptr;
			right = nullptr;
		}
	};

	TreeElem* root;

	int searchOfWord(TreeElem *root, string word)
	{
		if (!root) {
			return 0;
		}
		if (root->info == word) {
			return root->count;
		}
		if (root->info < word) {
			return searchOfWord(root->left, word);
		}
		else {
			return searchOfWord(root->right, word);
		}
	}

	void add(TreeElem*root, string word)
	{
		if (root->info.compare(word)==0) {
			root->count++;
			return;
		}
		if (root->info.compare(word)<0) {
			if (root->right == nullptr) {
				root->right = new TreeElem(word);
				return;
			}
			add(root->right, word);
		}
		else {
			if (root->left == nullptr) {
				root->left = new TreeElem(word);
				return;
			}
			add(root->left, word);
		}
	}

	void remove(TreeElem* root, string word)
	{
		if (root->info == word) {
			root->count--;
			return;
		}
		if (root->info > word) {
			if (root->left->info == word) {
				if (root->left->count == 1) {
					if (root->left->left != nullptr) {
						root->left = root->left->left;
						return;
					}
					if (root->left->right != nullptr) {
						root->left = root->left->right;
						return;
					}
					root->left = nullptr;
					return;

				}
				else {
					root->left->count--;
					return;
				}
			}
			remove(root->left, word);
		}
		else {
			if (root->right->info == word) {
				if (root->right->count == 1) {
					if (root->right->left != nullptr) {
						root->right = root->right->left;
						return;
					}
					if (root->right->right != nullptr) {
						root->right = root->right->right;
						return;
					}
					root->right = nullptr;
					return;
				}
				else {
					root->right->count--;
					return;
				}
			}
			remove(root->right, word);
		}
	}

	int countOfWords(TreeElem* root)
	{
		if (!root) { return 0; }
		return root->count + countOfWords(root->left) + countOfWords(root->right);
	}

	void write(TreeElem* root)
	{
		if (!root) { return; }
		write(root->left);
		cout << root->info;
		cout << "(" << root->count << ")";
		cout << endl;
		write(root->right);
	}

	void deleteAll(TreeElem * root)
	{
		if (!root) { return; }
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
	}

	TreeElem * copy(TreeElem* root)
	{
		if (!root) { return nullptr; }
		TreeElem* t = new TreeElem(root->info);
		t->left = copy(root->left);
		t->right = copy(root->right);
		t->count = root->count;
		return t;
	}
public:
	DictionaryTree()
	{
		root = new TreeElem();
	}

	DictionaryTree(string word)
	{
		root = new TreeElem(word);
	}

	~DictionaryTree()
	{
		deleteAll(root);
	}

	DictionaryTree& operator= (DictionaryTree const & dictionary)
	{
		if (this == &dictionary) { return *this; }
		this->root = copy(dictionary.root);
		return *this;
	}

	int searchOfWord(string word)
	{
		return searchOfWord(root, word);
	}

	void add(string word)
	{
		add(root, word);
	}

	void remove(string word)
	{
		remove(root, word);
	}

	int countOfWords()
	{
		return countOfWords(root);
	}

	void write()
	{
		write(root);
		cout << endl;
	}
};

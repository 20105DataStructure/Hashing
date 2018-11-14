#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef HASH_H
#define HASH_H
class Hash {
private:
	static const int hash[9999];
public:
	Hash();
	~Hash();
	void insertDataset(string txt_);
	void deleteDataset();
	void searchingDataset();
};
#endif
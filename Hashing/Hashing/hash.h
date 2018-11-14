#include <iostream>
#include <string>
#include <fstream>
#include "DataNode.h"
using namespace std;
#ifndef HASH_H
#define HASH_H
class Hash {
private:
	static const int tablesize=199999;

	struct dataset {
		DatasetNode* next;
	};
	dataset* hash[tablesize];
public:
	Hash();
	~Hash();
	void AddDataSet(string tconst, string Type, string title, int YYYY, int runtime, string*genres,int index);
	void insertDataset(string txt_);
	void deleteDataset();
	void searchingDataset();
};
#endif
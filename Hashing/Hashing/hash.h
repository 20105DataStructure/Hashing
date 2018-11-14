#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef HASH_H
#define HASH_H
class Hash {
private:
	static const int tablesize=19999;

	struct dataset {
		string tconst;
		string titleType;
		string peimaryTitle;
		int startYear;
		int runtimeMinutes;
		string* genres;
		dataset* next;
	};
	dataset* hash[tablesize];
public:
	Hash();
	~Hash();
	void AddDataSet(string tconst, string Type, string title, int YYYY, int runtime, string*genres);
	void insertDataset(string txt_);
	void deleteDataset();
	void searchingDataset();
};
#endif
#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"
using namespace std;

Hash::Hash() {

}
Hash::~Hash() {

}
void Hash::insertDataset(string txt_) {
	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	string runtimeMinutes;
	string Genres;
	string *genres = new string[3];

	ifstream file(txt_);
	while (file.good()) {
		getline(file, tconst, '\t');
		getline(file, titleType, '\t');
		getline(file, peimaryTitle, '\t');
		file >> startYear >> runtimeMinutes;
		getline(file, Genres);

		int pos1 = 1;
		int pos2;
		size_t n = count(Genres.begin(), Genres.end(), ',');
		int i = 0;
		if (n > 0) {
			pos1 = Genres.find("\"") + 1;
			for (; i < n; i++) {
				pos2 = Genres.find(",", pos1);
				genres[i] = Genres.substr(pos1, pos2 - pos1);
				pos1 = pos2 + 1;
			}
		}
		pos2 = Genres.find("\"", pos1);
		genres[i] = Genres.substr(pos1, pos2 - pos1);

		for (int i = 0; i < 3; i++) {
			cout << ' ' << genres[i];
			genres[i] = "";
		}
		//start coding here
		//code for the key agolthim
		if (runtimeMinutes[1] == 'N')
			cout << "\\N";
		else
			cout << runtimeMinutes;
		//end here
		cout << endl;
		if (file.eof())
			file.close();
	}
}
void Hash::deleteDataset() {

}
void Hash::searchingDataset() {

}
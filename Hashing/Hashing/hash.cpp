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
	int key, key_Runtime, key_title, key_type, key_tconst;

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
		key = 0;
		key_Runtime = 0;
		key_title = 0;
		key_type = 0;
		//runtime (first key)
		if (runtimeMinutes[1] == 'N')
			key += 0;
		else {
			key_Runtime = std::stoi(runtimeMinutes);
			key += (key_Runtime % 10);
		}
		//year(second key)
		key += (startYear % 10 * 10);
		//title(thrid key)
		key_title = int(peimaryTitle[0]);
		key += (key_title % 10 * 100);
		//type (4th key)
		key_type = int(titleType[0]);
		key += (key_type % 10 * 1000);
		//tconst(5th key)
		key_tconst = tconst[8] - '0';
		key += (key_tconst % 10 * 10000);
		//genres(6th key)

	
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
#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"
#include "DataNode.h"

using namespace std;

int main()
{
	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	string runtimeMinutes;
	string Genres;
	string *genres = new string[3];
	//DatasetList List;

	ifstream file("DataSetTest.txt");
	while (file.good()) {
		getline(file, tconst, '\t');
		getline(file, titleType, '\t');
		getline(file, peimaryTitle, '\t');
		file >> startYear >> runtimeMinutes;
		getline(file, Genres);

		cout << tconst << ' ' << titleType << ' ' << peimaryTitle << ' ' << startYear << ' ';
		if (runtimeMinutes[1] == 'N')
			cout << "\\N";
		else
			cout << runtimeMinutes;

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
		cout << endl;
		if (file.eof())
			file.close();
	}

	system("pause");
	return 0;
}


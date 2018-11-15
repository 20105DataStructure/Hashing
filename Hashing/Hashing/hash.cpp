#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"
#include "DataNode.h"
using namespace std;

Hash::Hash() {
	for (int i = 0; i < tablesize; i++) {
		
		hash[i];
	}
}
Hash::~Hash() {

}
//adding data intothe Dataset hash table 
//it may be haveing the coillison in the process ,so there would be consider by the linklist in the hash table 
void Hash::AddDataSet(string tconst, string Type, string title, int YYYY, string runtime, string*genres,int index) {
	int index_ = index;

	if (hash[index_] == NULL)
	{
		DatasetNode *newNode = new DatasetNode(tconst, Type, title, YYYY, runtime, genres);
		hash[index_]->next = newNode;
		newNode-> next = NULL;
	}
	else{
		DatasetNode * currnode = head;
		DatasetNode * prenode = NULL;
		DatasetNode *newNode = new DatasetNode(tconst, Type, title, YYYY, runtime, genres);
		for (; currnode->next; prenode = currnode, currnode = currnode->next);
		currnode->next = newNode;
		newNode->next = NULL;
	}
	
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

		int pos1 = 1, pos2, i = 0;
		size_t n = count(Genres.begin(), Genres.end(), ',');
		if (n > 0) {
			pos1 = Genres.find("\"") + 1;
			for (; i < (signed)n; i++) {
				pos2 = Genres.find(",", pos1);
				genres[i] = Genres.substr(pos1, pos2 - pos1);
				pos1 = pos2 + 1;
			}
		}
		pos2 = Genres.find("\"", pos1);
		genres[i] = Genres.substr(pos1, pos2 - pos1);
		
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
		if (n > 0) {
			key += 100000;
		}
		//past the  dataset to another funtion to insert dataset into the hash table
		AddDataSet(tconst, titleType, peimaryTitle, startYear, runtimeMinutes, genres,key);
		//end here
		cout << "sucess"<<endl;
		if (file.eof())
			file.close();
	}
}
void Hash::deleteDataset() {

}

void Hash::statistical() {

}
void Hash::searchingDataset() {
	bool code = false;
	bool type = false;
	bool title = false;
	bool year = false;
	bool runtime = false;
	bool genres = false;
	char c, t, T, y, r, g;
	string dcode, dtype, dtitle, dgenres, druntime;
	int dyear = 0;
	int pcode = 0, ptype = 0, ptitle = 0, pgenres = 0, pruntime = 0, pyear = 0;
	int key = 0;


	cout << "Please enter the source(s) you can provide" << endl;
	cout << "code   type   title   year   runtime   genres:" << endl;
	cout << "Type t represent you can give the soure and f represent can't respectively" << endl;
	cin >> c;
	cin >> t;
	cin >> T;
	cin >> y;
	cin >> r;
	cin >> g;
	cout << "Plese enter the data: " << endl;
	if (c == 't')
	{
		code = true;
		cout << "code: " << endl;
		cin >> dcode;
		pcode += dcode[8];
		key += pcode;
	}
	if (t == 't')
	{
		type = true;
		cout << "type: " << endl;
		cin >> dtype;
		ptype += int(dtype[0]) % 10;
		key += ptype * 10;
	}
	if (T == 't')
	{
		title = true;
		cout << "title: " << endl;
		cin >> dtitle;
		ptitle += int(dtitle[0]) % 10;
		key += title * 100;
	}
	if (y == 't')
	{
		year = true;
		cout << "year: " << endl;
		cin >> dyear;
		pyear += dyear % 10;
		key += pyear * 1000;
	}
	if (r == 't')
	{
		runtime = true;
		cout << "runtime (/N) represent no runtime: " << endl;
		cin >> druntime;
		if (druntime[1] == 'N')
			pruntime += 0;
		else
		{
			pruntime = std::stoi(druntime);
			pruntime += (pruntime % 10);
		}
		key += pruntime * 10000;
	}
	if (g == 't')
	{
		genres = true;
		cout << "genres (/N) represent no genres: " << endl;
		cin >> dgenres;
		if (dgenres[1] == 'N')
			pgenres += 0;
		else
			pgenres += 1;
		key += pgenres * 100000;
	}
	int check1 = 0, check2 = 0;
	//setting up the loop funtion
	if (code == true) check2 = 1;
	else if (type == true)check2 = 10;
	else if (title == true)check2 = 100;
	else if (year == true)check2 = 1000;
	else if (runtime == true)check2 = 10000;
	else if (genres == true)check2 = 100000;

	if (genres == true)check1 = 1000000;
	else if (runtime == true)check1 = 100000;
	else if (year == true)check1 = 10000;
	else if (title == true)check1 = 1000;
	else if (type == true)check1 = 100;
	else if (code == true)check1 = 10;
	//end of setting
	for (int i = 0; i < 199999; i++)
	{
		if (i%check1 / check2 == key) {
			if (hash[i]->next != NULL) {
				DatasetNode* currnode = hash[i]->next;
				int comparing = 0;
				//check funtion part 1
				//check for the first node in each hash table which having value 
				if (code == true) {
					if (currnode->tconst != dcode) {
						comparing += 1;
					}
				}
				if (type == true) {
					if (currnode->titleType != dtype) {
						comparing += 1;
					}
				}
				if (title == true) {
					if (currnode->peimaryTitle != dtitle) {
						comparing += 1;
					}
				}
				if (year == true) {
					if (currnode->startYear != dyear) {
						comparing += 1;
					}
				}
				if (runtime == true) {
					if (currnode->runtimeMinutes != druntime) {
						comparing += 1;
					}
				}
				if (genres == true) {
					int checkgenres = 0;
					for (i=0;i<3;i++){
						if (currnode->genres[i] == dgenres) {
							checkgenres += 1;
						}
						if (checkgenres = 0) {
							comparing += 1;
						}
					}
				}
				//output funtion 
				if (currnode->next != NULL) {
					DatasetNode* prevnode = currnode;
					currnode = currnode->next;
					do {
						//check funtion part two
						//by the way of checking linklist to check all the dataset in the hash table
						comparing = 0;
						if (code == true) {
							if (currnode->tconst != dcode) {
								comparing += 1;
							}
						}
						if (type == true) {
							if (currnode->titleType != dtype) {
								comparing += 1;
							}
						}
						if (title == true) {
							if (currnode->peimaryTitle != dtitle) {
								comparing += 1;
							}
						}
						if (year == true) {
							if (currnode->startYear != dyear) {
								comparing += 1;
							}
						}
						if (runtime == true) {
							if (currnode->runtimeMinutes != druntime) {
								comparing += 1;
							}
						}
						if (genres == true) {
							int checkgenres = 0;
							for (i = 0; i < 3; i++) {
								if (currnode->genres[i] == dgenres) {
									checkgenres += 1;
								}
								if (checkgenres = 0) {
									comparing += 1;
								}
							}
						}
						//output funtion
						prevnode = currnode;
						currnode = currnode->next;
					} while (currnode->next != NULL);
				}
			}
		}
	}
}
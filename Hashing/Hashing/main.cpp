#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"
#include "DataNode.h"

using namespace std;

int main()
{
	Hash Hash;
	string filename;
	char action;
	bool loop = true;

	cout << "Please enter the file name: ";
	cin >> filename;
	Hash.insertDataset(filename);
	cout << endl;

	while (loop)
	{
		cout << "Action: (s)earch (d)elete (S)tatistic (e)xit ";
		cin >> action;
		cout << endl;

		if (action == 's')
			Hash.searchingDataset();

		if (action == 'd')
			Hash.deleteDataset();

		if (action == 'S')
			Hash.statistical();

		if (action == 'e')
			break;
	}

	system("pause");
	return 0;
}


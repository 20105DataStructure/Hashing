#include <string>
using namespace std;

#ifndef DataNode_H
#define DataNode_H


class DatasetNode {
public:

	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	string runtimeMinutes;
	string* genres;
	DatasetNode* next;

public:
	DatasetNode(string code, string Type, string Title, int YYYY, string mins, string* genres) {
		this->tconst = code;
		this->titleType = Type;
		this->peimaryTitle = Title;
		this->startYear = YYYY;
		this->runtimeMinutes = mins;
		this->genres = genres;
		this->next = NULL;
	}
};
#endif
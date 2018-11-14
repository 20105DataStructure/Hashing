#include <string>
using namespace std;
class DatasetNode {
public:
	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	int runtimeMinutes;
	string* genres;
	DatasetNode* next;

public:
	DatasetNode(string code, string Type, string Title, int YYYY, int mins, string* genres) {
		this->tconst = code;
		this->titleType = Type;
		this->peimaryTitle = Title;
		this->startYear = YYYY;
		this->runtimeMinutes = mins;
		this->genres = genres;
		this->next = NULL;
	}
};

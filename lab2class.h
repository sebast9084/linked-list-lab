#include <iostream>
#include <string>
using namespace std;
struct Commit {
	int hash;
	string message;
	Commit* next;
	Commit(int h, const string& msg) : hash(h), message(msg),
	next(nullptr) {}
};

class CommitHistory {
private:
	Commit* head;
public:
	CommitHistory() : head(nullptr) {}
	void commit(const string& message); // append
	void log() const;// display all
	void reset(); // Delete last commit
	static CommitHistory merge(const CommitHistory& branch1, const CommitHistory& branch2);
	~CommitHistory();
};

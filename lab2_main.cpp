#include "lab2_class.h"
using namespace std;
int main() {
	srand(time(0)); // For random hash generation
	CommitHistory master;
	master.commit("Initial commit");
	master.commit("Add README");
	master.commit("Implement login system");
	CommitHistory featureBranch;
	featureBranch.commit("Start feature X");
	featureBranch.commit("Fix bug in feature X");
	cout << "\n== Master Branch ==";
	master.log();
	cout << "\n== Feature Branch ==";
	featureBranch.log();
	cout << "\n== Reset last commit on master ==";
	master.reset();
	master.log();
	cout << "\n== Merged History ==";
	CommitHistory merged = CommitHistory::merge(master, featureBranch);
	merged.reset();
	merged.log();
	std::cout << "\n== Master Branch Unchanged after merge==";
	master.log();
	std::cout << "\n== Feature Branch Unchanged after merge==";
	featureBranch.log();
	return 0;
}

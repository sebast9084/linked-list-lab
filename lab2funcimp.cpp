#include "lab2class.h"
void CommitHistory::commit(const string& message) {
	int hash = rand() % 10000; // Simulated hash
    	Commit* newCommit = new Commit(hash, message);
	if(!head){
		head = newCommit; // Checks if linkedlist already has a head, if not set head as newCommit
	}else{
	  	Commit* temp = head;
		while(temp -> next){ // Loops until temp -> next == nullptr
			temp = temp -> next; // Moves forward through the linked list
	  	}
		temp -> next = newCommit; // Sets the last node as newCommit
	}
}

void CommitHistory::log()const{ 
	// Check if the commit list is empty
	if(!head){
		cout << "NO commits!";
		return;
	}
	// Start from the first commit in the list
	Commit* temp = head;
	// Traverse through the entire commit list
	while (temp) {
		// Print the hash and message of the current commit
		cout << "Hash: " << temp->hash << " | Message: " << temp->message << endl;
		// Move to the next commit in the list
		temp = temp->next;
	}
}

void CommitHistory::reset() {
	if (!head) {
		cout << "No commits to reset!" << endl;
		return;
	}
	// f only one commit exists
	if (!head->next) {
		// Delete the single commit and set head to null
		delete head;
		head = nullptr;
		return;
	}
	// Initialize pointers to traverse the linked list
	Commit* prev = nullptr; // Will eventually point to the second-last commit
	Commit* curr = head;  // Will traverse the list to find the last commit
	// Traverse until the last commit is found
	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}
	delete curr;        // Delete the last commit
	prev->next = nullptr; // Remove its link from the list
}

CommitHistory CommitHistory::merge(const CommitHistory& branch1, const CommitHistory& branch2) {
	// Create a new CommitHistory object to store the merged result
	CommitHistory merged;
	// Pointer to traverse the first branch's commits
	Commit* temp = branch1.head;
	// Copy all commits from branch1 into the merged history
	while (temp) {
		merged.commit(temp->message); // Add the commit message to the new history
		temp = temp->next;            // Move to the next commit in branch1
	}
	// Reset the traversal pointer to the head of branch2
	temp = branch2.head;
	// Copy all commits from branch2 into the merged history
	while (temp) {
		merged.commit(temp->message); // Add the commit message to the new history
		temp = temp->next;            // Move to the next commit in branch2
	}
	// Return the fully merged commit history
	return merged;
}

CommitHistory::~CommitHistory() {
	// Start from the head of the commit list
	Commit* temp = head;
	// Traverse the entire list and delete each commit node
	while (temp) {
		// Store the next node temporarily
		Commit* next = temp->next;
		// Delete the current commit node to free memory
		delete temp;
		// Move to the next node
		temp = next;
	}
}


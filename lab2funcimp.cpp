#include "lab2class.h"
void CommitHistory::commit(const string& message) {
	int hash = rand() % 10000; // Simulated hash
    	Commit* newCommit = new Commit(hash, message);
	if(!head){
		head = newCommit; //Checks if linkedlist already has a head, if not set head as newCommit
	}else{
	  	Commit* temp = head;
		while(temp -> next){ //Loops until temp -> next == nullptr
			temp = temp -> next; //Moves forward through the linked list
	  	}
		temp -> next = newCommit; //Sets the last node as newCommit
	}
}

void CommitHistory::log()const{
	if(!head){
		cout << "NO commits!";
		return;
	}
	Commit* temp = head;
	while (temp) {
		cout << "Hash: " << temp->hash << " | Message: " << temp->message << endl;
		temp = temp->next;
	}
}

void CommitHistory::reset() {
	if (!head) {
		cout << "No commits to reset!" << endl;
		return;
	}
	//If only one commit exists
	if (!head->next) {
		delete head;
		head = nullptr;
		return;
	}
	//Traverse to the second last commit
	Commit* prev = nullptr;
	Commit* curr = head;
	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}
	delete curr;        //Delete the last commit
	prev->next = nullptr; //Remove its link from the list
}

CommitHistory CommitHistory::merge(const CommitHistory& branch1, const CommitHistory& branch2) {
	CommitHistory merged;
	//Pointer to traverse each list
	Commit* temp = branch1.head;
	while (temp) {
		merged.commit(temp->message); //Copy message
		temp = temp->next;
	}
	temp = branch2.head;
	while (temp) {
		merged.commit(temp->message); //Copy message
		temp = temp->next;
	}
	return merged;
}

CommitHistory::~CommitHistory() {
	Commit* temp = head;
	while (temp) {
		Commit* next = temp->next;
		delete temp;
		temp = next;
	}
}



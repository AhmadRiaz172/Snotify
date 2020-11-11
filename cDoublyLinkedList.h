#pragma once
#include <iostream>

using namespace std;
template<class T>
class DoublyLinkedList {
	struct Node {
		T data;
		Node* next;
		Node* prev;
	};

public:

	Node* head;
	Node* current;
	Node* tail;

	DoublyLinkedList() {
		head = NULL;
		current = NULL;
		tail = NULL;
	}

	void moveNext() {
		if (current == NULL) {
			cout << "current is NULL" << endl;
			return;
		}

		current = current->next;
	}

	void movePrevious() {
		if (current == NULL) {
			cout << "current is NULL" << endl;
			return;
		}

		current = current->prev;
	}

	void insertBeforeCurrent(T dataI) {
		if (current == head) {
			Node* newNode = new Node;
			newNode->data = dataI;
			newNode->next = head;
			head->prev = newNode;

			head = newNode;

		}
		else {
			Node* newNode = new Node;
			newNode->data = dataI;
			newNode->next = current;
			newNode->prev = current->prev;
			Node* temp = current->prev;
			temp->next = newNode;
		}
	}

	void deleteAtCurrent() {
		/* base case */
		if (head == NULL || current == NULL)
			return;

		/* If node to be deleted is head node */
		if (head == current)
			head = current->next;

		/* Change next only if node to be
		deleted is NOT the last node */
		if (current->next != NULL)
			current->next->prev = current->prev;

		/* Change prev only if node to be
		deleted is NOT the first node */
		if (current->prev != NULL)
			current->prev->next = current->next;

		/* Finally, free the memory occupied by current*/
		free(current);
		return;
	}

	Node* getCurrent() {
		return current;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void insertLast(T dataItem) {
		Node* newNode = new Node;
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = dataItem;
		if (head == NULL) {
			head = newNode;
			current = head;
			return;
		}
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
		return;

	}
	void moveToLast() {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		current = temp;
	}

	void moveToFirst() {
		current = head;
	}

	int Search(T n) {
		current = head;
		int count = -1;
		while (current != NULL) {
			if (current->data == n) {
				count++;
				return count;
			}
			current = current->next;
			count++;
		}
		if (current == NULL) {
			return -1;
		}
	}

	void clear() {
		Node* temp = head;
		Node* temp2 = head;
		while (temp != NULL) {
			temp = temp->next;
			temp->prev = NULL;
			delete temp2;
			temp2 = temp;
		}
		head = NULL;
		current = NULL;
		tail = NULL;
	}
};


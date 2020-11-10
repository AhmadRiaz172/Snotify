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
	Node* head;
	Node* current;
	Node* tail;

public:

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
		Node* temp = current;
		(current->prev)->next = current->next;
		(current->next)->prev = current->prev;
		temp = temp->next;
		delete current;
		current = temp;

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
		if (head == NULL) {
			Node* newNode = new Node;
			newNode->next = NULL;
			newNode->data = dataItem;
			head = newNode;
			tail = newNode;
			current = head;
		}
		else {
			Node* newNode = new Node;
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
			newNode->data = dataItem;
			tail = newNode;
		}
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


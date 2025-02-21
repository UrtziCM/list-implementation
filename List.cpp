#include <iostream>
#include <iomanip>
#include "List.h"

namespace Euneiz
{
	// Node stuff
	Node::Node(int data) {
		this->data = data;
		next = nullptr;
	}

	Node::~Node() {}

	// List stuff

	List::List() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	List::~List() {
		Clear();
	}

	void List::PushBack(int data) {
		Node* newNode = CreateNode(data);
		if (size > 0) {
			Node* tempTailNode = tail;

			tempTailNode->next = newNode;
			tail = newNode;
		}
		else {
			head = newNode;
			tail = head;
		}
		size++;
	}

	void List::PushFront(int data) {
		if (head) {
			Node* newHead = CreateNode(data);
			newHead->next = this->head;
			this->head = newHead;
		}
		else {
			head = CreateNode(data);
			tail = head;
		}
		size++;
	}

	void List::PopFront() {
		Node* nodeToDelete = this->head;
		this->head = nodeToDelete->next;
		delete nodeToDelete;
		size--;
	}
	bool List::Empty() {
		return size == 0;
	}
	int List::Size() {
		return size;
	}
	void List::Clear() {
		if (size == 1) { // Si no, al hacer erase de el primero siendo 1 solo, peta
			PopFront();
		}else if (size > 1) {
			Node* current_node = this->head;
			Node* next_node;
			while (current_node != nullptr) {
				next_node = current_node->next;
				delete current_node;
				current_node = next_node;
			}
			next_node = nullptr;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void List::Insert(int data, int index) {
		if (index >= size) {
			PushBack(data);
		}
		else if (index <= 0) {
			PushFront(data);
		}
		else { // tomamos previous y next del índice y actualizamos pointers
			Node* previousNode = head;
			Node* currentNode = head->next;
			Node* nextNode = nullptr;

			// Empezamos en el indice 1 porque current es el 1 y previous es el 0

			for (int currentIndex = 1; currentIndex < size; currentIndex++) {
				if (currentIndex == index) {
					nextNode = currentNode;
					break;
				}
				else {
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
			currentNode = CreateNode(data);
			previousNode->next = currentNode;
			currentNode->next = nextNode;
			size++;
		}

	}

	void List::Erase(int index) { // REDO AFTER VOLLEY
		if (!head || size <= 0) {
			return;
		}
		if (index > size - 1) { // Clamp values between 0 and size
			index = size - 1;
		}
		else if (index < 0) {
			index = 0;
		}

		switch (size) {
			case 1:
				Clear();
				break;
			case 2:
				if (index == 0) {
					PopFront();
				} else {
					Node* nodeToDelete = this->tail;
					this->tail = head;
					delete nodeToDelete;
				}
				size--;
				break;
			default: // Size is at least 3 so we go for the wanted index and the previous one
				if (index == 0) {
					Node* tempNewHead = head->next;
					size--;
					delete head;
					head = tempNewHead;
				} else {
					Node* previousNode = head;
					Node* currentNode = head->next;
					Node* nextNode = nullptr;

					// Empezamos en el indice 1 porque current es el 1 y previous es el 0

					for (int currentIndex = 1; currentIndex < size; currentIndex++) {
						if (currentIndex == index) {
							nextNode = currentNode->next;
							break;
						}
						else {
							previousNode = currentNode;
							currentNode = currentNode->next;
						}
					}
					size--;
					delete currentNode;
					previousNode->next = nextNode;
					if (!nextNode) { // If its null pointer
						tail = previousNode;
					}
				}
				break;
		}
	}

	Node* List::CreateNode(int data) {
		return new Node(data);
	}

	std::ostream& operator <<(std::ostream& os, const List& list) {
		Node* current_node = list.head;
		while (current_node) {
			os << std::setw(4) << current_node->data;
			current_node = current_node->next;
		}
		os << std::endl;
		return os;
	}
}
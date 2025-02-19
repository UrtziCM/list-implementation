#include <iostream>
#include <iomanip>
#include "List.h"

namespace Euneiz
{
	// Node stuff
	Node::Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
	
	Node::~Node() {
		//delete this->next;
	}
	
	// List stuff
	
    List::List() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
	List::~List() {
		Clear();
		//delete this->head;
		//delete this->tail;
	}
	void List::PushBack(int data) {
		size++;
		if (head) {
			Node* tempNodePointer = tail;
			tempNodePointer->next=CreateNode(data);
			tail = tempNodePointer->next;
		} else {
			head = CreateNode(data);
			tail = head;
		}
	}
	
	void List::PushFront(int data) {
		size++;
		if (head) {			
			Node* newHead = CreateNode(data);
			newHead->next = this->head;
			this->head = newHead;
		} else {
			head = CreateNode(data);
			tail = head;
		}
	}
	
	void List::PopFront(){ 
		size--;
		Node* nodeToDelete = this->head;
		this->head = nodeToDelete->next;
		delete nodeToDelete;
	}
	bool List::Empty() {
		return size == 0;
	}
	int List::Size() {
		return size;
	}
	void List::Clear() {
		if (size > 0) {
			Node* current_node = (*this).head;
			Node* next_node;
			while(current_node != nullptr)	{
				next_node = current_node->next;
				delete current_node;
				current_node = next_node;
			}
		}
		size = 0;
	}
	
	void List::Insert(int data, int index){
		if (index >= size) {
			PushBack(data);
		} else if (index <= 0) {
			
			PushFront(data);
		} else { // tomamos previous y next del índice y actualizamos pointers
			Node* previousNode = nullptr;
			Node* nextNode = nullptr;
			int currentIndex = 0;
			for (Node* currentNode = head; currentIndex < index; currentIndex++) {
				if (currentIndex == 0)
					previousNode = currentNode;
					continue;
				nextNode = currentNode;
				if (currentIndex == index) {
					break;
				}			
				previousNode = currentNode;
			}
			Node* newNode = CreateNode(data);
			previousNode->next = newNode;
			newNode->next = nextNode;
		}
		
		size++;	
	} // TODO: Implement
	
	void List::Erase(int index){
		if (this->Size() == 0) {
			return;
		}
		size--;
		
		if (size == 1 && index == 0) { // Y quieren borrar el primero: Clear
			this->Clear();
		} else if(size == 2) { // Y quieren borrar 1, head y tail pasan a ser el que no borra
			switch (index) {
				case 0:
					delete head;
					head = tail;
					break;
				case 1:
					delete tail;
					tail = head;
					break;
			}
		} else if (index == size - 1) { // Si se quiere borrar el último...
			Node* previousNode = nullptr;
			for (Node* currentNode = head; currentNode != tail;) {		
				previousNode = currentNode;
			}
			delete tail;
			tail = previousNode;
			
		} else { // Iteramos hasta tener los 3 (previous, current, next) y previous apunta a next
			Node* previousNode = nullptr;
			Node* nodeToDelete = nullptr;
			Node* nextNode = nullptr;
			int currentIndex = 0;
			for (Node* currentNode = head; currentIndex <= index; currentIndex++) {
				if (currentIndex == 0)
					previousNode = currentNode;
					continue;
				nodeToDelete = currentNode;
				nextNode = currentNode->next;
				
				previousNode = currentNode;
			}
			previousNode->next = nextNode;
			delete nodeToDelete; 
			
		}		
	}
	
	Node* List::CreateNode(int data) {
		Node* node = new Node(data);
		return node;
	}
	
    std::ostream& operator <<(std::ostream& os, const List& list) {
		Node* current_node = list.head;
		while(current_node) {
			os << std::setw(4) << current_node->data;
			current_node = current_node->next;
		}
		os << std::endl;
		return os;
	}
	
}
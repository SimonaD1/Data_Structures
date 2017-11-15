#include "stdafx.h"
#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(const T& data, Node<T>* next = nullptr)
	{
		this->data = data; 
		this->next = next; //pointer -> next element of queue
	}
};
template <typename T>
class queue
{
private:
	Node<T>* first; //pointer -> first element of queue
	Node<T>* last; //pointer -> last element of queue
	size_t sizeQueue; //size of queue

	void copy(const queue& other); //function copy
	void inIt();
	void destroy() const;
	bool isEmpty() const; // 
public:
	queue(); //default constructor
	queue(const queue& other); //copy constructor
	queue& opertator=(const queue& other1); //operator =
	void enqueue(const T&); //add new element in queue
	void dequeue(); //remove elemenet of queue
	T getFirst() const; //data of first element in queue
	T getLast() const; //data of last element in queue
	size_t getSizeOfQueue() const; //length of queue
};
template<typename T>
queue<T>::queue()
{
	this->inIt();
}
template <typename T>
queue<T>::queue(const queue& other) //copy constructor
{
	this->inIt();
	this->copy(other);
}
template<typename T>
queue<T>& queue<T>::operator=(const queue& other1) 
{
	if (this != &other1)
	{
		this->destroy();
		this->inIt();
		this->copy(other);
	}
	return *this;
}
template <typename T>
void queue<T>::enqueue(const T& newData) ///add new element in queue
{
	Node<T>* newElement = new Node<T>(this->newData, nullptr);
	if (newElement)
	{
		if (isEmpty())
		{
			this->first = newElement;
		}
		else
		{
			last->next = newElement;
		}
		this->last = newElement;
		this->sizeQueue++;
	}
}
template <typename T>
void queue<T>::dequeue() //remove element of queue
{
	if (!this->isEmpty())
	{
		Node<T>* delElement =this->first;
		if (delElement)
		{
			if (this->sizeQueue == 1)
			{
				this->inIt();
			}
			else
			{
				this->first = this->first->next;
				delete delElemet;
				this->sizeQueue--;
			}
		}
	}

}
template<typename T>
T queue<T>::getFirst() const //get data of first element
{
	if (!this->isEmpty())
	{
		return this->first->data;
	}
	else return nullptr;
}
template <typename T>
T queue<T>::getLast() const //get data of last element
{
	if (!this->isEmpty())
	{
		return this->last->data;
	}
	else return nullptr;
}
template <typename T>
size_t queue<T>::getSizeOfQueue() const //length of queue
{
	return this->sizeQueue;
}
template <typename T>
void queue<T>::copy(const queue& other) //copy function
{
	Node<T> node = other.first;
	for (int i = 0; i < this->sizeQueue(); i++)
	{
		this->enqueue(this->node->data);
		this->node = node->next;
	}
}
template <typename T>
void queue<T>::inIt()
{
	this->first = nullptr;
	this->last = nullptr;
	this->sizeQueue = 0;
}
template<typename T>
void queue<T>::destroy() const //destory queue
{
	if (!isEmpty())
	{
		for (int i = 0; i < this->sizeQueue(); i++)
		{
			this->dequeue();
		}
	}
}
template<typename T>
bool queue<T>::isEmpty() const 
{
	return this->sizeQueue == 0;
}
int main()
{
    return 0;
}


#include<iostream>
using namespace std;
template <class T>
struct node
{
	T data;
	node<T>* next;
	node(const T& data, node<T>* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};
template <class T>
class Stack
{
private:
	node<T>* topElement;
	size_t size;
	void copy(const Stack<T>& other);
	void print() const;
	bool isEmpty() const;
	void erase();
public:
	Stack();
	Stack(const Stack<T>& other);
	Stack& operator=(const Stack<T>& other);
	size_t getSize() const;
	const T& Top() const;
	void push(const T& data);
	void pop();
	~Stack();
	
};
template <class T>
void Stack<T>::copy(const Stack<T>& other)
{
	if (other.topElement == nullptr)
	{
		this->topElement = nullptr;
		this->size = 0;
		return;
	}
    
	this->topElement = new node<T>(other.topElement->data, other.topElement->next);
	node<T>* temp1 = this->topElement;
	node<T>* temp2 = other.topElement;
	while (temp2 != nullptr)
	{
		temp1->next = new node<T>(temp2->next->data, temp2->next->next);
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	this->size = other.size;
}
 template <class T>
 void Stack<T>::print() const
 {
	 node<T>* temp = topElement;
	 while (temp != nullptr)
	 {
		 cout << temp->data << " ";
		 temp = temp->next;
	 }
 }
 template <class T>
 Stack<T>::Stack()
 {
	 this->topElement = nullptr;
	 this->size = 0;
 }
 template <class T>
 Stack<T>::Stack(const Stack<T>& other)
 {
	 this->copy(other);
 }
 template <class T>
 Stack<T>& Stack<T>::operator=(const Stack<T>& other)
 {
	 if (this != &other)
	 {
		 //this->erase();
		 this->copy(other);
	 }
	 return *this;
 }
 template <class T>
 bool Stack<T>::isEmpty() const
 {
	 return this->size == 0;
 }
 template <class T>
 size_t Stack<T>::getSize() const
 {
	 return this->size;
 }
template <class T>
 const T& Stack<T>::Top() const
 {
	 if (!isEmpty())
	 {
		 return this->topElement->data;
	 }
	 throw "Empty Stack";
 }
template <class T>
void Stack<T>::push(const T& data)
{
	node<T>* temp = new node<T>(data);
	if (this->isEmpty())
	{
		this->topElement = temp;
	}
	else
	{
		temp->next = this->topElement;
		this->topElement = temp;
	}
	this->size++;
}
template <class T>
void Stack<T>::pop()
{
	if (!this->isEmpty())
	{
		node<T>* temp = this->topElement;
		this->topElement = this->topElement->next;
		delete temp;
		this->size--;
	}
}
template <class T>
void Stack<T>::erase()
{
	for (int i = 0; i <= this->size; i++)
	{
		this->pop();
	}
}
 template <class T>
 Stack<T>::~Stack()
 {
	 this->erase();
 }

int main()
{

}
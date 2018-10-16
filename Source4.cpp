#include<iostream>
using namespace std;
template <class T>
struct node
{
	T data;
	node<T>* next;
};
template <class T>
class List
{
	node<T>* head;
	node<T>* tail;
	/*List<T>()
	{
		head = NULL;
		tail = NULL;
	} */
public:
	List();
	void createNode(T data);
	void display();
	void insertStart(T data);
	void insertEnd(T data);
	void insertPosition(int pos, T data);
	void deleteFirst();
	void deleteLast();
	void deletePosition(int pos);
	T getData(int index);
	T operator[](int index);
	node<T>* reverseList();
};
template<class T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
}
template <class T>
void List<T>::createNode(T data)
{
	if (!head)
	{
		head = new node<T>;
		head->data = data;
		head->next = NULL;
		tail = head;
	}
	else if (tail == head)
	{
		tail = new node<T>;
		tail->data = data;
		tail->next = NULL;
		head->next = tail;
	}
	else
	{
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}
 template<class T>
 void List<T>::display() 
 {
	 node<T>* temp = new node<T>;
	 temp = head;
	 while (temp != NULL)
	 {
		 cout << temp->data << " ";
		 temp = temp->next;
	 }
 }
 template<class T>
 void List<T>::insertStart(T data)
 {
	 node<T>* temp = new node<T>;
	 temp->data = data;
	 temp->next = head;
	 head = temp;
 }
 template <class T>
 void List<T>::insertEnd(T data)
 {
	 node<T>* temp = new node<T>;
	 temp->data = data;
	 temp->next = NULL;
	 tail->next = temp;
	 tail = temp;
 }
 template<class T>
 void List<T>::insertPosition(int pos, T data)
 {
	 node<T>* temp = new node<T>;
	 node<T>* curr = new node<T>;
	 node<T>* pre = new node<T>;
	 curr = head;
	 for (int i = 0; i < pos; i++)
	 {
		 pre = curr;
		 curr = curr->next;
	 }
	 temp->data = data; // !!!!!!!!
	 pre->next = temp;
	 temp->next = curr;
 }
 template <class T>
 void List<T>::deleteFirst()
 {
	 node<T> temp = new node<T>;
	 temp = head;
	 head = head->next;
	 delete temp;
 }
 template <class T>
 void List<T>::deleteLast()
 {
	 node<T>* curr = new node<T>;
	 node<T>* pre = new node<T>;
	 curr = head;
	 while (curr->next != NULL)
	 {
		 pre = curr;
		 curr = curr->next;
	 }
	 tail = pre;
	 pre->next = NULL;
	 delete curr;
 }
 template <class T>
 void List<T>::deletePosition(int pos)
 {
	 node<T>* curr = new node<T>;
	 node<T>* pre = new node<T>;
	 curr = head;
	 for (int i = 0; i < pos; i++)
	 {
		 pre = curr;
		 curr = curr->next;
	 }
	 pre->next = curr->next;
 }
template <class T>
T List<T>::getData(int index)
{
	if (index == 0)
	{
		return this->head->data;
	}
	else
	{
		node<T>* temp = new node<T>;
		temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
}
template <class T>
T List<T>::operator[](int index)
{
	return getData(index);
}
template <class T>
node<T>* List<T>::reverseList()
{
	node<T>* pre = new node<T>;
	node<T>* curr = new node<T>;
	node<T>* next = new node<T>;
	curr = head;
	pre = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	head = pre;
	return head;
}

int main()
{

}
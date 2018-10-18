#include <iostream>
using namespace std;
template <class T>
struct node
{
	T data; //promenliva za danni 
	node *next; //ukazatel na sledvashtiq vzel
};
template <class T>
class list // klas koito da sodrzi funkciite za obrabotka na vzlite i treba da ima dva vazhni ukazatelq head i tail 
{
private:
	node<T>* head; // ukazatel km prviq vzel 
	node<T>* tail; // ukazatel km posledniq vzel
public:
	list<T>() //konstruktor 
	{
		head = NULL; //nachalni stoinosti i na dvata ukazateli sa NULL
		tail = NULL;
	}
	void addNode(T data) //metod za dobavqne na nov vzel
	{
		if (!head)
		{
			// The list is empty t.e ne ima nikakov vzel i sozdavame vzel v koito kazvame che e i head i tail
			head = new node<T>;
			head->data = data;
			head->next = NULL;
			tail = head;
		} // The list isn't empty 
		else if (tail == head)
		{ // The list has one element
			tail = new node<T>;
			tail->data = data;
			tail->next = NULL;
			head->next = tail;
		}
		else
		{ 	// The list has more than one element
			node<T>* temp = new node<T>; //sozdavame nov vzel
			temp->data = data;
			temp->next = NULL;
			tail->next = temp; //vzimame pointer-a ot tail i go davame na temp 
			tail = temp; //i veche kazvame che opashkata e noviq sozdaden vzel koito sme go krstili temp
		}
	}
	void display() //metod za pokazvane na svrzaniq spisak
	{
		node<T>* temp = new node<T>; //sozdavame privremen node
		temp = head; //temporary node go zimame kako head
		while (temp != NULL) //dodeka pointero na temp ne stane NULL t.e posleden vzel od spisko
		{
			cout << temp->data << " ";
			temp = temp->next; // od koga ke ispecatime mestime pointero na sledniot element
		}
		// nai-vajni operacii koito se izvrshvat v svrzan spisak
		void insertStart(T data)
		{
			node<T>* temp = new node<T>;
			temp->data = data;
			temp->next = head;
			head = temp;
		}
		void insertEnd(T data)
		{
			node<T>* temp = new node<T>;
			temp->data = data;
			temp->next = NUll;
			tail->next = temp;
			tail = temp;
		}
		void insertPositon(int pos, T data)
		{
			node<T>* pre = new node<T>;
			node<T>* cur = new node<T>;
			node<T>* temp = new node<T>;
			cur = head;
			for (int i = 1; i < pos; i++)
			{
				pur = cur;
				cur = cur->next;
			}
			temp->data = data;
			pre->next = temp;
			temp->next = cur;
		}
		void deleteFirst()
		{
			node<T>* temp = new node<T>;
			temp = head;
			head = head->next;
			delete temp;
		}
		void deleteLast()
		{
			node<T>* pre = new node<T>;
			node<T>* cur = new node<T>;
			cur = head;
			while (cur->next != NULL)
			{
				pre = cur;
				cur = cur->next;
			}
			tail = pre;
			pre->next = NULL;
			delete cur;
		}
		void deletePostion(int pos)
		{
			node<T>* pre = new node<T>;
			node<T>* cur = new node<T>;
			cur = head;
			for (int i = 0; i < pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
		}
		// vrshtane na data pri podaden index na vzel ot koito iskame da se vrne data
		T getData(int index)
		{
			if (index == 0)
			{
				// ako podadenio index = 0 vrhstame data ot head
				return this->head->data;
			}
			else
			{
				node<T>* cur = this->head;
				for (int i = 0; i < index; i++)
				{
					cur = cur->next;
				}
				return cur->data;
			}
		}
		T operator[](int index) //izvikvame metoda getData s podaden konkreten index
		{
			return getData(index);
		}
	}
	node<T>* reverseList()
	{
		node<T>* cur = new node<T>;
		node<T>* pre = new node<T>;
		node<T>* next = new node<T>; //paza address na sledvashtiq vzel da nqma gubene na informaciq
		cur = head;
		pre = NULL;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next; 
		}
		head = pre;
		return head;
	} 
};

int main()
{

}
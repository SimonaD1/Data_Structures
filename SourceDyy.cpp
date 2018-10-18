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
class LList
{
private:
	node<T>* head;
	node<T>* tail;
	size_t size;
	void copy(const LList<T>& other);
	bool isEmpty();
	void inIt();
	void erase();
public:
	LList();
	LList(const LList<T>& other);
	LList<T>& operator=(const LList<T>& other);

	void insertStart(const T& data);
	void insertEnd(const T& data);
	void insertPosition(int pos, const T& data);

	void deleteStart();
	void deleteEnd();
	void deletePosition(int pos);

	T operator[](size_t index);
	//node<T>* reverseList();
	T getData(int index);

	//getters for the pointers not for the actual values
	node<T>* getFirst() const;
	node<T>* getLast() const;
	T getFirstElement() const;
	T getLastElement() const;

	node<T>* goToElement(size_t index);
	void changeValueAtIndex(size_t index, const T& data);
	int getSizeOfList();

	~LList();

};
template<class T>
LList<T>::LList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}
template <class T>
node<T>* LList<T>::getFirst() const
{
	if (this->isEmpty())
	{
		return nullptr;
	}
	return this->head;
}
template <class T>
node<T>* LList<T>::getLast() const
{
	if (this->isEmpty())
	{
		return nullptr;
	}
	return this->tail;
}
template <class T>
T LList<T>::getFirstElement() const
{
	return this->head->data;
}
template <class T>
T LList<T>::getLastElement() const
{
	return this->tail->data;
}
template <class T>
void LList<T>::insertStart(const T& data)
{
	node<T>* element = new node<T>(data, this->next);
	if (element)
	{
		if (this->isEmpty())
		{
			this->head = element;
			this->tail = element;
		}
		else
		{
			this->head->next = element;
			this->head = element;
		}
		this->size++;
	}
}
template <class T>
void LList<T>::insertEnd(const T& data)
{
	node<T>* element = new node<T>(data, this->next);
	if (element)
	{
		if (this->isEmpty())
		{
			this->head = element;
			this->tail = element;
		}
		else
		{
			this->tail->next = element;
			this->tail = element;
		}
		this->size++;
	}
}
template <class T>
node<T>* LList<T>::goToElement(size_t index)
{
	if (index < 0 || index >= this->size)
	{
		return nullptr;
	}
	node<T>* temp = this->head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}
template <class T>
void LList<T>::changeValueAtIndex(size_t index, const T& data)
{
	if (!this->isEmpty())
	{
		if (index < 0 || index >= this->size)
		{
			cout << "Index can't be smaller than 0 or bigger than list length" << endl;
		}
		else
		{
			this->goToElement(index)->data = data;
		}
	}
	else
	{
		cout << "Error empty List" << endl;
	}
}
template <class T>
void LList<T>::insertPosition(int pos, const T& data)
{
	if (!this->isEmpty())
	{
		if (pos < 0 || pos >= this->size)
		{
			cout << "Index can't be smaller than 0 or bigger than list length" << endl;
		}
		else if (pos == 0) insertStart(data);
		else if (pos == this->size - 1) insertEnd(data);
		else
		{
			node<T>* element = new node<T>(data, this->goToElement(pos)->next);
			this->goToElement(pos) = element;
		}
		this->size++;
	}
}
template <class T>
void LList<T>::deleteStart()
{
	if (!this->isEmpty())
	{
		node<T>* temp = this->head;
		this->head = this->head->next;
		if (this->size == 1)
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		delete temp;
		this->size--;
	}
	else
	{
		   else cout << "Empty List[There is nothing to delete]" << endl;
	}
}
template <class T>
void LList<T>::deletePosition(int pos)
{
	if (!this->isEmpty())
	{
		if (pos == 0) this->deleteStart;
		else
		{
			node<T>* removed = this->goToElement(pos);
			node<T>* temp = this->goToElement(pos - 1);

			if (pos == this->size - 1) this->tail = temp;
			temp->next = removed->next;
			delete removed;
			this->size--;

		}
	}
}
template <class T>
void LList<T>::deleteEnd()
{
	if (!this->isEmpty())
	{
		if (this->tail)
		{
			this->deletePosition(this->size - 1);
		}
	}
	else cout << "Empty List[There is nothing to delete]" << endl;
}
template <class T>
T LList<T>::operator[](size_t index)
{
	if (index < 0 || index >= this->size)
	{

		cout << "Index can't be smaller than 0 or bigger than list length" << endl;
		return 0;
	}
	else this->goToElement(index)->data;
}
template <class T>
T LList<T>::getData(int index)
{
	return this->goToElement(index)->data;
}
template<class T>
int LList<T>::getSizeOfList()
{
	return this->size;
}
template <class T>
void LList<T>::copy(const LList<T>& other)
{
	node<T>* temp = other.getFirst();
	for (int i = 0; i < other.getSizeOfList(); i++)
	{
		this->insertEnd(temp->data);
		temp = temp->data;
	}
}
template <class T>
LList<T>::LList(const LList<T>& other)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
	this->copy(other);
}
template <class T>
void LList<T>::inIt()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}
template <class T>
void LList<T>::erase()
{
	for (int i = 0; i < this->size; i++)
	{
		this->deleteStart();
	}
	this->inIt;
}
template <class T>
bool LList<T>::isEmpty()
{
	return (this->head == nullptr) && (this->tail == nullptr);
}
template<class T>
LList<T>& LList<T>::operator=(const LList<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->inIt();
		this->copy(other);
	}
	return *this;
}
template <class T>
LList<T>::~LList()
{
	this->erase();
}
int main()
{

}
#include <iostream>
using namespace std;
template<typename T>
struct Node //konstruirame element koito ima data i pointer kon sledvashtiq element
{
    T data; //danni koito ima elementa
    Node<T>* next; //pointer 
    Node(const T& data,Node<T>* next = nullptr) //na nullptr ako v slucai nqma kade da sochi t.e nqma sledvasht element
    {
        this->data = data;
        this->next = next;
    }
};
template <typename T>
class Stack
{
private:
    Node<T>* first;
    size_t size;
    void copy(const Stack<T>& otherSt); //1->2->3
    void copyReverse(const Stack<T>& otherSt); //3->2->1
    void emptyStack();
    void inIt();
    bool isEmpty() const; //proverqva dali steka e prazen
public:
    Stack();
    Stack(const Stack& otherSt);
    Stack& operator=(const Stack& other);
    size_t length() const;
    T top() const;
    void pop();
    void push(const T& newData);
    ~Stack();
};
template <typename T>
Stack<T>::Stack()
{
    this->first = nullptr;
    this->size = 0;
}
template <typename T>
Stack<T>::Stack(const Stack& otherSt)
{
    this->inIt();
    this->copy(otherSt);
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& otherSt)
{
    if(this != otherSt)
    {
        this->emptyStack();
        this->inIt();
        this->copy(otherSt);
    }
    return *this;
}
template <typename T>
T Stack<T>::top() const //vrshta nai-gorniq element
{
    return this->first->data;
}
template <typename T>
void Stack<T>::push(const T& newData) //dobavq nov element
{
    Node<T>* add = new Node<T>(newData,this->first); 
    if(add)
    {
        this->first = add;
        this->size++;
    }

}
template <typename T>
void Stack<T>::pop() //premahva element
{
    if(!isEmpty())
    {
        Node<T>* element = this->first;
        this->first = this->first->next;
        delete element;
        this->size--;
    }
}
template <typename T>
size_t Stack<T>::length() const //vrshta dolzinata na steka t.e broq na elementite v steka
{
    return this->size;
}
template <typename T>
bool Stack<T>::isEmpty() const //proverqva dali steka e prazen
{
    return this->size == 0;
}
template <typename T>
void Stack<T>::copyReverse(const Stack& otherSt)
{
    Node<T>* node = otherSt.first; //pointer kon prviq element ot steka
    for(int i=0; i < otherSt.length(); i++)
    {
        this->push(node->data); //dobavqs element
        node = node->next; //samiq element go nasocvas kon sledvashtiq
    }
}
template <typename T>
void Stack<T>::copy(const Stack& otherSt)
{
    Stack<T> reverseStack;
    reverseStack.copyReverse(otherSt);
    this->copy(reverseStack);
}
template <typename T>
void Stack<T>::emptyStack() //prazni steka
{
    for(int i=0; i<= this->size; i++)
    {
        this->pop();
    }
}
template <typename T>
Stack<T>::~Stack()
{
    this->emptyStack();
}

int main()
{

    return 0;
}

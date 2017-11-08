#include <iostream>
using namespace std;
template<typename T>
struct Node
{
    T data;
    Node<T>* next;
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
    void copy(const Stack<T>& otherSt);
    void copyReverse(const Stack<T>& St);
    void emptyStack();
    void inIt();
    bool isEmpty() const;
public:
    Stack();
    Stack(const Stack& otherSt);
    Stack& operator=(const Stack& other);
    size_t length() const;
    T top() const;
    void pop();
    void push(const T& newElement);
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
void Stack<T>::push(const T& newElement) //dobavq nov element
{
    Node<T>* add = new Node<T>(newElement,this->first);
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
size_t Stack<T>::length() const
{
    return this->size;
}
template <typename T>
bool Stack<T>::isEmpty() const
{
    return this->size == 0;
}
template <typename T>
void Stack<T>::copyReverse(const Stack& otherSt)
{
    Node<T>* node = otherSt.first;
    for(int i=0; i < otherSt.length(); i++)
    {
        this->push(node->data);
        node = node->next;
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

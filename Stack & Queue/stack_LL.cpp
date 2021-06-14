#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack
{
    Node<T> *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T element)
    {
        Node<T> *n = new Node<T>(element);
        n->next = head;
        head = n;
        size++;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }

        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};

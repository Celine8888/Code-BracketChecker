#ifndef DSList_H
#define DSList_H

#include <iostream>

/**
 * @brief Singly-linked list that uses position
 *
 * Implement all described functions and provide a test program using CATCH2
 *
 * @tparam Object
 */
using namespace std;

template <typename Object>
class DSList
{
private:
    /**
     * @brief The nested Node data structure
     *
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };

    Node *head;

public:
    // You need to implement at least:
    // Default constructor
    DSList()
    {
        head = nullptr;
    }
    // Rule-of-3
    // destructor
    ~DSList()
    {
        Node *curr = nullptr;
        curr = head;
        head = nullptr;
        Node *temp = nullptr;
        while (curr != nullptr)
        {
            temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
    // copy constructor
    DSList(const DSList &rhs)
    {
        head = nullptr;
        Node *currRhs = rhs.head;
        if (rhs.head != nullptr)
        {
            head = new Node(currRhs->data);
            Node *currLhs = head;
            while (currRhs->next != nullptr)
            {
                currRhs = currRhs->next;
                currLhs->next = new Node(currRhs->data);
                currLhs = currLhs->next;
            }
            currLhs->next = nullptr;
        }
    }
    // copy assignment operator
    DSList &operator=(const DSList &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        // delete what was in lhs
        if (head != nullptr)
        {
            Node *curr = nullptr;
            curr = head;
            head = nullptr;
            Node *temp = nullptr;
            while (curr != nullptr)
            {
                temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        Node *currRhs = rhs.head;
        if (rhs.head != nullptr)
        {
            head = new Node(currRhs->data);
            Node *currLhs = head;
            while (currRhs->next != nullptr)
            {
                currRhs = currRhs->next;
                currLhs->next = new Node(currRhs->data);
                currLhs = currLhs->next;
            }
            currLhs->next = nullptr;
        }
        return *this;
    }
    // size
    size_t size() const
    {
        size_t size = 0;
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            size++;
        }
        return size;
    }
    // is the list empty?
    bool empty() const
    {
        return (head == nullptr);
    }
    // clear the whole list
    void clear()
    {
        Node *curr = nullptr;
        curr = head;
        head = nullptr;
        Node *temp = nullptr;
        while (curr != nullptr)
        {
            temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = nullptr;
    }
    // find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
    int find(const Object obj) const
    {
        int position = 0;
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            if (curr->data == obj)
            {
                return position;
            }
            position++;
        }
        return -1;
    }
    // insert at the beginning of the list (push_front).
    void push_front(const Object obj)
    {
        Node *temp = head;
        head = new Node(obj, temp);
    }
    // insert at the end of the list (push_back).
    void push_back(const Object obj)
    {
        Node *curr = head;
        if (curr == nullptr)
        {
            head = new Node(obj, nullptr);
        }
        else
        {
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = new Node(obj, nullptr);
        }
    }
    // remove the first element(pop_front)
    void pop_front()
    {
        if (head == nullptr)
        {
            cerr << "List is empty\n";
        }
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
    // remove the last element (pop_back)
    void pop_back()
    {
        if (head == nullptr)
        {
            cerr << "List is empty" << '\n';
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *currFront = head->next;
            Node *currBack = head;
            while (currFront->next != nullptr)
            {
                currFront = currFront->next;
                currBack = currBack->next;
            }
            delete currBack->next;
            currFront = nullptr;
            currBack->next = nullptr;
        }
    }
    void display() const
    {
        cout << "List content: \n";
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            cout << curr->data << '\n';
        }
    }
    Object top() const
    {
        return head->data;
    }
};

#endif

#pragma once

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class TwoWayList
{
private:

    Node* head;
    int size;

public:

    void Print()
    {
        Node* cur = this->head;

        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    void addElement(const int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty())
        {
            this->head = newNode;
        }
        else
        {
            Node* current = this->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
        this->size++;
    }

    void SetFirstElement(int value)
    {
        Node* newnode = new Node;
        newnode->data = value;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        this->head = newnode;
        this->size++;
    }

    void DeleteElement(int pos)
    {
        pos -= 2;

        Node* curr = this->head;

        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }

        Node* p = curr->next;
        curr->next = curr->next->next;
        curr->next->prev = curr;
        delete p;
    }

    int SearchElement(int pos)
    {
        pos--;

        if (pos > size)
        {
            throw out_of_range("pos is bigger than size");
        }
        Node* cur = this->head;

        for (int i = 0; i < pos; i++)
        {
            cur = cur->next;
        }

        return cur->data;
    }

    Node* GetHead()
    {
        return this->head;
    }


    TwoWayList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    TwoWayList(int value)
    {
        this->head = new Node;
        this->head->data = value;
        this->head->next = nullptr;
        this->head->prev = nullptr;
    }

    TwoWayList(const TwoWayList& list)
    {
        this->size = list.size;

        Node* cur = list.head;

        while (cur != nullptr)
        {
            this->pushFront(cur->data);
            cur = cur->next;
        }
    }

    TwoWayList(TwoWayList&& other)
    {
        Node* cur = other.head;

        while (cur != nullptr)
        {
            this->pushFront(cur->data);
            cur = cur->next;
        }

        other.clear();
    }

    TwoWayList& operator=(const TwoWayList& L)
    {
        Node* currThis = this->head;
        Node* currL = L.head;

        while (currL != nullptr && currThis != nullptr)
        {
            currThis->data = currL->data;

            currL = currL->next;
            currThis = currThis->next;
        }

        while (currL != nullptr)
        {
            pushFront(currL->data);
            currL = currL->next;
        }
    }

    TwoWayList& operator=(TwoWayList&& list)
    {
        Node* cur = list.head;

        while (cur != nullptr)
        {
            this->pushFront(cur->data);
            cur = cur->next;
        }

        list.clear();
    }

    void Sethead(Node* head)
    {
        this->head = head;
    }

    void SetSize(int size)
    {
        this->size = size;
    }

    int GetSize()
    {
        return this->size;
    }

    void pushFront(const int& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        size++;

        if (head->next != nullptr)
        {
            head->next->prev = head;
        }
    }

    void popFront() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    bool isEmpty() const {
        return (head == nullptr);
    }

    int getSize() const {
        return size;
    }

    int& front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    const int& front() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    ~TwoWayList()
    {
        clear();
    }
};

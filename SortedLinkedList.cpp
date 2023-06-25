/* File: SortedLinkedList.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementation of member functions for the Node class and SortedLinkedList class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#include <cstdlib>
#include <iostream>
#include "SortedLinkedList.h"

using namespace std;

// Implementation for the member functions of the Node class

Node::Node()
{
    next = NULL;
}

Node::Node(Card value)
{
    data = value;
    next = NULL;
}


// Implementation for the member functions of the SortedLinkedList class

//default constructor
SortedLinkedList::SortedLinkedList()
{
    head = NULL;
}

// insert a new node, which is a Card object to the list
// so that the nodes are in non-decreasing order of card values defined by poker game
// To maintain this order, the list needs to use insert() ONLY to add new node
void SortedLinkedList::insert(Card newcard)
{
    Node* newnode = new Node(newcard);
    Node* pre = NULL;
    Node* current = head;

    while (current!= NULL && newcard < current->data ) 
    {
        pre = current; 
        current = current->next;
    }
    if (current == head)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        pre->next = newnode;
        newnode->next = current;
    }
}

// remove the front node from the list
void SortedLinkedList::pop_front()
{
    if (size() == 0)
        cout << "Cannot remove from an empty list." << endl;
    else
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// return how many nodes in the list
int SortedLinkedList::size() const
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

// return true if the list is empty
// otherwise return false
bool SortedLinkedList::isEmpty() const
{
    return (size()==0);
}
// return a vector of nodes 
// which stores the nodes from the sorted list.
// provide flexible way to access the nodes in the list
vector<Card> SortedLinkedList::access() const
{
    vector<Card> nodes_in_list;
    Node* current = head;
    while (current != NULL)
    {
        nodes_in_list.push_back(current->data);
        current = current->next;
    }
    return nodes_in_list;
}


// display the nodes in the list from the front to the tail
void SortedLinkedList::print() const
{
    vector<Card> nodes = access();
    for (size_t i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i] << "\t";
    }
    cout << endl;
}

// The Law of BIG THREE
// the definition of copy constructor
// the definition of assignment operator
// the definition of destructor

// copy constructor
SortedLinkedList::SortedLinkedList(const SortedLinkedList& other)
{
    this->head = NULL;
    Node* other_cur = other.head;
    if (other.head != NULL)
    {
        Node* newnode = new Node(other.head->data);
        this->head = newnode;
        other_cur = other_cur->next;
        Node* current = this->head;
        while (other_cur != NULL)
        {
            Node* newnode = new Node(other_cur->data);
            current->next = newnode;
            current = current->next;
            other_cur = other_cur->next;
        }
    }   
}

// assignment operator 
SortedLinkedList& SortedLinkedList::operator=(const SortedLinkedList& other)
{
    // first check to avoid self assignment
    if (this != &other)
    {
        while (!isEmpty())
            pop_front();
        this->head = NULL;
        Node* other_cur = other.head;
        if (other.head != NULL)
        {
            Node* newnode = new Node(other.head->data);
            this->head = newnode;
            other_cur = other_cur->next;
            Node* current = this->head;
            while (other_cur != NULL)
            {
                Node* newnode = new Node(other_cur->data);
                current->next = newnode;
                current = current->next;
                other_cur = other_cur->next;
            }
        }   
    }
    return *this;
}

//destructor
SortedLinkedList::~SortedLinkedList()
{
    while (!isEmpty())
        pop_front();
}

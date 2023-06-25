/* File: SortedLinkedList.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: The declaration of the Node class and the SortedLinkedList class
 * Since these two classes have very closed relationship, we declare them in one header file
 * 
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <vector>
#include "card.h"

class Node
{
    public:
        Node();
        Node(Card value);
        friend class SortedLinkedList;
    private:
        Card data;
        Node* next;
};

class SortedLinkedList
{
    public:
        //default constructor
        SortedLinkedList();

        // insert a new node which is a Card object to the list
        // so that the nodes are in non-decreasing order of card values defined by poker game
        void insert(Card newcard);
        
        // remove the front node from the list
        void pop_front();

        // return how many nodes in the list
        int size() const;

        // return true if the list is empty
        // otherwise return false
        bool isEmpty() const;

        // return a vector of cards 
        // which stores the data of each node from the sorted list.
        // provide flexible way to access the data of each node in the list
        vector<Card> access() const;

        // display the nodes in the list from the front to the tail
        void print() const;

        // The Law of BIG THREE
        // the definition of copy constructor
        // the definition of assignment operator
        // the definition of destructor

        // copy constructor
        SortedLinkedList(const SortedLinkedList& other);

        // assignment operator 
        SortedLinkedList& operator=(const SortedLinkedList& other);

        //destructor
        ~SortedLinkedList();

    private:
        Node* head;  //point at the first node in the list
};

#endif 	/* SORTEDLINKEDLIST_H */

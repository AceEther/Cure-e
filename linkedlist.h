//Linkedlist.h
//Jim le
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "FlightRecord.h"
#include <iostream>

struct Node {
    FlightRecord data;
    Node* next;
    
    Node(FlightRecord record) : data(record), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;
    
public:
    LinkedList();
    ~LinkedList();
    
    void insert(FlightRecord record);
    void printAll();
    int getSize();
    Node* getHead();
};

#endif

//"LinkedList.h is a class that stores multiple FlightRecords in a chain. 
//Each record is in a Node, and each Node points to the next one. 
//The LinkedList keeps track of where the chain starts (head) and how many records are stored (size). 
//It has 4 main functions: add a record, print all records, get the count, and get the first record."
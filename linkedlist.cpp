//LinkedList.cpp
//Jim Le    
//Implementation of LinkedList class for storing flight records

#include "LinkedList.h"
#include <iomanip>

LinkedList::LinkedList() { //contructor runs    
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {          //Destructor
    Node* current = head;           //Starts first node
    while (current != nullptr) {     //looping while there are nodes
        Node* temp = current;       //save current node
        current = current->next;    // move to next node
        delete temp;           //delete the node saved
    }
    head = nullptr;      //set head to nothing 
    size = 0;          //set size to 0
}

void LinkedList::insert(FlightRecord record) {  //create new node
    Node* newNode = new Node(record);             //store pointer
    
    if (head == nullptr) {       //if list is empty(head is nullptr). (If this is the first record, make it the start of the list.)
        head = newNode;         //new node the head
    } else {
        Node* current = head;    //start head  
        while (current->next != nullptr) {    //go next next
            current = current->next;        //connect last node to current node together
        }                                   //(Find the end of the list and add the new node there)
        current->next = newNode;
    }
    size++;
}

void LinkedList::printAll() {
    if (head == nullptr) {                 // if list is empty
        std::cout << "No records in list." << std::endl;      //print no record in list
        return;
    }

    //Print a nice table header with column names.
    std::cout << "\n== ALL RECORDS ==" << std::endl;   //print header. 
    std::cout << std::left << std::setw(20) << "Carrier"   //Print carrir 20 character wide, left , setw(create columns)
              << std::setw(6) << "Year"   
              << std::setw(10) << "Airport"  
              << std::setw(15) << "Carrier Delays"
              << std::setw(12) << "NAS"     
              << std::setw(12) << "Security"
              << std::setw(15) << "Late Aircraft"
              << std::setw(15) << "Cancelled" << std::endl;
    std::cout << std::string(105, '-') << std::endl;    //105 dashes 
    
//Go through each record in the list and print it as a table row.
    Node* current = head;            //node = header
    while (current != nullptr) {      //loop through each node
        std::cout << std::left << std::setw(20) << current->data.carrier
                  << std::setw(6) << current->data.year
                  << std::setw(10) << current->data.airport
                  << std::setw(15) << current->data.carrierDelayCt
                  << std::setw(12) << current->data.nasDelayCt
                  << std::setw(12) << current->data.securityDelayCt
                  << std::setw(15) << current->data.lateAircraftCt
                  << std::setw(15) << current->data.cancelledFlights << std::endl;
        
        current = current->next;
    }
}

int LinkedList::getSize() {  //Tell me how many records are in the list
    return size; 
}

Node* LinkedList::getHead() {
    return head; //return a pointer to the first node 
}

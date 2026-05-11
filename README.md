CURE-E Project: Airline Delay Analysis

Author:Jim Le - CSCI 211 Data Structures - Spring 2026

Overview
This is a C++ program that analyzes airline delay data from 2013 to 2023. This program reads airline delay records from a file, stores them in a linked list data structure, and displays the information in an organized table format. The main goal is to help travelers understand which airlines are most reliable and help airlines identify where their delays are coming from.



The Problem
Every day, millions of people book flights, but many don't know which airlines are actually the most reliable. Travelers want to get to point A to point B efficently, and airlines need to understand what causes their delays so they can improve. This project was created to answer the question: which airlines are actually the most reliable.

The Solution
I built a program using a linked list data structure to solve this problem. A linked list is like a chain where each link holds one airline's delay information and points to the next airline. This approach allows the program to efficiently store and organize any number of airline records without needing to know the size ahead of time. The program reads 50 airline records from a data file, stores them in the linked list, and displays them in a clean, readable table format that travelers and airlines can use to make better decisions.

How It Works
The program has several key components. FlightRecord.h is a struct that stores one airline delay record, including the carrier name, year, airport code, and six different types of delay counts. LinkedList.h defines the LinkedList class and outlines what operations it can perform. LinkedList.cpp contains the actual implementation of these operations, including a constructor that creates an empty list, a destructor that cleans up memory, an insert function that adds new records to the end of the chain, and a printAll function that displays all records in a formatted table. Finally, main.cpp is the main program that reads the data file, parses each line, creates FlightRecord objects, inserts them into the linked list, and provides a menu for the user to view the data.

How to Use
To compile the program, I had to use a 3rd party website to run my code. The program will load 50 airline delay records and display a menu. Choose option 1 to view all the airline records in a table format, which shows the carrier name, year, airport, and all the different delay information. Choose option 2 to exit the program.

Conclusion
This CURE-E project demonstrates the importance of data structures in solving real-world problems. By using a linked list to organize and display airline delay data, the program provides valuable insights that can help both travelers and airlines make better decisions. The project taught me not only how to implement a linked list, but also how to think about problems systematically, manage memory properly, and write clean, organized code. I'm proud of what I accomplished and excited about the potential to expand this project in the future.


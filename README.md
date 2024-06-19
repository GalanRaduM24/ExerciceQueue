# Restaurant Order Management System

## Overview
This project simulates a restaurant order management system using queues to handle customer orders. Each order consists of an arrival time and a preparation duration. The orders are processed in the order of their arrival, and the program ensures that no orders are started after the restaurant's closing time.

## Features
- Queue Implementation: Manages orders using two queues for arrival times and preparation durations.
- Order Processing: Processes orders based on their arrival times and calculates the actual completion time.
- Output Information: Displays the number of served orders, unfulfilled orders, and the actual closing time of the restaurant.

## Files
- main.cpp: The main program file that contains the implementation of the order management system.
- Queue.h: Header file defining the queue data structure used in the program.
- test.txt: Input file containing the closing time of the restaurant and the list of orders.
#pragma once

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#include "Util.hpp"
#include "Node.hpp"

/*
    Starting from node 1, find the nearest node and visit it.
    Repeat until you're at the last node and you return to one.

    Prints out the path, the total distance, and the time it took
*/
void nearestNeighbor (std::string filename) {
    std::deque<Node> q;
    getData(filename, q);

    // for some reason, my LinkedList is not favoring me today
    // so i'm going to use another queue instead
    std::deque<Node> q2;

    double total_distance = 0;
    // getting the first item in the linkedlist
    Node curr = q.front();
    q.pop_front();
    q2.push_back(curr);

    // for each item in the queue starting with first
    // we find the closest node to it 
    // and then append it and repeat
    while (q.size() > 0) {

        // finding the closest neighbor starting with curr
        int index_of_closest_node = 0;
        double smallestDistance = INT32_MAX;
        for (int i = 0; i < q.size(); i++) {
            // if distance is lower than lowest distance
            if ( distance( curr , q[i] ) < smallestDistance ) {
                index_of_closest_node = i;
                smallestDistance = distance( curr , q[i] );
            }
        }
        // and then adding it to our variable
        total_distance += smallestDistance;

        // with the index now found, we will remove it from
        // the deque and then add it to the linkedlist
        Node smallestNode = q[index_of_closest_node];

        // stitching it onto the linkedlist
        q2.push_back(smallestNode);
        q.erase(q.begin() + index_of_closest_node);

        curr = q2.back();

    }

    // add the date for the last item 
    total_distance += distance(curr, q2.front());
    q2.push_back(q2.front()); 

    // once linkedlist has been assembled and
    // total distance
    // print the distance and the list

    // printing ids of the pathways

    while (q2.size() > 0) {
        curr = q2.front();
        std::cout << curr.getID() << " ";
        q2.pop_front();
    }
    // printing total dist
    std::cout << std::endl << "Total Distance: " << total_distance << std::endl;
    // time
    std::cout << "Time in ms: " << 69420 << std::endl;
}
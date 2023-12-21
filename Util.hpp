#pragma once

#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <cmath>

#include "Node.hpp"

// takes a line and splits it by spaces
// like the split() method in languages
// like python
std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> v;

    int lower = 0;
    for (int i =0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back( s.substr(lower, i - lower) );
            lower = i + 1;
        }
    }

    v.push_back( s.substr(lower, s.length() - lower) );

    return v;
}


// reads in a tsp file and will return all the coordinates int he order
// marshalling it into the vector
void getData(std::string filePath, std::deque<Node>& v) {
    std::ifstream file(filePath);
    
    // the files aren't neccesarily clean and have a lot of comments
    // so I skip lines until i reach NODE_COORD_SECTION
    std::string line;

    while (std::getline(file, line)) {
        // we're going to skip lines until we reach the node cord and
        // now we start reading in the lines
        std::size_t loc = line.find("NODE_COORD_SECTION");
        if (loc != std::string::npos) {
            break;
        }
    }

    while(std::getline(file,line)) {
        // if the data isn't a line of data
        // seperated by two spaces
        // 192 33.32 332
        // we will break
        std::size_t loc = line.find(" ");
        if (loc == std::string::npos) {
            break;
        }

        std::vector<std::string> data = split(line, " ");

        Node pair(std::stoi(data[0]), std::stod(data[1]), std::stod(data[2]), nullptr);
        v.push_back(pair);
    }

}

// prints the distance between
// two nodes
double distance(Node a, Node b) {
    return std::sqrt(
        std::pow(a.getX() - b.getX(), 2) +
        std::pow(a.getY() - b.getY(), 2)
    );
}
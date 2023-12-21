#include <iostream>

#include "Node.hpp"

Node::Node() {}

Node::Node(int id, double a, double b, Node* next) {
    this->id = id;
    this->x = a;
    this->y = b;
    this->next = next;
}

double Node::getX() {
    return this->x;
}

double Node::getY() {
    return this->y;
}

Node* Node::getNext() {
    return this->next;
}

int Node::getID() {
    return this->id;
}

void Node::setX(double x) {
    this->x = x;
}

void Node::setY(double y) {
    this->y = y;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setID(int ID) {
    this->id = ID;
}

void Node::print() {
    std::cout << "( ID:" << this-> id << " " <<  this->x << " , " << this->y << " )" << std::endl;
}
#pragma once

#include <iostream>

class Node {
    private:
        int id;
        double x;
        double y;
        Node* next = nullptr;
    public:
        Node() {}
        Node(int id, double a, double b, Node* next) {
            this->id = id;
            this->x = a;
            this->y = b;
            this->next = next;
        }

        double getX() {
            return this->x;
        }

        double getY() {
            return this->y;
        }

        int getID() {
            return this->id;
        }

        Node* getNext() {
            return this->next;
        }

        void setX(double x) {
            this->x = x;
        }

        void setY(double y) {
            this->y = y;
        }

        void setID(int ID) {
            this->id = ID;
        }

        void setNext(Node* next) {
            this->next = next;
        }

        void print() {
            std::cout << "( ID:" << this-> id << " " <<  this->x << " , " << this->y << " )" << std::endl;
        }
};
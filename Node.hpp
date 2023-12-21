#pragma once
class Node {
    private:
        int id;
        double x;
        double y;
        Node* next = nullptr;
    public:
        Node();
        Node(int id, double a, double b, Node* next);

        double getX();
        double getY();
        int getID();
        Node* getNext();

        void setX(double x);
        void setY(double y);
        void setID(int i);
        void setNext(Node* next);

        void print();
};
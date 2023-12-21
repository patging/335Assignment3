#include <iostream>
#include <vector>
#include <queue>

#include "NearestNeighbor.hpp"

#include "Node.hpp"
#include "Util.hpp"


int main() {

    // std::deque<Node> v;
    // getData("./dj38.tsp", v);
    // int j = v.size();
    // Node n;
    // for(int i = 0 ; i < j; i++) {
    //     n = v.front();
    //     v.pop_front();
    //     n.print();
    // }

    nearestNeighbor("./dj38.tsp");

    return 0;
}
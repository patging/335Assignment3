#include <string>
#include <queue>

#include "Node.hpp"
#include "Util.hpp"

void greedyTSP (std::string filename) {
    std::deque<Node> q;
    getData(filename, q);
}
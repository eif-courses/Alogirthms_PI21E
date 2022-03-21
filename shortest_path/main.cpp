// Dijkstra's Algorithm in C++

#include <vector>
#include <iostream>
//#include "CTurtle.hpp"

using namespace std;
constexpr static int INFINITY_NUM = 1000000;
//namespace ct = cturtle;
class Node {
public:
  explicit Node(char id);
  int distanceFromStart;
  char id;
  Node* previous;
};

class Edge {
public:
  Edge(Node* node1, Node* node2, int distance);
  bool Connects(Node* node1, Node* node2) const;
  Node* _node1{};
  Node* _node2{};
  int _distance{};
};

vector<Edge*> edges;
vector<Node*> nodes;

class Dijkstra {
public:
  static void DijkstrasTest();
  static void Dijkstras();
  static vector<Node*>* AdjacentRemainingNodes(Node* node);
  static Node* ExtractSmallest(vector<Node*>& nodes);
  static int Distance(Node* node1, Node* node2);
  static bool Contains(vector<Node*>& nodes, Node* node);
  static void PrintShortestRouteTo(Node* destination);
};

int main() {

  Dijkstra::DijkstrasTest();
  return 0;
}

Node::Node(char id) : id(id), previous(nullptr), distanceFromStart(INFINITY_NUM) {
  nodes.emplace_back(this);
}

Edge::Edge(Node *node1, Node *node2, int distance) : _node1(node1), _node2(node2), _distance(distance) {
  edges.emplace_back(this);
}

bool Edge::Connects(Node *node1, Node *node2) const {
  return ((node1 == _node1 && node2 == _node2) || (node1 == _node2 && node2 == _node1));
}

void Dijkstra::DijkstrasTest() {

  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* d = new Node('d');
  Node* e = new Node('e');
  Node* f = new Node('f');
  Node* g = new Node('g');

  Edge* e1 = new Edge(a, c, 1);
  Edge* e2 = new Edge(a, d, 2);
  Edge* e3 = new Edge(b, c, 2);
  Edge* e4 = new Edge(c, d, 1);
  Edge* e5 = new Edge(b, f, 3);
  Edge* e6 = new Edge(c, e, 3);
  Edge* e7 = new Edge(e, f, 2);
  Edge* e8 = new Edge(d, g, 1);
  Edge* e9 = new Edge(g, f, 1);

  a->distanceFromStart = 0;  // set start node
  Dijkstras(); // from global vectors
  PrintShortestRouteTo(f);
}

void Dijkstra::Dijkstras() {
  while (!nodes.empty()) {
    Node* smallest = ExtractSmallest(nodes);
    vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest);

    const size_t size = adjacentNodes->size();
    for (int i = 0; i < size; ++i) {
      Node* adjacent = adjacentNodes->at(i);
      int distance = Distance(smallest, adjacent) + smallest->distanceFromStart;

      if (distance < adjacent->distanceFromStart) {
        adjacent->distanceFromStart = distance;
        adjacent->previous = smallest;
      }
    }
    delete adjacentNodes;
  }
}

// Find the node with the smallest distance,
// remove it, and return it.
Node* Dijkstra::ExtractSmallest(vector<Node*>& nodes_param) {
  size_t size = nodes_param.size();
  if (size == 0) return nullptr;
  int smallestPosition = 0;
  Node* smallest = nodes_param.at(0);
  for (int i = 1; i < size; ++i) {
    Node* current = nodes_param.at(i);
    if (current->distanceFromStart < smallest->distanceFromStart) {
      smallest = current;
      smallestPosition = i;
    }
  }
  nodes_param.erase(nodes_param.begin() + smallestPosition);
  return smallest;
}

// Return all nodes adjacent to 'node' which are still
// in the 'nodes' collection.
vector<Node*>* Dijkstra::AdjacentRemainingNodes(Node* node) {
  auto* adjacentNodes = new vector<Node*>();
  const size_t size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    Node* adjacent = nullptr;
    if (edge->_node1 == node) {
      adjacent = edge->_node2;
    } else if (edge->_node2 == node) {
      adjacent = edge->_node1;
    }
    if (adjacent && Contains(nodes, adjacent)) {
      adjacentNodes->push_back(adjacent);
    }
  }
  return adjacentNodes;
}

// Return distance between two connected nodes
int Dijkstra::Distance(Node* node1, Node* node2) {
  const size_t size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    if (edge->Connects(node1, node2)) {
      return edge->_distance;
    }
  }
  return -1;  // should never happen
}

// Does the 'nodes' vector contain 'node'
bool Dijkstra::Contains(vector<Node*>& nodes_param, Node* node) {
  const size_t size = nodes_param.size();
  for (int i = 0; i < size; ++i) {
    if (node == nodes_param.at(i)) {
      return true;
    }
  }
  return false;
}
void Dijkstra::PrintShortestRouteTo(Node* destination) {
  Node* previous = destination;
  cout << "Distance from start: " << destination->distanceFromStart << endl;
  while (previous) {
    cout << previous->id << " ";
    previous = previous->previous;
  }
  cout << endl;
}


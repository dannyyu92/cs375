#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
  id = -1;
  priority = -1;
}

Node::Node(int idIn, int priorityIn) {
  id = idIn;
  priority = priorityIn;
}

bool Node::hasNoPriority() {
  if (priority == -1) {return true;}
  else {return false;}
}

bool Node::isEmpty() {
  if (id == -1) {return true;}
  else {return false;}
}

void Node::printNode() {
  cout << "id: " << id << endl;
  cout << "priority: " << priority<< endl;
}

void Node::setNode(int idIn, int priorityIn) {
  id = idIn;
  priority = priorityIn;
}

int Node::getID() {
  return id;
}

int Node::getPriority() {
  return priority;
}

void Node::setID(int idIn) {
  id = idIn;
}

void Node::setPriority(int priorityIn) {
  priority = priorityIn;
}

Node::~Node() {}

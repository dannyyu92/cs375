
class Node {
  public:
    Node();
    Node(int idIn, int priorityIn);
    int id;
    int priority;
    int getID();
    int getPriority();
    void setNode(int idIn, int priorityIn);
    void setID(int idIn);
    void setPriority(int priorityIn);
    void printNode();
    bool isEmpty();
    bool hasNoPriority();
    ~Node();
};
    
    

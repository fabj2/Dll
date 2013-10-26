
class Node 
{
private:
    int data;
    Node* prev;
    Node* next;

protected:

public:
    void setNext(Node* nn) { next = nn; }
    void setPrev(Node* pn) { prev = pn; }
    Node& getNext() const { return *next; }
    Node& getPrev() const { return *prev; }
    int getData() { return data;}
    void setData(int val) {data = val;}
};
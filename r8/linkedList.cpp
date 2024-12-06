#include <iostream>
#include <cassert>

struct Node {
    int val_;
    Node* next_;
    Node(int value) : val_(value), next_(nullptr) {}
};

class linkedList {
private:
    Node* head_;
public:
    friend void print(const linkedList&);
    linkedList() : head_(nullptr) {};
    ~linkedList()
    {
        while (head_)
        {
            Node* tmp = head_;
            head_ = head_->next_;
            delete tmp;
        }
    };
    void insert_back(int value)
    {
        Node* new_node = new Node(value);
        if (!head_)
        {
            head_ = new_node;
            return;
        }
        Node* it = head_;
        while (true) 
        {
            if (it->next_)
                it = it->next_;
            else 
            {
                it->next_ = new_node;
                break;
            }
        }
    }
};

void print(const linkedList& list) 
{
    Node* it = list.head_;
    while (it) 
    {
        std::cout << it->val_ << " ";
        it = it->next_;
    }
    std::cout << "\n";
}


int main() {
    linkedList list;
    list.insert_back(10);
    list.insert_back(20);
    list.insert_back(30);
    print(list);
    return 0;
}
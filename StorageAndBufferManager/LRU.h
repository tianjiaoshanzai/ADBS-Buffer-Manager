#pragma once

#include <unordered_map>

class LRU{
    struct Node {
        Node() = default;
        Node(int frame_id_in) : frame_id(frame_id_in) {}
        int frame_id;
        Node* prev, * next;
    };

public:
    LRU(int max_size);
    ~LRU();
    int Victim();
    //void Insert(int frame_id_in);
    void addFrame(int frame_id_in);
    void setFrame(int frame_id_in);
    void Remove(int frame_id_in);
    int Size();

private:
    inline void set_pointer(Node* p, Node* q) {
        p->next = q;
        q->prev = p;
    }

    void pop_node();
    void append_node(Node* new_node);

    std::unordered_map<int, Node*> map_;
    Node* head_, * tail_;
    int size_;
    int max_size_;
};
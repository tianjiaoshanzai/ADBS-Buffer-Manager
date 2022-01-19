#include"LRU.h"


LRU::LRU(int max_size) : max_size_(max_size) {
    size_ = 0;
    head_ = new Node();
    tail_ = new Node();
    head_->next = tail_;
    tail_->prev = head_;
}

LRU::~LRU() {
    Node* p = head_, * tmp;
    for (; p != nullptr; p = tmp) {
        tmp = p->next;
        delete p;
    }
}


int LRU::Victim() {
    if (size_ == 0)
        return -1;
    int ret;
    ret = head_->next->frame_id;
    pop_node();
    return ret;
}

void LRU::Insert(int frame_id) {
    auto iter = map_.find(frame_id);
    if (iter == map_.end()) {
        if (size_ == max_size_)
            pop_node();
        append_node(new Node(frame_id));
        return;
    }
    Node* tmp = iter->second;
    set_pointer(tmp->prev, tmp->next);
    size_--;
    append_node(tmp);
}

void LRU::Remove(int frame_id) {
    auto iter = map_.find(frame_id);
    if (iter == map_.end()) {
        return;
    }
    Node* tmp = iter->second;
    set_pointer(tmp->prev, tmp->next);
    map_.erase(frame_id);
    size_--;
    delete tmp;
}

int LRU::Size() {
    return size_;
}


void LRU::pop_node() {
    Node* tmp = head_->next;
    set_pointer(head_, tmp->next);
    map_.erase(tmp->frame_id);
    delete tmp;
    size_--;
}

void LRU::append_node(Node* new_node) {
    Node* tmp = tail_->prev;
    map_[new_node->frame_id] = new_node;
    set_pointer(tmp, new_node);
    set_pointer(new_node, tail_);
    size_++;
}
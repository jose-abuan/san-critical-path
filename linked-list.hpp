#pragma once

template<typename T>
class LinkedList{
    private:

    struct Node{
        T data;
        Node* next;
    };

    Node* head;

    public:
        LinkedList();

        // Push
        void push(T value);
        // Pop

};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr){}

template<typename T>
void push(T value){
            Node newNode = new Node{value, head};
            head = newNode;
        
}
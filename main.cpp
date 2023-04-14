#include <iostream>

using namespace std;

class EmptyQueue{};

class FullQueue{};

template <class ItemType>
class Queue{
    private:
        int front_, rare_;
        ItemType* items;
        int maxQue;
    public:
        Queue(){
            maxQue = 501;
            front_ = -1;
            rare_ = -1;
            items = new ItemType[maxQue];
        }

        Queue(int max_){
            maxQue = max_ +1;
            front_ = maxQue - 1;
            rare_ = maxQue + 1;
            items = new ItemType[maxQue];
        }
        ~Queue(){
            delete [] items;
        }
        void makeEmpty(){
            front_ = maxQue - 1;
            rare_ = maxQue - 1;
        }
        bool isEmpty(){
            return (front_ == rare_);
        }
        bool isFull(){
            return ((rare_+1)%maxQue) == front_;
        }
        void enqueue(ItemType newItem){
            if (isFull())
                throw FullQueue();
            else{
                rare_ = (rare_ + 1) % maxQue;
                items[rare_] = newItem;
            }
        }

        void dequeue(ItemType& item){
            if (isEmpty()){
                throw EmptyQueue();
            }
            else{
                front_ = (front_ + 1) % maxQue;
                item = items[front_];
            }
        }
};

int main()
{
    Queue<int> q1;
    q1.enqueue(65);
    return 0;
}

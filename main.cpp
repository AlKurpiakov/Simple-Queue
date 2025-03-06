#include "Simple_Queue.h"
#include "QueueTemplate.h"
#include <chrono>
#include <random>



int main(){
    SimpleQueue<int> Squeue(10000);
    QueueTemplate<int> Tqueue(10000);
    for (int i = 0; i < 10000 - 1; i++){
        Squeue.Push(rand());
        Tqueue.Push(rand());        
    }
    chrono::steady_clock::time_point Sbegin1 = chrono::steady_clock::now();
    chrono::steady_clock::time_point Send1 = chrono::steady_clock::now();
    
    chrono::steady_clock::time_point Tbegin1 = chrono::steady_clock::now();
    
    chrono::steady_clock::time_point Tend1 = chrono::steady_clock::now();


    chrono::steady_clock::time_point Sbegin2 = chrono::steady_clock::now();

    chrono::steady_clock::time_point Send2 = chrono::steady_clock::now();
    
    chrono::steady_clock::time_point Tbegin2 = chrono::steady_clock::now();
    
    chrono::steady_clock::time_point Tend2 = chrono::steady_clock::now();
    // queue.Push(2);
    // queue.Push(3);
    // queue.Push(4);
    // queue.Push(5);
    
    // for(int i = 0; i < 4; i++){
    //     cout << queue.Front() << "\n";
    //     cout << queue.Back() << "\n";
    //     queue.Pop();
    //     cout << "\n";
    // }

    // try { 
    //     queue.Pop();
    // }
    // catch (const char* e) {
    //     cout << e << "\n";
    // }

    return 0;
}

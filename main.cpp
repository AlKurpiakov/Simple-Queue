#include "Simple_Queue.h"

int main(){
    SimpleQueue<int> queue(100);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    queue.Push(5);
    
    for(int i = 0; i < 4; i++){
        cout << queue.Front() << "\n";
        cout << queue.Back() << "\n";
        queue.Pop();
        cout << "\n";
    }

    try { 
        queue.Pop();
    }
    catch (const char* e) {
        cout << e << "\n";
    }

    return 0;
}
#include<iostream>
#include<stack>
using namespace std ;


class node {
    public:
    int data ;
    node *next ;
};


class Queue {
    private :
        int capacity ;
        int size ;
        node *front, *rear;
    public :
    
        Queue(int capacity) {
            this -> capacity = capacity ;
            front = rear = nullptr ;
            size = 0 ;
        }
        
        int isEmpty() {
            if(size==0) {
                return 1 ;
            }
            else {
                return 0 ;
            }
        }
        
        
        void enque(int x) {
            
            if(size == 0) {
                    node *P = new node ;
                    P -> data = x ;
                    front = rear = P ;
                    P -> next = nullptr ;
                    P = nullptr ;
                    size++;
                }else{
                    node *P = new node ;
                    P -> data = x ;
                    rear -> next = P ;
                    rear = rear -> next ;
                    P -> next = nullptr ;
                    P = nullptr ;
                    size++;
                }
        }
        
        void deque() {
            node *temp ;
            temp = front ;
            front = front -> next ;
            delete temp ;
            size--;
        }
        
        int queue_first() {
            return rear->data ;
        }
        
        int queue_last() {
            return front->data ;
        }
        
        void display() {
            node *temp ;
            int i ;
            stack<int> st; 
            for(i=0,temp=front ; i<size ; i++, temp = temp->next) {
                st.push(temp->data);
            }
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }cout<<endl;
        }
        
};

int main() {
    Queue Q(3);
    Q.enque(10);
    Q.enque(20);
    Q.enque(30);
    Q.enque(40);
    Q.enque(50);
    Q.enque(60);
    Q.enque(70);
    Q.enque(80);
    Q.enque(90);
    Q.display();
     cout<<"First : "<<Q.queue_first()<<"  Last : "<<Q.queue_last()<<endl;
    Q.deque();
    Q.deque();
    Q.deque();
    Q.deque();
    Q.display();
     cout<<"First : "<<Q.queue_first()<<"  Last : "<<Q.queue_last()<<endl;
    Q.enque(40);
    Q.enque(50);
    Q.enque(60);
    Q.enque(70);
    Q.enque(80);
    Q.display();
    cout<<"First : "<<Q.queue_first()<<"  Last : "<<Q.queue_last()<<endl;
    
    
    return 0 ;
}




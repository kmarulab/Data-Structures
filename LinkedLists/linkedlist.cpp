#include <iostream>
#include <array>
using namespace std;

namespace dsa{
    template <typename T>
    class Node{
        
        public:
        //Properties
            T data;
            Node<T> *next;

        Node(): data(NULL), next(NULL){};
        Node(T x):data(x), next(NULL){};

        void setData(T data){
            this->data = data;
        }
        T getData(){
            return this->data;
        }

        void setNext(Node<T> *next){
            this->next = next;
        }

        T getNext(){
            return this->next;
        }
    };

    //linkedList Class
    template <typename T>
    class LinkedList{
        public:

            Node<T> *head;
            Node<T> *tail;
            int size;

            //constructor
            LinkedList(): head(NULL), tail(NULL), size(0){};

            //Functions

            //add to list
            void addToList(T data){
                //empty list
                Node<T>* newNode = new Node<T>(data);

                if(this->size==0){
                    this->head = newNode;
                    this->tail = newNode;
                    this->head->next = tail;
                    this->size++;
                } else{
                    this->tail->next = newNode;
                    this->tail = newNode;
                    this->size++;
                }
                
            }

            void insertFirst(T data){
                Node<T>* newNode = new Node<T>(data);
                newNode->next = this->head;
                this->head = newNode;
                newNode->data = data;
                this->size++;
            }

            void printList(){
                Node<T> *tempNode = this->head;

                while(tempNode->next!=NULL){
                    cout<<tempNode->data<<endl;
                    tempNode = tempNode->next;
                }

                cout<<tempNode->data<<endl;
            }
            int getSize(){
                return this->size;
            }
            T getLast(){
                return this->tail->data;
            }

            void removeFirst(){
                Node<T>* first = this->head;
                this->head = first->next;

                delete first; 
                this->size--;
            }

            T getFirst(){
                return this->head->data;
            }
    };
}

int main(){
    array<string, 5>  test = {"K", "E", "N", "Y", "A"};
    array<int, 5> test2 = {10,20,30,40,50};

    dsa::LinkedList<string> list1;
    
    for(string i: test){
        list1.addToList(i);
    }

    dsa::LinkedList<int> numbers;
    for(int i: test2){
        numbers.addToList(i);
    }

    
    numbers.printList();

    cout<<list1.getSize()<<endl;
    list1.addToList("Kennar");
    cout<<list1.getSize()<<endl;
    list1.insertFirst("Onyango");
    list1.printList();
    cout<<list1.getSize()<<endl<<list1.getLast()<<endl<<endl;
    // list1.removeFirst();
    list1.printList();
    cout<<endl<<list1.getFirst()<<endl;


}



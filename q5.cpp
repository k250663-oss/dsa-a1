#include<iostream>
using namespace std;
class Node{
public:
    int id;
    char name[30];
    char category[30];
    int price;
    Node* next;
    Node(int i ,char n[] ,char c[] ,int p){
        id = i;
        price = p;
        next = NULL;
        int j = 0;
        while(n[j]!= '\0'){
            name[j] = n[j];
            j++;
        }
        name[j] = '\0';
        j = 0;
        while(c[j] != '\0'){
            category[j] = c[j];
            j++;
        }      category[j] = '\0';
    }
};
class ProductList{
public:
    Node* head;
    ProductList(){
        head = NULL;
    }
    void insert(int id ,char name[] ,char category[] ,int price){
        Node* n = new Node(id ,name ,category ,price);
        if(head == NULL || id < head->id){
            n->next = head;
            head = n;
            return;
        }
        Node* temp = head;

        while(temp->next != NULL && temp->next->id < id){

            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){

            cout<<temp->id<<" "<<temp->name<<" "<<temp->category<<" "<<temp->price<<endl;

            temp = temp->next;
        }
    }
};

Node* merge(Node* a , Node* b){
    Node* head = NULL;
    Node* tail = NULL;

    while(a != NULL && b != NULL){

        Node* temp;

        if(a->id < b->id){
            temp = a;
            a = a->next;
        }

        else if(b->id < a->id){

            temp = b;
            b = b->next;
        }
        else{

            if(a->price <= b->price){

                temp = a;

                Node* del = b;
            a = a->next;
                b = b->next;
                delete del;
            }

            else{

                temp = b;

                Node* del = a;
                a = a->next;
                b = b->next;

                delete del;
            }
        }

        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    if(a != NULL){
        tail->next = a;
    }
    else{
        tail->next = b;
    }
    return head;
}
int count(Node* head){
    int c = 0;

    while(head != NULL){
        c++;
        head = head->next;
    }
    return c;
}

int total_price(Node* head){

    int total = 0;

    while(head != NULL){
        total += head->price;
        head = head->next;
    }

    return total;
}

int main(){

    ProductList Glowcare;
    ProductList Beautyhub;

    char n1[]= "Cream";
    char n2[]= "serum";
    char n3[]= "lotion";

    char c1[] ="skin";
    char c2[] ="face";
    char c3[] ="body";

    Glowcare.insert(1 , n1 , c1 , 500);
    Glowcare.insert(3 , n2 , c2 , 800);
    Beautyhub.insert(2 , n3 , c3 , 600);
    Beautyhub.insert(3 , n2 , c2 , 700);

    cout<<"GlowCare:"<<endl;
    Glowcare.display();
    cout<<endl;
    cout<<"BeautyHub:"<<endl;
    Beautyhub.display();
//ths will merge it:
    Node* master = merge(Glowcare.head , Beautyhub.head);

    cout<<endl;
    Node* temp = master;
    while(temp != NULL){

        cout<<temp->id<<" "<<temp->name<<" "<<temp->category<<" "<<temp->price<<endl;
        temp = temp->next;
    }

    cout<<"total products: "<<count(master)<<endl;
    cout<<"total cost: "<<total_price(master)<<endl;
}

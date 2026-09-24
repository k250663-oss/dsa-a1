#include<iostream>
using namespace std;
class Song{
public:
    char title[30];
    char genre[20];
    int duration;
    bool explicit_song;

    Song(char t[],char g[] ,int d ,bool e){

        int i = 0;
        while(t[i] != '\0'){
            title[i] = t[i];
            i++;
        }
        title[i] = '\0';
        i = 0;
        while(g[i] != '\0'){
            genre[i] = g[i];
            i++;
        }
        genre[i] = '\0';
        duration = d;
        explicit_song = e;
    }
};
class Node{
public:
    Song* song;
    Node* next;
    Node(Song* s){
        song = s;
        next = NULL;
    }
};
class Playlist{
public:
    Node* head;
    Playlist(){
        head = NULL;
    }
    int count(){
        int c = 0;
        Node* temp = head;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
    bool same_genre(Song* a , Song* b){
        int i = 0;

        while(a->genre[i] != '\0' && b->genre[i] != '\0'){
            if(a->genre[i] != b->genre[i]){
                return false;
            }
            i++;
        }

        return a->genre[i] == b->genre[i];
    }
    bool valid(Song* s ,int pos){

        Node* temp = head;

        for(int i = 0 ;i<pos ; i++){
            temp = temp->next;
        }
        if(pos > 0){

            Node* prev = head;
            for(int i = 0 ; i<pos-1 ; i++){
                prev = prev->next;
            }

            if(same_genre(prev->song , s)){
                return false;
            }
        }
        if(temp != NULL){
            if(same_genre(temp->song , s)){
                return false;
            }
        }

        return true;
    }

    void insert(Song* s , int pos){
        int total = count();

        int newpos = -1;
        for(int i = pos ; i<=total ; i++){

            if(valid(s , i)){
                newpos = i;
                break;
            }
        }

        if(newpos == -1){
            cout<<"invalid position"<<endl;
            return;
        }

        Node* n = new Node(s);

        if(newpos == 0){
            n->next = head;
            head = n;
            return;
        }

        Node* temp = head;

        for(int i = 0 ; i<newpos-1 ; i++){
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
    }

    void search(char title[]){
        Node* temp = head;

        while(temp != NULL){

            int i = 0;
            bool found = true;

            while(title[i] != '\0' ||temp->song->title[i] != '\0'){
                if(title[i] != temp->song->title[i]){
                    found = false;
                    break;
                }

                i++;
            }

            if(found){
                cout<<"song found"<<endl;
                return;
            }

            temp = temp->next;
        }
        cout<<"song not found"<<endl;
    }

    void delete_at(int pos){

        if(pos < 0 || pos >= count()){
            cout<<"invalid position"<<endl;
            return;
        }

        Node* del;

        if(pos == 0){

            del = head;

            if(del->song->explicit_song){
                cout<<"make song non-explicit first"<<endl;
                return;
            }

            head = head->next;

            delete del->song;
            delete del;

            return;
        }

        Node* temp = head;

        for(int i = 0 ; i<pos-1 ; i++){
            temp = temp->next;
        }

        del = temp->next;

        if(del->song->explicit_song){
            cout<<"make song non-explicit first"<<endl;
            return;
        }

        temp->next = del->next;

        delete del->song;
        delete del;}

    void display(){

        Node* temp = head;
        while(temp != NULL){

            cout<<temp->song->title<<" "<<temp->song->genre<<" "<<temp->song->duration<<endl;

            temp = temp->next;
        }
    }
};

int main(){

    Playlist p;

    char t1[] = "S1";
    char g1[] = "g1";
    char t2[] = "S2";
    char g2[] = "g2";
    char t3[] = "S3";
    char g3[] = "g3";

    Song* s1 = new Song(t1 , g1 , 200 , false);
    Song* s2 = new Song(t2 , g2 , 180 , false);
    Song* s3 = new Song(t3 , g3 , 150 , false);
    p.insert(s1 , 0);
    p.insert(s2 , 1);
    p.insert(s3 , 2);

    p.display();
}

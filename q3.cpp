#include<iostream>
using namespace std;
//comb sort

void comb_sort(int arr[] , int size){
    int gap = size;
    bool swap = true;
    while(gap != 1 || swap){
        gap = gap/1.3;
        if(gap<1){
            gap = 1;
        }
            swap = false;
        
        for(int i = 0 ; i+ gap<size ; i++){
            if(arr[i]>arr[i+gap]){
                int x = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = x;
                swap = true;
            }
        }
    }

}
int main(){
    int arr[] = { 2 , 9 , 3 , 7 , 1};
    int size = 5;
    comb_sort(arr , size);
    for(int i = 0 ; i< size  ; i++){
        cout<<arr[i]<<" ";
    }
}
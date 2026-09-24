#include<iostream>
using namespace std;
//85 , 42 , 120  , 35 , 67 , 50
//insertion sort

void insertion_sort(int arr[] , int size){
    for (int i = 0 ; i<size ; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0 ; j--){
            if(temp<arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main(){
    int arr[] = {85 , 42 , 120 , 35 , 67 , 50};
    int size = 6;
    insertion_sort(arr , 6);
    for(int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
}
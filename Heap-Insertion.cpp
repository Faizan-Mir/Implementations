#include<bits/stdc++.h>
using namespace std;


class heap{
    
    public: 
      
      int arr[100]; 
      int size; 
      
      heap(){
          arr[0]=-1;
          size =0; 
      }
      
      
      
      void insert(int data){
          size = size+1;
          int current = size;
          arr[current]= data;
          
          while(current !=1){
              if(arr[current]>arr[current/2]){
                 swap(arr[current], arr[current/2]); 
              }
              else{
                  return; 
              }
          }
      }
      
      
      void print(){
          for(int i=1; i<=size; i++){
              cout<<arr[i]<<" ";
          }
          cout<<endl; 
      }
};

int main(){
    
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    
    h.print(); 
    
    
    return 0; 
}

#include<bits/stdc++.h>
using namespace std;


// Generation of PN Sequences using Feedaback Shift Registor Method. 
int main()
{

cout<<"Input N, Where 2^N is the number of bits in the PN Sequence"<<endl;
int N;
cin>>N;


vector<int> arr(N);
vector<int> pn; 


// Initial State

cout<<"Enter the Initital State of the FSR"<<endl;
for(int i=0; i<N; i++){
    cin>>arr[i]; 
}

pn.push_back(arr[0]); 

cout<<"States of the FSR"<<endl; 
for(int i=0; i<N; i++){
    cout<<arr[i]<<" "; 
}
cout<<endl; 




for(int i=0; i<pow(2,N)-2; i++){

    
    int temp = arr[2]^arr[3]; 
    pn.push_back(temp); 
    
    for(int j=N-1; j>=0; j--){
        arr[j] = arr[j-1];
    }
    
    arr[0] = temp; 
    
    for(int k=0; k<N; k++){
        cout<<arr[k]<<" "; 
    }
    cout<<endl; 
    
}


cout<<"PN Sequence"<<endl; 
for(int i=0; i<pn.size(); i++){
    cout<<pn[i];
}


return 0; 
} 

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Input the Message for User 1 (Same size as Message of User 2)
    string message1 = "tech";
     vector<string> message1_vector;
    for (int i = 0; i < message1.size(); i++) {
       string temp =  bitset<8>(message1[i]).to_string(); 
       cout<<temp<<endl; 
       message1_vector.push_back(temp);  
    }
    
    
    // Input the Message for User 2 (Same Size as Message of User 1)
    string message2 = "film";
     vector<string> message2_vector;
    for (int i = 0; i < message2.size(); i++) {
       string temp =  bitset<8>(message2[i]).to_string(); 
       message2_vector.push_back(temp);  
    }
    
    // PN Sequence for User 1 PN1= 100010011010111
       vector<int> PN1 = {1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1};
    // PN Sequence for User 2 PN1=111100010011010
       vector<int> PN2 = {1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1}; 
       
     // Total number of symbols are message size * 8 
     cout<<" User 1 Message: "<<message1<<endl;
     cout<<" User 2 Message: "<<message2<<endl; 
     
     vector<vector<vector<int>>> CDMA_message(message1.size(), vector<vector<int>>(8, vector<int>(15))); 
     cout<<"CDMA Transmitted Message:"<<endl; 
     for(int word_no = 0; word_no<message1_vector.size(); word_no++){
         // For each word
         
         for(int bit_no =0;bit_no<8; bit_no++){
             // for each bit (symbol)
             vector<int> transmit(15); 
             int symbol1 = int(message1_vector[word_no][bit_no] -'0'); 
             if(symbol1 == 0) symbol1 =-1;
             int symbol2 = int(message2_vector[word_no][bit_no]-'0');
             if(symbol2 ==0 ) symbol2 =-1; 
             
             vector<int> pn1(15);
             vector<int> pn2(15); 
             for(int i=0; i<15; i++){
       pn1[i] = PN1[i]*symbol1;
       pn2[i] = PN2[i]*symbol2;
       transmit[i]= pn1[i]+pn2[i]; 
       cout<<transmit[i]; 
   }
        CDMA_message[word_no][bit_no] = transmit;      
         }
         
         
         
     }
       
       
// Receiving the CDMA Message
cout<<endl; 
cout<<"Decoded CDMA Message"<<endl; 

vector<vector<int>> decoded(CDMA_message.size(), vector<int> (8)); 

for(int word_no = 0; word_no<CDMA_message.size(); word_no++){
    // for each word 
    for(int bit_no =0; bit_no<8; bit_no++){
        // for each bit
        int sum1 =0;
        for(int i=0; i<15; i++){
            sum1+= PN1[i] * CDMA_message[word_no][bit_no][i]; 
        }
        if(sum1>0) sum1=1;
        else sum1=0; 
        decoded[word_no][bit_no] = sum1; 
        cout<<sum1; 
    }
    cout<<endl; 
}
 
    return 0;
}

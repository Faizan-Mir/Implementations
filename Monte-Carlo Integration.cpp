#include<bits/stdc++.h>
using namespace std;


double func(double x){
        
        return sin(x); 
    }
    
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(){
    
    double l=0; // Lower Limit
    double r=10; // Upper Limit
    int N =1000; // No of samples
    
    
double Integral=0;

for(int i=0; i<N; i++){
    
   double x_random = fRand(l,r);  
    Integral += func(x_random);
    
}
    
    Integral = (r-l)*Integral/N; 
 cout<<Integral; 
    return 0; 
}

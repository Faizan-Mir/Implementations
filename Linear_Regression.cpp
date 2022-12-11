#include<bits/stdc++.h>
using namespace std;

int main(){
    // Linear Regression 
    
    vector<double> x = {1,2,3,4,5,6,7,8,9};
    vector<double> y(x.size());
    for(int i=0; i<x.size(); i++){
        y[i]= 12*x[i]+15; 
    }
  //  vector<double> y = {2,4,6,8,10,12,14,16,18}; 
    
    double a1=0; // Summation of x^2
    double b1=0; // Summation of x
    double c1;  // Summation of xy
    
    for(int i=0; i<x.size(); i++){
        a1 += pow(x[i],2);
        b1 += x[i];
        c1 += x[i]*y[i]; 
    }
    
    double a2=0; // Summation of x^2
    double b2=x.size(); // Summation of x
    double c2;  // Summation of xy
    
    for(int i=0; i<x.size(); i++){
        a2 += x[i];
        c2 += y[i]; 
    }
    
    double res_x;
    double res_y; 
    
    
    if ((a1 * b2) - (b1 * a2) == 0){
    cout << "The system has no solution." << endl;
}
else{
    res_x = ((c1*b2) - (b1*c2))/((a1*b2)-(b1*a2));
    res_y = ((a1*c2) - (c1*a2)) / ((a1*b2) - (b1*a2));
}


cout<<"Prediction: "<<res_x<<"x + "<<res_y;     
    
    
    
    
    
    
    return 0; 
}

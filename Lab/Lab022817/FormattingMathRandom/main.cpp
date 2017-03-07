/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 28, 2017, 11:22 AM
 * Purpose:  Utilize math and formatting libraries
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float fuVal,  //Future value from savings $'s
          prsVal, //Present value in savings $;s
          invRate;//Investment Rate or Interest Rate %
    unsigned short numCPer;//Number of compounding periods (years)
          
    //Initialize variables
    prsVal=4.99999e3f;
    invRate=6e-2f;
    numCPer=7.2e-1f/invRate;//Rule of 72

    //Map inputs to outputs or process the data
    fuVal=prsVal*pow((1+invRate),numCPer);
    
    //Output the transformed data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Interest rate            =  "<<invRate*100<<"%"<<endl;
    cout<<"Years left in savings    =  "<<numCPer<<"(yrs)"<<endl;
    cout<<"Present value in savings = $"<<setw(8)<<prsVal<<endl;
    cout<<"Future value (power)     = $"<<setw(8)<<fuVal<<endl;
    
    //Map inputs to outputs or process the data
    fuVal=prsVal*exp(numCPer*log(1+invRate));
    
    //Output the transformed data
    cout<<"Future value (exp & log) = $"<<setw(8)<<fuVal<<endl;
    
    //Shows relationship between multiplication and logs with addtion
    float op1=4,op2=5,prod;
    prod=op1*op2;
    cout<<"Product of "<<op1<<"*"<<op2<<"               ="<<prod<<endl;
    prod=exp(log(op1)+log(op2));
    cout<<"Product of exp(log("<<op1<<")+log("<<op2<<"))="<<prod<<endl;
    
    //Exit stage right!
    return 0;
}


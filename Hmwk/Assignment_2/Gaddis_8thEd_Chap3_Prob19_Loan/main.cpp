/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 2nd, 2017, 11:52 AM
 * Purpose:  Calculate Loan Parameters
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PERCENT=100.0f;//Percent conversion
const float CNVYRMN=12.0f; //Year to month conversion

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float consRec,//What the consumer receives $'s
          mthPay; //Monthly Payment $'s
    int   intRate,//Yearly percentage interest Rate
          nMonths;//Number of months in the loan
    
    //Input data
    cout<<"This program calculates Loan Parameters"<<endl;
    cout<<"Input the loan amount to be received $";
    cin>>consRec;
    cout<<"Number of months in the loan ";
    cin>>nMonths;
    cout<<"Interest rate % = ";
    cin>>intRate;
    
    //3 different ways to write the same equation
    //First way breaks the equation up
    float i=intRate/CNVYRMN/PERCENT;//Intermediate Calculation of interest rate
    float temp=pow((1+i),nMonths);  //Intermediate Calculation of (1+i)^n
    mthPay=i*temp*consRec/(temp-1); //Amortized monthly payment -> True method
    //Second way writes it all in 1 line
    mthPay=intRate/CNVYRMN/PERCENT*pow((1+intRate/CNVYRMN/PERCENT),nMonths)
            *consRec/(pow((1+intRate/CNVYRMN/PERCENT),nMonths)-1);
    //Third way uses variable names as short as possible
    float n=nMonths;//Use shorter names for variables
    float l=consRec;//Use shorter names for variables
    mthPay=i*pow(1+i,n)*l/(pow(1+i,n)-1);
    
    //Output the transformed data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Loan amount received = $"<<consRec<<endl;
    cout<<"Number of monthly payments = "<<nMonths<<endl;
    cout<<"Interest rate = "<<intRate<<"%"<<endl;
    cout<<"Monthly Payment = $"<<mthPay<<endl;
    
    //Exit stage right!
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 12 2017, 2:00 PM
 * Purpose:  Calculate interest due, total amount due, and minimum payment.
 *           
 *           
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    
    float   acntbal,    //Account balance
            intdue,     //Interest due
            totdue,     //Total amount due
            minpymt;    //Minimum payment
    char    ans;        //User's answer
    
    do
    {
    //Initialize variables
    
    cout<<"Enter your account balance in dollars:"<<endl;
    cin>>acntbal;
   
    //Input data
    cout<<setprecision(2)<<fixed;
    
    if(acntbal>1000)
        intdue = 1000*0.015f + (acntbal - 1000)*0.01f;
    else
        intdue = acntbal*0.015;
    
    //Map inputs to outputs or process the data
    
    totdue = acntbal + intdue;
    
    if (totdue*0.1 > 10)
        minpymt = totdue*0.1;
    else
        minpymt = 10;
     
   
    //Output the transformed data
    cout<<"Your interest due is $"<<intdue<<endl;
    cout<<"Your total amount due is $"<<totdue<<endl;
    cout<<"Your minimum payment is $"<<minpymt<<endl;
    
    cout<<"Would you like to continue? Press Y or y for yes"<<endl;
    cin>>ans;
            
    } while (ans=='Y' || ans=='y');
    
    //Exit stage right!
    return 0;
}

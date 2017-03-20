/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 19 2017, 3:00 PM
 * Purpose:  Determine which of two number is larger
 *           
 *           
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int num1, num2;//The two numbers the user needs to input.
 
    //Initialize variables
    cout<<"Please enter two numbers."<<endl;
    cin>>num1;
    cin>>num2;
           
    //Input data
    
    (num1>num2) ?
        cout<<"The first number is larger than the second."<<endl:
        cout<<"The first number is smaller than the first"<<endl;
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

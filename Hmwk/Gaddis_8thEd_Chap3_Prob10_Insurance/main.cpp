/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 8, 2017, 9:00 PM
  Purpose:  Find the minimum amount of insurance user should buy given
 *          the replacement cost of the building
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants


//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float repCost,      //Replacement cost of building
            minAmnt;    //Minimum amount of insurance
    //Input values
    
    cout<<"Please enter the replacement cost of the building"<<endl;
    cin>>repCost;
    
    //Process by mapping inputs to outputs
    
    minAmnt = repCost*0.8f;
    
    //Output values
    
    cout<<"The minimum amount of insurance is $"<<minAmnt<<endl;

    //Exit stage right!
    return 0;
}

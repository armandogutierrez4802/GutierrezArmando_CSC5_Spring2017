/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 5, 2017, 7:00 PM
  Purpose:  Rewrite a compilable program to adhere to correct programming style.
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
    
    float Radius,   //Radius of the sphere
          Volume;     //Volume of the sphere
    
    //Input values
    
    cout<< "Enter radius of a sphere."<<endl;
    cin>> Radius;
    
    //Process by mapping inputs to outputs
    
    Volume = (4.0/3.0)*3.1415*Radius*Radius*Radius;//Volume of sphere equation
    
    //Output values
    
    cout<< " The volume is "<< Volume <<endl;

    //Exit stage right!
    return 0;
}

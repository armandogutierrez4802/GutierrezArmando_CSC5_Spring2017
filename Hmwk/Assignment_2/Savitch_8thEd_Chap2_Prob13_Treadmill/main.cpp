/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 5, 2017, 6:30 PM
  Purpose:  To convert miles per hour(mph) to minutes per mile.
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
    
    float min_mil,    //Minutes per mile
          mph,        //Miles per hour
          sec;        //Seconds
   
  
    
    
    //Input values
    cout<<"Enter your speed in miles per hour"<<endl;
    cin>>mph;
    
    
    //Process by mapping inputs to outputs
    
    min_mil = (1/mph)*60;
    
    int min = static_cast<int>(min_mil);
    
    sec = (min_mil-min)*60;
    
    //Output values
    
    cout<<"Your pace is "<<min<<" minutes and "<<sec<<" seconds per mile"<<endl;

    //Exit stage right!
    return 0;
}
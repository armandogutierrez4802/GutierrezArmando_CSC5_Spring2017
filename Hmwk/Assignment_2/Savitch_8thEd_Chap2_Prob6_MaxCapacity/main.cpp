/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 4, 2017, 4:06 PM
  Purpose:  To determine whether or not a meeting room is in violation
 *          of fire law regulations regarding maximum room capacity.
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
    
    int MaxCap,   //Maximum capacity for the meeting room
        nPeople,  //Number of People to attend the meeting
        come,     //Number of people that can still attend(if under max capacity)
        leave;    //Number of people that need to leave for meeting to be held
    
  
    //Input values
    cout<<"Please enter how many people will be attending the meeting"<<endl;
    cin>>nPeople;
   
   MaxCap = 350;
    come=MaxCap-nPeople;
    leave=nPeople-MaxCap;
    
    //Process by mapping inputs to outputs
    if (nPeople>MaxCap)
    {
        cout<<"Sorry, the meeting cannot be held as planned due to fire "
              "regulations."<<endl;
        cout<<leave<<" people need to leave for the meeting to be held."<<endl;
    }
    else
    { 
        cout<<"It is legal to hold the meeting."<<come<<" people may still"
              " attend the meeting"<<endl;
         
       
    }
    //Output values

    //Exit stage right!
    return 0;
}
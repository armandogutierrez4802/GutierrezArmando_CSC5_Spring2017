/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 8, 2017, 9:00 PM
  Purpose:  To all the user to repeat a pay increase
 *          calculation as many times as they want.
 */

//System Libraries
#include <iostream>
using namespace std;


//Global Constants
const float increas=0.076f; //Pay increase


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    
    float currSal,      //Current Annual Salary
          newSal,       //New Annual Salary
          nmthSal,      //New Monthly Salary
          due;          //Pay due to the employee as result of the raise
    char  ans;          //User's answer to repeat calculation
            
    //Input values
    do
    {
          cout<<"Enter your current salary."<<endl;
          cin>>currSal;
 
    //Process by mapping inputs to outputs
          due = currSal*increas/2;
          newSal = currSal*(1+increas);
          nmthSal = newSal/12.0f;
    
    //Output values
          cout<<"Current annual salary due = $"<<due<<endl;
          cout<<"New annual salary = $"<<newSal<<endl;
          cout<<"New monthly salary = $"<<nmthSal<<endl;
          
          cout<<"Would you like to repeat calculation with "
                "different values? 'Y' for yes or 'N' for no:"<<endl;
          cin>>ans;
    }     while(ans=='Y'|| ans=='y');
                  
          
    //Exit stage right!
    return 0;
}

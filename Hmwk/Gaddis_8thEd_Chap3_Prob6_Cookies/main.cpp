/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 4, 2017, 4:06 PM
  Purpose:  
 */

//System Libraries
#include <iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float csug=1.5/48.0f,//Cups of sugar per cookie
          cbut=1/48.0f,//Cups of butter per cookie
          cflr=2.75/48.0f,//Cups of flour per cookie
          sugar,//Cups of sugar to make cookies
          butter,//Cups of butter to make cookies
          flour;//Cups of flour to make cookies
    int ncookie;//Number of cookies user wants to make
    
    //Input values
    cout<<"How many cookies would you like to make"<<endl;
    cin>>ncookie;
    
    //Process by mapping inputs to outputs
    cout<<fixed<<setprecision(2);
    sugar = ncookie*csug;
    butter = ncookie*cbut;
    flour = ncookie*cflr;
    
    
    //Output values
     cout<<"The ingredients to make "<<ncookie<<" cookies are:"<<endl;
    cout<<sugar<<" cups of sugar"<<endl;
    cout<<butter<<" cups of butter"<<endl;
    cout<<flour<<" cups of flour"<<endl;
  

    //Exit stage right!
    return 0;
}

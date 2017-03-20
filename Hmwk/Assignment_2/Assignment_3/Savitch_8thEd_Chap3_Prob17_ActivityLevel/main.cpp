/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 7th, 2017, 10:00 PM
 * Purpose:  To update the user's BMR based on activity level
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and initialize variables
    char sex, actlev;                 //M or F, Activity Level
    unsigned short ht,wt,age; //height(in), weight(lbs), age(yrs)
    unsigned char cdyCals=230;//Candy bar calories
    float bmr;  //Basic Metabolic Rate (calories)
    int nCdyBrs;//Number of candy bars we can eat
 
    //Input data
    cout<<"This program calculates the number of ";
    cout<<"candy bars allowed per day based upon your BMR"<<endl;
    cout<<"Type in your Sex(M/F),Wt(lbs),Ht(in),Age(yrs)"<<endl;
    cout<<"Inputs are integer based"<<endl;
    cin>>sex>>wt>>ht>>age;
    
    //Map inputs to outputs or process the data
    if (sex=='M')
         bmr=66 + 6.3f*wt + 12.9f*ht - 6.8f*age;
    else
        bmr=655 + 4.3f*wt +  4.7f*ht - 4.7f*age;
    
    
     cout<<"What is your activity level: Sedentary, Somewhat Active, Active, "
            "or Highly Active"<<endl;
    cin>>actlev;
    
    if (actlev=='Sedentary'||'sedentary')
        bmr = 1.2*bmr;
    if (actlev=='Somewhat Active'||'somewhat active'||'Somewhat active')
        bmr = 1.3*bmr;
    if (actlev=='Active'||'active')
        bmr=1.4*bmr;
    if (actlev=='Highly Active'||'highly active'||'Highly active')
        bmr=1.5*bmr;
    
    
    nCdyBrs=static_cast<int>(bmr/cdyCals);
    
    //Output the transformed data
    cout<<"The number of candy bars you can eat = "<<nCdyBrs<<endl;
    
    
    
    //Exit stage right!
    return 0;
}

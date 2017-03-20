/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 13 2017, 11:00 PM
 * Purpose:  To determine whether or not a sphere will float or sink.
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
    float   buFc,     //Buoyant Force
            objwt,     //Weight of Object
            radius,    //Radius of sphere
            volume,    //Volume of Submerged Object
            spWt=62.4f;//Specific Weight of fluid in lb/cubic feet
    
    //Initialize variables
    cout<<"Enter the weight of sphere in pounds"<<endl;
    cin>>objwt;
    
    cout<<"Enter radius of the sphere in feet"<<endl;
    cin>>radius;
  
    //Input data
    volume = (4.0/3.0f)*3.14f*radius*radius;
    buFc = volume * spWt;
    
  
    //Map inputs to outputs or process the data
    cout<<"Volume ="<<volume<<endl;
    cout<<"Buoyant force ="<<buFc<<endl;
   
    
    
    //Output the transformed data
    if(objwt<=buFc)
        cout<<"The sphere will float"<<endl;
    else
        cout<<"The sphere will sink"<<endl;
    
    //Exit stage right!
    return 0;
}


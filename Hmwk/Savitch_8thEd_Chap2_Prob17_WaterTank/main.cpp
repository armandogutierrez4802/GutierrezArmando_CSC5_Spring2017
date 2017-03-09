/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 5, 2017, 7:15 PM
  Purpose:  To find the number of gallons of water in a water
 *          well of a particular radiues and depth.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
float cft_gal = 7.48f,  //Cubic feet to gallons conversion
      ft_in = 1/12.0f;  //Ft to inch conversion

//Executable code begins here!!!
int main(int argc, char** argv) {
    
    //Declare Variables
    float radius,           //Radius of water well
          depth,            //Depth of water well
          volume,           //Volume of water well
          galWtr;          //gallons of water in well
    
    //Input values
    cout<<"This program calculates gallons of water in a cylindrical "
          "water well"<<endl;
    cout<<"Enter radius:"<<endl;
    cin>>radius;
    cout<<"Enter depth:"<<endl;
    cin>>depth;
    
    //Process by mapping inputs to outputs
    
    radius = radius*ft_in;
    
    volume = 3.14159*radius*radius*depth;   //Calculate volume
    
    galWtr = volume*cft_gal;    //Convert volume to gallons
    
    
    //Output values
    
    cout<<"The volume of the well is "<<volume<<endl;
    cout<<"the number of gallons of water in the well is "<<galWtr<<endl;
    
    //Exit stage right!
    return 0;
}
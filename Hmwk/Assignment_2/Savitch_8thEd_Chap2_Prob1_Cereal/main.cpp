/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 4, 2017, 6:53 PM
  Purpose:  To output weight of cereal package from ounces to metric tons,
 *          and find number of boxes needed to yield 1 metric ton of cereal.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float oz_Ton = 1/35273.92f;   //Ounce to metric ton conversion

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float Wtoz, //Weight of package of cereal in ounces
          WtTon,//Weight of package of cereal in metric tons
          numbox;//Number of boxes to make one metric ton
    char ans;   //The user's answer to continue/ repeat or not.
            
    //Input values
    do
    {
    
    cout<<"Enter weight of cereal package in ounces:"<<endl;
    cin>>Wtoz;
    
    
    //Process by mapping inputs to outputs
    
    WtTon = Wtoz*(oz_Ton);
    numbox = 35273.92/Wtoz;
    
    
    //Output values
    cout<<"The weight of the packages in metric tons is "<<WtTon<<endl;
    
    cout<<"The number of boxes to reach 1 metric ton is "<<numbox<<endl;
    cout<<"If you wish to continue, press 'y' for yes or 'n' for no"<<endl;
    cin>>ans;
    } while ( ans=='y' || ans=='Y');
    
    cout<<"Good-bye"<<endl;

    //Exit stage right!
    return 0;
}

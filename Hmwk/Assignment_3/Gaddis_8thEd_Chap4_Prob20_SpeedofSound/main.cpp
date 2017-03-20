/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 18 2017, 3:00 PM
 * Purpose:  To calculate time it will take for sound to travel
 *           
 *           
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float speed, dist, time;//Speed in ft/sec, Distance in feet, time in sec
   
    int choice;//The user's choice

    //Iitialize Variables
    do
    {
    cout<<fixed<<setprecision(4);
    cout<<"Enter the number for the corresponding medium"<<endl;
    cout<<"1. Air"<<endl;
    cout<<"2. Water"<<endl;
    cout<<"3. Steel"<<endl;
    cin>>choice;
    
    //Input Data
    switch(choice)
    {
    case 1:
        speed=1100;//Speed of sound through air in feet per second
        cout<<"Please enter the distance it traveled"<<endl;
        cin>>dist;
        if(dist>0)
        {
        time = dist/speed;
        cout<<"The time it will take is "<<time<<endl;
        }
        else
            cout<<"Invalid Entry"<<endl;
        break;
        
    case 2:
        speed=4900;//Speed of sound through water in feet per second
        cout<<"Please enter the distance it traveled"<<endl;
        cin>>dist;
        if(dist>0)
        {
        time = dist/speed;
        cout<<"The time it will take is "<<time<<endl;
        }
        else
            cout<<"Invalid Entry"<<endl;
        break;
        
    case 3:
        speed=16400;//Speed of sound through steel in feet per second
        cout<<"Please enter the distance it traveled"<<endl;
        cin>>dist;
        if(dist>0)
        {
        time = dist/speed;
        cout<<"The time it will take is "<<time<<endl;
        }
        else
            cout<<"Invalid Entry"<<endl;
    }
    }while(choice==1||choice==2||choice==3);
      
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}



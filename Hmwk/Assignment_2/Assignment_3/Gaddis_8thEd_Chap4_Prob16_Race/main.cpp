/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March  2017, :00 PM
 * Purpose:  Declare first, second, and third place of runners
 *           
 *           
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <string>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    string runner1, runner2, runner3;//The three runners' names
    float time1, time2, time3;//The three times
    
    //Initialize variables
    cout<<"Please enter the name of runners 1, 2, and 3 in that order"<<endl;
    cin>>runner1;
    cin>>runner2;
    cin>>runner3;
    
    //Input data
    cout<<"Only enter positive time values for the following"<<endl;
    cout<<"Enter "<<runner1<<"'s time in seconds to finish the race"<<endl;
    cin>>time1;
    if (time1<0)
    {  cout<<"Enter a positive time value!"<<endl;
        cin>>time1;
    }
    
    cout<<"Enter "<<runner2<<"'s time in seconds to finish the race"<<endl;
    cin>>time2;
    if (time2<0)
    {
        cout<<"Enter a positive time value!"<<endl;
        cin>>time2;
    }
   
        cout<<"Enter "<<runner3<<"'s time in seconds to finish the race"<<endl;
    cin>>time3;
    if (time3<0)
    {   
        cout<<"Enter a positive time value!"<<endl;
        cin>>time3;
    }
    
    //Map inputs to outputs or process the data
    if(time1<time2)
    {
        if(time2<time3)
        {
            cout<<"First Place: "<<runner1<<endl;
            cout<<"Second Place: "<<runner2<<endl;
            cout<<"Third Place: "<<runner3<<endl;
        }
        else
        {
            if(time1<time3)
            {
            cout<<"First Place: "<<runner1<<endl;
            cout<<"Second Place: "<<runner3<<endl;
            cout<<"Third Place: "<<runner2<<endl;
            }
            else
            {
            cout<<"First Place: "<<runner3<<endl;
            cout<<"Second Place: "<<runner1<<endl;
            cout<<"Third Place: "<<runner2<<endl;
            }
        }  
    }
    else
    {
        if(time1<time3)
        {
            cout<<"First Place: "<<runner2<<endl;
            cout<<"Second Place: "<<runner1<<endl;
            cout<<"Third Place: "<<runner3<<endl;
        }
        else
        {
            if(time2<time3)
            {
            cout<<"First Place: "<<runner2<<endl;
            cout<<"Second Place: "<<runner3<<endl;
            cout<<"Third Place: "<<runner1<<endl;
            }
            
            else 
            {
            cout<<"First Place: "<<runner3<<endl;
            cout<<"Second Place: "<<runner2<<endl;
            cout<<"Third Place: "<<runner1<<endl;
            }
        }
        
    }
    
    //Exit stage right!
    return 0;
}

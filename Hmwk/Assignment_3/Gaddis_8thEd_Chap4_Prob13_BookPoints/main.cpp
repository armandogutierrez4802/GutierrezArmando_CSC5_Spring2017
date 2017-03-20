/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 19 2017, 8:00 PM
 * Purpose:  Show the user the number of award points they have in a book club
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
    int bkpnts,//Book Points
        numbks,//Number of books purchased by the user
        awdpnts;//Award points
    
    //Initialize variables
    cout<<"This program shows you the number of points you earn"<<endl;
    cout<<"Input the number of books purchased this month"<<endl;
    cin>>numbks;
   
    //Map inputs to outputs or process the data
    
    if (numbks==0)
        cout<<"You have earned 0 points this month"<<endl;
    if (numbks==1)
        cout<<"You have earned 5 points this month"<<endl;
    if (numbks==2)
        cout<<"You have earned 15 points this month"<<endl;
    if (numbks==3)
        cout<<"You have earned 30 points this month"<<endl;
    if (numbks>=4)
        cout<<"You have earned 60 points this month"<<endl;
   
    
    //Exit stage right!
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on March 17 2017, 3:00 PM
 * Purpose:  Caclulate area of a circle, rectangle, or triangle.
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
    float area, radius, length, width, base, height;
    int choice;//User's choice
    
    //Initialize variables
    
    do 
    {
        cout<<"This program caclulates the area of a geometrical figure"<<endl;
        cout<<"Enter a number 1-4 correseponding to the figure you would like"
          " to find the area of"<<endl;
        cout<<"1. Circle"<<endl;
        cout<<"2. Rectangle"<<endl;
        cout<<"3. Triangle"<<endl;
        cout<<"4. None of the above"<<endl;
        cin>>choice;
    
    
    //Input data     
    switch (choice)
    {
    case 1:
        cout<<"Enter the radius of the circle"<<endl;
        cin>>radius;
        if (radius>0)
        {    
        area=3.14*radius*radius;
        cout<<"The area of the circle is "<<area;
        }
        else
            cout<<"Invalid Entry"<<endl;
        break;
        
    case 2: 
        cout<<"Enter the length and width of the rectangle"<<endl;
        cin>>length;
        cin>>width;
        if (length>0 && width>0)
        {
            area=length*width;
            cout<<"The area of the rectangle is "<<area<<endl;   
        }
        else
            cout<<"Invalid Entry"<<endl;
        break;
        
    case 3:
        cout<<"Enter the length of the base and height of the triangle"<<endl;
        cin>>base;
        cin>>height;
        if(base>0 && height>0)
        {
            area = .5*base*height;
        cout<<"The area of the triangle is "<<area<<endl;
        }
        else
            cout<<"Invalid Entry"<<endl;
        } 
    } while (choice==1||choice==2||choice==3);
    
   
                
        
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 21, 2017, 11:32 AM
 * Purpose:  Calculate the percentage budget
 *           for the military and nasa
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PERCENT=100.0f;//Percentage
const float BILLION=1.0e9f;//Conversion to Billions
const float TRILION=1.0e12f;//Conversion to Trillions

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float fedBudg=3.54e12f;   //3.54 Trillion $'s 2016 Fed Budget
    float milBudg=0.580e12f;  //580 Billion   $'s 2016 DOD Budget
    float nasaBud=18.5e9f;    //18.5 Billion  $'s 2016 NASA Budget
    float perMil,perNasa;     //Percentage budget
    
    //Map inputs to outputs or process the data
    perMil=milBudg/fedBudg*PERCENT;
    perNasa=nasaBud/fedBudg*PERCENT;
    
    //Output the transformed data
    cout<<"Federal Budget  = $"<<fedBudg/TRILION<<" trillion"<<endl;
    cout<<"Military Budget = $"<<milBudg/BILLION<<" billion"<<endl;
    cout<<"NASA Budget     = $"<<nasaBud/BILLION<<" billion"<<endl;
    cout<<"Military Budget percentage = "<<perMil<<"%"<<endl;
    cout<<"Nasa Budget percentage     = "<<perNasa<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}


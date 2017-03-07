/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 21, 2017, 11:32 AM
 * Purpose:  Calculate the per person debt and percentage increase
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PERCENT=100.0f;//Percentage
const float MILLION=1.0e6f;//Conversion to Billions
const float TRILION=1.0e12f;//Conversion to Trillions

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float fDt2008=9.7e12f;    //9.7 Trillion   $'s 2008 Fed Debt
    float fDt2016=20.e12f;    //20. Trillion   $'s 2016 Fed Debt
    float pop2008=304e6f;     //304 Million    Population in 2008
    float pop2016=322e6f;     //322 Million    Population in 2016
    float per2008,per2016;    //Personal Debt
    float perChng,mulChng;    //Percentage and multiplicative change
    float ppChng;             //Per person change in debt
    
    //Map inputs to outputs or process the data
    per2008=fDt2008/pop2008;
    per2016=fDt2016/pop2016;
    perChng=(fDt2016-fDt2008)/fDt2008*PERCENT;
    mulChng=fDt2016/fDt2008;
    ppChng=(per2016-per2008)/per2008*PERCENT;
    
    //Output the transformed data
    cout<<"Federal Debt 2008  = $"<<fDt2008/TRILION<<" trillion"<<endl;
    cout<<"Federal Debt 2016  = $"<<fDt2016/TRILION<<" trillion"<<endl;
    cout<<"US Population 2008 =  "<<pop2008/MILLION<<" million"<<endl;
    cout<<"US Population 2016 =  "<<pop2016/MILLION<<" million"<<endl;
    cout<<"Percentage change in debt     = "<<perChng<<"%"<<endl;
    cout<<"Multiplicative change in debt = "<<mulChng<<"x"<<endl;
    cout<<"Per person debt in 2008 = $"<<per2008<<endl;
    cout<<"Per person debt in 2016 = $"<<per2016<<endl;
    cout<<"Per person % change in debt = "<<ppChng<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
  File:   main.cpp
  Author: Armando Gutierrez
  Created on March 4, 2017, 4:06 PM
  Purpose:  
 */

//System Libraries
#include <iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float rate=16.78f,          //Pay rate
          gPay,                 //Gross Pay
          SStax,           //Social Security tax
          Fedtax,          //Federal income tax
          SItax,          //State Income tax
          netPay;               //Net Pay
              
    int numdp,            //Number of dependents
        hrsWkd,           //Hours worked  
        udues=35;         //union dues
    
    //Input values
    cout<<fixed<<setprecision(2);
    cout<<"How many hours did you work last week?"<<endl;
    cin>>hrsWkd;
    
    if (hrsWkd>40)
        gPay = 40*rate + 1.5f*rate*(hrsWkd-40);
    else
        gPay = hrsWkd*rate;
    
    SStax = 0.06f*gPay;
    Fedtax = 0.14f*gPay;
    SItax = 0.05f*gPay;
    
    
    
    cout<<"How many dependents do you have?"<<endl;
    cin>>numdp;
    
    if(numdp>=3)
    {   netPay = gPay - SStax - Fedtax - SItax - udues - 10;
    }
    else
    {   netPay = gPay - SStax - Fedtax - SItax - udues;
    }
   
    //Output values
    cout<<"Your gross pay is = $"<<gPay<<endl;
    cout<<"Social Security Tax = $"<<SStax<<endl;
    cout<<"Federal Income Tax = $"<<Fedtax<<endl;
    cout<<"State Income Tax = $"<<SItax<<endl;
    cout<<"Union dues = $"<<udues<<endl;
    cout<<"Your net pay = $"<<netPay<<endl;
    cout<<"Thank you"<<endl;
    //Exit stage right!
    return 0;
}

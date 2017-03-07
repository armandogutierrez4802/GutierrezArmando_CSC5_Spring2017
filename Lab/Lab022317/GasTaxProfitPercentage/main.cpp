/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 23, 2017, 11:32 AM
 * Purpose:  Calculate the Tax and Profit Percentage
 *    References:  http://watchdog.org/232083/california-gas-taxes/
 *                 http://www.forbes.com/2011/05/10/oil-company-earnings.html
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PERCENT=100.0f;//For percentage calculation

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float fedTax=0.184f, //Federal Tax cents per gallon
          caTax=0.390f,  //California excise tax cents per gallon
          cpTax=0.100f,  //California cap and trade tax cents per gallon
          caSlsTx=0.08f, //California sales tax = 8% of base price
          oilPrft=0.07f;  //Oil company profit cents per gallon
    float pumpPr,basePr; //Pump and base price in $'s
    float pctTax,pctPrft;//Percentage tax, Percentage profit
    
    //Input data
    cout<<"What price did you pay at the pump $'s/gallon $";
    cin>>pumpPr;
    
    //Map inputs to outputs or process the data
    basePr=(pumpPr-fedTax-caTax-cpTax)/(1+caSlsTx);
    pctTax=(basePr*caSlsTx+fedTax+caTax+cpTax)/basePr*PERCENT;
    pctPrft=oilPrft/basePr*PERCENT;
    
    //Output the transformed data
    cout<<"Federal tax/gallon          = $"<<fedTax<<endl;
    cout<<"California tax/gallon       = $"<<caTax<<endl;
    cout<<"Cap and trade tax/gallon    = $"<<cpTax<<endl;
    cout<<"California sales tax/gallon = $"<<caSlsTx*basePr<<endl;
    cout<<"Base Price/gallon           = $"<<basePr<<endl;
    cout<<"Oil company profit/gallon   =  "<<pctPrft<<"%"<<endl;
    cout<<"Total percentage tax/Gallon =  "<<pctTax<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}


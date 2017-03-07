/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 *
 * Created on March 7, 2017, 12:01 PM
 * Purpose: Calculate # of candy bars
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Declare Variables and Initialize variables
    char sex; //M or F
    unsigned short ht,wt,age;//height(inches),weight(lbs),age(years)
    unsigned char cdyCals=230;//Candy bar calories
    float bmr;//Basal metabolic rate(calories)
    int nCdyBrs;//Number of cany bars we can eat
    
    //Input data
    
    cout<<"This program calculates the number of "
          "candy bars allowed per day based on your BMR"<<endl;
    cout<<"Type in your sex(M/F), Wt(lbs), Ht(in),Age(yrs)"<<endl;
    cout<<"Inputs are integer based"<<endl;
    cin>>sex>>wt>>ht>>age;
    
    //Process data
    
    bmr = (sex=='M')?
        66 + 6.3f*wt + 12.9f*ht - 6.8f*age:
        655 + 4.3f*wt + 4.7f*ht - 4.7*age;
    nCdyBrs = static_cast<int>(bmr/cdyCals);
    
    //Outputs transformed data
    cout<<"The number of candy bars you can eat = "<<nCdyBrs<<endl;
    
    
    
    
    
    return 0;
}


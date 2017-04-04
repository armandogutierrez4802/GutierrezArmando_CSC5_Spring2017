/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on April 3rd, 2017, 8:00 PM
 * Purpose: Assignment 4 Switch Menu
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random number generator
#include <ctime>     //Set the random number seed
#include <iomanip>   //Formatting
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
float LITER=.264179;//How many gallons in one liter
float PERCENT=100.0f;//Percent conversion
const float MSSERTH=5.972e27f;  //Mass of earth in grams
const float GCONST=6.673E-8f;   //Gravitational Constant cm^3/gm sec^2
const float CNVFTCM=1.0f/30.48f;//Conversion from ft to cm
const float CNVMFT=5280.0f;     //Conversion from miles to feet
const float RADERTH=3959;       //Radius of the Earth in miles

//Function Prototypes
float inflation(float price1, float price2);//For Problem 6
float mpg(int miles, int liters);//For problem 7
float Max(float num1, float num2);//For Problem 9
float Max(float num1, float num2, float num3);//For Problem 9



//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char choice;
    
    //Show menu and loop
    do{
        //Display Menu
        cout<<endl<<endl<<"Type any letter to exit"<<endl;
        cout<<"Type 0 for Gaddis_8thEd_Chap5_Prob2_AsciiCode"<<endl;
        cout<<"Type 1 for Gaddis_8thEd_Chap5_Prob8_MathTutor"<<endl;
        cout<<"Type 2 for Gaddis_8thEd_Chap5_Prob_16_AccountBalance"<<endl;
        cout<<"Type 3 for Gaddis_8thEd_Chap5_Prob17_SalesBarChart"<<endl;
        cout<<"Type 4 for Gaddis_8thEd_Chap5_Prob19_BudgetAnalysis"<<endl;
        cout<<"Type 5 for Gaddis_8thEd_Chap5_Prob_20RandNumGuessGame"<<endl;
        cout<<"Type 6 for Savitch_8thEd_Chap4_Prob4_Inflation"<<endl;
        cout<<"Type 7 for Savitch_8thEd_Chap4_Prob1_MPG"<<endl;
        cout<<"Type 8 for Savitch_8thEd_Chap4_Prob7_CheckWeight"<<endl;
        cout<<"Type 9 for Savitch_8thEd_Chap4_Prob12_MaxNumber"<<endl<<endl;
       
        //Input the choice
        cout<<"Problem ";
        cin>>choice;
        
        //Place solutions to problems in switch statement
        switch(choice){
            case '0':{
                //Declare the ascii limit
                int limit=127;

                //Map inputs to outputs or process the data
                for(int i=0;i<=limit;i++){
                    cout<<static_cast<char>(i);
                    if(i%16==15)cout<<endl;
                }
                break;
            }
            
            case '1':{
                            //Set the random number seed
                srand(static_cast<unsigned int>(time(0)));

                //Declare variables
                int op1,op2,result,answer;
                char choice;

                //Input data
                do{
                    cout<<"Math Tutor"<<endl;
                    cout<<"Choose the operation * / + - "
                          "or anything else to exit"<<endl;
                    cin>>choice;
                    cout<<endl<<endl;
                    if(!(choice=='+'||choice=='-'||choice=='/'||choice=='*')){
                        cout<<"Exit the Math Tutor"<<endl;
                        exit(0);
                    }

                    //Map inputs to outputs or process the data
                    switch(choice){
                        case '+':{
                            op1=rand()%900+100;//[100-999]
                            op2=rand()%900+100;//[100-999]
                            answer=op1+op2;//[3 to 4 digit result]
                            break;
                        }
                        case '-':{
                            op1=rand()%900+100;//[100-999]
                            op2=rand()%900+100;//[100-999]
                            answer=op1-op2;//[0 to 3 digit result]
                            break;
                        }
                        case '*':{
                            op1=rand()%90+10;//[10-99]
                            op2=rand()%90+10;//[10-99]
                            answer=op1*op2;//[2 to 4 digit result]
                            break;
                        }
                        case '/':{
                            answer=rand()%90+10;//[10-99]
                            op2=rand()%90+10;//[10-99]
                            op1=answer*op2;//[2 to 3 digit result]
                            break;
                        }
                        default:{
                            cout<<"Bad operator"<<endl;
                            return 1;
                        }
                    }

                    //Output the transformed data
                    cout<<setw(8)<<op1<<endl;
                    cout<<choice<<setw(7)<<op2<<endl;
                    cout<<"--------"<<endl;
                    cin>>result;

                    //Compare the answer
                    cout<<endl;
                    cout<<((result==answer)?"Correct":"Incorrect")<<endl;
                    cout<<"The answer = "<<answer<<endl<<endl;
                }while(choice=='+'||choice=='-'||choice=='/'||choice=='*');
                
                break;
            }
            
            case '2':{
                //Declare variables
                float aRate,//Annual Rate
                      mRate,//Monthly Rate
                      amntDep,//Amount Deposited
                      amntWtd,//Amount Withdrawn
                      numMnth,//Number of months 
                      stBal,//Starting balance
                      multply;//

                //Initialize variables
                cout<<"Enter annual interest rate"<<endl;
                cin>>aRate;
                cout<<"Enter starting balance"<<endl;
                cin>>stBal;
                cout<<"Enter the number of months the account has been active"<<endl;
                cin>>numMnth;  

                //Map inputs to outputs or process the data
                for (int i=1; i<=numMnth; i++){
                    cout<<"Enter amount deposited for month "<<i<<endl;
                    cin>>amntDep;
                    stBal+=amntDep;//Update the starting balance

                    cout<<"Enter amount withdrawn for month "<<i<<endl;
                    cin>>amntWtd;
                    stBal-=amntWtd;//Update the starting balance

                    //Apply the monthly interest to the starting balance
                    cout<<fixed<<setprecision(2)<<endl;
                    mRate=aRate/12;
                    multply=(mRate*stBal)/12;
                    stBal+=multply;
                }


                //Output the transformed data
                cout<<"Your ending balance is "<<stBal<<endl;
            
                break;
            }
            
            case '3':{
                //Declare variables
                int store1,store2,store3,store4,store5;//Sales of each 5 stores

                //Initialize variables
                cout<<"Enter the sales for each store."<<endl;
                cout<<"Store 1: "<<endl;
                cin>>store1;
                cout<<"Store 2: "<<endl;
                cin>>store2;
                cout<<"Store 3: "<<endl;
                cin>>store3;
                cout<<"Store 4: "<<endl;
                cin>>store4;
                cout<<"Store 5: "<<endl;
                cin>>store5;

                //Output the sales bar chart
                cout<<"SALES BAR CHART"<<endl<<endl;
                cout<<"Each * represents $100"<<endl<<endl; 

                //Calculate store 1
                store1=store1/100;
                cout<<"Store 1: ";
                for(int i=1;i<=store1;i++){
                    cout<<"*";
                }
                cout<<endl;

                //Store 2
                store2=store2/100;
                cout<<"Store 2: ";
                for(int i=1;i<=store2;i++){
                    cout<<"*";
                }
                cout<<endl;

                //Store 3
                store3=store3/100;
                cout<<"Store 3: ";
                for(int i=1;i<=store3;i++){
                    cout<<"*";
                }
                cout<<endl;

                //Store 4
                store4=store4/100;
                cout<<"Store 4: ";
                for(int i=1;i<=store4;i++){
                    cout<<"*";
                }
                cout<<endl;

                //Store 5
                store5=store5/100;
                cout<<"Store 5: ";
                for(int i=1;i<=store5;i++){
                    cout<<"*";
                }
                cout<<endl;
            
                break;
            }
            
            case '4':{
                 //Declare variables
                 float total=0,//Total amount in expenses
                  expense,//Individual expense
                         budget;// Monthly budget
                     int numExp;//Number of expenses       
                     
                    //Initialize variables      
                     cout<<"Please enter you monthly budget"<<endl;
                     cin>>budget;
                     cout<<"How many expenses do you have?"<<endl;
                     cin>>numExp;
                     
                      for (int i=1; i<=numExp;i++){
                          cout<<"Enter expense "<<i<<endl;
                          cin>>expense;
                          total+=expense;
                      }
                    
                    //Output the transformed data
                     if(total>budget)
                         cout<<"You are over budget"<<endl;
                     else
                         cout<<"You are under budget"<<endl;
                     
                     
                     
                         
                         
                break;
            }
            
            case '5':{
                //Set the random number seed
                srand(static_cast<unsigned int>(time(0)));

                //Declare variables
                int number,guess;//The random number, and user's guess


                //Input data
                cout<<"This is a guessing game."<<endl;
                cout<<"The program will end when you guess correctly"<<endl;

                do{
                number=rand()%19+1;//Initialize the random number
                cout<<"Enter a number between 1 and 20"<<endl;
                cin>>guess;

                //Output the data
                if(number==guess)
                    cout<<"Good job"<<endl;
                
                if(number>guess)
                    cout<<"Too low. Try again"<<endl;
                if(number<guess)
                    cout<<"Too high. Try again"<<endl;

                cout<<"The correct answer was "<<number<<endl<<endl;

                }while(number!=guess);
                
                break;
            }
            
            case '6':{
                //Declare variables

                float price1,//Price of item one year ago
                        price2,//Current price of item
                    rateInf;//Rate of inflation
                char choice;

                do {

                //Initialize variables
                cout<<"How much was the cost of your item 1 year ago"<<endl;
                cin>>price1;
                cout<<"How much does it cost now?"<<endl;
                cin>>price2;

                //Output the transformed data
                cout<<fixed<<setprecision(2)<<endl;
                rateInf = inflation(price1,price2);
                cout<<"Rate of inflation is "<<rateInf*PERCENT<<" percent"<<endl;
                cout<<"To repeat the calculation press 'Y' or 'y'."<<endl;
                cin>>choice;

                }while(choice=='Y'||choice=='y');
                            break;
                        }
            
            case '7':{
                //Declare variables
                int miles, liters;
                char choice;

                do{
                //Initialize variables
                cout<<"Enter number of liters of gasoline used by car"<<endl;
                cin>>liters;
                cout<<"Now enter number of miles traveled by car"<<endl;
                cin>>miles;

                //Output the transformed data
                cout<<"Your car gets "<<mpg(miles,liters)<<" miles per gallon"<<endl;

                cout<<"To repeat calculation, press 'Y' or 'y'."<<endl;
                cin>>choice;
                }while (choice=='Y'||choice=='y');

                break;
            }
            
            case '8':{
                 //Declare variables
                 float myWeight;//Result in lbs
                 float myMass=6;//Units of slugs

                //Map inputs to outputs or process the data
                //F=G*M1*M2/D^2
                myWeight=GCONST*CNVFTCM*CNVFTCM*CNVFTCM*MSSERTH*myMass
                        /(RADERTH*RADERTH*CNVMFT*CNVMFT);

                //Output the transformed data
                cout<<fixed<<setprecision(1)<<showpoint;
                cout<<"You weigh "<<myWeight<<" lbs"<<endl;
                
                break;
            }
            
            case '9':{
                //Declare variables
                float num1,num2,num3;//The user's three numbers
                //Initialize variables
                cout<<"Please enter the three numbers"<<endl;
                cin>>num1;
                cin>>num2;
                cin>>num3;

                //Output the transformed data
                cout<<"The largest of the three numbers is "
                        <<Max(num1,num2,num3)<<endl;
                cout<<"The largest of the first two numbers is "
                        <<Max(num1,num2)<<endl;
                cout<<"The largest of the last two numbers is "
                        <<Max(num2,num3)<<endl;
            
                break;
            }
            
            default:{
                cout<<"Exit the program"<<endl;
            }
        }
    }while(choice>='0'&&choice<='9');
    
    //Exit stage right!
    return 0;
}

//Define the function inflation for Problem 6
float inflation(float price1, float price2) {

    return ((price2-price1)/price1);   
}

//Define mpg function for Problem 7
 float mpg(int miles, int liters)
    {
        float gallons;
        gallons = liters * LITER;//Conversion
        return (miles/gallons);
    }
           
//Define the function Max For Problem 9
    float Max(float num1,float num2,float num3){
        if(num1>num2){
            if(num1>num3)
                return num1;
            else
                return num3;       
        }
        else 
            if(num2>num3)
                return num2;
            else
                return num3;  
    }
    
    float Max(float num1,float num2){
        if (num1>num2)
            return num1;
        else
            return num2;
    }

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on May 4, 2017, 8:00 PM
 * Purpose: Assignment 5 Switch Menu
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random number generator
#include <ctime>     //Set the random number seed
#include <iomanip>   //Formatting
#include <cmath>     //Math functions
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes (for each problem)
float getSales(string);//0
void findHighest(float,float,float,float);//0
int getNumAccidents(string);//1
void findLowest(int,int,int,int,int);//1
float Celsius(float F);//2
int coinToss();//3
float present_Value(float ftrVal,float rate,float years);//4
int num_Employees();//5
int num_Days(int emplyee);//5
float mean(int emplyee,int totDays);//5
float new_Population(int strtPop,float bRate,float dRate);//6
float mean(float s1, float s2, float s3, float s4);//7
float standard_Deviation(float s1,float s2,float s3,
                            float s4,float average,int n);//7
void input(int &feet, int &inches);//8
void conversion(int feet, int inches, int &meters,float &cm);//8
void output(int feet, int inches,int meters,float cm);//8
float semiperimeter(float a,float b,float c);//9
void area_perimeter(float a,float b,float c,float &area,float &pmeter);//9

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char choice;
    
    //Show menu and loop
    do{
        //Display Menu
        cout<<endl<<endl<<"Type any letter to exit"<<endl;
        cout<<"Type 0 for Gaddis_8thEd_Chap6_Prob3_WinningDivision"<<endl;
        cout<<"Type 1 for Gaddis_8thEd_Chap6_Prob4_DrivingArea"<<endl;
        cout<<"Type 2 for Gaddis_8thEd_Chap6_Prob_7_Temperature"<<endl;
        cout<<"Type 3 for Gaddis_8thEd_Chap6_Prob8_CoinToss"<<endl;
        cout<<"Type 4 for Gaddis_8thEd_Chap6_Prob9_PresentValue"<<endl;
        cout<<"Type 5 for Gaddis_8thEd_Chap6_Prob13_DaysOut"<<endl;
        cout<<"Type 6 for Gaddis_8thEd_Chap6_Prob16_Population"<<endl;
        cout<<"Type 7 for Savitch_8thEd_Chap5_Prob4_StandardDeviation"<<endl;
        cout<<"Type 8 for Savitch_8thEd_Chap5_Prob6_MetricConversion"<<endl;
        cout<<"Type 9 for Savitch_8thEd_Chap5_Prob13_TriangleArea"<<endl<<endl;
       
        //Input the choice
        cout<<"Problem ";
        cin>>choice;
        
        //Place solutions to problems in switch statement
        switch(choice){
            case '0':{
                //Declare variables
                float NE, NW, SE, SW;//Sales of Northeast, northwest, etc

                //Input data and Call functions
                NE=getSales("Northeast");
                NW=getSales("Northwest");
                SE=getSales("Southeast");
                SW=getSales("Southwest");
                findHighest(NE,NW,SE,SW);
    
                break;
            }
            
            case '1':{
                //Declare variables
                int numAcc;//Number of accidents
                int north,south,east,west,central;//The 5 divisions

                //Call functions
                north=getNumAccidents("North");
                south=getNumAccidents("South");
                east=getNumAccidents("East");
                west=getNumAccidents("West");
                central=getNumAccidents("Central");
                findLowest(north,south,east,west,central);
                
                break;
            }
            
            case '2':{
                //Declare variables
                float F=0, C;//Temperature in Fahrenheit and Celsius

                //Input data
                for(int i=1; i<=20; i++){
                    F=i;
                    cout<<"Fahrenheit: "<<F<<"  ";
                    cout<<"Celsius: "<<Celsius(F)<<endl;
                }
                
                break;
            }
            
            case '3':{
                //Set the random number seed
                srand(time(0));

                //Declare variables
                int side;
                int heads=0, tails=0;//Number of heads and tails
                int numToss;//Number of coin tosses

                //Number of tosses
                cout<<"Enter number of coin tosses"<<endl;
                cin>>numToss;

                //Keep track of the result of each toss
                for(int i=1;i<=numToss;i++){
                    side=coinToss();
                    if(side==1)
                        heads++;
                    if(side==2)
                        tails++;
                }

                //Output the transformed data
                cout<<"Out of "<<numToss<<" tosses:"<<endl;
                cout<<heads<<" were heads"<<endl;
                cout<<tails<<" were tails"<<endl;
                
                break;
            }
            
            case '4':{
                //Declare variables
                float ftrVal;//Future Value
                float rate;//Interest rate
                float years;//Number of years
                float prsVal;//Present Value

                //Input data
                cout<<"Input Future Value:"<<endl;
                cin>>ftrVal;
                cout<<"Input Interest Rate:"<<endl;
                cin>>rate;
                cout<<"Input Years:"<<endl;
                cin>>years;

                //Call present value function
                prsVal=present_Value(ftrVal,rate,years);

                //Output the transformed data
                cout<<fixed<<setprecision(2)<<endl;
                cout<<"Present Value = $"<<prsVal<<endl;
                
                break;
            }
            
            case '5':{
                //Declare variables
                int emplyee;//Number of employees
                int numDays;//Number of days absent
                float average;//Average days missed per employee
                int totDays;//Total days 

                //Call functions
                emplyee=num_Employees();
                totDays=num_Days(emplyee);
                average=mean(emplyee,totDays);
                cout<<"Mean = "<<average<<endl;
                break;
            }
            
            case '6':{
                //Declare variables
                int strtPop;//Starting population size
                float bRate;//Annual birth rate
                float dRate;//Annual death rate
                int years;//Number of years to display
                float newPop;//New population size

                //Input and validate data
                cout<<"Enter starting Population:"<<endl;
                cin>>strtPop;
                while(strtPop<2){
                    cout<<"Enter starting Population:"<<endl;
                cin>>strtPop;
                }
                cout<<"Enter birth rate:"<<endl;
                cin>>bRate;
                while(bRate<0){
                    cout<<"Enter birth rate:"<<endl;
                cin>>bRate;
                }
                cout<<"Enter death rate:"<<endl;
                cin>>dRate;
                while(dRate<0){
                    cout<<"Enter death rate:"<<endl;
                    cin>>dRate;
                }
                cout<<"Enter number of years"<<endl;
                cin>>years;
                while(years<1){
                    cout<<"Enter number of years"<<endl;
                    cin>>years;
                }

                //Output the transformed data
                cout<<"Populations at specific years"<<endl;
                for(int i=1;i<=years;i++){
                    newPop=new_Population(strtPop,bRate,dRate);
                    cout<<fixed<<setprecision(0);
                    cout<<"Year "<<i<<":"<<endl;
                    cout<<newPop<<endl;
                    strtPop=newPop;
                }
                
                break;
            }
            
            case '7':{
                //Declare variables
                float s1, s2, s3, s4;//Four scores
                float average;//Average of scores
                float stdDev;//Standard deviation of scores
                char choice;//User's choice

                do{
                //Input data
                cout<<"Enter scores"<<endl;
                cout<<"Score 1:"<<endl;
                cin>>s1;
                cout<<"Score 2:"<<endl;
                cin>>s2;
                cout<<"Score 3:"<<endl;
                cin>>s3;
                cout<<"Score 4:"<<endl;
                cin>>s4;

                //Calculate average by calling function
                average=mean(s1,s2,s3,s4);

                //Calculate standard deviation by calling function
                stdDev=standard_Deviation(s1, s2, s3, s4,average,4);

                //Map inputs to outputs or process the data
                cout<<"Standard Deviation is "<<stdDev<<endl;

                //Enter choice
                cout<<"Enter 'Y' or 'y' to repeat"<<endl;
                cin>>choice;

                }while(choice=='Y' || choice=='y');
                
                break;
            }
            
            case '8':{
                //Declare variables
                int feet, inches, meters;
                float cm;
                char choice;

                do{

                //Call input function
                input(feet, inches);

                //Call conversion function
                conversion(feet, inches, meters, cm);

                //Call output function
                output(feet, inches, meters, cm);

                //Repeat calculation
                cout<<"Enter 'Y' or 'y' to repeat the calculation"<<endl;
                cin>>choice;

                }while (choice=='Y'||choice=='y');
                            break;
            }
            
            case '9':{
                //Declare variables
                float a,b,c;//Sides of triangle
                float area;//Area of triangle
                float pmeter;//Perimeter of triangle

                //Input data
                cout<<"Enter lengths of triangles:"<<endl;
                cout<<"a=";
                cin>>a;
                cout<<"b=";
                cin>>b;
                cout<<"c=";
                cin>>c;

                //Verify if it is triangle
                if(a+b>c && b+c>a && a+c>b){

                    //Map inputs to outputs or process the data
                    semiperimeter(a,b,c);
                    area_perimeter(a,b,c,area,pmeter);

                    //Output the transformed data
                    cout<<"Perimeter = "<<pmeter<<endl;
                    cout<<"Area = "<<area<<endl;
                }
                else{
                    cout<<"The lengths of these sides do not form a triangle"<<endl;
                }
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
//Problem 0 functions
float getSales(string dvision){
    float sales;
    cout<<"Enter sales for "<<dvision<<endl;
    cin>>sales;
    while(sales<0)
        {
        cout<<"Sales must be positive"<<endl;
        cout<<"Enter sales for "<<dvision<<endl;
        cin>>sales;  
        }
    return sales;
}

void findHighest(float NE,float NW,float SE,float SW){
    float highest;
    
    if(NE>SE && NE>NW && NE>SW){
        cout<<"Highest is Northeast with $"<<NE<<endl;
    }
    if(SE>NE && SE>NW && SE>SW){
        cout<<"Highest is Southeast with $"<<SE<<endl;
    }
    if(NW>NE && NW>SE && NW>SW){
        cout<<"Highest is Northwest with $"<<NW<<endl;
    }
    if(SW>NE && SW>NW && SW>SE){
        cout<<"Highest is Southwest with $"<<SW<<endl;
    }
}

//Problem 1 functions
int getNumAccidents(string dvision){
    //Declare variables
    int numAcc;
    
    cout<<"Enter number of accidents for "<<dvision<<endl;
    cin>>numAcc;
    
    while(numAcc<0){//Validate
        cout<<"Must be positive number"<<endl;
        cout<<"Enter number of accidents for "<<dvision<<endl;
    cin>>numAcc;
    }
    return numAcc;
}

void findLowest(int north, int south, int east, int west, int central){
    //Conditions
    
    if(north<south && north<east && north<west && north<central){
        cout<<"Safest driving area is North Division"<<endl;
    }
    if(south<north && south<east && south<west && south<central){
        cout<<"Safest driving area is South Division"<<endl;
    }
    if(east<south && east<north && east<west && east<central){
        cout<<"Safest driving area is East Division"<<endl;
    }
    if(west<south && west<east && west<north && west<central){
        cout<<"Safest driving area is West Division"<<endl;
    }
    if(central<south && central<east && central<west && central<north){
        cout<<"Safest driving area is Central Division"<<endl;
    }
}

//Problem 2 functions
float Celsius(float F){
    float C;//Degrees Celsius
    
    cout<<fixed<<setprecision(2);
    //Equation
    C=(5.0/9.0f)*(F-32);
    return C;
}

//Problem 3 function
int coinToss(){
    //Declare variables
    int side=rand()%2+1;
    
    //Output side
    if(side==1)
        cout<<"Heads"<<endl;
    else
        cout<<"Tails"<<endl;
    
    return side;
}

//Problem 4 function
float present_Value(float ftrVal,float rate,float years){
    //Declare Variables
    float prsVal;//Present Value
    
    //Equation
    prsVal=ftrVal/pow((1+rate),years);
    
    return prsVal;
}

//Problem 5 functions
int num_Employees(){
    int emplyee;
    cout<<"Enter number of employees"<<endl;
    cin>>emplyee;
    return emplyee;
}

int num_Days(int emplyee){
    int totDays=0;//Total days missed
    int numDays;//Number of days;
    
    cout<<"Enter number of days missed for each employee"<<endl;
    
    for(int i=1;i<=emplyee;i++){
    cout<<"Employee "<<i<<":"<<endl;
    cin>>numDays;
    totDays+=numDays;
    }
    
    return totDays;
}   

float mean(int emplyee,int totDays){
    float average;//Average days missed per employee
    average=static_cast<float>(totDays/emplyee);
    return average;
}

//Problem 6 functions
float new_Population(int strtPop,float bRate,float dRate){
    //Declare variables
    float newPop;
    
    //Size of population for a year
    newPop=strtPop+(bRate*strtPop)-(dRate*strtPop);
    
    
    return newPop;
}

//Problem 7 functions
float mean(float s1, float s2, float s3, float s4){
    float average;
    average=(s1+s2+s3+s4)/4.0f;
    return average;
}
float standard_Deviation(float s1,float s2,float s3,float s4,float average,int n){
    //Declare variables
    float stdDev;
    //Calculate
    stdDev=pow((s1-average),2)+pow((s2-average),2)+pow((s3-average),2)+
            pow((s4-average),2);
    stdDev=stdDev/4.0f;
    stdDev=sqrt(stdDev);
    return stdDev;
}

//Problem 8 functions
void input(int &feet, int &inches){
    cout<<"Enter feet:"<<endl;
    cin>>feet;
    cout<<"Enter inches:"<<endl;
    cin>>inches;
    feet+=(inches/12);
    inches%=12;
}

void conversion(int feet, int inches,int &meters,float &cm){
    meters = (12*feet+inches)*0.3048f/12;
    cm=((12*feet+inches)*0.3048f/12-meters)*100;
}

void output(int feet, int inches,int meters,float cm){
    cout<<feet<<" feet and "<<inches<<" inches is equal to "<<meters<<" meters"
            " and "<<cm<<" cm"<<endl;
}

//Problem 9 functions
float semiperimeter(float a,float b,float c){
    float s;//Semiperimeter of triangle
    s=(a+b+c)/2.0f;
    return s;
}
void area_perimeter(float a,float b,float c,float &area,float &pmeter){
    float s;//Semiperimeter of triangle
    s=semiperimeter(a,b,c);
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    pmeter=a+b+c;
}
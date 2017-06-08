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
#include <cmath>     //Math functions
#include <string>    //Strings
#include <iomanip>   //Formatting
#include <fstream>   //File i/o
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
char letter_grade(float score);//Problem 1
int bubbleSort(int[],int);//Problem 8
int selectionSort(int[],int);//Problem 8
void displayArrays(int[],int);//Problem 8
float standard_deviation(float x[], int size);//Problem 9


//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char choice;
    
    //Show menu and loop
    do{
        //Display Menu
        cout<<endl<<endl<<"Type any letter to exit"<<endl;
        cout<<"Type 0 for Gaddis_8thEd_Chap7_Prob1_LargestSmallestValues"<<endl;
        cout<<"Type 1 for Gaddis_8thEd_Chap7_Prob12_GradeBook"<<endl;
        cout<<"Type 2 for Gaddis_8thEd_Chap7_Prob_3_ChipsAndSalsa"<<endl;
        cout<<"Type 3 for Gaddis_8thEd_Chap7_Prob7_NumberAnalysis"<<endl;
        cout<<"Type 4 for Gaddis_8thEd_Chap8_Prob1_ChargeAccount"
                                                   "Validation"<<endl;
        cout<<"Type 5 for Gaddis_8thEd_Chap8_Prob3_LotteryWinner"
                                                   "Modification"<<endl;
        cout<<"Type 6 for Gaddis_8thEd_Chap8_Prob4_ChargeAccount"
                                                   "Modification"<<endl;
        cout<<"Type 7 for Gaddis_8thEd_Chap8_Prob5_RainFallStats"
                                                   "Modification"<<endl;
        cout<<"Type 8 for Gaddis_8thEd_Chap8_Prob9_SortingBenchmarks"<<endl;
        cout<<"Type 9 for Savitch_8thEd_Chap7_Prob4_StandardDeviation"
                                                    "Array"<<endl<<endl;
       
        //Input the choice
        cout<<"Problem ";
        cin>>choice;
        
        //Place solutions to problems in switch statement
        switch(choice){
            case '0':{
                //Declare variables
                int size=10;//Size of array/number of elements
                int array[size];//array to be inputted into
                int largest, smallest;//Largest and smallest values of the 10


                //Input data
                cout<<"Input ten integers:"<<endl;
                for(int i=0;i<10;i++){
                cout<<"Number "<<i+1<<":"<<endl;
                cin>>array[i];       
                }

                //Initialize largest and smallest
                largest=array[0];
                smallest=array[0];

                //Find largest and smallest
                for(int j=0;j<10;j++){
                    if(array[j]>largest){
                        largest=array[j];
                    }
                    if(array[j]<smallest){
                        smallest=array[j];
                    }
                }

                //Output the transformed data
                cout<<"Largest is "<<largest<<endl;
                cout<<"Smallest is "<<smallest<<endl;

    
                break;
            }
            
            case '1':{
                //Declare variables
                string names[5];//Names of students
                float scores[4];//Score on each exam
                char fGrade[5];//Final letter grade in class
                float average[5];//Average of exam scores

                //Input data
                for(int i=0;i<5;i++){
                    cout<<"Enter name of student "<<(i+1)<<":"<<endl;
                    cin>>names[i];

                    for(int j=0;j<4;j++){
                    cout<<"Input score "<<(j+1)<<":"<<endl;
                    cin>>scores[j];
                    }
                    average[i]=0;
                    for(int j=0;j<4;j++){
                        average[i]+=scores[j];
                    }
                    average[i]/=4;
                    //Call letter_grade function
                    fGrade[i]=letter_grade(average[i]);
                }


                //Output the transformed data
                cout<<fixed<<setprecision(2)<<endl;
                for(int i=0;i<5;i++){
                    cout<<names[i]<<": "<<endl;
                    cout<<average[i]<<": "<<endl;
                    cout<<fGrade[i]<<": "<<endl;
                }

                break;
            }
            
            case '2':{
                //Declare variables
                int sType=5;//Salsa types
                int jSold=5;//Jars sold
                string salsa[5]={"Mild","Medium","Sweet","Hot","Zesty"};
                int jars[jSold];
                int tSales=0;//Total sales
                int hSale;//Highest sale of jars
                int lSale;//Lowest sale of jars
                string highest;//Highest sold salsa type
                string lowest;//Lowest sold salsa type

                //Input data
                for(int i=0;i<sType;i++){
                    cout<<"Enter number of jars sold for "<<salsa[i]<<" salsa:"<<endl;
                    cin>>jars[i];
                    while(jars[i]<0){
                        cout<<"Enter positive number:"<<endl;
                        cin>>jars[i];
                    }
                }

                //Initialize variables once entered
                hSale=jars[0];
                highest=salsa[0];
                lSale=jars[0];
                lowest=salsa[0];

                for(int i=0;i<sType;i++){
                    tSales+=jars[i];//total sales calculation

                    if(hSale<jars[i]){
                        hSale=jars[i];//Find highest sales of jars and salsa
                        highest=salsa[i];
                    }
                    if(lSale>jars[i]){
                        lSale=jars[i];
                        lowest=salsa[i];
                    }
                }

                //Output the transformed data
                cout<<"Sales for each salsa type:"<<endl;

                for(int i=0;i<sType;i++){
                    cout<<salsa[i]<<" Salsa: "<<jars[i]<<" jars"<<endl;
                }

                cout<<"Total jars sold: "<<tSales<<endl;
                cout<<"Highest number of jars sold: "<<hSale<<endl;
                cout<<"Highest selling salsa: "<<highest<<endl;
                cout<<"Lowest number of jars sold: "<<lSale<<endl;
                cout<<"Lowest selling salsa: "<<lowest<<endl;

                break;
            }
            
            case '3':{
                //Declare variables and open files
                int size;//Size of array
                int smallest,largest;
                int array[30];
                int counter=0;
                int num;
                int total;
                ifstream in;//Input File

                //Initialize Variables
                string inName="ArrayValues.txt";//String name

                in.open(inName);//Open the Input file


                while(!in.eof()){
                    in>>num;
                    array[counter]=num;
                    counter++;
                }

                smallest=array[0];
                largest=array[0];
                total=0;

                //Find largest and smallest
                for(int i=0;i<counter;i++){
                    if(array[i]>largest)
                        largest=array[i];
                    if(array[i]<smallest)
                        smallest=array[i];
                    total+=array[i];//Add up numbers too
                }


                //Output the transformed data
                cout<<"The smallest value is "<<smallest<<endl;
                cout<<"The largest values is "<<largest<<endl;
                cout<<"Total of numbers in array is "<<total<<endl;
                cout<<"Average of numbers in array is "<<total/counter<<endl;



                //Close file
                in.close();
                
                break;
            }
            
            case '4':{
                //Declare variables
                int size=18;//array size
                int charge[18]={5658845,4520125,7895122,8777541,8451277,1302850,
                                8080152,4562555,5552012,5050552,7825877,1250255,
                                1005231,6545231,3852085,7576651,7881200,4581002};
                int chrgNum;//Charge number
                bool found=false;

                //Input data
                cout<<"Enter account charge number:"<<endl;
                cin>>chrgNum;

                //Map inputs to outputs or process the data
                for(int i=0;i<size;i++){
                    if(charge[i]==chrgNum){
                        found=true;
                    }
                }

                //Output the transformed data
                if(found)
                    cout<<"Number is valid"<<endl;
                else
                    cout<<"Number is invalid"<<endl;
               
                
                break;
            }
            
            case '5':{
                //Declare variables
                int size=10;//size of array
                int winNum[10]={13579,26791,26792,33445,55555,  //Winning numbers
                                62483,77777,79422,85647,93121};
                int userNum;//User's number
                int first=0;
                int last=size-1;
                int middle;
                bool found=false;

                //Input data
                cout<<"Enter your number:"<<endl;
                cin>>userNum;

                //Binary search
                while(!found && first<=last){
                    middle=(first+last)/2;
                    if(winNum[middle]==userNum)
                        found=true;
                    else if(winNum[middle]>userNum)
                        last=middle-1;
                    else 
                        first=middle+1;
                }

                //Output the transformed data
                if(found)
                    cout<<"Congrats, you won"<<endl;
                else
                    cout<<"You're number was not in the winning list"<<endl;
               
                break;
            }
            
            case '6':{
                //Declare variables
                const int size=18;
                int chrgNum;//account number
                int charge[size]={5658845,4520125,7895122,8777541,8451277,1302850,
                                  8080152,4562555,5552012,5050552,7825877,1250255,
                                  1005231,6545231,3852085,7576651,7881200,4581002};

                //Ask for input
                cout<<"Enter charge account number:"<<endl;
                cin>>chrgNum;

                //Bubble Sort Array
                bool swap;
                int temp;

                do
                {  
                    swap=false;
                    for(int count=0;count<(size-1);count++){
                        if(charge[count]>charge[count+1]){
                            temp=charge[count];
                            charge[count]=charge[count+1];
                            charge[count+1]=temp;
                            swap=true;
                        }
                    }
                }while(swap);

                //Binary Search
                int first=0;
                int last=size-1;
                int middle;
                bool found=false;

                    while(!found && first<=last){
                    middle=(first+last)/2;
                    if(charge[middle]==chrgNum)
                        found=true;
                    else if(charge[middle]>chrgNum)
                        last=middle-1;
                    else 
                        first=middle+1;
                }

                //Output the transformed data
                cout<<"Array after sorting"<<endl;
                for(int i=0;i<size;i++){
                    cout<<charge[i]<<", "<<endl;
                }

                if(found)
                    cout<<"Number is valid"<<endl;
                else
                    cout<<"Number is invalid"<<endl;
                
                break;
            }
            
            case '7':{
                //Declare variables
                int size=12;//Size of array
                int rainVal[12];//Rainfall Values array for 12 months
                string name[12]={"January","February","March","April","May",
                                 "June","July","August","September","October",
                                 "November","December"};

                //Input data
                cout<<"Enter total rainfall for:"<<endl;
                for(int i=0; i<12;i++){
                    cout<<name[i]<<":"<<endl;
                    cin>>rainVal[i];
                    while(rainVal[i]<0){
                        cout<<"Enter positive number:"<<endl;
                        cin>>rainVal[i];     
                    }
                }

                //Bubble Sort Array
                bool swap;
                int temp;
                string tempStg;

                do
                {  
                    swap=false;
                    for(int count=0;count<(size-1);count++){
                        if(rainVal[count]>rainVal[count+1]){
                            temp=rainVal[count];//Swap rain values
                            rainVal[count]=rainVal[count+1];
                            rainVal[count+1]=temp;

                            tempStg=name[count];//Swap corresponding months
                            name[count]=name[count+1];
                            name[count+1]=tempStg;

                            swap=true;
                        }
                    }
                }while(swap);

                //Output the transformed data
                cout<<"Months and rainfall value from highest to lowest"<<endl;

                for(int i=11;i>=0;i--){
                cout<<name[i]<<": "<<rainVal[i]<<endl;

                }

                break;
            }
            
            case '8':{
                //Declare variables
                const int size=20;
                int array1[20]={4,65,123,75,23,65,4,6,67,12,98,53,16,7,34,7,43,90,33,2};
                int array2[20]={4,65,123,75,23,65,4,6,67,12,98,53,16,7,34,7,43,90,33,2};
                int exchng1;
                int exchng2;

                //Call Functions to sort and add up exchanges
                exchng1=bubbleSort(array1,size);
                exchng2=selectionSort(array2,size);


                //Display arrays
                displayArrays(array1,size);
                cout<<endl;
                cout<<"Number of exchanges for array1: "<<exchng1<<endl;
                displayArrays(array1,size);
                cout<<endl;
                cout<<"Number of exchanges for array2: "<<exchng2<<endl;
                displayArrays(array2,size);
                
                break;
            }
            
            case '9':{
                //Declare variables
                float array[100];
                float mean;
                float stdDev;
                int size;

                //Input data
                cout<<"Enter array size:"<<endl;
                cin>>size;
                cout<<"Enter values:"<<endl;
                for(int i=0;i<size;i++){
                    cin>>array[i];
                }

                //Call standard deviation function
                stdDev=standard_deviation(array,size);

                //Output the transformed data
                cout<<"Standard Deviation = "<<stdDev<<endl;
                
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

//Problem 1 Function
char letter_grade(float score){
    if(score>=90 && score<=100)
        return 'A';
    if(score>=80 && score<90)
        return 'B';
    if(score>=70 && score<80)
        return 'C';
    if(score>=60 && score<70)
        return 'D';
    else
        return 'F';
    
}

//Problem 8 functions
void displayArrays(int arrayX[],int size){//arrayX change to integers[]
    for(int i=0;i<size;i++){
        cout<<arrayX[i]<<", ";
    }
    cout<<endl;
}

int bubbleSort(int array1[], int size){
    
    //Local Variables
    bool swap;
    int temp;
    int exchng1=0;//Number of exchanges/swaps
    do
    {  
        swap=false;
        for(int count=0;count<(size - 1);count++){
            if(array1[count]>array1[count+1]){
                temp=array1[count];
                array1[count]=array1[count+1];
                array1[count+1]=temp;
                swap=true;
                exchng1++;
            }
        }
    }while(swap);
    
    return exchng1;
}

int selectionSort(int array2[],int size){
    //Local Variables
    int start, mIndex, minVal;
    int exchng2=0;
    
    for(start=0;start<(size-1);start++){
        mIndex=start;
        minVal=array2[start];
        for(int index=start+1;index<size;index++){
            if(array2[index]<minVal){
                minVal=array2[index];
                mIndex = index;
                exchng2++;
            }
        }
        array2[mIndex]=array2[start];
        array2[start]=minVal;
    }
    return exchng2;
}

//Problem 9 Function
float standard_deviation(float array[], int size){
    //Declare/Initialize variables
    float stdDev=0;
    float mean=0;
    
    //Calculate standard deviation
    for(int i=0;i<size;i++){
        mean=mean+array[i];
    }
    mean=mean/size;
    for(int i=0;i<size;i++){
        stdDev=stdDev + ((array[i]-mean)*(array[i]-mean));
    }
    stdDev/=size;
    stdDev=sqrt(stdDev);
    return stdDev;
}
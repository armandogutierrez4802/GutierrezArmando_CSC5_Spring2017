/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 *
 * Created on May 17, 2017, 9:28 PM
 * 
 * Left to do:
 * searching
 * defaulted parameters
 * 
 * 
 * 
 * Done:
 * returning primitive data types, pass by reference,
 * output is formatted and you should read and write to files, pass by value
 * basic array (1-D array)
 * 2-D array
 * sorting
 * Passing the arrays between functions
 */
 
//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set the seed
#include <iomanip>   //Format the output
#include <fstream>   //File I/O
#include <string>    //Strings
#include <cmath>     //Math functions
 
//User Libraries
 
using namespace std;            
 
/*
 *
 * 
 * 
 * 
 * 
 * Lehr said: "ARRAYS ARE PASSED BY REFERENCE"...no need to put ampersand
 */
 
//Global Constants
const float PERCENT=100.0f;//Conversion to Percent
const int HDTHSND=10e5; //One Hundred Thousand
const int SIZE=2;
    
//Function Prototypes
int crdVal ();//Returns new card value
void winner(int, int, int&, int&, int, int[][SIZE],int[], int[]);//Output winner
void sort(int[][SIZE],int);//Bubble sort
 
int main(int argc, char** argv) {
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare file and game variables
    ifstream in;//Input File
    ofstream out;//Output File
    int dlrCrd, usrCrd;//Dealer's/User's card
    int dlrSum=0, usrSum=0;//Dealer's/User's sum of cards
    char choice;//User's choice
    int wins=0,losses=0;//Number of wins/losses
    int nPlayrs, lmPlyrs=HDTHSND;//Number of games/Limit to games
    int hand[10]={};//Cards in first hand
    int split1,split2;//The third cards in each hand for split option
    char sChoice;//Split choice
    int stsTble[nPlayrs][SIZE];//Statistics Table;
    int winArry[nPlayrs];//Initial amount of money
    int bet[nPlayrs];//Bets       **Maybe have fun with the bet options later, but just do sorting for now
    
    
    //Initialize variables
    string inName="GameInfo.txt";//String name
    string outName="GameStats.txt";//String name
    in.open(inName);//Open the Input file
    out.open(outName);//Open the Output file
    while(in>>nPlayrs);//Last value in file becomes the number of games
    in>>nPlayrs;
    nPlayrs=(nPlayrs>lmPlyrs)?lmPlyrs:nPlayrs;//Limit games
    for(int row=0;row<nPlayrs;row++){//Initialize 2-D array
        for(int column=0;column<SIZE;column++){
          stsTble[row][column]=0;
        }
    }
    for(int x=0;x<nPlayrs;x++){//Initialize money array
        winArry[x]=0;
    }
    for(int y=0;y<nPlayrs;y++){//Initialize bet array
        bet[y]=0;
    }
    
    
    for(int i=0;i<nPlayrs;i++){
        stsTble[i][0]=i+1;
        cout << stsTble[i][0];
    }
    cout << "mac fix:"<<endl;
    
    //Start the game
    int beg=time(0);
    
    for(int i=0;i<nPlayrs;i++){
        cout<<"Player "<<i+1<<endl;//Display number of game
        cout<<"Enter amount you wish to spend in dollars(minimum $100):"<<endl;
        cin>>stsTble[i][1];
        cout<<"Enter amount you wish to bet(minimum $5):"<<endl;
        cin>>bet[i];
        
        
        //User first card
        usrCrd=crdVal();//[1-11]
        cout<<"User's first card value: "<<usrCrd<<endl;
        hand[0]=usrCrd;
 
        //User's second card
        usrCrd=crdVal();//[1-11]
        cout<<"User's second card value: "<<usrCrd<<endl;
        hand[1]=usrCrd;
 
        //Update and display user's sum
 
        usrSum=hand[0]+hand[1];
        cout<<"User's sum: "<<usrSum<<endl;
 
        //Show dealer's card 1
        dlrCrd=crdVal();//[1-11]
        cout<<"Dealer's first card value: "<<dlrCrd<<endl;
 
        //Update dealer's sum
        dlrSum+=dlrCrd;
 
        //Dealer's second card. Do not display
        dlrCrd=crdVal();//[1-11]
        cout<<"Dealer's second card is face down"<<endl<<endl;
    
        //Update dealer's sum
        dlrSum+=dlrCrd;
 
        cout<<"Enter 0 to Stay"<<endl;
        cout<<"Enter 1 to Hit"<<endl;
        cout<<"Enter 2 to Double Down"<<endl;
        if(hand[0]==hand[1])
        cout<<"Enter 3 to Split"<<endl;
 
        cin>>choice;//Enter user's choice to hit or stay
 
        switch(choice){
            case '1': {     //*Hit option could probably use a VECTOR which keeps adding elements
                bool hit=true;
                do{
                usrCrd=crdVal();
                cout<<"User's card value: "<<usrCrd<<endl;
                //Update and display user sum
                usrSum+=usrCrd;
                cout<<"User's sum: "<<usrSum<<endl;
 
                cout<<"Enter 1 to hit. Enter 0 to stay"<<endl;
                cin>>hit;//Enter user's choice to hit or stay
 
                }while(hit && usrSum<21 && dlrSum<21);
 
                break;
            }//End case 1
 
            case '2':{
                usrCrd=crdVal();
                cout<<"User's card value: "<<usrCrd<<endl;
                //Update and display user sum
                usrSum+=usrCrd;
                cout<<"User's sum: "<<usrSum<<endl;
                bet[i]*=2;//Double the bet
                break;
            }//End case 2
 
            case '3':{     //with arrays now
                cout<<"You will be hit once per hand"<<endl;
                split1=crdVal();
                split2=crdVal();
                cout<<"Hand 1 card: "<<split1<<endl;
                cout<<"Hand 2 card: "<<split2<<endl;
                cout<<"Enter '1' or '2' to choose which hand you would like to keep"<<endl;
                cin>>sChoice;
                if(sChoice=='1'){
                    usrSum/=2;
                    usrSum+=split1;
                    cout<<"User's sum: "<<usrSum<<endl;
                }
                if(sChoice=='2'){
                    usrSum/=2;
                    usrSum+=split2;
                    cout<<"User's sum: "<<usrSum<<endl;
                }
                break;
            }
 
            default: cout<<"You have chosen to stay"<<endl<<endl;
        }//End switch
 
 
 
            //Show dealer's card and sum     
                    //Dealer must stay at 17      
                do{
                    cout<<"The dealer will hit"<<endl;
                    dlrCrd=crdVal();
                    cout<<"Dealer's card value: "<<dlrCrd<<endl;
 
                    //Update dealer's sum
                    dlrSum+=dlrCrd;
                    cout<<"Dealer's sum: "<<dlrSum<<endl<<endl;
                    }while(dlrSum<17);
 
                    cout<<"The dealer stays at "<<dlrSum<<endl;
 
        //Output winner
        winner(usrSum,dlrSum,wins,losses,i,stsTble,winArry,bet);
 
            cout<<endl<<endl;//Separate the games  
 
             //Re-initialize/Reset sums for next game
             usrSum=0;
             dlrSum=0;  
    }//End the For loop       
            
    int end=time(0);//End time of Game play
 
    //Output the game statistics to the screen
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Total number of Players = "<<nPlayrs<<endl;
    cout<<"Number of games won   = "<<wins<<endl;
    cout<<"Number of games lost  = "<<losses<<endl;
    cout<<"Percentage wins       = "
            <<static_cast<float>(wins)/nPlayrs*PERCENT<<"%"<<endl;
    cout<<"Percentage losses     = "
            <<static_cast<float>(losses)/nPlayrs*PERCENT<<"%"<<endl;
    cout<<"Total time to play this round in integer seconds = "<<end-beg<<endl;
    cout<<"Ratio of Longest to shortest game = 10^"<<log10(nPlayrs)<<endl<<endl;
    cout<<"Statistics Table"<<endl;
    cout<<"Player  Money($)    Win"<<endl;
    for(int row=0;row<nPlayrs;row++){
        for(int column=0;column<SIZE;column++){             //FIX THE COLUMNS
            cout<<stsTble[row][column]<<setw(10);
            
        }//end inner for loop
        cout<<winArry[row];
 
        cout<<endl;
    }//end outer for loop
    
    
    //Call bubble sort function for ranking
    sort(stsTble,nPlayrs);
   
    //Output ranking
    cout<<"Ranking of players by final amount of money:"<<endl;
    cout<<"Place  Player  Money($)"<<endl;
     
    for(int row=0;row<nPlayrs;row++){
        cout<< row+1<<"       ";
        for(int column=0;column<SIZE;column++){
            cout << stsTble[row][column]<<"       ";
        }
        cout<<endl;
    }
    
    //Output the game statistics to a file          ***FIX THIS!!!
                // Recall, that this is displaying the sorted array...So display normal array before sorting it!
    out<<"Total number of Games = "<<nPlayrs<<endl;
    out<<"Number of games won   = "<<wins<<endl;
    out<<"Number of games lost  = "<<losses<<endl;
    out<<"Percentage wins for round      = "
            <<static_cast<float>(wins)/nPlayrs*PERCENT<<"%"<<endl;
    out<<"Percentage losses     = "
            <<static_cast<float>(losses)/nPlayrs*PERCENT<<"%"<<endl;
    out<<"Total time to play these games in integer seconds = "<<end-beg<<endl;
    out<<"Ratio of Longest to shortest game = 10^"<<log10(nPlayrs)<<endl<<endl;
    out<<"Statistics Table"<<endl;
    out<<"Game   Wins   Time"<<endl;
    for(int row=0;row<nPlayrs;row++){
        for(int column=0;column<SIZE;column++){
            out<< stsTble[row][column]<<"      ";
        }
        out<<endl;
    }
    
    //Close files
    in.close();
    out.close();
    
    //Exit main
    return 0;
}
 
 
// 
int crdVal (){
    int card;
    card=1+(rand()%10);
    return card;
}
 
void winner(int usrSum, int dlrSum, int& wins, int&losses,
                int i, int stsTble[][SIZE],int winArry[], int bet[]){
    
//    stsTble[i][0]=i+1;
    
    if(usrSum<21 && dlrSum<21){
            if(usrSum==dlrSum)
             cout<<"Push"<<endl;
            else if (usrSum>dlrSum){
                cout<<"Player wins"<<endl;
                wins++;
                stsTble[i][1]+=bet[i];
                winArry[i]=1;
            }
            else{
                cout<<"House wins"<<endl;
                losses++;
                stsTble[i][1]-=bet[i];
                winArry[i]=0;
            }
            }//end nested if-else
                
        if(usrSum>21){
            cout<<"Player busts!"<<endl;
            losses++;//Update losses
            stsTble[i][1]-=bet[i];
            winArry[i]=0;
            }
 
        if(dlrSum>21 && usrSum<21){
            cout<<"Player wins"<<endl;
            wins++;
            stsTble[i][1]+=bet[i];
            winArry[i]=1;
            }
            
        if(usrSum==21){
            cout<<"Player gets blackjack!"<<endl;
            wins++;//Update wins
            stsTble[i][1]+=bet[i];
            winArry[i]=1;
        }
 
        if(dlrSum==21 && usrSum<21){   
            cout<<"House gets blackjack!"<<endl; 
            losses++;//Update losses
            stsTble[i][1]-=bet[i];
            winArry[i]=0;
        }
}
 
void sort(int stsTble[][SIZE],int nPlayrs){
    bool swap;
    int temp,t2;
    
        do{  
            swap=false;
            for(int i=0;i<nPlayrs-1;i++){
                if(stsTble[i][1]<stsTble[i+1][1]){
                    temp=stsTble[i][1];
                    t2=stsTble[i][0];
                    stsTble[i][1]=stsTble[i+1][1];
                    stsTble[i][0]=stsTble[i+1][0];
                    stsTble[i+1][1]=temp;
                    stsTble[i+1][0] = t2;
                    swap=true;
                }
            }
        }while(swap);
    
}




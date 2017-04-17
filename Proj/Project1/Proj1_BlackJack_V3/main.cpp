/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Armando Gutierrez
 * Created on April 8, 2017, 4:05 PM
 * Purpose: Game of Black Jack
 */

#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set the seed
#include <iomanip>   //Format the output

using namespace std;

/*
 * 
 */

    //Global Constants
    const float PERCENT=100.0f;//Conversion to Percent
    
    //Function Prototypes
    
int main(int argc, char** argv) {
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    cout<<"This is a game of BlackJack, where the computer is the dealer"<<endl;
    
    //Declare variables
    int dlrCrd=0;//Dealer's card
    int usrCrd=0;//User's card
    int dlrSum, usrSum;//Dealer's and User's sum of cards
    char choice;//User's choice
    int losses=0;//Number of losses
    int wins=0;//Number of wins
    int nGames;//Number of games
    //Maybe for string, just enter the user's name!
    
    //Initialize number of games
    cout<<"How many games would you like to play?"<<endl;
    cin>>nGames;
    
    //Start the game
    int beg=time(0);
    
    for(int i=1;i<=nGames;i++){
    
    cout<<"Game "<<i<<endl;//Display number of game
    
    //User first card
    usrCrd=1+(rand()%10);//[1-10]
    cout<<"User's first card value: "<<usrCrd<<endl;
    
    //Update user's sum
    usrSum+=usrCrd;
    
    //User's second card
    usrCrd=1+(rand()%10);//[1-10]
    cout<<"User's second card value: "<<usrCrd<<endl;
    
    //Update and display user's sum
    usrSum+=usrCrd;
    cout<<"User's sum: "<<usrSum<<endl;
    
    //Show dealer's card 1
    dlrCrd=1+(rand()%10);
    cout<<"Dealer's first card value: "<<dlrCrd<<endl;
    
    //Update dealer's sum
    dlrSum+=dlrCrd;
    
    //Dealer's second card. Do not display
    dlrCrd=1+(rand()%10);
    cout<<"Dealer's second card is face down"<<endl<<endl;
    
    //Update dealer's sum
    dlrSum+=dlrCrd;
            
    cout<<"Enter 0 to Stay"<<endl;
    cout<<"Enter 1 to Hit"<<endl;
    cout<<"Enter 2 to Double Down"<<endl;

    cin>>choice;//Enter user's choice to hit or stay

    switch(choice){
        case '1': {
            bool hit=true;              //CHECK THIS BOOL STUFF
            do{
            usrCrd=1+(rand()%10);
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
            usrCrd=1+(rand()%10);
            cout<<"User's card value: "<<usrCrd<<endl;
            //Update and display user sum
            usrSum+=usrCrd;
            cout<<"User's sum: "<<usrSum<<endl;
        }//End case 2
        
        default: cout<<"You have chosen to stay"<<endl<<endl;
    }//End switch
    
        //Show dealer's card and sum             //If-else --> do/while
                //Dealer must stay at 17      
            do{
                cout<<"The dealer will hit"<<endl;
                dlrCrd=1+(rand()%10);
                cout<<"Dealer's card value: "<<dlrCrd<<endl;

                //Update dealer's sum
                dlrSum+=dlrCrd;
                cout<<"Dealer's sum: "<<dlrSum<<endl<<endl;
                }while(dlrSum<17);
               
                cout<<"The dealer stays at "<<dlrSum<<endl;

    //Output who won and/or lost the game (nested if-else)
        if(usrSum<21 && dlrSum<21){
            if (usrSum>dlrSum){
                cout<<"User wins"<<endl;
                wins++;
            }
            else{
                cout<<"House wins"<<endl;
                losses++;
            }
            }//end nested if-else
                
        if(usrSum>21){
            cout<<"User busts!"<<endl;
            losses++;//Update losses
            }

        if(dlrSum>21 && usrSum<21){
            cout<<"User wins"<<endl;
            wins++;
            }
            
        if(usrSum==21){
            cout<<"User gets blackjack!"<<endl;
            wins++;//Update wins
        }

        if(dlrSum==21 && usrSum<21){   
            cout<<"House gets blackjack!"<<endl; 
            losses++;//Update losses
        }
        
        if(usrSum==dlrSum)
             cout<<"Push"<<endl;
         
        cout<<endl<<endl;//Separate the games  
         
         //Re-initialize/Reset sums for next game
         usrSum=0;
         dlrSum=0;  
    }//End the For loop       
            
    int end=time(0);//End time of Game play
    
    //Output number of wins and losses
    cout<<"Number of wins = "<<wins<<endl;
    cout<<"Number of losses = "<<losses<<endl;

    //Output the game statistics to the screen
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Total number of Games = "<<nGames<<endl;
    cout<<"Number of games won   = "<<wins<<endl;
    cout<<"Number of games lost  = "<<losses<<endl;
    cout<<"Percentage wins       = "
            <<static_cast<float>(wins)/nGames*PERCENT<<"%"<<endl;
    cout<<"Percentage losses     = "
            <<static_cast<float>(losses)/nGames*PERCENT<<"%"<<endl;
    cout<<"Total time to play these Games in integer seconds = "<<end-beg<<endl;
    

    return 0;
}
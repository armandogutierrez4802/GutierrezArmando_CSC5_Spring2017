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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    cout<<"This is a game of BlackJack, where the computer is the dealer"<<endl;
    
    //Declare variables
    int dlrCrd=0;//Dealer's card
    int usrCrd=0;//User's card
    int dlrSum, usrSum;//Dealer's and User's sum of cards
    char choice;//User's choice

    //Start the game
    int beg=time(0);
    
    //User card 1
    usrCrd=1+(rand()%10);//[1-10]
    cout<<"User's first card value: "<<usrCrd<<endl;
    
    //Update user's sum
    usrSum+=usrCrd;
    cout<<"User's sum: "<<usrSum<<endl;
    
    //Show dealer's card 1
    dlrCrd=1+(rand()%10);
    cout<<"Dealer's first card value: "<<dlrCrd<<endl;
    
    //Update dealer's sum
    dlrSum+=dlrCrd;
    cout<<"Dealer's sum: "<<dlrSum<<endl<<endl;
    
    cout<<"Enter 'H' or 'h' to hit. Enter 'S' or 's' to stay"<<endl;
            cin>>choice;//Enter user's choice to hit or stay
        
        do{
            usrCrd=1+(rand()%10);
            cout<<"User's card value: "<<usrCrd<<endl;
            //Update and display user sum
            usrSum+=usrCrd;
            cout<<"User's sum: "<<usrSum<<endl;


                //Show dealer's card
                if(dlrSum<17){  //Dealer must stay at 17
                dlrCrd=1+(rand()%10);
                cout<<"Dealer's card value: "<<dlrCrd<<endl;

                //Update dealer's sum
                dlrSum+=dlrCrd;
                cout<<"Dealer's sum: "<<dlrSum<<endl<<endl;
                }//end if statement
            
            cout<<"Enter 'H' or 'h' to hit. Enter 'S' or 's' to stay"<<endl;
            cin>>choice;//Enter user's choice to hit or stay
            
            }while((choice=='H'||choice=='h')&&usrSum<=21&&dlrSum<=21);

    
    //Output who one and lost (nested if-else)
      
            
    
        
    
   
    
    
    

    return 0;
}


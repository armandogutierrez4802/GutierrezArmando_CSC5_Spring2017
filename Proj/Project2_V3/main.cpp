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
 * It must illustrate all the concepts we have covered, most recently being 
 * functions and arrays.
 * 2 dimensional arrays.
 * Passing the arrays between functions.
 * defaulted parameters. --> can i just default the 0 in crdVal() and remove argument in code?
 * Sorting game players/searching should also be included.
 * 
 * 
 * 
 * Done:
 * returning primitive data types, pass by reference,
 * output is formatted and you should read and write to files, pass by value
 * basic array (1-D array)
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
 * Maybe the hand one array can be used each time the person hits...and then
 * the user sum will just be the sum of all the elements in the array!!!**
 * This would be done with vectors! Look at case '1' for more comment.
 * 
 * Maybe for the sorting one...Time each INDIVIDUAL game and rank the games by time
 * ex. fastest to slowest: game 3, game 1, game 7, etc.......WHAT DOES SORTING
 * GAME PLAYERS MEAN?
 * 
 * Perhaps I can let 2 people play this game and output the statistics in a 2-D array!!
 * --> changed mind...2-D array will display a table: game, and whether it was won or lost.
 * 
 * 
 * ARRAYS ARE PASSED BY REFERENCE
 */

//Global Constants
const float PERCENT=100.0f;//Conversion to Percent
const int HDTHSND=10e5; //One Hundred Thousand
const int SIZE = 2;
    
//Function Prototypes

int crdVal (int);//Returns new card value
void winner(int, int, int&, int&, int, int[][SIZE]);//Output winner

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
    int nGames, lmGames=HDTHSND;//Number of games/Limit to games
    int hand[10]={};//Cards in first hand
    int split1,split2;//The third cards in each hand for split option
    char sChoice;//Split choice
    int p2crd, p3crd;//Players 2 and 3 cards
    int p2sum=0,p3sum=0;//Players 2 and 3 sums
    char nPlayer;//Number of players
    int stsTble[nGames][SIZE];//Statistics Table
    
    
    //Initialize variables
    string inName="GameInfo.txt";//String name
    string outName="GameStats.txt";//String name
    
    in.open(inName);//Open the Input file
    out.open(outName);//Open the Output file
    while(in>>nGames);//Last value in file becomes the number of games
    in>>nGames;
    nGames=(nGames>lmGames)?lmGames:nGames;//Limit games
    
    for(int row=0;row<nGames;row++){
        for(int column=0;column<SIZE;column++){
          stsTble[row][column]=0;
        }
    
    }
    

    //Start the game
    int beg=time(0);
    
    for(int i=0;i<nGames;i++){
    
        cout<<"Game "<<i+1<<endl;//Display number of game
        
        //User first card
        usrCrd=crdVal(0);//[1-11]
        cout<<"User's first card value: "<<usrCrd<<endl;
        hand[0]=usrCrd;

        //User's second card
        usrCrd=crdVal(0);//[1-11]
        cout<<"User's second card value: "<<usrCrd<<endl;
        hand[1]=usrCrd;

        //Update and display user's sum

        usrSum=hand[0]+hand[1];
        cout<<"User's sum: "<<usrSum<<endl;

        //Show dealer's card 1
        dlrCrd=crdVal(0);//[1-11]
        cout<<"Dealer's first card value: "<<dlrCrd<<endl;

        //Update dealer's sum
        dlrSum+=dlrCrd;

        //Dealer's second card. Do not display
        dlrCrd=crdVal(0);//[1-11]
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
            case '1': {     //*Hit option could probably use a vector which keeps adding elements
                bool hit=true;
                do{
                usrCrd=crdVal(0);
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
                usrCrd=crdVal(0);
                cout<<"User's card value: "<<usrCrd<<endl;
                //Update and display user sum
                usrSum+=usrCrd;
                cout<<"User's sum: "<<usrSum<<endl;
                break;
            }//End case 2

            case '3':{     //with arrays now
                cout<<"You will be hit once per hand"<<endl;
                split1=crdVal(0);
                split2=crdVal(0);
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
                    dlrCrd=crdVal(0);
                    cout<<"Dealer's card value: "<<dlrCrd<<endl;

                    //Update dealer's sum
                    dlrSum+=dlrCrd;
                    cout<<"Dealer's sum: "<<dlrSum<<endl<<endl;
                    }while(dlrSum<17);

                    cout<<"The dealer stays at "<<dlrSum<<endl;

        //Output winner
        winner(usrSum,dlrSum,wins,losses,i,stsTble);

            cout<<endl<<endl;//Separate the games  

             //Re-initialize/Reset sums for next game
             usrSum=0;
             dlrSum=0;  
    }//End the For loop       
            
    int end=time(0);//End time of Game play

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
    cout<<"Ratio of Longest to shortest game = 10^"<<log10(nGames)<<endl;
    cout<<"Statistics Table"<<endl;
    cout<<"Game     Wins"<<endl;
    for(int row=0;row<nGames;row++){
        for(int column=0;column<2;column++){
            cout<< stsTble[row][column]<<"      ";
        }
        cout<<endl;
    }
    
    //Output the game statistics to a file
    out<<"Total number of Games = "<<nGames<<endl;
    out<<"Number of games won   = "<<wins<<endl;
    out<<"Number of games lost  = "<<losses<<endl;
    out<<"Percentage wins       = "
            <<static_cast<float>(wins)/nGames*PERCENT<<"%"<<endl;
    out<<"Percentage losses     = "
            <<static_cast<float>(losses)/nGames*PERCENT<<"%"<<endl;
    out<<"Total time to play these games in integer seconds = "<<end-beg<<endl;
    out<<"Ratio of Longest to shortest game = 10^"<<log10(nGames)<<endl;
    
    //Close files
    in.close();
    out.close();
    
    //Exit main
    return 0;
}

int crdVal (int card){
    card=1+(rand()%10);
    return card;
}

void winner(int usrSum, int dlrSum, int& wins, int&losses,
            int i, int stsTble[][SIZE]){
    
    stsTble[i][0]=i+1;
    
    if(usrSum<21 && dlrSum<21){
            if(usrSum==dlrSum)
             cout<<"Push"<<endl;
            else if (usrSum>dlrSum){
                cout<<"User wins"<<endl;
                wins++;
                stsTble[i][1]=1;
            }
            else{
                cout<<"House wins"<<endl;
                losses++;
                stsTble[i][1]=0;
            }
            }//end nested if-else
                
        if(usrSum>21){
            cout<<"User busts!"<<endl;
            losses++;//Update losses
            stsTble[i][1]=0;
            }

        if(dlrSum>21 && usrSum<21){
            cout<<"User wins"<<endl;
            wins++;
            stsTble[i][1]=1;
            }
            
        if(usrSum==21){
            cout<<"User gets blackjack!"<<endl;
            wins++;//Update wins
            stsTble[i][1]=1;
        }

        if(dlrSum==21 && usrSum<21){   
            cout<<"House gets blackjack!"<<endl; 
            losses++;//Update losses
            stsTble[i][1]=0;
        }
}




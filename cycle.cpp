/*
 * =====================================================================================
 *
 *       Filename:  cycle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2015 12:28:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>

#include "util.h"
#include "fight.h"

using namespace std;

vector<int> cycle(vector<int> gameInfo)
{
    srand(time(NULL));

    string choice;

    //gameInfo is in this order:
    //hp,atk,def,magatk,magdef,class,level,exp,alive,coins

    cout << "What would you like to do?\n";
    cout << "\t1. Train\n";
    cout << "\t2. Shop\n";
    cout << "\t3. Spar\n";
    cout << "\t4. Adventure\n";
    cout << "\t5. Info\n";
    cout << "\t6. Quit\n\n";

    cin >> choice;

    if(choice == "1")
    {
        int trainTime;
        cout << "How long would you like to train?\n";
        cin >> trainTime;
        sleep(trainTime);
        gameInfo.at(7) += trainTime;
    }
    if(choice == "2")
    {
        cout << "Buy a random stat upgrade for " << gameInfo.at(9)+(rand()%5) << " dollars?\n";
        string buy;
        if((buy == "yes" || buy == "Yes") && gameInfo.at(9)+5>=0)
        {
            gameInfo.at(rand()%5)++;
        }
        else
        {
            cout << "Thanks for your time.\n";
        }
    }
    if(choice == "3")
    {
        gameInfo.at(9) += fight(gameInfo,{gameInfo.at(0)-1,gameInfo.at(1)-1,gameInfo.at(2)-1,gameInfo.at(3)-1,gameInfo.at(4)-1,1,gameInfo.at(6)-1});
    }
    if(choice == "4")
    {
        int tempStat = rand()%5;
        int tempState;
        tempState = fight(gameInfo,{gameInfo.at(0)+tempStat-2,gameInfo.at(1)+tempStat-2,gameInfo.at(2)+tempStat-2,gameInfo.at(3)+tempStat-2,gameInfo.at(4)+tempStat-2,1,gameInfo.at(6)+tempStat-2});
    }
    if(choice == "5")
    {
        cout << "HP: " << gameInfo.at(0) << endl;
        cout << "Attack: " << gameInfo.at(1) << endl;
        cout << "Defense: " << gameInfo.at(2) << endl;
        cout << "Magic Attack: " << gameInfo.at(3) << endl;
        cout << "Magic Defense: " << gameInfo.at(4) << endl;
        cout << "Class: " << whatClass(gameInfo.at(5)) << endl;
        cout << "Level: " << gameInfo.at(6) << endl;
        cout << "Experience: " << gameInfo.at(7) << "/" << 5*gameInfo.at(6)*(gameInfo.at(6)+1) << endl;
        cout << "Coins: " << gameInfo.at(9) << endl << endl;
        cin.ignore();
    }
    if(choice == "6")
    {
        exit(2);
    }

    vector<int> tempLevelInfo;
    tempLevelInfo = levelCheck(gameInfo.at(6),gameInfo.at(7));
    gameInfo.at(6) = tempLevelInfo.at(0);
    gameInfo.at(7) = tempLevelInfo.at(1);
    
    return gameInfo;
}

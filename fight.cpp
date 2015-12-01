/*
 * =====================================================================================
 *
 *       Filename:  fight.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2015  3:06:02 PM
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
#include <string>

#include "util.h"
#include "fight.h"

using namespace std;

int fight(vector<int> playerStat, vector<int> enemyStat)//int for money stolen
{
    int stolen = 0;

    string choice;
    string enemyChoice;

    int playerHealth = playerStat.at(0);
    int enemyHealth = enemyStat.at(0);

    bool selfDefend;
    bool enemyDefend;

    //gameInfo is in this order:
    //hp,atk,def,magatk,magdef,class,level,exp,alive,coins
    
    while(true)
    {
        cout << "Choices:\n" 
             << "\t1. Physical Attack\n"
             << "\t2. Defend\n"
             << "\t3. Magic Attack\n"
             << "\t4. Magic Heal\n"
             << "\t5. Snatch\n\n";
        cin >> choice;

        enemyChoice = enemyFight(playerHealth,enemyHealth,enemyStat);

        if(choice == "2")
        {
            selfDefend = true;
        }
        if(enemyChoice == "2")
        {
            cout << "Your enemy has chosen to defend themself.\n";
            enemyDefend = true;
        }

        if(choice == "1")
        {
            int damage;
            if(enemyDefend)
            {
                damage = playerStat.at(1)-enemyStat.at(1);
                if(damage > 0)
                {
                    enemyHealth -= damage;
                }
            }
            else
            {
                damage = (playerStat.at(1)*1.5)-enemyStat.at(1);
                if(damage > 0)
                {
                    enemyHealth -= damage;
                }
            }
            if(damage > 0)
            {
                cout << "You deal " << damage << " damage.\n";
            }
            else
            {
                cout << "You don't deal any damage.\n";
            }
        }
        if(choice == "3")
        {
            enemyHealth -= playerStat.at(3);
            cout << "You deal " << playerStat.at(3) << " damage.\n";
        }
        if(choice == "4")
        {
            playerHealth += playerStat.at(4);
            cout << "You heal " << playerStat.at(4) << " health.\n";
        }
        if(choice == "5")
        {
            stolen += playerStat.at(6);
            cout << "You steal " << playerStat.at(6) << " dollars.\n";
        }

        if(enemyChoice == "1")
        {
            cout << "Your enemy has chosen to attack.\n";
            int damage;
            if(selfDefend)
            {
                damage = enemyStat.at(1)-playerStat.at(1);
                if(damage > 0)
                {
                    playerHealth -= damage;
                }
            }
            else
            {
                damage = (playerStat.at(1)*1.5)-enemyStat.at(1);
                if(damage > 0)
                {
                    playerHealth -= damage;
                }
            }
            if(damage > 0)
            {
                cout << "Your enemy does " << damage << " damage, leaving you at "
                     << playerHealth << "health.\n";
            }
            else
            {
                cout << "Your enemy does no damage.\n";
            }
        }
        if(enemyChoice == "3")
        {
            playerHealth -= enemyStat.at(3);
            cout << "Your enemy deals " << enemyStat.at(3) << " damage.\n";
        }
        if(enemyChoice == "4")
        {
            enemyHealth += enemyStat.at(4);
            cout << "Your enemy heals " << enemyStat.at(4) << " health.\n";
        }

        if(playerHealth <= 0)
        {
            cout << "You have lost.\n";
            return -1;
        }
        if(enemyHealth <= 0)
        {
            cout << "You have won.\n";
            return stolen;
        }
    }
    return -1;
}

string enemyFight(int selfHealth, int enemyHealth, vector<int> enemyStat)
{
    return "1";
}
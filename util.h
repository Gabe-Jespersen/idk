/*
 * =====================================================================================
 *
 *       Filename:  util.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2015 12:02:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <string>

#ifndef UTIL_H
#define UTIL_H

int classSelect();
std::vector<int> statMaker(int);
std::string whatClass(int);
std::vector<int> levelCheck(int,int);

#endif

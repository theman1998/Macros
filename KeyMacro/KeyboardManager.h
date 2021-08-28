#ifndef _KEYBAORDMANAGER_H_
#define _KEYBAORDMANAGER_H_

#include <windows.h>
#include <iostream>
#include <string>
#include "KeysDefine.h"

/**
 * Controlls all actions taken with the keyboard. 
 */
class KeyboardManagaer 
{
public:
	//constructos
	KeyboardManagaer();

	//methods
	void spamLetter(std::string letter, INPUT* inHolder);
	void spam(INPUT ipKeyboard[2], int amount, int freq);



};



#endif // !_KEYBAORDMANAGER_H_
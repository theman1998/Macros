#include "KeyboardManager.h"


KeyboardManagaer::KeyboardManagaer() 
{

}

void KeyboardManagaer::spamLetter( std::string letter, INPUT* inHolder )
{

    unsigned int letterCode = ::getKeyValue( letter[0] );

    // INPUT ipLetter[2];
     // Set up a generic keyboard event.
    inHolder[0].type = INPUT_KEYBOARD;
    inHolder[0].ki.wScan = 0; // hardware scan code for key
    inHolder[0].ki.time = 0;
    inHolder[0].ki.dwExtraInfo = 0;
    // Press the "E" key
    inHolder[0].ki.wVk = letterCode; // virtual-key code for the "E" key
    inHolder[0].ki.dwFlags = 0; // 0 for key press
    inHolder[1].type = INPUT_KEYBOARD;
    inHolder[1].ki.wScan = 0; // hardware scan code for key
    inHolder[1].ki.time = 0;
    inHolder[1].ki.dwExtraInfo = 0;
    // Press the "E" key
    inHolder[1].ki.wVk = letterCode; // virtual-key code for the "E" key
    inHolder[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press


}



//function that handles the spamming of the keyboard charcter
void KeyboardManagaer::spam( INPUT ipKeyboard[2], int amount, int freq )
{
    Sleep(1000);
    for (int i = 0; i < amount; i++)
    {
        Sleep(freq / 2);
        SendInput(1, &ipKeyboard[0], sizeof(INPUT));
        Sleep(freq / 2);
        SendInput(1, &ipKeyboard[1], sizeof(INPUT));

        Sleep(4);

        if (GetAsyncKeyState(VK_ESCAPE)) break;
    }

}
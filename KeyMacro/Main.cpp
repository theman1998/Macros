// created by ethan medjuck
// program made for windows systems. Used windows input API to create macros and apply macros
//
/// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes



#define WINVER 0x0500
#include "KeysDefine.h"
#include "KeyboardManager.h"


//0=keydown   1=keyup
INPUT ipE[2];
INPUT ipWindows[2];
INPUT ipM[2];
KeyboardManagaer km;
// can save 5 keys
INPUT ipSpace[10];

char exitKey = 'p';
char switchKey = 'l';


// prototypes
void init(), SpamE(), spamMouseE(), windowsP(), freeMode(), watchKey();
void qAsTrigger();


int main()
{

    // intialize
    init(),


        std::cout << +'a' << std::endl;
    std::cout << +'z' << std::endl;

    std::cout << "1 2 3 macro program!" << std::endl;
    std::cout << "Features are coming, first we can used a pre define tempplate, or we can set the pattern and keys we want (not created yet)." << std::endl;
    std::cout << "commands: " << std::endl;
    std::cout << "(k)unlock free mode: 3" << std::endl;
    std::cout << "("<< switchKey <<") to switch auto left click" << std::endl;
    std::cout << "("<< exitKey << ") exit program" << std::endl;


    while (1) 
    {
        //std::string userInput = " ";
        //std::cin >> userInput;
        Sleep(1000);

        //if (GetAsyncKeyState(getKeyValue(switchKey))
        //{
        //    SpamE();
        //}
        //else if (GetAsyncKeyState(getKeyValue(switchKey))
        //{
        //    spamMouseE();
        //}

        if (GetAsyncKeyState( getKeyValue( 'k' )))
        {
            freeMode();
        }
        else if ( GetAsyncKeyState( getKeyValue(switchKey)))
        {
            qAsTrigger();
        }

        //exit and leave
        if (GetAsyncKeyState( getKeyValue(exitKey)))
        {
            break;
        }
        Sleep(1000);
    }


    return 0;
}

//option witch will allow us to set out keys and create patterns
void freeMode()
{
    INPUT inputKey[2];
    std::string inKey;
    int loopCounter = 0;
    int speedMS = 10;


    std::cout << "We are in free mode! lets set up some keys" << std::endl;
    std::cout << "what key would you like spam?";
    std::cin >> inKey;
    std::cout << "how many times would you like it clicked?" << std::endl;
    std::cin >> loopCounter;
    std::cout << "time between each click (in milliseconds)?" << std::endl;
    std::cin >> speedMS;

    km.spamLetter(inKey, inputKey);
    km.spam(inputKey, loopCounter, speedMS);


    std::cout << "returning to main menu!" << std::endl;
    //while (1)
    //{
    //    if (GetAsyncKeyState(VK_ESCAPE))break;
    //    watchKey();
    //}
}

void qAsTrigger()
{
    std::cout << "left click spammable: (true)" << std::endl;
    int clickTrigger = 0;
    while (1)
    {
        if ( GetAsyncKeyState( VK_LBUTTON) && clickTrigger == 0 )
        {
            Sleep(50);
            for (int i = 0; i < 5; i++)
            {
                SendInput(1, &ipM[0], sizeof(INPUT));
                Sleep(40);
                SendInput(1, &ipM[1], sizeof(INPUT));
                Sleep(40);
            }
            clickTrigger++;
        }
        //else if ( GetAsyncKeyState( getKeyValue( exitKey )))
        //{
        //    for ( int i = 0; i < 8; i++ )
        //    {
        //        Sleep(50);
        //        SendInput(1, &ipM[0], sizeof(INPUT));
        //        Sleep(50);
        //        SendInput(1, &ipM[1], sizeof(INPUT));
        //    }
        //}
        else
        {
            clickTrigger = 0;
        }
        if ( GetAsyncKeyState( getKeyValue( exitKey )) || GetAsyncKeyState(getKeyValue(switchKey))) break;

    }

    std::cout << "left click spammable: (false)" << std::endl;

}


void init()
{
    // Set up a generic keyboard event.
    ipE[0].type = INPUT_KEYBOARD;
    ipE[0].ki.wScan = 0; // hardware scan code for key
    ipE[0].ki.time = 0;
    ipE[0].ki.dwExtraInfo = 0;
    // Press the "E" key
    ipE[0].ki.wVk = 0x45; // virtual-key code for the "E" key
    ipE[0].ki.dwFlags = 0; // 0 for key press
    ipE[1].type = INPUT_KEYBOARD;
    ipE[1].ki.wScan = 0; // hardware scan code for key
    ipE[1].ki.time = 0;
    ipE[1].ki.dwExtraInfo = 0;
    // Press the "E" key
    ipE[1].ki.wVk = 0x45; // virtual-key code for the "E" key
    ipE[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press



    //mouse
    ipM[0].type = INPUT_MOUSE;
    ipM[0].mi.time = 0;
    ipM[0].mi.dwExtraInfo = 0;

    ipM[1].type = INPUT_MOUSE;
    ipM[1].mi.time = 0;
    ipM[1].mi.dwExtraInfo = 0;

    // Release the "Left button down" key
    ipM[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN; // KEYEVENTF_KEYUP for key release

    ipM[1].mi.dwFlags = MOUSEEVENTF_LEFTUP; // KEYEVENTF_KEYUP for key release


    // Set up a generic keyboard event.
    ipWindows[0].type = INPUT_KEYBOARD;
    ipWindows[0].ki.wScan = 0; // hardware scan code for key
    ipWindows[0].ki.time = 0;
    ipWindows[0].ki.dwExtraInfo = 0;
    // Press the "E" key
    ipWindows[0].ki.wVk = VK_LWIN; // virtual-key code for the "E" key
    ipWindows[0].ki.dwFlags = 0; // 0 for key press
    ipWindows[1].type = INPUT_KEYBOARD;
    ipWindows[1].ki.wScan = 0; // hardware scan code for key
    ipWindows[1].ki.time = 0;
    ipWindows[1].ki.dwExtraInfo = 0;
    // Press the "E" key
    ipWindows[1].ki.wVk = VK_LWIN; // virtual-key code for the "E" key
    ipWindows[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press




}

void SpamE()
{
    Sleep(1000);
    for (int i = 0; i < 300; i++)
    {
        Sleep(20);
        SendInput(1, &ipE[0], sizeof(INPUT));
        Sleep(20);
        SendInput(1, &ipE[1], sizeof(INPUT));
        
        Sleep(4);

        if (GetAsyncKeyState(VK_ESCAPE)) break;
    }
    

}


void spamMouseE()
{
    Sleep(1000);
    for (int i = 0; i < 300; i++)
    {
        Sleep(10);
        SendInput(1, &ipM[0], sizeof(INPUT));
        Sleep(10);
        SendInput(1, &ipM[1], sizeof(INPUT));
        Sleep(20);
        SendInput(1, &ipE[0], sizeof(INPUT));
        Sleep(20);
        SendInput(1, &ipE[1], sizeof(INPUT));

        if (GetAsyncKeyState(VK_ESCAPE)) break;

    }

}


void windowsP()
{

    SHORT state = GetAsyncKeyState(VK_NUMLOCK);




    if (state & 1)
    {
      SendInput(1, &ipWindows[0], sizeof(INPUT));
        SendInput(1, &ipWindows[1], sizeof(INPUT));
    }

}


void watchKey()
{

    //checks to see if key was pressed
   SHORT state = GetAsyncKeyState(0x45);


   if (state & 1)
   {
       SendInput(1, &ipWindows[0], sizeof(INPUT));
       SendInput(1, &ipWindows[1], sizeof(INPUT));
   }

}

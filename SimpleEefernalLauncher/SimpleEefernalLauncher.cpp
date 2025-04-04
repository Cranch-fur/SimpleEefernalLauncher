#include <iostream>

#include <conio.h>
#include <windows.h>
#include <iostream>
#include "CranchyLib.h"

using namespace std;




const string startupTargetPath = "EefernalFog\\StartupTarget.txt";
const string startupArgumentsPath = "EefernalFog\\StartupArguments.txt";




void Close(string message = "")
{
    cout << endl << endl;


    if (message.empty() == false)
        cout << message << endl;


    cout << "Press any key to continue...";
    _getch();
    exit(0);
}




int main()
{
    if (FileUtilities::FileExist(startupTargetPath) == false) 
    {
        Close("ERROR: \"" + startupTargetPath + "\" file doesn't exist!");
    }
    string startupTarget = FileUtilities::ReadFileContents(startupTargetPath);
    if (startupTarget.empty())
    {
        Close("ERROR: Failed to read \"" + startupTargetPath + "\" file contents!");
    }
    cout << "Startup Target: " << startupTarget << endl;


    if (FileUtilities::FileExist(startupArgumentsPath) == false)
    {
        Close("ERROR: \"" + startupArgumentsPath + "\" file doesn't exist!");
    }
    string startupArguments = FileUtilities::ReadFileContents(startupArgumentsPath);
    if (startupArguments.empty()) 
    {
        cout << "Startup Arguments: Failed to read \"" + startupArgumentsPath + "\" file contents or there's no startup arguments set!" << endl;
    }
    else 
    {
        cout << "Startup Arguments: " << startupArguments << endl;
    }
    

    if (WindowsUtilities::StartProcess(startupTarget, startupArguments) == false) 
    {
        Close("ERROR: Failed to start process!");
    }


    exit(0);
}
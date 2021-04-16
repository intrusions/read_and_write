#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 10008);
        if (hProcess == NULL)
        {
            cout << "Erreur : " << GetLastError() << endl;
            system("pause");
            return EXIT_FAILURE;
        }

        int intToWrite = 666;
        WriteProcessMemory(hProcess, (LPVOID)0x8FFB50, &intToWrite, sizeof(int), NULL);
        if (WriteProcessMemory != 0)
            cout << "Overwritten successfully" << endl;
        else
        { 
            cout << "error code : " << GetLastError() << endl;
            system("pause");
            return EXIT_FAILURE;
        }
        CloseHandle(hProcess);
        cout << "Press ENTER to quit." << endl;
        system("pause > nul");
}
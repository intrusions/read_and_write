#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 2472);
    if (!hProcess)
    {
        cout << "Error : " << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    }

    int int_to_write = 666;
    WriteProcessMemory(hProcess, (LPVOID)0xC7DEBCF604, &int_to_write, sizeof(int), NULL);
    if (WriteProcessMemory)
        cout << "int overwritten successfully" << endl;
    else
    {
        cout << "Error code : " << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    }

    string string_to_write = "xel was here";
    WriteProcessMemory(hProcess, (LPVOID)0xC7DEBCF628, &string_to_write, sizeof(string), NULL);
    if (WriteProcessMemory)
        cout << "string overwritten successfully" << endl;
    else
    {
        cout << "Error code : " << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    }
    CloseHandle(hProcess);
    cout << "Press ENTER to quit." << endl;
    system("pause > nul");
}

#include <windows.h>
#include <iostream>

using namespace std;


int		main()
{
	HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, 13124); // hProcess

	if (hProcess == NULL)
	{
		cout << "Echec d'OpenProcess. GetLastError =" << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	LPCVOID lpBaseAddressPtr2int = (LPCVOID)0x4FFC0C; //lpBaseAddress ptr2int
	int value_intRead = 0; // lpBuffer
	int value_ptr2int = 0;
	char value2string[120] = "0";
	int nSize = sizeof(int); // nSize

	ReadProcessMemory(hProcess, lpBaseAddressPtr2int, &value_ptr2int, nSize, NULL);
	cout << "Ce qu'il se trouve dans l'dresse donner = " << hex << value_ptr2int << endl;
	ReadProcessMemory(hProcess, (LPCVOID)value_ptr2int, &value_ptr2int, nSize, NULL);
	cout << "Ce qu'il se trouve a l'adresse qui etait stocker dans l'adresse d'avant = " << dec << value_ptr2int << endl;
	ReadProcessMemory(hProcess, (LPCVOID)0x4FFCA0, &value2string, sizeof(value2string), NULL);
	cout << "Ce qu'il se trouve a l'adresse de varString = " << hex << value2string << endl;
	CloseHandle(hProcess);
	cout << "Appuyez sur ENTER pour quitter." << endl;
	system("pause");

}
#include <Windows.h>
#include <iostream>
#include <string>


#define CHAR_ARRAY_SIZE 128

using namespace std;

int main() {
	int varInt(123456);
	string varString("A simple string");

	do {
		cout << "Process ID: " << dec << GetCurrentProcessId() << endl;
		cout << endl;
		cout << "varInt       (0x" << hex << uppercase << (uintptr_t)&varInt << ") = " << dec << varInt << endl;
		cout << "varString    (0x" << hex << uppercase << (uintptr_t)&varString << ") = " << varString << endl;
		cout << endl;
		cout << "Press ENTER to print again." << endl;
		getchar();
		cout << endl << "---------------------------------------------------" << endl << endl;
	} while (true);

	return EXIT_SUCCESS;
}

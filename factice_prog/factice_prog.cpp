#include <Windows.h>
#include <iostream>
#include <string>


#define CHAR_ARRAY_SIZE 128

using namespace std;

int main() {
	int var_int(123456);
	string var_string("A simple string");

	do {
		cout << "Process ID: " << dec << GetCurrentProcessId() << endl;
		cout << endl;
		cout << "varInt       (0x" << hex << uppercase << (uintptr_t)&var_int << ") = " << dec << var_int << endl;
		cout << "varString    (0x" << hex << uppercase << (uintptr_t)&var_int << ") = " << var_int << endl;
		cout << endl;
		cout << "Press ENTER to print again." << endl;
		getchar();
		cout << endl << "---------------------------------------------------" << endl << endl;
	} while (true);

	return EXIT_SUCCESS;
}

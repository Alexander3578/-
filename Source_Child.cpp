#include <iostream>
#include <windows.h>
#include <conio.h>


using namespace std;

int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "ru");
	double n = atof(argv[0]);
	double* mass = new double[n];
	double el;
	double A = atof(argv[argc - 1]);
	int j = 0;
	for (int i = 1; i < argc - 1; i++) {
		el = atof(argv[i]);
		if (el > A) {
			mass[j] = atof(argv[i]);
			j++;
		}
	}
	for (; j < n; j++) {
		mass[j] = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << mass[i] << endl;
	}
	//_cprintf("\n My %d parameter =  %s", i, argv[i]);

	_cputs("\nНажмите любую клавишу.\n");
	_getch();

	delete[] mass;

	return 0;
}
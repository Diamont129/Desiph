#include <iostream>
#include <locale>
#include <cctype>


using namespace std;

const char sot[10] = { 'д', 'л', 'ж', 'б', 'о', 'я', 'е', 'ю', 'и', 'с' };

char* swap(char* s, int b, int c, int d)
{
	int v = 0;
	for (int i = 0; i < (strlen(s)); i++)
	{
		if ((s[i] > -65) && (s[i] < -32)) { s[i] = s[i] + 32; v = 1; }
		for (int j = 0; j < 10; j++)
		{
			if (s[i] == sot[j])
			{
				if (j == d) { s[i] = sot[c]; break; }
				s[i] = sot[j + b];
				break;
			}
		}
		if (v == 1) { s[i] = s[i] - 32; v = 0; }
	}
	return s;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	char fam[] = "Фамилия";
	char vir[] = "Оясшьде ню люжай. Люжаюшь - ню ояйде. Тэмулбен Ченгедхан";
	cout << "Введите 1 для шифровки слова Фамилия, 2 для дешифровки фразы: ";
	cin >> a;
	switch (a)
	{
	case 1: { b = 1; c = 0; d = 9;
		cout << swap(fam, b, c, d) << endl;
		system("Pause");
		break;
	}
	case 2: { b = -1; c = 9; d = 0;
		cout << swap(vir, b, c, d) << endl;
		system("Pause");
		break;
	}
	}
}
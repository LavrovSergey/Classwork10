#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

struct scan_info {
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
}s;

void write(scan_info* mas, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << ':';
		cout << "Название модели: ";
		while (mas[i].model[0] == '\0' || mas[i].model[0] < 0)
		{
			cin.getline(mas[i].model, 25);
		}
		for (int j = strlen(mas[i].model); j < 24; j++)
		{
			char a = '0';
			mas[i].model[j] = a;
		}
		mas[i].model[24] ='\0';
		while (mas[i].price <0)
		{   
			cout << "Цена: ";
			cin>>mas[i].price;
		}
		while (mas[i].x_size < 0)
		{
			cout << "Горизонтальный размер области сканирования: ";
			cin >> mas[i].x_size;
		}
		while (mas[i].y_size < 0)
		{
			cout << "Вертикальный размер области сканирования: ";
			cin >> mas[i].y_size;
		}
		while (mas[i].optr < 0)
		{
		    cout << "Оптическое разрешение: ";
			cin >> mas[i].optr;
		}
		while (mas[i].grey < 0)
		{
			cout << "Число градаций серого: ";
			cin >> mas[i].grey;
		}
		cout << endl;
	}

	cout << endl;
	ofstream file("scan.doc");
	for (int i = 0; i < n; ++i) {
		file.write((char*)& mas[i], sizeof(scan_info));
	}
	file.close();
	
}

void write_bin(scan_info* mas, int n)
{
    ofstream bin("scan.bin");
	bin << n;
	for (int i = 0; i < n; ++i) 
	 { 
		for (int j = 0; j < 25; ++j)
		{
			if (mas[i].model[j] !='0'&& mas[i].model[j] != '\0') { bin << mas[i].model[j]; }
		}
		bin << mas[i].price << mas[i].x_size << mas[i].y_size << mas[i].optr << mas[i].grey;
	 }
}



int main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество принтеров " << endl;
	cin >> n;
	scan_info* mas = new scan_info[n];
	write(mas, n);
	write_bin(mas, n);
	

}


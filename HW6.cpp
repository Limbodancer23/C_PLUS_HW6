#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
/*
1) Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
 Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.
2) Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
 Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
3) Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
Имена файлов запросить у польлзователя.
4) * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
5) * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
Используем функцию find которая есть в строках std::string.
*/
int** FillMatrix(size_t size, int** ppArr);
int** PrintMatrix(size_t size, int** ppArr);
int** DelMatrix(size_t size, int** ppArr);
void Combiner(std::string file1, std::string file2);
inline void PowerOfTwo() {
	int size = 0;
	int val = 2;
	std::cout << "Enter array size: ";
	std::cin >> size;
	int* pArr = new (std::nothrow) int[size];

	if (pArr != nullptr)
	{
		for (size_t i = 0; i < size; i++)
		{
			pArr[i] = 2 << i;

			std::cout << pArr[i] << " ";
		}
	}
	else
	{
		std::cout << "Can not allocate memory!";
	}

	delete[] pArr;
	pArr = nullptr;
}

 int** MatrixCreator() {
	int** ppArr;
	const size_t N = 4;
	const size_t M = 4;

	ppArr = new int* [M];

	for (size_t i = 0; i < M; i++)
	{
		ppArr[i] = new int[N];
	}
	return ppArr;

}

int** FillMatrix(size_t size, int** ppArr) {
	srand(time(0));
	for (size_t i = 0; i <= (size / 2) + 1; i++)
	{
		for (size_t j = 0; j <= size / 2 ; j++)
		{
			ppArr[i][j] = rand() % 100;
			ppArr[size - i - 1][size - j - 1] = rand() % 100;
		}
	}

	return ppArr;
}

int** PrintMatrix(size_t size, int** ppArr) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << ppArr[i][j] << " ";
		}
		std::cout << "\n";
	}

	return ppArr;
}

int** DelMatrix(size_t size, int** ppArr) {
	for (size_t i = 0; i < size; i++)
	{
		delete[] ppArr[i];
	}

	delete[] ppArr;
	ppArr = nullptr;
	return 0;
}

void FileManager() {
	std::string file1;
	std::string file2;
	std::cout << "Enter filename for first text: ";
	if (!std::cin.fail())
	{
		std::cin >> file1;
	}
	else
	{
		std::cout << "Try again!";
	}

	std::cout << "Enter filename for second text: ";
	if (!std::cin.fail())
	{
		std::cin >> file2;
	}
	else
	{
		std::cout << "Try again!";
	}
	std::ofstream fout1(file1 + ".txt");
	std::ofstream fout2(file2 + ".txt");
	fout1 << "Lorem ipsum dolor sit amet, consectetur adipiscing elit," << "\n";
	fout1 << "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." << "\n";
	fout1 << "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Duis aute irure dolor in reprehenderitin voluptate velit esse cillum dolore eu fugiat nulla pariatur.Excepteur sint occaecat cupidatat non proident" << "\n";
	fout1 << "sunt in culpa qui officia deserunt mollit anim id est laborum." << "\n";

	for (size_t i = 0; i < 50; i++)
	{
		fout2 << i << "\n";
	}
	fout1.close();
	fout2.close();

	Combiner(file1, file2);
}

void Combiner(std::string file1, std::string file2) {
	std::ifstream fin(file1 + ".txt");
	std::ofstream fout("united.txt");

	std::string str;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::getline(fin, str);
			fout << str << std::endl;
		}

	}
	fin.close();

	std::ifstream fin1(file2 + ".txt");
	if (fin1.is_open())
	{
		while (!fin1.eof())
		{
			std::getline(fin1, str);
			fout << str << std::endl;
		}

	}
	fin1.close();
}

void FindLetter(std:: string filename, std::string letter) {
	std::ifstream fin(filename);
	std::string str;
	bool flag = false;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::getline(fin, str);
			if (str.find(letter) != std::string::npos)
			{
				flag = true;
				break;
			}
		}
	}
	fin.close();
	if (flag) {
		std::cout << "Letter " << "'" << letter << "' " << "found!";
	}
	else
	{
		std::cout << "Not found!";
	}
}

int main()
{
	//PowerOfTwo();

	//DelMatrix(4, PrintMatrix(4, FillMatrix(4, MatrixCreator())));
	
	//FileManager();
	
	//FindLetter("united.txt", "2");
}

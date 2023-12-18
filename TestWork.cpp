
#include "TestWork.h"

struct IndexedNumbers
{
	//Cоздаем структуру для сохранения начальных индексов.
	unsigned int num_index;
	double value;//вещественные числа с двойной точностью

};


int main()
{
	setlocale(LC_CTYPE, "Russian");//Поддержка русского языка

	cout << "Введите размер массива:" << endl;
	//задаем вводом размер массива

	unsigned int* array_size = new unsigned int;//Условие ТЗ - на вход целое положительное число, размером не более 4 байт, тип unsigned int ему удовлетворяет.

	cin >> *array_size;


	// Вводим числа и с применяем описанную структуру для сохранения индексов
	//выделяем память под массив этих структур
	IndexedNumbers* num_array = new IndexedNumbers[*array_size];
	//заполнение массива
	for (int i = 0; i < *array_size; ++i)
	{
		cin >> num_array[i].value;
		num_array[i].num_index = i;
	}

	// Сортировка массива по значениям в убывающем порядке, правило задано в лямбда функции
	//использовать std sort как по мне для решения данной задачи вполне оптимально.
	//Так как задача описана довольно в общем плане, и на каком уровне должна быть эффективность не сильно понятно.

	sort((num_array), (num_array + *array_size), [](const IndexedNumbers& a, const IndexedNumbers& b) {	return a.value > b.value; });

	// Вывод двух наибольших элементов и их индексов 
	cout << "Наибольшие числа:\n";

	for (int i = 0; i < min((unsigned)2, *array_size); ++i)
	{
		cout << "Число: " << num_array[i].value << "\t" << "Индекс: " << num_array[i].num_index << endl;
	}

	//освобождаем память, которую заняли
	delete array_size;
	array_size = nullptr;
	delete[] num_array;
	num_array = nullptr;
}


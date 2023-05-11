#include <stdlib.h>
#include <stdint.h>

//==================================================
//					Selection Sort
void SelectSort(uint32_t array[], uint32_t size)
{
	for (int i = 0; i < size - 1; i++) {
	/* устанавливаем начальное значение минимального индекса */
		int min_i = i;
		/* находим индекс минимального элемента */
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min_i]) {
				min_i = j;
			}
		}
		/* меняем значения местами */
		int tmp = array[i];
		array[i] = array[min_i];
		array[min_i] = tmp;
	}
}

//==================================================
// 					Quick Sort
void QuickSort(uint32_t array[], long int left, long int right)
{
    int pivot, tmp;
    long int i = left, j = right;
    pivot = array[(i + j) / 2];		// Получение опорного элемента
    do
    {
        while (array[i] < pivot)
			i++;
        while (array[j] > pivot)
			j--;
        if (i <= j )
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    while (i < j);
	if (left < j)
		QuickSort(array, left, j);
    if (i < right)
		QuickSort(array, i, right);
}


//==================================================
//					Radix Sort
void RadixSort(uint32_t array[], uint32_t size)
{
	int i, exp=1;
	uint32_t m=0;
	// Создание временного массива
	uint32_t *b = malloc(sizeof(uint32_t)*size);
	for(i=0; i < size; i++)
		if(array[i] > m)
			m = array[i];
	while(m / exp > 0)
	{
		int buff[10] = {0};
		for(i = 0; i < size; i++)
			buff[array[i] / exp % 10]++;
		for(i = 1; i < 10; i++)
			buff[i] += buff[i - 1];
		for(i = size - 1; i >= 0; i--)
			b[--buff[array[i] / exp % 10]] = array[i];
		for(i=0; i < size; i++)
			array[i] = b[i];
		exp *= 10;
	}
	free(b);
}

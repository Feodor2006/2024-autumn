#include <iostream>
#include <cstdlib>
#include <cstdio>

class ArrayList
{
private:
    int len;
    int capacity; // добавляем переменную для хранения текущей вместимости
    int* data;

    void init(int capacity = 10)
    {
        this->len = 0; // изначально длина равна 0
        this->capacity = capacity;
        this->data = (int*)malloc(sizeof(int) * capacity);
    }

    bool indexValid(int index)
    {
        return 0 <= index && index < this->len; // исправлено условие
    }

    void expand()
    {
        capacity *= 2; // удваиваем вместимость
        data = (int*)realloc(data, sizeof(int) * capacity);
    }

public:
    ArrayList(int capacity = 10)
    {
        this->init(capacity);
    }

    ArrayList(const ArrayList& list)
    {
        this->init(list.capacity);
        this->len = list.len;
        for (int i = 0; i < list.len; ++i)
        {
            this->data[i] = list.data[i];
        }
    }

    ~ArrayList()
    {
        free(this->data);
    }

    void randomize(int min = 10, int max = 99)
    {
        for (int i = 0; i < capacity; ++i)
        {
            this->data[i] = rand() % (max - min + 1) + min;
        }
        len = capacity; // устанавливаем длину массива на заполненное количество
    }

    void print()
    {
        for (int i = 0; i < this->len; ++i)
        {
            printf("%d ", this->data[i]);
        }
        printf("\n");
    }

    int get(int index)
    {
        if (indexValid(index))
        {
            return this->data[index];
        }
        return -1;
    }

    void set(int index, int value)
    {
        if (indexValid(index))
        {
            this->data[index] = value;
        }
    }

    int count()
    {
        return len;
    }

    void pushBack(int element)
    {
        if (len == capacity)
        {
            expand();
        }
        data[len++] = element; // добавляем элемент и увеличиваем длину
    }

    void pushFront(int element)
    {
        if (len == capacity)
        {
            expand();
        }
        for (int i = len; i > 0; --i)
        {
            data[i] = data[i - 1]; // сдвигаем элементы вправо
        }
        data[0] = element; // помещаем новый элемент в начало
        len++;
    }

    void insert(int index, int element)
    {
        if (index < 0 || index > len) return; // проверка валидности индекса
        if (len == capacity)
        {
            expand();
        }
        for (int i = len; i > index; --i)
        {
            data[i] = data[i - 1]; // сдвигаем элементы вправо
        }
        data[index] = element; // вставляем элемент
        len++;
    }

    int popBack()
    {
        if (len > 0)
        {
            return data[--len]; // возвращаем последний элемент и уменьшаем длину
        }
        return -1; // если массив пуст
    }

    int popFront()
    {
        if (len > 0)
        {
            int firstElement = data[0];
            for (int i = 0; i < len - 1; ++i)
            {
                data[i] = data[i + 1]; // сдвигаем элементы влево
            }
            len--;
            return firstElement; // возвращаем первый элемент
        }
        return -1; // если массив пуст
    }

    int extract(int index)
    {
        if (!indexValid(index)) return -1; // проверка валидности индекса
        int extractedValue = data[index];
        for (int i = index; i < len - 1; ++i)
        {
            data[i] = data[i + 1]; // сдвигаем элементы влево
        }
        len--;
        return extractedValue; // возвращаем извлеченное значение
    }

    void reverse(int start, int end)
    {
        while (start < end)
        {
            std::swap(data[start], data[end]); // меняем местами элементы
            start++;
            end--;
        }
    }

    int sum()
    {
        int total = 0;
        for (int i = 0; i < len; ++i)
        {
            total += data[i]; // суммируем элементы
        }
        return total;
    }

    int secondMax()
    {
        if (len < 2) return -1; // если элементов меньше 2

        int first = -1, second = -1; // инициализируем первое и второе максимальные значения
        for (int i = 0; i < len; ++i)
        {
            if (data[i] > first)
            {
                second = first;
                first = data[i];
            }
            else if (data[i] > second && data[i] < first)
            {
                second = data[i];
            }
        }
        return second; // возвращаем второе максимальное значение
    }

    int lastMinIndex()
    {
        if (len == 0) return -1; // если массив пуст
        int lastIndex = 0;
        int minValue = data[0];

        for (int i = 1; i < len; ++i)
        {
            if (data[i] <= minValue)
            {
                minValue = data[i];
                lastIndex = i; // запоминаем последние индекс минимального элемента
            }
        }
        return lastIndex;
    }

    int shift(int k)
    {
        k = k % len; // корректируем k для снижения размера
        if (k < 0) k += len; // обрабатываем отрицательное значение
        reverse(0, len - 1);
        reverse(0, len - k - 1);
        reverse(len - k, len - 1); // вращаем массив
        return len;
    }

    int countOdd()
    {
        int count = 0;
        for (int i = 0; i < len; ++i)
        {
            if (data[i] % 2 != 0)
            {
                count++;
            }
        }
        return count;
    }

    int sumEven()
    {
        int totalEven = 0;
        for (int i = 0; i < len; ++i)
        {
            if (data[i] % 2 == 0)
            {
                totalEven += data[i]; // суммируем четные элементы
            }
        }
        return totalEven;
    }
};

int max(ArrayList list)
{
    int mx = list.get(0);
    for (int i = 0; i < list.count(); ++i)
    {
        mx = (mx > list.get(i) ? mx : list.get(i));
    }
    return mx;
}

int main(int argc, char* argv[])
{
    ArrayList list(10);
    list.randomize();
    list.print();
    printf("Max: %d\n", max(list));
    printf("Sum: %d\n", list.sum());
    printf("Second Max: %d\n", list.secondMax());
    printf("Last Min Index: %d\n", list.lastMinIndex());
    printf("Count Odd: %d\n", list.countOdd());
    printf("Sum Even: %d\n", list.sumEven());
    return 0;
}
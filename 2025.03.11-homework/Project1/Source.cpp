#include <iostream>
#include <cstdlib>
#include <cstdio>

class ArrayList
{
private:
    int len;
    int capacity; // ��������� ���������� ��� �������� ������� �����������
    int* data;

    void init(int capacity = 10)
    {
        this->len = 0; // ���������� ����� ����� 0
        this->capacity = capacity;
        this->data = (int*)malloc(sizeof(int) * capacity);
    }

    bool indexValid(int index)
    {
        return 0 <= index && index < this->len; // ���������� �������
    }

    void expand()
    {
        capacity *= 2; // ��������� �����������
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
        len = capacity; // ������������� ����� ������� �� ����������� ����������
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
        data[len++] = element; // ��������� ������� � ����������� �����
    }

    void pushFront(int element)
    {
        if (len == capacity)
        {
            expand();
        }
        for (int i = len; i > 0; --i)
        {
            data[i] = data[i - 1]; // �������� �������� ������
        }
        data[0] = element; // �������� ����� ������� � ������
        len++;
    }

    void insert(int index, int element)
    {
        if (index < 0 || index > len) return; // �������� ���������� �������
        if (len == capacity)
        {
            expand();
        }
        for (int i = len; i > index; --i)
        {
            data[i] = data[i - 1]; // �������� �������� ������
        }
        data[index] = element; // ��������� �������
        len++;
    }

    int popBack()
    {
        if (len > 0)
        {
            return data[--len]; // ���������� ��������� ������� � ��������� �����
        }
        return -1; // ���� ������ ����
    }

    int popFront()
    {
        if (len > 0)
        {
            int firstElement = data[0];
            for (int i = 0; i < len - 1; ++i)
            {
                data[i] = data[i + 1]; // �������� �������� �����
            }
            len--;
            return firstElement; // ���������� ������ �������
        }
        return -1; // ���� ������ ����
    }

    int extract(int index)
    {
        if (!indexValid(index)) return -1; // �������� ���������� �������
        int extractedValue = data[index];
        for (int i = index; i < len - 1; ++i)
        {
            data[i] = data[i + 1]; // �������� �������� �����
        }
        len--;
        return extractedValue; // ���������� ����������� ��������
    }

    void reverse(int start, int end)
    {
        while (start < end)
        {
            std::swap(data[start], data[end]); // ������ ������� ��������
            start++;
            end--;
        }
    }

    int sum()
    {
        int total = 0;
        for (int i = 0; i < len; ++i)
        {
            total += data[i]; // ��������� ��������
        }
        return total;
    }

    int secondMax()
    {
        if (len < 2) return -1; // ���� ��������� ������ 2

        int first = -1, second = -1; // �������������� ������ � ������ ������������ ��������
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
        return second; // ���������� ������ ������������ ��������
    }

    int lastMinIndex()
    {
        if (len == 0) return -1; // ���� ������ ����
        int lastIndex = 0;
        int minValue = data[0];

        for (int i = 1; i < len; ++i)
        {
            if (data[i] <= minValue)
            {
                minValue = data[i];
                lastIndex = i; // ���������� ��������� ������ ������������ ��������
            }
        }
        return lastIndex;
    }

    int shift(int k)
    {
        k = k % len; // ������������ k ��� �������� �������
        if (k < 0) k += len; // ������������ ������������� ��������
        reverse(0, len - 1);
        reverse(0, len - k - 1);
        reverse(len - k, len - 1); // ������� ������
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
                totalEven += data[i]; // ��������� ������ ��������
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
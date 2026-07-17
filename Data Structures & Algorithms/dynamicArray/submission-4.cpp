class DynamicArray {

private:
    int size;
    int* arr;
    int capacity;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
        return;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();
        arr[size] = n;
        size++;
    }

    int popback() {
        int k = 0;
        k = arr[size - 1];
        size--;
        return k;
    }

    void resize() {
        int newsize = capacity * 2;
        int* newarray = new int[newsize];
        for (int i = 0; i < size; i++)
        {
            newarray[i] = arr[i];
        }
        delete[] arr;
        arr = newarray;
        capacity = newsize;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

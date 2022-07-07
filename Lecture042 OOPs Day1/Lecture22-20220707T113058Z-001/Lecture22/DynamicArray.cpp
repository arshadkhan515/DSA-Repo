class DynamicArray {
    int capacity;
    int totalElements;
    int *arr;
    
    public:
        DynamicArray() {
            capacity = 5;
            totalElements = 0;
            arr = new int[5];
        }
        DynamicArray(DynamicArray const &s2) {
            this->capacity = s2.capacity;
            this->totalElements = s2.totalElements;

            // Shallow copy (Not preferred)
            // arr = s2.arr;

            this->arr = new int[capacity];
            for(int i = 0; i < totalElements; i++) {
                this->arr[i] = s2.arr[i];
            }
        }
        void operator=(DynamicArray const &s2) {
            this->capacity = s2.capacity;
            this->totalElements = s2.totalElements;

            // Shallow copy (Not preferred)
            // arr = s2.arr;

            this->arr = new int[capacity];
            for(int i = 0; i < totalElements; i++) {
                this->arr[i] = s2.arr[i];
            }
        }
        void add(int element) {
            // No elements can be placed
            if(totalElements == capacity) {
                capacity = capacity * 2;
                int* newArr = new int[capacity];
                for(int i = 0; i < totalElements; i++) {
                    newArr[i] = arr[i];
                }
                delete []arr;
                arr = newArr;
            }
            // Place at totalElements position
            arr[totalElements] = element;
            totalElements++;
        }
        int get(int index) const {
            if(index >= totalElements) {
                return -1;
            }
            return arr[index];
        }
        void add(int index, int element) {
            if(index < totalElements) {
                arr[index] = element;
            } else {
                add(element);
            }
        }
        void print() const {
            for(int i = 0; i < totalElements; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        ~DynamicArray() {
            delete []arr;
        }
};
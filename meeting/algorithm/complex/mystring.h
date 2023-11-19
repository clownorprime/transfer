class MyString {
    private:
        char *array;
        int capacity;
        int size;
        const int DEFAULTCAPA = 8;
    public:
        MyString() {
            int capacity = DEFAULTCAPA;
            array = new char[capacity];
        }
        Mystring(int val) {
        }
        Mystring(Mystring &s) {
        }
};

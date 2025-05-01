#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class BadTypeException {
public:
    string message;
    BadTypeException(const string& msg) : message(msg) {}
};

class TypeSafeContainer {
    void* data;
    string typeName;

public:
    TypeSafeContainer() : data(nullptr), typeName("") {}

    template <typename T>
    void store(const T& value) {
        delete (T*)data;
        data = new T(value);
        typeName = typeid(T).name();
    }

    template <typename T>
    T get() {
        if (typeid(T).name() != typeName) {
            throw BadTypeException("Incorrect type requested.");
        }
        return *(T*)data;
    }

    ~TypeSafeContainer() {
        delete (char*)data;
    }
};

int main() {
    try {
        TypeSafeContainer container;
        container.store<int>(42);
        cout << "Stored int: " << container.get<int>() << endl;
        // Uncommenting the line below will throw
        // cout << "Trying wrong type: " << container.get<string>() << endl;
    } catch (BadTypeException& e) {
        cout << "Exception: " << e.message << endl;
    }
    return 0;
}

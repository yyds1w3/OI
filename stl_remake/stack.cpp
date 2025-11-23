#include <stdexcept>
template<typename T>
struct stack
{
    T *m_data;
    int m_capacity;
    int m_top;

    // init
    stack(int capacity = 10) : m_capacity(capacity), m_data(new T[capacity]), m_top(-1) {
        if (capacity <= 0){
            throw std::invalid_argument("Capacity must be positive");
        }
    }
    // destroy
    ~stack() {
        delete[] m_data;
    }
    // copy constructor s1(s2)
    stack(stack& other){
        m_capacity = other.m_capacity;
        m_top = other.m_top;
        m_data = new T[m_capacity];
        for (int i = 0; i < m_top + 1; ++i){
            m_data[i] = other.m_data[i];
        }
    }
    // copy assignment Opertaor s1 = s2
    stack& operator = (stack& other){
        if (this != other){
            m_capacity = other->m_capacity;
            m_top = other->m_top;
            m_data = new T[m_capacity];
            for (int i = 0; i < m_top + 1; ++i){
                m_data[i] = other->m_data[i];
            }
            return *this;
        }
    }
    // get_capacity
    int get_capacity(){
        return m_capacity;
    }
    // get_size
    int get_size(){
        return m_top + 1;
    }
    // empty
    bool empty(){
        return get_size() == 0;
    }
    // full
    bool full(){
        return get_size() == m_capacity;
    }
    // push
    void push(const T& value){
        if (full()){
            resize(2 * m_capacity);
        }
        m_data[++m_top] = value;
    }
    // pop
    void pop(){
        if (empty()){
            throw std::runtime_error("Stack underflow: Cannot pop form empty stack.");
        }
        m_top--;
    }
    // top
    T& top(){
        return m_data[m_top];
    }
    // top const version
    const T& top() const{
        return m_data[m_top];
    }
    // clear
    void clear(){
        m_top = -1;
    }

private:
    // resize
    void resize(int new_capacity){
        T* new_data = new T[m_capacity];
        for (int i = 0; i < m_capacity; ++i){
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
};

// // test
// #include <iostream>
// int main(){
//     stack<int> s1(1);
//     s1.push(1);
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     s1.push(2);
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     s1.push(3);
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     s1.push(4);
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     s1.push(5);
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     stack<int> s2 = s1;
//     std::cout << s2.top() << " " << s2.get_capacity() << std::endl;
//     s2.pop();
//     std::cout << s1.top() << " " << s1.get_capacity() << std::endl;
//     std::cout << s2.top() << " " << s2.get_capacity() << std::endl;
// }

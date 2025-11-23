#include <stdexcept>
template<typename T>
struct queue
{
    T *m_data;
    int m_capacity;
    int m_front;
    int m_back;

    queue(int capacity = 10) : m_capacity(capacity), m_data(new T[capacity]), m_front(0), m_back(0) {
        if (capacity <= 0)
            throw std::invalid_argument("Queue capacity cannot be less than 1");
    }
    ~queue(){
        delete[] m_data;
    }
    T front(){
        if (empty())
            throw std::runtime_error("Cannot get front from the empty queue");
        return m_data[m_front];
    }
    const T& front() const{
        return m_data[m_front];
    }
    T back(){
        if (empty())
            throw std::runtime_error("Cannot get back from the empty queue");
        return m_data[m_back-1];
    }
    const T& back() const
    {
        return m_data[m_back-1];
    }
    int get_capacity(){
        return m_capacity;
    }
    int get_size(){
        if (m_back < m_front)
            return m_back + m_capacity - m_front;
        else
            return m_back - m_front;
    }
    bool empty(){
        return get_size() == 0;
    }
    bool full(){
        return get_size() == m_capacity - 1; // 还剩一个元素默认满了
    }
    void push(const T& value){
        if (full())
            resize(2 * m_capacity);
        m_data[m_back++] = value;
    }

    void pop(){
        if (empty())
            throw std::runtime_error("Queue is empty, cannot pop from an empty queue.");
        ++m_front;
    }

private:
    void resize(int new_capacity){
        T *new_data = new T[new_capacity];
        for (int i = m_front; i % m_capacity != m_back; ++i){
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
};

//test
// #include <iostream>
// int main(){
//     queue<int> q(1);
//     q.push(1);
//     std::cout << q.get_size() << " "  << q.get_capacity() << " " << q.front() << " " << q.back() <<std::endl;
//     q.push(2);
//     q.pop();
//     std::cout << q.get_size() << " " << q.get_capacity() << " " << q.front() << " " << q.back() << std::endl;
//     q.push(3);
//     std::cout << q.get_size() << " "  << q.get_capacity() << " " << q.front() << " " << q.back() <<std::endl;
//     q.push(4);
//     q.pop();
//     std::cout << q.get_size() << " " << q.get_capacity() << " " << q.front() << " " << q.back() << std::endl;
//     q.pop();
//     std::cout << q.get_size() << " " << q.get_capacity() << " " << q.front() << " " << q.back() << std::endl;
//     q.pop();
//     std::cout << q.get_size() << " " << q.get_capacity()  << std::endl;
//     q.pop();
//     std::cout << q.get_size() << " " << q.get_capacity()  << std::endl;
// }
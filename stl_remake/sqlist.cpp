#define MAXSIZE 100
#include <stdexcept>
// #include <iostream>
// using namespace std;
// sqlist 的位序从1开始
template <typename T>
struct sqlist{   
private:
    T m_data[MAXSIZE];
    int m_length;
public:
    // initialization
    sqlist(int length = 0) : m_length(length) {}

    // destroy
    ~sqlist() = default;

    // get_length
    int get_length() const{
        return m_length;
    }
    // empty
    bool empty() const{
        return m_length == 0;
    }
    // full
    bool full() const{
        return m_length >= MAXSIZE;
    }
    // insert
    void insert(int index, T value){
        if (index < 1 || index > m_length + 1){
            throw std::invalid_argument("Cannot insert at a invalid index");
        }
        if (full()){
            throw std::runtime_error("Cannot insert into a full sqlist");
        }
        for (int i = m_length - 1; i >= index - 1; --i)
        {
            m_data[i + 1] = m_data[i];
        }
        m_data[index - 1] = value;
        m_length++;
    }
    // remove
    void remove(int index){
        if (index < 1 || index > m_length){
            throw std::invalid_argument("Cannot remove at a invalid index");
        }
        if (empty()){
            throw std::runtime_error("Cannot remove from an empty sqlist");
        }
        for (int i = index; i <= m_length - 1; ++i){
            m_data[i - 1] = m_data[i];
        }
        m_length--;
    }
    // remove
    void remove (int index, T& value){
        if (index < 1 || index > m_length){
            throw std::invalid_argument("Cannot remove at a invalid index");
        }
        if (empty()){
            throw std::runtime_error("Cannot remove from an empty sqlist");
        }
        value = m_data[index - 1];
        for (int i = index; i <= m_length - 1; ++i)
        {
            m_data[i - 1] = m_data[i];
        }
        m_length--;
    }

    // get_elem
    T get_elem(int index){
        if (index < 1 || index > m_length)
        {
            throw std::invalid_argument("Cannot get_elem at a invalid index");
        }
        return m_data[index - 1];
    }
    // locate_elem
    int locate_elem(T value){
        for (int i = 0; i < m_length; ++i){
            if (m_data[i] == value)
                return i + 1;
        }
        return 0;
    }
    // void display()
    // {
    //     cout << "线性表内容: ";
    //     for (int i = 0; i < m_length; ++i)
    //     {
    //         cout << m_data[i];
    //         if (i < m_length - 1)
    //             cout << " ";
    //     }
    //     cout << " | 长度: " << m_length << endl;
    // }
};

// 测试代码
// int main()
// {
//     try
//     {
//         cout << "=== 静态数组线性表测试 ===" << endl;

//         // 创建线性表
//         sqlist<int> list;

//         // 测试初始状态
//         cout << "\n1. 初始状态测试:" << endl;
//         cout << "长度: " << list.get_length() << endl;
//         cout << "是否为空: " << (list.empty() ? "是" : "否") << endl;
//         cout << "是否已满: " << (list.full() ? "是" : "否") << endl;

//         // 测试插入操作
//         cout << "\n2. 插入操作测试:" << endl;
//         list.insert(1, 10); // 在位置1插入10
//         list.insert(1, 20); // 在位置1插入20
//         list.insert(2, 30); // 在位置2插入30
//         list.insert(4, 40); // 在位置4插入40
//         list.display();

//         // 测试获取元素
//         cout << "\n3. 获取元素测试:" << endl;
//         cout << "位置1的元素: " << list.get_elem(1) << endl;
//         cout << "位置2的元素: " << list.get_elem(2) << endl;
//         cout << "位置3的元素: " << list.get_elem(3) << endl;

//         // 测试查找元素
//         cout << "\n4. 查找元素测试:" << endl;
//         cout << "元素10的位置: " << list.locate_elem(10) << endl;
//         cout << "元素20的位置: " << list.locate_elem(20) << endl;
//         cout << "元素99的位置: " << list.locate_elem(99) << " (0表示未找到)" << endl;

//         // 测试删除操作
//         cout << "\n5. 删除操作测试:" << endl;
//         list.remove(2); // 删除位置2的元素
//         cout << "删除位置2后:" << endl;
//         list.display();

//         // 测试带返回值的删除
//         cout << "\n6. 带返回值的删除测试:" << endl;
//         int deletedValue;
//         list.remove(1, deletedValue);
//         cout << "删除位置1的元素: " << deletedValue << endl;
//         list.display();

//         // 测试边界情况
//         cout << "\n7. 边界情况测试:" << endl;
//         try
//         {
//             list.insert(10, 100); // 无效位置
//         }
//         catch (const exception &e)
//         {
//             cout << "异常捕获: " << e.what() << endl;
//         }

//         try
//         {
//             list.get_elem(10); // 无效位置
//         }
//         catch (const exception &e)
//         {
//             cout << "异常捕获: " << e.what() << endl;
//         }

//         // 清空列表测试
//         cout << "\n8. 清空操作测试:" << endl;
//         while (!list.empty())
//         {
//             list.remove(1);
//         }
//         cout << "清空后长度: " << list.get_length() << endl;
//         list.display();
//     }
//     catch (const exception &e)
//     {
//         cerr << "测试过程中发生异常: " << e.what() << endl;
//     }

//     return 0;
// }

#include <stdexcept>

template <typename T>
struct LNode{
    T m_data;
    LNode<T> *m_next;

    LNode(const T& data = T(), LNode<T> * next = nullptr): m_data(data), m_next(next) {}
    ~LNode() = default;
};

template <typename T>
struct linklist
{
    LNode<T> *m_head;

    linklist() : m_head(NULL) {}
    ~linklist() {}

    // insert
    void insert(int index, T data){
        if (index < 1)
            throw std::invalid_argument("Index must be greater than or equal to 1.");
        LNode<T> *p;
        p = m_head; // 指向 a1

        for (int i = 2; i <= index; ++i) // i = 2 , p 指向 a2 , i = index , p -> index
        {
            p = p->m_next;
            if (p == nullptr){
                throw std::runtime_error("Index out range of the size of linklist.");
            }
        }
        back_insert(p, data);
    }

    // back_insert
    void back_insert(LNode<T>* p, T data){
        if (p == nullptr){
            throw std::runtime_error("Cannot insert behind nullptr");
        }
        LNode<T> *s = new LNode<T>(data);
        if (s == nullptr){
            throw std::runtime_error("Memory allocation failed.");;
        }
        s->m_next = p->m_next;
        p->m_next = s;
    }
    // prior_insert
    void prior_insert(LNode<T> *p, T data)
    {
        if (p == m_head || p == nullptr)
        {
            throw std::runtime_error("Cannot insert prior headptr or nullptr.");
        }
        LNode<T> *s = new LNode<T>(data);
        if (s == nullptr)
        {
            throw std::runtime_error("Memory allocation failed.");
        }
        s->m_next = p->m_next;
        p->m_next = s;
        T temp_data;
        temp_data = p->m_data;
        p->m_data = s->m_data;
        s->m_data = temp_data;
    }

    // remove
    void remove(int index){
        LNode<T> *p, *s;
        p = m_head;
        for (int i = 2; i < index && p != nullptr; ++i) // i = 2, p->2   p->index - 1
        {
            p = p->m_next;
            if (p == nullptr)
            {
                throw std::runtime_error("Index out range of the size of linklist.");
            }
        }
        s = p->m_next;
        if (s == nullptr)
            throw std::runtime_error("Cannot delete the nullptr");
        p->m_next = s->m_next;
        delete s;
    }
};

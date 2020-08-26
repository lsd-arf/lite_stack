#include <iostream>
#include <array>
#include <cassert>

class Stack
{
private:
    std::array<int, 10> m_stack{}; // стек
    int m_length{}; // длина стека

public:
    void reset() // сбрасываем значения стека
    {
        m_length = {};
        m_stack = {};
    }

    bool push(int elem) // добавляем элемент в стек
    {
        if (m_length < 10) {
            m_stack[m_length++] = elem;
            return true; // если еще не заполнен
        }
        else
            return false; // если уже заполнен
    }

    int pop() // достаём элемент из стека
    {
        assert(m_length > 0); // если true, выполняется код дальше, иначе ошибка и программа закрывается
        return m_stack[--m_length];
    }

    void print() // выводим все значения стека
    {
        std::cout << "( ";
        for (int i(0); i < m_length; ++i)
            std::cout << m_stack[i] << ' ';
        std::cout << ")\n";
    }
};

int main()
{
    using namespace std;

    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
// MyArray.inc

template<typename T>
MyArray<T>::MyArray()
{
    m_length = 0;
    m_data = nullptr;
}

template<typename T>
MyArray<T>::MyArray(const int& length)
    : m_length(length)
{
    m_data = new T[length];
}

template<typename T>
MyArray<T>::~MyArray()
{
    reset();
}

template<typename T>
void MyArray<T>::reset()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

template<typename T>
T& MyArray<T>::operator[](const int& index)
{
    assert(index >= 0);
    assert(index < m_length);
    return m_data[index];
}

template<typename T>
int MyArray<T>::getLength()
{
    return m_length;
}

template<typename T>
void MyArray<T>::print()
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}
// Class blueprint
template <class T>
class DynArray{
 public:
  // Delete default,copy constructor & copy assigment
  DynArray() = delete;
  DynArray(const DynArray &data) = delete;
  DynArray &operator=(const DynArray &rhs) = delete;

  // Public interfaces
  DynArray(int N);
  ~DynArray();
  T &operator[](const unsigned i);

 private:
  T *data;
};

// Class implementation

template <class T>
DynArray<T>::DynArray(int count)
{
  data = new T[count]();
}

template <class T>
DynArray<T>::~DynArray()
{
  delete[] data;
}

template <class T>
T& DynArray<T>::operator[](const unsigned i)
{
  return data[i];
}

// Example of function template specialization
template <>
DynArray<double>::~DynArray()
{
  // This destructor will only match double type
  delete[] data;
}

int main()
{
  DynArray<int> d1(5);
  DynArray<char> d3(5);
  DynArray<bool> d4(5);
  DynArray<float> d2(5);

  return 0;
}

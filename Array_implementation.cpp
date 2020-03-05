#include <iostream>
#include <stdexcept>

class Array {
   size_t size_;   
   uint32_t* ptr;  
 
public:
   explicit Array (int n = 10);         
   Array(const Array& other); 
   Array& operator=(const Array& rhs);
   Array(const uint32_t a[], int n);    
   ~Array();                           
     
   bool operator== (const Array& rhs) const;     // a1 == a2
   bool operator!= (const Array& rhs) const;     // a1 != a2
 
   uint32_t operator[](int index) const;  // const version     - Read only access
   uint32_t& operator[](int index);       // non-const version - Can mutate array
 
   size_t size() const { return size_; }    
 
   friend std::ostream & operator<< (std::ostream & out, const Array & a); 
   friend std::istream & operator>> (std::istream & in, Array & a);        
};
 
Array::Array (int n)
{
   if (n <= 0) 
      throw std::invalid_argument("error: size must be greater then zero");
 
   size_ = n;
   ptr = new uint32_t[size_];
   for (int i = 0; i < size_; ++i) ptr[i] = 0;
}

// Copy constructor
// Do a deep copy to make our Array follow value semantacis
Array::Array (const Array& a) 
{
   size_ = a.size_;
   ptr = new uint32_t[size_];
   for (int i = 0; i < size_; ++i) ptr[i] = a.ptr[i];           
}
 
// Construct from existing uint32_t[]
Array::Array (const uint32_t a[], int n) 
{
   size_ = n;
   ptr = new uint32_t[size_];
   for (int i = 0; i < size_; ++i) ptr[i] = a[i];     
}
 
Array::~Array() 
{
   delete[] ptr;  
}
 
Array& Array::operator=(const Array& rhs)
{
   if (this != &rhs) 
   {  
      if (size_ != rhs.size_) 
	  {
         // reallocate memory for the array
         delete [] ptr;
         size_ = rhs.size_;
         ptr = new uint32_t[size_];
      }
      // Copy elements
      for (int i = 0; i < size_; ++i) {
         ptr[i] = rhs.ptr[i];
      }
   }
   return *this;
}
 
// Comparison operator==
bool Array::operator== (const Array& rhs) const 
{
   if (size_ != rhs.size_) return false;
 
   for (int i = 0; i < size_; ++i) 
      if (ptr[i] != rhs.ptr[i]) return false;
   
   return true;
}
 
// Implement operator!= using operator==
bool Array::operator!= (const Array& rhs) const 
{
   return !(*this == rhs);
}
 
// Index operator[] - const version
uint32_t Array::operator[](int index) const 
{
   if (index < 0 || index >= size_) 
      throw std::out_of_range("error: index out of range");
   return ptr[index];
}
 
// Index operator[] - non-const version
uint32_t & Array::operator[] (int index) 
{
   if (index < 0 || index >= size_) 
      throw std::out_of_range("error: index out of range");
   return ptr[index];
}
 
// Stream insertion and extraction operation using
// non-member friend functions
std::ostream & operator<< (std::ostream & out, const Array & a)
{
   for (int i = 0; i < a.size_; ++i) 
      out << a.ptr[i] << ' ';
   return out;
}
 
// Overload stream extraction operator in >> a (as friend)
std::istream & operator>> (std::istream & in, Array & a) 
{
   for (int i = 0; i < a.size_; ++i) 
      in >> a.ptr[i];
   return in;
}


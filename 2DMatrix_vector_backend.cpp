#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class T, size_t R, size_t C>
class Matrix
{
   using value_type = T;
   using iterator = value_type*;
   using const_iterator = const value_type*;
   std::vector<T> vec;
public:
   Matrix() :vec(R*C) {}
   explicit Matrix(std::initializer_list<T> l):vec(l) {}
   
   constexpr T* data() noexcept 
   {
	   return vec.data(); 
   }
   
   constexpr const T* data() const noexcept 
   { 
	   return vec.data(); 
   }

   constexpr T& at(const size_t r, const size_t c) 
   {
      return vec.at(r*C + c);
   }

   constexpr const T& at(const size_t r, const size_t c) const
   {
      return vec.at(r*C + c);
   }

   constexpr T& operator() (const size_t r, const size_t c)
   {
      return vec[r*C + c];
   }

   constexpr const T& operator() (const size_t r, const size_t c) const
   {
      return vec[r*C + c];
   }

   constexpr bool empty() const noexcept
   {
      return R == 0 || C == 0;
   }

   constexpr size_t size(int const rank) const
   {
      if (rank == 1) return R;
      else if (rank == 2) return C;
      throw std::out_of_range("Rank is out of range!");
   }

   void fill(const T& value)
   {
      std::fill(std::begin(vec), std::end(vec), value);
   }

   void swap(Matrix& other) noexcept
   {
      vec.swap(other.vec);
   }
   const_iterator begin() const 
   {
	   return vec.data();
   }
   const_iterator end() const 
   {
	   return vec.data() + vec.size(); 
   }
   iterator begin()
   {
	   return vec.data(); 
   }
   iterator end() 
   { 
	   return vec.data() + vec.size(); 
   }
};


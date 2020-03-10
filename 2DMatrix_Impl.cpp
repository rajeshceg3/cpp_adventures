#include <stdexcept>

// Barebone implementation of a C++ class for representing
// a 2-D Matrix
class IntMatrix {
  size_t rows_, cols_;
  int* data_;
public:
  IntMatrix(size_t rows, size_t cols);
  IntMatrix(const IntMatrix& mat);               
  IntMatrix& operator= (const IntMatrix& rhs);   
  int& operator() (size_t row, size_t col);        
  int  operator() (size_t row, size_t col) const;  
  ~IntMatrix();                              
  bool operator==(const IntMatrix& Other);
  bool operator!=(const IntMatrix& Other);
};


IntMatrix::IntMatrix(size_t rows, size_t cols):
	rows_ (rows),
	cols_ (cols)
{
  if (rows == 0 || cols == 0)
    throw std::out_of_range("Cannot Create IntMatrix with Zero size");
  data_ = new int[rows * cols];
}

bool IntMatrix::operator==(const IntMatrix& Other)
{
	if( (rows_ != Other.rows_) || (cols_ != Other.cols_)) return false;
	for(size_t irow = 0; irow < rows_; irow++)
		for(size_t icol = 0; icol < cols_; icol++)
			if (data_[cols_*irow + icol] != Other.data_[cols_*irow + icol])   
				return false;
	
	return true;		
}

bool IntMatrix::operator!=(const IntMatrix& Other)
{
	return !(*this == Other);
}

IntMatrix::IntMatrix(const IntMatrix& mat)
{
	size_t irows = mat.rows_;
	size_t icols = mat.cols_;
    int* mat_ptr = mat.data_;
	int* data_ = new int[irows*icols];
	for(size_t irow = 0; irow < irows; irow++)
		for(size_t icol = 0; icol < icols; icol++)
			data_[icols*irow + icol] = mat_ptr[icols*irow + icol];	
}

IntMatrix& IntMatrix::operator=(const IntMatrix& rhs)
{
	if(*this != rhs)
	{
		if(( rhs.rows_ != rows_ )||( rhs.cols_ != cols_ ))
		{
			rows_ = rhs.rows_;
			cols_ = rhs.cols_;
			int* rhs_ptr = rhs.data_;
			delete[] data_;
			data_ = new int[rows_*cols_];
			
			for(size_t irow = 0; irow < rows_; irow++)
				for(size_t icol = 0; icol < cols_; icol++)
					data_[cols_*irow + icol] = rhs_ptr[cols_*irow + icol];                
		}							
	}
	return *this;	
}

IntMatrix::~IntMatrix()
{
  delete[] data_;
}

int& IntMatrix::operator() (size_t row, size_t col)
{
  if (row >= rows_ || col >= cols_)
    throw std::out_of_range("IntMatrix index is out of range");
  return data_[cols_*row + col];
}

int IntMatrix::operator() (size_t row, size_t col) const
{ 
  if (row >= rows_ || col >= cols_)
    throw std::out_of_range("IntMatrix index is out of range");
  return data_[cols_*row + col];
}

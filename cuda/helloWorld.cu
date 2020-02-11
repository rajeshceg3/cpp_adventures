#include <iostream>
#include <math.h>

// Cuda function
__global__ void add(int n, float *one, float *two)
{
  int index = threadIdx.x;
  int jump_length = blockDim.x;
  for (int i = index; i < n; i += jump_length)
      one[i] = one[i] + two[i];
}

int main()
{
  int count = 1000000;
  float *one, *two;

  // Allocate memory using cuda calls
  cudaMallocManaged(&one, count*sizeof(float));
  cudaMallocManaged(&two, count*sizeof(float));

 // fill arrays with values
  for (int i = 0; i < count; i++)
  {
    one[i] = 1.0f;
    two[i] = 1.0f;
  }

  // Call cuda function for computation
  add<<<1, 256>>>(count, x, y);

  // Wait for Cuda operations to complete
  cudaDeviceSynchronize();

  // Release memory using cuda calls
  cudaFree(x);
  cudaFree(y);
  
  return 0;
}

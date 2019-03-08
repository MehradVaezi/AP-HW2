#include"libArr.h"

int LibArr::counter(int n)
{
  int sum{};
  arr = new int[n];
  for(int i{}; i < n; i++)
    {
      arr[i] = i+1;
      sum += (i+1);
    }
  return sum;
}

LibArr::~LibArr()
{
  delete[] arr;
}
  

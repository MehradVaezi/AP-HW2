#include"libVec.h"

int LibVec::counter(int n)
{
  int sum{};
  for(int i{1}; i <= n; i++)
    {
      v.push_back(i);
      sum += i;
    }
  return sum;
}
  

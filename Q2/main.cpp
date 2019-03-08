#include"libVec.h"
#include"libArr.h"
#include<cmath>
#include<chrono>

using namespace std::chrono;

template <class T>
double runTime(int (T::* f)(int), int n)
{
  T var;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  (var.*f)(n);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();;
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  return 1000*time_span.count();
}

int main()
{
  int (LibVec::* Vecfunc) (int) = &LibVec::counter;
  int (LibArr::* Arrfunc) (int) = &LibArr::counter;

  for(size_t i{1}; i <= 10000000; i*=10)
    {
      std::cout << "Step: " << i << std::endl;
      std::cout << "LibVec class timeout: " << runTime(Vecfunc, i) << " ms" << std::endl;
      std::cout << "LibArr class timeout: " << runTime(Arrfunc, i) << " ms" << std::endl;
      std::cout << "--------------------------" << std::endl;
    }

  return 0;
}

  

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cmath>

class Map
{
 public:
  Map(int n);
  void showMap();
  void findRoute_slow(); // This is for Part: A (Slower)
  void findRoute_fast(); // This is for Part: B (Faster)
  void showRoute_slow(); // Displays Part: A (Slower)
  void showRoute_fast(); // Displays Part: B (Faster)
  void findBestRoute(); // Finds Fastest Route for Part: A
  void showBestRoute();
  ~Map();
 private:
  void dispvec(std::vector<int>);
  std::vector<int> hor1, ver1, hor2, ver2, hor3, ver3;
  std::string best_result;
  size_t random(size_t);
  int diff1(std::vector<int>, std::vector<int>); // 0: Right & 1: Down
  int diff2(std::string);
  int sum(const std::vector<int>&);
  void addvector(std::vector<int>&);
  std::vector<int> sort(std::vector<int>);
  bool access(std::vector<std::string>, std::string);
  int** arr;
  int N;
};

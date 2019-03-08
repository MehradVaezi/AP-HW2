#include"map.h"

Map::Map(int n)
{
  std::srand(static_cast<unsigned>(std::time(nullptr))); // Must be on top of the Constructor so that it generates a NEW set of integers by every call of the Constructor!
  N = n;
  arr = new int*[n];
  for(int i{}; i < n; i++)
    arr[i] = new int[n];
  for(int i{}; i < n; i++)
    for(int j{}; j < n; j++)
      arr[i][j] = random(n*n) + 1;
}

void Map::showMap()
{
  std::cout << "\n" << "This is your Map!" << "\n";
  for(int i{}; i < N; i++)
    {
      for(int j{}; j < N; j++)
	std::cout << std::setw(4) << arr[i][j];
      std::cout << std::endl;
    }
  std::cout << "\n";
}

void Map::findRoute_slow()
{
  int i{}, j{};
  while(i != (N-1) || j != (N-1))
    {
      hor1.push_back(i);
      ver1.push_back(j);
      if (i != (N-1) && j != (N-1))
	{
	  if (fabs(arr[i][j] - arr[i+1][j]) < fabs(arr[i][j] - arr[i][j+1]))
	      i++;
	  else
	      j++;
	}
      else if (i == (N-1))	    
	      j++;	    
      else if (j == (N-1))
	      i++;	     
    }
  std::cout << "Slow Distance: " << diff1(hor1, ver1);
}

void Map::findRoute_fast()
{
  int i{}, j{};
  while(i != (N-1) || j != (N-1))
    {
      hor2.push_back(i);
      ver2.push_back(j);
      if (i != (N-1) && j != (N-1))
	{
	  if ((fabs(arr[i][j] - arr[i+1][j]) < fabs(arr[i][j] - arr[i+1][j+1])) && (fabs(arr[i][j] - arr[i+1][j]) < fabs(arr[i][j] - arr[i][j+1])))
	      i++;
	  else if((fabs(arr[i][j] - arr[i][j+1]) < fabs(arr[i][j] - arr[i+1][j+1])) && (fabs(arr[i][j] - arr[i][j+1]) < fabs(arr[i][j] - arr[i+1][j])))
	      j++;
	  else if((fabs(arr[i][j] - arr[i+1][j+1]) < fabs(arr[i][j] - arr[i+1][j])) && (fabs(arr[i][j] - arr[i+1][j+1]) < fabs(arr[i][j] - arr[i][j+1])))
	    {
	      i++; j++;
	    }
	  else
	    {
	      i++; j++;
	    }
	}
      else if (i == (N-1))	    
	      j++;	    
      else if (j == (N-1))
	      i++;
    }
  hor2.push_back(i);
  ver2.push_back(j);
  std::cout << "Fast Distance: " << diff1(hor2, ver2);
  
}

void Map::showRoute_slow()
{
  std::cout << "\n" << "Slower Route:" << "\n";
  int x{};
  for(int i{}; i < N; i++)
    {
    for(int j{}; j < N; j++)
      {
	if( i == (N-1) && j == (N-1))
	    std::cout << std::setw(4) << '8';
	else
	  {
	    if (i == hor1[x] && j == ver1[x])
	      {
		std::cout << std::setw(4) << '8';
		x++;
	      }
	    else
	      std::cout << std::setw(4) << '-';
	  }
      }
    std::cout << std::endl;
    }
  std::cout << std::endl;
}

void Map::showRoute_fast()
{
  std::cout << "\n" << "Faster Route:" << "\n";
  int x{};
  for(int i{}; i < N; i++)
    {
    for(int j{}; j < N; j++)
      {
	if( i == (N-1) && j == (N-1))
	    std::cout << std::setw(4) << '8';
	else
	  {
	    if (i == hor2[x] && j == ver2[x])
	      {
		std::cout << std::setw(4) << '8';
		x++;
	      }
	    else
	      std::cout << std::setw(4) << '-';
	  }
      }
    std::cout << std::endl;
    }
  std::cout << std::endl;
}

void Map::findBestRoute()
{
  std::vector<int> v1, v2;
  std::vector<std::string> result;
  std::string path{}, s{};
  int a{}, rem{N-1}, best{99999};
  for(int i{}; i < N-1; i++)
    v1.push_back(0);
  while(sum(v1) <= (N-1)*(N-1))
    {
      v2 = sort(v1);
      a = v2[0];
      for(size_t i{}; i < v2.size(); i++)
	{
	  path += std::string(a, '1');
	  rem = rem - a;
	  path += '0';
	  a = v2[i+1] - v2[i];
	}
      path += std::string(rem, '1');
      if(access(result, path))
	result.push_back(path);
      rem = N-1;
      path = "";
      addvector(v1);
    }
  for(size_t j{}; j < result.size(); j++)
    if (diff2(result[j]) < best)
      {
	best = diff2(result[j]);
	best_result = result[j];
      }
  std::cout << "Best Distance: " << diff2(best_result) << std::endl;
}

void Map::showBestRoute()
{
  std::cout << "Best Route: " << std::endl;
  int x{}, y{};
  hor3.push_back(x); ver3.push_back(y);
  for(size_t i{}; i < best_result.size(); i++)
    {
      if (best_result[i] == '0')
	{
	  y++;
	  hor3.push_back(x); ver3.push_back(y);
	}
      else if (best_result[i] == '1')
	{
	  x++;
	  hor3.push_back(x); ver3.push_back(y);
	}
    }
  x = 0; y = 0;
  for(int i{}; i < N; i++)
    {
      for(int j{}; j < N; j++)
	{
	  if (i == hor3[x] && j == ver3[y])
	    {
	      std::cout << std::setw(4) << '8';
	      x++; y++;
	    }
	      else
	    std::cout << std::setw(4) << '-';
	}
      std::cout << std::endl;
      }
}

int Map::diff1(std::vector<int> hor, std::vector<int> ver)
{
  int sum{};
  for(size_t i{}; i < hor.size() - 1; i++)
    sum += abs(arr[hor[i+1]][ver[i+1]] - arr[hor[i]][ver[i]]);
  sum += abs(arr[N-1][N-1] - arr[hor[hor.size()-1]][ver[ver.size()-1]]); 
  return sum;   
}

int Map::diff2(std::string s)
{
  int sum{};
  int x{}, y{};
  for(size_t i{}; i < s.size(); i++)
    {
      if(s[i] == '0')
	{
	  y++;
	  sum += abs(arr[x][y] - arr[x][y-1]);
	}
      else if(s[i] == '1')
	{
	  x++;
	  sum += abs(arr[x][y] - arr[x-1][y]);
	}
    }
  return sum;
}

void Map::dispvec(std::vector<int> v)
{
  for(size_t i{}; i < v.size(); i++)
    std::cout << v[i] << ", ";
  std::cout << std::endl; 
}
  
size_t Map::random(size_t cnt)
{
  return static_cast<size_t>(std::rand() / (RAND_MAX / cnt + 1)); // Generates random int between (0, cnt - 1)
}

int Map::sum(const std::vector<int>& v)
{
  int s{};
  for(size_t i{}; i < v.size(); i++)
    s += v[i];
  return s;
}

void Map::addvector(std::vector<int>& v)
{
  int i{}, sum{};
  bool all{false};
  for (size_t i{}; i < v.size(); i++)
    sum += v[i];
  all = (sum == (static_cast<int>(v.size()) * static_cast<int>(v.size())));
  if(all)
    for(size_t i{}; i < v.size(); i++)
      v[i] = v[i] + 1;
  std::vector<int> w{-10};
  while(!all)
    {
      if (v[i] < static_cast<int>(v.size()))
	{
	  v[i] = v[i] + 1;
	  break;
	}
      else if (v[i] == static_cast<int>(v.size()) && i != (static_cast<int>(v.size())-1))
	{
	  v[i] = 0;
	  i++;
	}
    }
}

std::vector<int> Map::sort(std::vector<int> v)
{
  int temp{};
  for(size_t i{}; i < v.size(); i++)
    for(size_t j{i+1}; j < v.size(); j++)
      if (v[i] > v[j])
	{
	  temp = v[i];
	  v[i] = v[j];
	  v[j] = temp;
	}
  return v;
}

bool Map::access(std::vector<std::string> v, std::string s)
{
  bool acc{true};
  for(size_t i{}; i < v.size(); i++)
    if(v[i] == s)
	acc = false;
  return acc;
}
Map::~Map()
{
  for(int i{}; i < N; i++)
      delete[] arr[i];
  delete[] arr;
}
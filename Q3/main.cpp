#include<iostream>
#include<fstream>
#include<vector>
#include<string>

std::vector<int> sort(std::vector<int>&);
int counter(std::vector<int>);
void disp(std::vector<int>);

int main()
{
  std::vector<int> yearv, monthv, dayv, pro_idv, cust_idv, pro_countv, cust_countv;
  std::vector<int> newyear, newmonth, newday, procnt, custcnt;
  std::vector<int> temp1, temp2;
  char ch{};
  int year, month, day, extra, pro_id, cust_id;
  int cnt{1};
  std::ifstream ifs{ "db.txt" };
  std::ofstream ofs{ "dbnew.txt" };
  while(!ifs.eof())
    {
      ifs >> ch;
      if(ch != '[')
	break;
      ifs >> year;
      yearv.push_back(year);
      ifs >> ch;
      ifs >> month;
      monthv.push_back(month);
      ifs >> ch;
      ifs >> day;
      dayv.push_back(day);
      ifs >> extra;
      ifs >> ch;
      ifs >> extra;
      ifs >> ch;
      ifs >> pro_id;
      pro_idv.push_back(pro_id);
      ifs >> cust_id;
      cust_idv.push_back(cust_id);
    }
  for (size_t i{}; i < (yearv.size()-1); i++)
    {
      if ((yearv[i] == yearv[i+1]) && (monthv[i] == monthv[i+1]) && (dayv[i] == dayv[i+1]))
	  cnt++;
      else
	{
	  for(size_t j{i+1-cnt}; j <= i; j++)
	    {
	      temp1.push_back(pro_idv[j]);
	      temp2.push_back(cust_idv[j]);
	    }
	  ofs << '[' << yearv[i] << '-' << monthv[i] << '-' << dayv[i] << "] " << (cnt - counter(temp1)) << ", " << (cnt - counter(temp2)) << std::endl;
	  cnt = 1;
	  temp1.clear();
	  temp2.clear();
	}														  
    }
  for(size_t j{yearv.size()-cnt}; j <= yearv.size() - 1; j++)
	    {
	      temp1.push_back(pro_idv[j]);
	      temp2.push_back(cust_idv[j]);
	    }
  ofs << '[' << yearv[yearv.size()-1] << '-' << monthv[yearv.size()-1] << '-' << dayv[yearv.size()-1] << "] " << (cnt - counter(temp1)) << ", " << (cnt - counter(temp2)) << std::endl;
  return 0;
}

std::vector<int> sort(std::vector<int>& v)
{
  int temp{};
  for(size_t i{}; i < v.size(); i++)
	for(size_t j{i+1}; j < v.size(); j++)
	{
	  if (v[i] > v[j])
	    {
	      temp = v[i];
	      v[i] = v[j];
	      v[j] = temp;
	    }
	}
  return v;
}

int counter(std::vector<int> v)
{
  sort(v);
  int cnt{}, temp{};
  for(size_t i{}; i < v.size(); i++)
    for(size_t j{i+1}; j < v.size(); j++)
	if(v[i] == v[j])
	  {
	    cnt++;
	    temp++;
	    i += temp;
	    temp = 0;
	  }
  return cnt;
}

void disp(std::vector<int> v)
{
  for(size_t i{}; i < v.size(); i++)
    std::cout << v[i] << ", ";
  std::cout << std::endl;
}
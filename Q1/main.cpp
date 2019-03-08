#include"map.h"

int main()
{
  Map map{4};
  map.showMap();
  map.findRoute_slow();
  map.showRoute_slow();
  map.findRoute_fast();
  map.showRoute_fast();
  map.findBestRoute();
  map.showBestRoute();
  return 0;
}

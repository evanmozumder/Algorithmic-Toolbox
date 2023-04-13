#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compareByEnd(const Segment &a, const Segment &b){
  return a.end<b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(),segments.end(),compareByEnd);
  // for (size_t i = 0; i < segments.size(); ++i) {
  //   points.push_back(segments[i].start);
  //   points.push_back(segments[i].end);
  // }
  int k=0;
  points.push_back(segments[k].end);
  for(int i=1;i<segments.size();i++){
    if((points[k] >= segments[i].start) && (points[k] <= segments[i].end)) continue;
    else{
      points.push_back(segments[i].end);
      k++;
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout<<"\n";
}

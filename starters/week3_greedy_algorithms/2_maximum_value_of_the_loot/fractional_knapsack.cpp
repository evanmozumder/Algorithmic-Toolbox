#include <iostream>
#include <vector>
using namespace std;

using std::vector;

int bestItem(vector<int>weights, vector<int>values){
  double maxValuePerWeight = 0.0;
  int bi = 0;
  for(int i=0;i<weights.size();i++){
    if(weights[i]>0.0){
      if((values[i]/(double)weights[i])>maxValuePerWeight){
        maxValuePerWeight = values[i]/(double)weights[i];
        bi = i;
      }
    }
  }

  return bi;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double>amounts(n);
  for(int i=0;i<n;i++)amounts[i]=0;

  // write your code here
  while(n-- && capacity!=0){
    int bi = bestItem(weights, values);
    if(weights[bi]<=capacity){
      capacity -= weights[bi];
      value += values[bi];
      weights[bi] = 0;
    }else {
      value += (values[bi]/double(weights[bi]))*double(capacity);
      capacity = 0;
    }
  }
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    bool ch=false;
    for(int i=1;i<stops.size();i++){
        if(stops[i]-stops[i-1]>tank)return -1;
    }
    int last_tank=0,cnt=0;
    for(int i=0;i<stops.size();i++){
        if(stops[i]-last_tank < tank)continue;
        else if(stops[i]-last_tank == tank){
            if(i==stops.size()-1)continue;
            last_tank = stops[i];
            cnt++;
        }
        else {
            last_tank = stops[i-1];
            cnt++;
        }
    }

    return cnt;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};


bool comp (Segment lhs, Segment rhs) {
    return lhs.end < rhs.end;
 
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    sort(segments.begin(), segments.end(), comp);
    
    int current = -1;
    for(const auto item : segments){
        if (item.start > current){
            current = item.end;
            points.push_back(current);
        }
    }
    /*
    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].start);
        points.push_back(segments[i].end);
    }*/
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
}

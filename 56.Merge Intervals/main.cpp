#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(const Interval& lhs, const Interval& rhs) {
    return lhs.start<rhs.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<Interval> result;

        if (intervals.size() < 1) {
            return result;
        }

        std::sort(intervals.begin(), intervals.end(), compareInterval);
        Interval current = intervals[0];
        for (int i=1,sz=intervals.size(); i<sz; i++) {
            if (current.end < intervals[i].start) {
                result.push_back(current);
                current = intervals[i];
            } else {
                current.end = std::max(current.end, intervals[i].end);
            }
        }
        current.end = std::max(current.end, intervals.back().end);
        result.push_back(current);

        return result;
    }
};

int main() {
    std::vector<Interval> data {
        Interval(1,3),
        Interval(2,6),
        Interval(8,10),
        Interval(15,18),
    };

    Solution s;
    std::vector<Interval> result = s.merge(data);

    std::for_each(result.begin(), result.end(), [](const Interval & arg) {
        std::cout<<"["<<arg.start<<","<<arg.end<<"]";
    });
    std::cout<<std::endl;

    return 0;
}

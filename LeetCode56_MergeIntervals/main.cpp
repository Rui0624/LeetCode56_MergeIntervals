//
//  main.cpp
//  LeetCode56_MergeIntervals
//
//  Created by Rui on 1/7/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



 //Definition for an interval.
    struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    static bool compare(const Interval &a, const Interval &b)
    {
        return (a.start < b.start); //create the compare used in the sort(), to make sure the sort of intervals will be in the increasing sort of start in each Intervals
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res; //the result vector for return
        if(intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), compare); //sort the intervals gave by increasing order of start
        res.push_back(intervals[0]); // push the first element into res
        
        for(int i = 1; i < intervals.size(); i++) //pass throught all the other intervals
        {
            if(res.back().end >= intervals[i].start) //compare the end of last element in res and the start of next element in intervals to find the overlaping;
            {
                res.back().end = max(res.back().end, intervals[i].end); //update the end of last element in the res, merger the possible overlapping
            }else{
                res.push_back(intervals[i]); //else put the new intervals into res
            }
        }
        return res;
    }
};

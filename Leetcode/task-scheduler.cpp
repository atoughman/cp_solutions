// problem link
// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int mx_freq = 0;
        int mx_freq_count = 0;
        for(auto &x: tasks) {
            freq[x]++;
            if(freq[x] > mx_freq) {
                mx_freq = freq[x];
                mx_freq_count = 1;
            } else if(freq[x] == mx_freq) ++mx_freq_count;
        }

        return max((int)tasks.size(), (n+1) * (mx_freq-1) + mx_freq_count);
    }
};
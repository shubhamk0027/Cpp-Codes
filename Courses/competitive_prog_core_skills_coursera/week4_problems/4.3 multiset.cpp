#include <iostream>
#include <array>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// NUMS must be a power of two!!
// Otherwise, obviously segment tree will not work
const int NUMS = 131072;
const int ST_SIZE = NUMS * 2;

typedef std::pair<int, int> interval;
typedef array<int, ST_SIZE> segment_tree;

void read_input(int &n, vector<interval> &is)
{
    cin >> n;

    int l;
    int r;

    while (cin >> l >> r)
    {
        is.push_back({l, r});
    }
}

void print_segment_tree(segment_tree &st)
{
    array<int, NUMS> counts = {0};
    for (int i = 1; i <= NUMS; i++)
    {
        int j = 1;
        int left = 1;
        int right = NUMS;
        int med = left + (right - left - 1) / 2;
        while (j < ST_SIZE)
        {
            counts[i - 1] += st[j];
            if (i <= med)
            {
                j = j * 2;
                right = med;
                med = left + (right - left - 1) / 2;
            }
            else
            {
                j = j * 2 + 1;
                left = med + 1;
                med = left + (right - left - 1) / 2;
            }
        }
    }

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i])
            cout << i + 1 << " " << counts[i] << endl;
    }
}

int add_to_segment_tree(interval in, segment_tree &st, vector<int> bounding_segment)
{
    auto max = [](int a, int b) { return (a > b) ? a : b; };
    auto min = [](int a, int b) { return (b > a) ? a : b; };
    int start = bounding_segment[0];
    int end = bounding_segment[1];
    int index = bounding_segment[2];
    int l = in.first;
    int r = in.second;
    //cout << "Adding segment " << l << "-" << r << " inside bounding segment " << start << ", " << end << " at pos " << index << endl;

    if (start == l && end == r) // perfect match
    {
        st[index]++;
        //cout << "Perfect match of segment " << l << "-" << r << " inside bounding segment " << start << ", " << end << " at pos " << index << endl;
        return 0;
    }
    else if (start > r || end < l) // out_of_bounds
    {
        //cout << "Throwing away this segment" << start << ", " << end << endl;
        return 0;
    }
    else
    {
        int left_end = start + (end - start - 1) / 2;
        int right_start = start + (end - start + 1) / 2;
        vector<int> left_segment = {start, left_end, index * 2};
        vector<int> right_segment = {right_start, end, index * 2 + 1};
        add_to_segment_tree({l, min(left_end, r)}, st, left_segment);
        add_to_segment_tree({max(right_start, l), r}, st, right_segment);
        return 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    segment_tree st = {0};
    vector<interval> is;
    vector<int> bs = {1, NUMS, 1};

    read_input(n, is);

    for (auto &i : is)
    {
        add_to_segment_tree(i, st, bs);
    }

    print_segment_tree(st);

    return 0;
}
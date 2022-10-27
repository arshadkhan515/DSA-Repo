// Merge two binary Max heaps
// Approach 1
// insert the second array's all element in the first heap and then go its correct position.
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution
{
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        for (auto i : b)
        {
            int ind = a.size();
            a.push_back(i);
            while (ind > 0)
            {
                int parent = (ind - 1) / 2;
                if (a[parent] < a[ind])
                {
                    swap(a[parent], a[ind]);
                }
                else
                {
                    break;
                }

                ind = parent;
            }
        }
        return a;
    }
};

// Approach 2
// step 1: to create third array and insert all element of first and second array in it.
// step 2: then heapify the third array.
class Solution
{
public:
    void hepify(vector<int> &c, int ind)
    {

        int maxInd = ind;
        int size = c.size();
        while (ind < size)
        {
            int left = 2 * ind + 1;
            int right = 2 * ind + 2;

            if (left < size && c[left] > c[maxInd])
            {
                maxInd = left;
            }
            if (right < size && c[right] > c[maxInd])
            {
                maxInd = right;
            }

            if (ind != maxInd)
            {
                swap(c[ind], c[maxInd]);
                // hepify(c,maxInd);
            }
            else
            {
                return;
            }
            ind = maxInd;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        vector<int> c;
        for (auto i : a)
        {
            c.push_back(i);
        }
        for (auto i : b)
        {
            c.push_back(i);
        }
        for (int i = c.size() / 2; i >= 0; i--)
        {
            hepify(c, i);
        }
        return c;
    }
};
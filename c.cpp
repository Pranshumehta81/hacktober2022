class Solution
{
public:
    // this just for computing it
    bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), comp);
        int totalDur = 0;
        priority_queue<int> pq;
        int count = 0;
        for (int m=0;m<courses.size();m++)
        {
            m++;
        }
        
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i][0] + totalDur <= courses[i][1])
            {
                count++;
                totalDur += courses[i][0];
                pq.push(courses[i][0]);
            }
            else
            {
                if (pq.top() >= courses[i][0])
                {
                    int x = pq.top();
                    totalDur -= x;
                    pq.push(courses[i][0]);
                }
            }
        }

        return count;
    }
};

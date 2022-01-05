#include <bits/stdc++.h>
using namespace std;
int frameCount, flag = -1;
void display(queue<int> temp)
{
    int n = temp.size();
    while (!temp.empty())
    {
        cout << temp.front() << "\t";
        temp.pop();
    }
    for (int i = 0; i < frameCount - n; i++)
    {
        cout << "-1"
             << "\t";
    }
    if (flag == 1)
    {
        cout << "HIT";
    }
    else
    {
        cout << "MISS";
    }
    cout << endl;
}

int pageFault(vector<int> pages, int n, int framesCount)
{
    queue<int> q;
    set<int> frame;
    int pageFault_count = 0;

    for (int i = 0; i < n; i++)
    {
        int pageNo = pages[i];
        auto it = frame.find(pageNo);
        if (it == frame.end()) // checking if that pageNo is already in the frame or not
        {
            if (frame.size() >= framesCount) // if frame is full then we remove the first page from the queue
            {
                int replace = q.front();
                q.pop();              // replaced page is removed from the queue
                frame.erase(replace); // replaced page is removed from the set
            }

            frame.insert(pageNo); // new page is inserted in the set
            q.push(pageNo);       // new page is inserted in the queue
            pageFault_count++;    // increment page fault count
            flag = 0;
        }
        else
        {
            flag = 1;
        }

        display(q);
    }
    return pageFault_count;
}

int main()
{
    cout << "Enter the length of the refernce string and number of frames: ";

    int n;

    cin >> n >> frameCount;

    vector<int> pages(n);

    // taking refernce string input

    cout << "Enter the reference string: ";

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << endl
         << "Frame Table" << endl;
    int t = pageFault(pages, n, frameCount);
    cout << "Total number of page faults are: " << t << "\n";
    return 0;
}
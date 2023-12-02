#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        // bool collisionOccurred = true;
        // while(collisionOccurred && asteroids.size() > 1){
        //     int i = 0;

        //     while(i+1 < asteroids.size()){
        //         if((asteroids[i] > 0 && asteroids[i+1] < 0) ||
        //             (asteroids[i] < 0 && asteroids[i+1] > 0))
        //         {
        //             if(abs(asteroids[i]) > abs(asteroids[i+1])){
        //                 asteroids.erase(asteroids.begin() + i + 1);
        //             }
        //             else if(abs(asteroids[i]) < abs(asteroids[i+1])){
        //                 asteroids.erase(asteroids.begin() + i);
        //             }
        //             else{
        //                 asteroids.erase(asteroids.begin() + i);
        //                 asteroids.erase(asteroids.begin() + i);
        //             }
        //             collisionOccurred = true;
        //         }
        //         else{
        //             collisionOccurred = false;
        //         }
        //         i++;
        //     }
        // }

        // return asteroids;

        vector<int> stack;

        for (const int a : asteroids)
        {
            if (a > 0)
            {
                stack.push_back(a);
            }
            else
            {
                while (!stack.empty() && stack.back() > 0 && stack.back() < -a)
                {
                    stack.pop_back();
                }

                if (stack.empty() || stack.back() < 0)
                {
                    stack.push_back(a);
                }
                else if (stack.back() == -a)
                {
                    stack.pop_back();
                }
            }
        }

        return stack;
    }

    void print(vector<int> vect)
    {
        cout << "[";
        for (int x : vect)
        {
            cout << x << " ";
        }
        cout << "]";
        cout << endl;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> asteroids = {10, 2, -5};

    vector<int> result = s->asteroidCollision(asteroids);
    s->print(result);

    delete s;
    return 0;
}
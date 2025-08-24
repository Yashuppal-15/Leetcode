class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for(int i=0; i<n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        stack<double> Mistack;
        for(auto [pos, spd] : cars)
        {
            double time = (double) (target - pos)/spd;
            if(Mistack.empty() || Mistack.top() < time)
            {
                Mistack.push(time);
            }
        }
        return Mistack.size();
    }
};
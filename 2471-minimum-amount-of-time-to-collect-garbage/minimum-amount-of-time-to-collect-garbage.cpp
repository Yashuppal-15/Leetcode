class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int pickM = 0, pickP = 0, pickG = 0;
        int lastM = 0, lastP = 0, lastG = 0;

        // Step 1: Count garbage and last index
        for (int i = 0; i < garbage.size(); i++) {
            for (char ch : garbage[i]) {
                if (ch == 'M') {
                    pickM++;
                    lastM = i;
                }
                if (ch == 'P') {
                    pickP++;
                    lastP = i;
                }
                if (ch == 'G') {
                    pickG++;
                    lastG = i;
                }
            }
        }

        // Step 2: Calculate travel time
        int travelM = 0, travelP = 0, travelG = 0;

        for (int i = 0; i < lastM; i++) travelM += travel[i];
        for (int i = 0; i < lastP; i++) travelP += travel[i];
        for (int i = 0; i < lastG; i++) travelG += travel[i];

        // Step 3: Total time
        return pickM + travelM + pickP + travelP + pickG + travelG;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() == 0 || hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (auto it : cardCount) {
            int card = it.first;
            int freq = it.second;

            if (freq > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[card + i] < freq) {
                        return false;
                    }
                    cardCount[card + i] -= freq;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int temp = numBottles;
        int rem = 0;

        while (temp >= numExchange) {
            int newBottles = temp / numExchange;
            rem = temp % numExchange;
            sum += newBottles;
            temp = newBottles + rem;
        }

        return sum;
    }
};

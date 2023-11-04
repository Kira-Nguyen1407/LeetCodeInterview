#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;

    if (prices.size() > 1)
    {
        int count = 0;
        int sell_price = 10001, buy_price = 10001;
        int index_of_buy_price = -1;

        while (count < prices.size() && profit == 0)
        {
            for (int i = 0; i < prices.size(); i++)
            {
                if (sell_price == 10001)
                {
                    if (prices[i] < buy_price)
                    {
                        buy_price = prices[i];
                        index_of_buy_price = i;
                    }
                }
                else
                {
                    if(i == 0)
                        buy_price = 10001;

                    if (prices[i] < buy_price && prices[i] > sell_price)
                    {
                        buy_price = prices[i];
                        index_of_buy_price = i;
                    }
                }
                cout << "buy_price: " << buy_price << endl;
            }

            sell_price = buy_price;
            // cout << "sell_price: " << sell_price << endl;

            for (int j = index_of_buy_price + 1; j < prices.size(); j++)
            {
                if (prices[j] > sell_price)
                {
                    sell_price = prices[j];
                }
            }

            if (sell_price > buy_price)
            {
                profit = sell_price - buy_price;
            }

            count++;
        }
    }

    return profit;
}

int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout << maxProfit(prices) << endl;

    return 0;
}
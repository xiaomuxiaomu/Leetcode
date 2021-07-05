#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	typedef	struct stockNote
	{
		int MaxProfit;
		int BuyPrice;
		stockNote()
		{
			MaxProfit = 0;
			BuyPrice = 0;
		}

	}stockNote;
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		stockNote Note[1000];
		int max = 0;
		Note[0].BuyPrice = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			if (Note[i].BuyPrice == 0)
				Note[i].BuyPrice = prices[i];
			if (prices[i] > Note[i - 1].BuyPrice)
			{
				if (prices[i] - Note[i - 1].BuyPrice > Note[i - 1].MaxProfit)
				{
					Note[i].BuyPrice = Note[i - 1].BuyPrice;
					Note[i].MaxProfit = prices[i] - Note[i].BuyPrice;
					if (Note[i].MaxProfit >= max)
					{
						max = Note[i].MaxProfit;
						for (int loop = i - 1; loop >= 0; loop--)
						{
							Note[loop].MaxProfit = 0;
							if (prices[loop] == Note[i].BuyPrice)
								break;
						}
					}
				}
			}
		}
		sort(&Note[0], &Note[1000], [](stockNote a, stockNote b) -> int { return a.MaxProfit > b.MaxProfit; });
		max = 0;
		for (int i = 0; i < k; i++)
			max += Note[i].MaxProfit;
		return max;
	}
};


int main(void)
{
	Solution

	return 0
}
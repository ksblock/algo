//#1427
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string input;
	vector<char> v;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		for (int j = i + 1; j < input.length(); j++)
		{
			if (input[i] < input[j])
			{
				char temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

	cout << input;
}
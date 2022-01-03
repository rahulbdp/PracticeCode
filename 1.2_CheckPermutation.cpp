#include <iostream>

using namespace std;

bool checkPermutation(string str1, string str2)
{
	string toParse = str1;
	string toSearch = str2;
	
	for (auto &i: toParse )
	{
		cout<<i<<endl;
		cout<<toSearch<<endl;
		bool anyMatch = false;
		for (auto j=toSearch.begin();j!=toSearch.end();j++)
		{
			if (i == *j)
			{
				toSearch.erase(j);
				anyMatch = true;
				break;
			}
		}
		if (anyMatch == false)
			return false;
	}
	if (toSearch.length() == 0)
		return true;
	else
		return false;
}

int main()
{
	string ip1 = "dog i am";
	string ip2 = "i am god";
	bool result = checkPermutation(ip1,ip2);
	cout<<"is String ("<<ip1<<") and ("<<ip2<<") are permutation = "<<result<<endl;;
	return 0;
}
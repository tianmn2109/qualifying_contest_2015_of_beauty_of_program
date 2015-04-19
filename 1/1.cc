#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

bool isRun(int y)
{
	if ( (y % 4 == 0 && y % 100 != 0)
             || y % 400 == 0)
		return true;
	return false;
}

int cal(int sm, int sd, int sy, int em, int ed, int ey)
{
	int sum = 0;
	for (int i = sy + 1; i < ey; i ++)
		if (isRun(i))
			sum ++;
	if (sy == ey && isRun(sy))
	{
		if ( ( em == 1 || (em == 2 && ed < 29) ) 
                     || sm > 2)
		{}
		else
		{
			sum ++;
		}
		return sum;	
	}
	if (isRun(sy))
	{
		if (sm == 1 || (sm == 2 && sd <= 29))
			sum ++;
	}
	if (isRun(ey))
	{
		if (em > 2 || (em == 2 && ed == 29))
			sum ++;
	}
	return sum;
}


int main()
{
	map<string, int> m;
	m["January"] = 1;
	m["February"] = 2;
	m["March"] = 3;
	m["April"] = 4;
	m["May"] = 5;
	m["June"] = 6;
	m["July"] = 7;
	m["August"] = 8;
	m["September"] = 9;
	m["October"] = 10;
	m["November"] = 11;
	m["December"] = 12;
	string month;
	int m1 = 0;
	string day;
	int d1 = 0;
	int y1 = 0;
	int m2 = 0;
	int y2 = 0;
	int d2 = 0;
	int num;
	cin >> num;
	int id = 1;
	while (num --) {
		cin >> month;
		cin >> day;
		cin >> y1;
		m1 = m[string(month.c_str())];
		day = day.substr(0, day.size() - 1);
		d1 = atoi(day.c_str());
		
		cin >> month;
		cin >> day;
		cin >> y2;
		m2 = m[string(month.c_str())];
		day = day.substr(0, day.size() - 1);
		d2 = atoi(day.c_str());

		cout << "Case #" << id ++ << ": " << cal(m1, d1, y1, m2, d2, y2) << endl;

	}
	return 0;
}

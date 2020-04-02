#include "stdafx.h"
bool Check(int num, int now_line, int now_column)
{
	for (int i = 0; i < s; ++i)
	{
		if (shudu[now_line][i] == num || shudu[i][now_column] == num)
			return false;
	}
	if (block != 0)
	{
		int i, j;
		for (i = now_line / block_line * block_line; i < now_line / block_line * block_line + block_line; i++)
		{
			for (j = now_column / block_column * block_column; j < now_column / block_column * block_column + block_column; j++)
			{
				if (shudu[i][j] == num)
					return false;
			}
		}
	}
	return true;
}

bool Work(int now_line, int now_column)
{
	if (now_line == s)
	{
		return true;
	}
	else
	{
		int next_line, next_column;
		next_column = now_column + 1;
		next_line = (next_column == s ? now_line + 1 : now_line);
		next_column = (next_column == s ? 0 : next_column);
		if (shudu[now_line][now_column] != 0)
		{
			if (Work(next_line, next_column)) return true;
		}
		else
		{
			for (int i = 1; i <= s; i++)
			{
				if (Check(i, now_line, now_column))
				{
					shudu[now_line][now_column] = i;
					if (Work(next_line, next_column)) return true;
				}
			}
			shudu[now_line][now_column] = 0;
			return false;
		}
	}
}

void Input()
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cin >> shudu[i][j];
		}
	}
}

void Output()
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cout << shudu[i][j];
			if (j != s - 1) cout << " ";
		}
		cout << endl;
	}
	if (t)
		cout << endl;
}
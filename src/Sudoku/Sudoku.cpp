#include "stdafx.h"

//#include "stdafx.cpp"

int shudu[9][9], s, t, block = 0, block_line = 0, block_column = 0;

int main(int argc, char* argv[])
{
	s = atoi(argv[2]);
	t = atoi(argv[4]);
	freopen(argv[6], "r", stdin);
	freopen(argv[8], "w", stdout);
	while (t--)
	{
		Input();
		switch (s)
		{
		case 4:block = 1, block_line = 2, block_column = 2; break;
		case 6:block = 1, block_line = 2, block_column = 3; break;
		case 8:block = 1, block_line = 4, block_column = 2; break;
		case 9:block = 1, block_line = 3, block_column = 3; break;
		default:break;
		}
		if (Work(0, 0)) Output(); 
		else cout << "No Answer." << endl;
	}
	fclose(stdin);
	fclose(stdout);
	//system("pause"); 
	return 0;
}
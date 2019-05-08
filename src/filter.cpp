#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//variables
	int x;
	int y;
	int z;
	int a = 0;
	int b = 255;
	int c = 100;
	
	ifstream myfile {"./data/file1", ios::binary}; 
	ofstream myfile2 {"./data/file3", ios::binary}; //myfile is a variable.
	
	if (myfile) //check to see if files were opened successfully.
	{
		if (myfile2)
		{
			while (!myfile.eof())
			{
			
				myfile.read(reinterpret_cast<char*>(&x), sizeof(x));
				myfile.read(reinterpret_cast<char*>(&y), sizeof(y));
				myfile.read(reinterpret_cast<char*>(&z), sizeof(z));
				int avg = (x + y + z) / 3;
				
				if (avg < 75) //write 3 zeroes to file3
				{
					for (int i = 0; i < 3; i++)
					{
						myfile2.write(reinterpret_cast<char*>(&a), sizeof(a));
					}
				}
				else if (avg > 150)
				{
					for (int i = 0; i < 3; i++)
					{
						myfile2.write(reinterpret_cast<char*>(&b), sizeof(b));
					}
				}
				else 
				{
					for (int i = 0; i < 3; i++)
					{
						myfile2.write(reinterpret_cast<char*>(&c), sizeof(c));
					}
				}
			}
		}
		else
		{
			cout << "Error opening file 2" << endl;
		}
	}
	else
	{
		cout << "Error opening file 1" << endl;
	}
}

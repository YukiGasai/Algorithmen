#include <iostream>;
#include <map>

using namespace std;

string text = "einenadelimheuhaufenfinden";

string needel = "finden";

int *fillJumpArray() {
	static int* arr = new int[26];

	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}

	for (int i = needel.length()-1; i >= 0; i--)
	{
		char c = needel[i];
		int index = (int)(c - 97);
		if (i == needel.length()-1) {
			arr[index] = needel.length() - 1;
		}
		else {
		
			arr[index] = needel.length() - 1 - i;
		}
	}

	return arr;
}

int CheckText(int i, int* jumpArr) {
	for (int j = needel.length()-1; j >= 0; j--)
	{
		if (text.length()-1 < i + j) {
			return -2;
		}
		if(text[i+j] != needel[j]){

			char c = text[i+ needel.length() - 1];
			int index = (int)(c - 97);

			int jumpvalue = jumpArr[index];

			return jumpvalue;
		}
	}
	return -1;
}

int main() {

	int* jumpArr = fillJumpArray();


	for (int i = 0; i < 26; i++)
	{
		cout << jumpArr[i] << "  " << i << endl;
	}

	for (int i = 0; i < text.length();)
	{
		cout << i << endl;
		int jump = CheckText(i, jumpArr);
		if (jump == -2) {
			cout << "NOT FOUND" << endl;
			break;
		}
		else if (jump == -1) {
			cout << "FOUND  " << i << endl;
			break;
		}
		else {
			if (jump == 0) {
				jump = 1;
			}
			i += jump;
		}
	}




}
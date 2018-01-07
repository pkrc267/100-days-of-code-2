#include <iostream>
#include <vector>
using namespace std;

bool rotate(vector<vector<int>> &m)
{
	if(m.size() == 0 || m.size() != m[0].size())
		return false;

	int n = m[0].size();
	
	for(int layer = 0; layer = n/2; ++layer){
		int first = layer;
		int last = n - 1 -layer;
		for(int i =first; i < last; ++i){
			int offset = i - first;

			int temp = m[first][i];
			m[first][i] = m[last - offset][first];
			m[last - offset][first] = m[last][last- offset];
			m[last][last - offset] = m[i][last];
			m[i][last] = temp;
		}
	}

	return true;
}

void display(std::vector<std::vector<int>> &v)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; i < n; ++i)
		{
			cout << v[i][j] << '\t';
		}
		cout << '\n';
	}
}

int main(){
	std::vector<std::vector<int>> matrix;
	int n;
	cout << "enter matrix dimention\n";
	cin >> n;
	for(int i =0; i < n; i++){
		std::vector<int> row;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			row.push_back(x);
		}
	}
	cout << "*********************\n";
	cout << (rotate()? "can be rotated\n" : "can't be rotated\n");
	cout << "the rotated matrix is:\n\n";

	return 0;
}
#include <iostream>
#define size 4
using namespace std;
class Backtraching_NQueen{
public:
	bool NQueen();
	bool solve(int column);	
	bool check_safe(int row, int column);
	void print();
private:
	int place[size][size];
	int count = 0, place_count = 0;
};
bool Backtraching_NQueen::NQueen() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			place[i][j] = 0;
	if (solve(0)) {
		print();
		return true;
	}
	else {
		cout << "No way to solve";
		return false;
	}
}
bool Backtraching_NQueen::solve(int column) {
	if (column >= size)
		return true;
	for (int i = 0; i < size; i++) {
		count++;
		if (check_safe(i, column)) {
			place[i][column] = 1;
			if (solve(column + 1))
				return true;
			place[i][column] = 0;
		}
	}
	return false;
}
bool Backtraching_NQueen::check_safe(int row, int column){
	int i, j;
	for (i = 0; i < column; i++)
		if (place[row][i])
			return false;
	place_count++;
	for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
		if (place[i][j])
			return false;
	place_count++;
	for (i = row, j = column; i < size && j >= 0; i++, j--)
		if (place[i][j])
			return false;
	place_count++;
	return true;
}
void Backtraching_NQueen::print() {
	cout << "count check= " << count << endl;
	cout << "place check= " << place_count << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << place[i][j] << "\t";
		cout << "\n";
	}
}
void main(){
	Backtraching_NQueen s;
	s.NQueen();
}

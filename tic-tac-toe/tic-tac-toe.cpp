#include <iostream>
using namespace std;

char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';
char result;

/*
1 2 O
4 X 6
7 8 9
*/

void Draw() {

	system("cls");
	//game structure
	cout << "tic-tac-toe game" << endl;
	cout << " -------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " | ";
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j];
			cout << " | ";
		}
		cout << endl;
		cout << " -------------" << endl;
	}

}

void Input() {
	int a;
	cout << "which number you choose? ";
	cin >> a;

	if (a == 1 && matrix[0][0] == '1')
		matrix[0][0] = player;

	else if (a == 2 && matrix[0][1] == '2')
		matrix[0][1] = player;

	else if (a == 3 && matrix[0][1] == '3')
		matrix[0][1] = player;

	else if (a == 4 && matrix[1][0] == '4')
		matrix[1][0] = player;

	else if (a == 5 && matrix[1][1] == '5')
		matrix[1][1] = player;

	else if (a == 6 && matrix[1][2] == '6')
		matrix[1][2] = player;

	else if (a == 7 && matrix[2][0] == '7')
		matrix[2][0] = player;

	else if (a == 8 && matrix[2][1] == '8')
		matrix[2][1] = player;

	else if (a == 9 && matrix[2][2] == '9')
		matrix[2][2] = player;
	else {
		cout << "wrong choice" << endl;
		Input();
	}
}

void changePlayer() {
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
/*
00 01 02
10 11 12
20 21 22
*/
bool winCheck() {

	for (int i = 0; i < 3; i++)
	{
		if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
		{
			result = matrix[0][i];
			return true;
		}
		if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
		{
			result = matrix[i][0];
			return true;
		}
		if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		{
			result = matrix[0][0];
			return true;
		}
		if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
			result = matrix[0][0];
			return true;
		}
	}
	return false;
}
int main()
{

	int i = 0, n = 9;
	Draw();
	while (i < n) {
		Input();
		changePlayer();
		Draw();
		if (winCheck()) {
			cout << result << " is the winner.";
			break;
		}
		i++;
	}
	if (i >= 9)
		cout << " no winner" << endl;
}

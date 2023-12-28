#include "Screen.h"

// ����� ������
void Screen::displayText(const string& text)
{
	cout << text << endl;
}

// ����� ���������
void Screen::displayOptions(vector<string>& options)
{
	for (size_t i = 0; i < options.size(); ++i) {
		cout << i + 1 << ". " << options[i] << endl;
	}
}

// ����� ������ �� ������
void Screen::displayCharacterByCharacter(const string& text)
{
	for (char c : text) {
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(35)); // �������� � �������������
	}
}

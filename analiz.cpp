#include "analiz.h"
string read_file(string filename)
{
	ifstream fin(filename + ".txt");
	string text = "";
	if (!fin.is_open()) // ���� ���� �� ������
	{
		cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
	}
	else
	{
		string tmp;
		while (std::getline(fin, tmp))
		{
			text += tmp;
		}

	}
	return text;
}
const int size_of_alphavit = 32;
string analiz(string text)
{
	const int size_of_memory = 256;//���� �� ������, �� ������ 1024 (���� ����� ������ ������ �� ������ � ������� 38-55)
	
	char most_char[size_of_alphavit] = {
	' ', '�', '�', '�', '�', '�', '�',
	'�', '�', '�', '�', '�', '�', '�',
	'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
	'�', '�', '�'
	};
	//������� ���-�� ���������� ������ �� �������
	char mb_char[size_of_memory] = { '\t' };
	int cout_mb_char[size_of_memory] = { 0 };
	int size_mb_char = 1;
	mb_char[0] = ' ';
	for (int i = 0; i < text.size(); i++)
	{
		if (text.at(i) == ' ')
		{
			cout_mb_char[0]++;
		}
		int index_mb = size_mb_char;
		for (int i_mb = 0; i_mb < size_mb_char; i_mb++)
		{
			if (text.at(i) == mb_char[i_mb])
			{
				index_mb = i_mb;
			}
		}
		if (index_mb == size_mb_char)
		{
			mb_char[index_mb] = text.at(i);
			size_mb_char++;
		}
		cout_mb_char[index_mb]++;
	}
	
	/*for (int i = 0; i < size_of_memory; i++)
	{
		cout << mb_char[i] << "count " << cout_mb_char[i] << endl;
	}*/
	//�� ����, ����������
	//������, ����� ���� �����, ��� � ����� �� ������������ �������� �������� ���-�� ���������
	//� ����� ������ ����� ��������� ������ ���, ��� ����� �����, ������� ��� ������

	//������ ���� ������������� ��� ������� �� ��������
	
	int copy_cout_mb_char[size_of_memory] = { 0 };
	char sort_mb_char[size_of_memory] = { '\0' };
	int tmp_index = 0;//������ ���� �����, ��� �� ����������
	for (int i = 0; i < size_of_memory; i++)// ������ �� ��������������� �������
	{
		tmp_index = 0;
		int max = 0;
		for (int i1 = 0; i1 < size_of_memory; i1++)//���� ���������� �������
		{
			if (max < cout_mb_char[i1])
			{
				tmp_index = i1;
				max = cout_mb_char[i1];
			}
		}
		sort_mb_char[i] = mb_char[tmp_index];
		copy_cout_mb_char[i] = cout_mb_char[tmp_index];
		cout_mb_char[tmp_index] = -1;
	}
	//����� �������������
	//c����� �������� �� �����������������,� �� ���� �� ���� �� ������������
	/*for (int i = 0; i < size_of_memory; i++)
	{
		cout << sort_mb_char[i] << endl << endl;
	}*/

	// ��������

	cout << "�������, ������� ��������� ������ �������:\n������ ������� - ����� � ������������� ����\n������ ������� - ����� � ����������� ����\n\n\n";
	for (int i = 0; i < size_of_alphavit; i++)
	{
		cout << most_char[i] << " -> " << sort_mb_char[i] << " ����������� ��� : " << copy_cout_mb_char[i] << endl;
	}
	cout << "\n\n\n";

	/*for (int i = 0; i < size_of_alphavit; i++)
	{
		std::replace(text.begin(), text.end(), most_char[i], sort_mb_char[i]);
	}
	for (int i = size_of_alphavit; i < size_mb_char; i++)
	{
		std::replace(text.begin(), text.end(), sort_mb_char[i], '*');
	}*/

	text = replace_char(text, most_char, sort_mb_char);

	return text;
}

string replace_char(string text, char* old_char, char* new_char)
{
	for (int i = 0; i < text.length(); i++)
	{
		for (int i_c = 0; i_c < size_of_alphavit; i_c++)
		{
			if (text.at(i) == old_char[i_c])
			{
				text[i] = new_char[i_c];
				break;
			}
		}
	}
	return text;
}


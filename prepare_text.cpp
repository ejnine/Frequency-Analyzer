
#include "prepare_text.h"
string prepare(string text)
{
	string tmp = "";
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] < '�' && text[i] > '�')
		{
			tmp += (text[i] + 32);
		}
		else
		{
			if ((text[i] > '�' || text[i] < '�') && text[i] != ' ')
			{
				tmp += ' ';
			}
			else
			{
				tmp += text[i];
			}
		}
	}
	return tmp;
}

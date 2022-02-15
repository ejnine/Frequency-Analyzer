
#include "prepare_text.h"
string prepare(string text)
{
	string tmp = "";
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] < 'ß' && text[i] > 'À')
		{
			tmp += (text[i] + 32);
		}
		else
		{
			if ((text[i] > 'ÿ' || text[i] < 'à') && text[i] != ' ')
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

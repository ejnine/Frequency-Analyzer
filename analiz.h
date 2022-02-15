#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <algorithm>
using namespace std;

string read_file(string filename);
string analiz(string old_text);
string replace_char(string text, char* old_char, char* new_char);
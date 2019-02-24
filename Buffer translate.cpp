#include <iostream>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

char * OutClipboard()
{
	char * text = NULL;
	
	if ( OpenClipboard(0) ) 
	{
    	HANDLE hData = GetClipboardData( CF_TEXT );
    	text = (char*)GlobalLock( hData );
    	GlobalUnlock( hData );
    	CloseClipboard();
	}
	return text;
}

void ToClipboard(char* text)
{
    if(OpenClipboard(0))
    {
        EmptyClipboard();
        char* clip_data = (char*)(GlobalAlloc(GMEM_FIXED, MAX_PATH));
        lstrcpy(clip_data, text);
        SetClipboardData(CF_TEXT, (HANDLE)(clip_data));
        LCID* lcid = (DWORD*)(GlobalAlloc(GMEM_FIXED, sizeof(DWORD)));
        *lcid = MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_NEUTRAL), SORT_DEFAULT);
        SetClipboardData(CF_LOCALE, (HANDLE)(lcid));
        CloseClipboard();
    }
}

string Translate(string text)
{
	int i;
	
	for(i = 0; i < text.length(); i++)
	{
		switch(text[i])
		{
			case '�': text[i] = 'q'; break;
			case '�': text[i] = 'w'; break;
			case '�': text[i] = 'e'; break;
			case '�': text[i] = 'r'; break;
			case '�': text[i] = 't'; break;
			case '�': text[i] = 'y'; break;
			case '�': text[i] = 'u'; break;
			case '�': text[i] = 'i'; break;
			case '�': text[i] = 'o'; break;
			case '�': text[i] = 'p'; break;
			case '�': text[i] = '['; break;
			case '�': text[i] = ']'; break;
			case '�': text[i] = 'a'; break;
			case '�': text[i] = 's'; break;
			case '�': text[i] = 'd'; break;
			case '�': text[i] = 'f'; break;
			case '�': text[i] = 'g'; break;
			case '�': text[i] = 'h'; break;
			case '�': text[i] = 'j'; break;
			case '�': text[i] = 'k'; break;
			case '�': text[i] = 'l'; break;
			case '�': text[i] = ';'; break;
			case '�': text[i] = 222; break;
			case '�': text[i] = 'z'; break;
			case '�': text[i] = 'x'; break;
			case '�': text[i] = 'c'; break;
			case '�': text[i] = 'v'; break;
			case '�': text[i] = 'b'; break;
			case '�': text[i] = 'n'; break;
			case '�': text[i] = 'm'; break;
			case '�': text[i] = ','; break;
			case '�': text[i] = '.'; break;
			case '�': text[i] = 'Q'; break;
			case '�': text[i] = 'W'; break;
			case '�': text[i] = 'E'; break;
			case '�': text[i] = 'R'; break;
			case '�': text[i] = 'T'; break;
			case '�': text[i] = 'Y'; break;
			case '�': text[i] = 'U'; break;
			case '�': text[i] = 'I'; break;
			case '�': text[i] = 'O'; break;
			case '�': text[i] = 'P'; break;
			case '�': text[i] = '{'; break;
			case '�': text[i] = '}'; break;
			case '�': text[i] = 'A'; break;
			case '�': text[i] = 'S'; break;
			case '�': text[i] = 'D'; break;
			case '�': text[i] = 'F'; break;
			case '�': text[i] = 'G'; break;
			case '�': text[i] = 'H'; break;
			case '�': text[i] = 'J'; break;
			case '�': text[i] = 'K'; break;
			case '�': text[i] = 'L'; break;
			case '�': text[i] = ':'; break;
			case '�': text[i] = 34 ; break;
			case '�': text[i] = 'Z'; break;
			case '�': text[i] = 'X'; break;
			case '�': text[i] = 'C'; break;
			case '�': text[i] = 'V'; break;
			case '�': text[i] = 'B'; break;
			case '�': text[i] = 'N'; break;
			case '�': text[i] = 'M'; break;
			case '�': text[i] = '<'; break;
			case '�': text[i] = '>'; break;
			case 'q': text[i] = '�'; break;
			case 'w': text[i] = '�'; break;
			case 'e': text[i] = '�'; break;
			case 'r': text[i] = '�'; break;
			case 't': text[i] = '�'; break;
			case 'y': text[i] = '�'; break;
			case 'u': text[i] = '�'; break;
			case 'i': text[i] = '�'; break;
			case 'o': text[i] = '�'; break;
			case 'p': text[i] = '�'; break;
			case '[': text[i] = '�'; break;
			case ']': text[i] = '�'; break;
			case 'a': text[i] = '�'; break;
			case 's': text[i] = '�'; break;
			case 'd': text[i] = '�'; break;
			case 'f': text[i] = '�'; break;
			case 'g': text[i] = '�'; break;
			case 'h': text[i] = '�'; break;
			case 'j': text[i] = '�'; break;
			case 'k': text[i] = '�'; break;
			case 'l': text[i] = '�'; break;
			case ';': text[i] = '�'; break;
			case 'z': text[i] = '�'; break;
			case 'x': text[i] = '�'; break;
			case 'c': text[i] = '�'; break;
			case 'v': text[i] = '�'; break;
			case 'b': text[i] = '�'; break;
			case 'n': text[i] = '�'; break;
			case 'm': text[i] = '�'; break;
			case ',': text[i] = '�'; break;
			case '.': text[i] = '�'; break;
			case '/': text[i] = '.'; break;
			case 'Q': text[i] = '�'; break;
			case 'W': text[i] = '�'; break;
			case 'E': text[i] = '�'; break;
			case 'R': text[i] = '�'; break;
			case 'T': text[i] = '�'; break;
			case 'Y': text[i] = '�'; break;
			case 'U': text[i] = '�'; break;
			case 'I': text[i] = '�'; break;
			case 'O': text[i] = '�'; break;
			case 'P': text[i] = '�'; break;
			case 123: text[i] = '�'; break;
			case 125: text[i] = '�'; break;
			case 'A': text[i] = '�'; break;
			case 'S': text[i] = '�'; break;
			case 'D': text[i] = '�'; break;
			case 'F': text[i] = '�'; break;
			case 'G': text[i] = '�'; break;
			case 'H': text[i] = '�'; break;
			case 'J': text[i] = '�'; break;
			case 'K': text[i] = '�'; break;
			case 'L': text[i] = '�'; break;
			case ':': text[i] = '�'; break;
			case 34 : text[i] = '�'; break;
			case 'Z': text[i] = '�'; break;
			case 'X': text[i] = '�'; break;
			case 'C': text[i] = '�'; break;
			case 'V': text[i] = '�'; break;
			case 'B': text[i] = '�'; break;
			case 'N': text[i] = '�'; break;
			case 'M': text[i] = '�'; break;
			case '<': text[i] = '�'; break;
			case '>': text[i] = '�'; break;
			case '?': text[i] = ','; break;
			case '�': text[i] = '~'; break;
			case '�': text[i] = '`'; break;
		}
	}
	
	return text;		
}

int main()
{	
	string text;
	
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	
	setlocale(LC_ALL, "rus");
	
	ifstream fin;
	fin.open("temp.txt", ios::in);
	
	fin >> text;
	fin.close();
	
	ofstream hout;
	hout.open("history.txt", ios::app);
	
	hout << asctime(timeinfo) << "Original:     " << text << "\nTranslated:   ";
	
	text = Translate(text);
	
	hout << text << "\n----------------------------------------\n";
	
	ofstream tout;
	tout.open("temp.txt", ios::trunc);
	tout << text;
	
	hout.close();
  	tout.close();
	return 0;
}

#include <iostream>
#include <windows.h>
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
			case 'é': text[i] = 'q'; break;
			case 'ö': text[i] = 'w'; break;
			case 'ó': text[i] = 'e'; break;
			case 'ê': text[i] = 'r'; break;
			case 'å': text[i] = 't'; break;
			case 'í': text[i] = 'y'; break;
			case 'ã': text[i] = 'u'; break;
			case 'ø': text[i] = 'i'; break;
			case 'ù': text[i] = 'o'; break;
			case 'ç': text[i] = 'p'; break;
			case 'õ': text[i] = '['; break;
			case 'ú': text[i] = ']'; break;
			case 'ô': text[i] = 'a'; break;
			case 'û': text[i] = 's'; break;
			case 'â': text[i] = 'd'; break;
			case 'à': text[i] = 'f'; break;
			case 'ï': text[i] = 'g'; break;
			case 'ð': text[i] = 'h'; break;
			case 'î': text[i] = 'j'; break;
			case 'ë': text[i] = 'k'; break;
			case 'ä': text[i] = 'l'; break;
			case 'æ': text[i] = ';'; break;
			case 'ý': text[i] = 222; break;
			case 'ÿ': text[i] = 'z'; break;
			case '÷': text[i] = 'x'; break;
			case 'ñ': text[i] = 'c'; break;
			case 'ì': text[i] = 'v'; break;
			case 'è': text[i] = 'b'; break;
			case 'ò': text[i] = 'n'; break;
			case 'ü': text[i] = 'm'; break;
			case 'á': text[i] = ','; break;
			case 'þ': text[i] = '.'; break;
			case 'É': text[i] = 'Q'; break;
			case 'Ö': text[i] = 'W'; break;
			case 'Ó': text[i] = 'E'; break;
			case 'Ê': text[i] = 'R'; break;
			case 'Å': text[i] = 'T'; break;
			case 'Í': text[i] = 'Y'; break;
			case 'Ã': text[i] = 'U'; break;
			case 'Ø': text[i] = 'I'; break;
			case 'Ù': text[i] = 'O'; break;
			case 'Ç': text[i] = 'P'; break;
			case 'Õ': text[i] = '{'; break;
			case 'Ú': text[i] = '}'; break;
			case 'Ô': text[i] = 'A'; break;
			case 'Û': text[i] = 'S'; break;
			case 'Â': text[i] = 'D'; break;
			case 'À': text[i] = 'F'; break;
			case 'Ï': text[i] = 'G'; break;
			case 'Ð': text[i] = 'H'; break;
			case 'Î': text[i] = 'J'; break;
			case 'Ë': text[i] = 'K'; break;
			case 'Ä': text[i] = 'L'; break;
			case 'Æ': text[i] = ':'; break;
			case 'Ý': text[i] = 34 ; break;
			case 'ß': text[i] = 'Z'; break;
			case '×': text[i] = 'X'; break;
			case 'Ñ': text[i] = 'C'; break;
			case 'Ì': text[i] = 'V'; break;
			case 'È': text[i] = 'B'; break;
			case 'Ò': text[i] = 'N'; break;
			case 'Ü': text[i] = 'M'; break;
			case 'Á': text[i] = '<'; break;
			case 'Þ': text[i] = '>'; break;
			case 'q': text[i] = 'é'; break;
			case 'w': text[i] = 'ö'; break;
			case 'e': text[i] = 'ó'; break;
			case 'r': text[i] = 'ê'; break;
			case 't': text[i] = 'å'; break;
			case 'y': text[i] = 'í'; break;
			case 'u': text[i] = 'ã'; break;
			case 'i': text[i] = 'ø'; break;
			case 'o': text[i] = 'ù'; break;
			case 'p': text[i] = 'ç'; break;
			case '[': text[i] = 'õ'; break;
			case ']': text[i] = 'ú'; break;
			case 'a': text[i] = 'ô'; break;
			case 's': text[i] = 'û'; break;
			case 'd': text[i] = 'â'; break;
			case 'f': text[i] = 'à'; break;
			case 'g': text[i] = 'ï'; break;
			case 'h': text[i] = 'ð'; break;
			case 'j': text[i] = 'î'; break;
			case 'k': text[i] = 'ë'; break;
			case 'l': text[i] = 'ä'; break;
			case ';': text[i] = 'æ'; break;
			case 'z': text[i] = 'ÿ'; break;
			case 'x': text[i] = '÷'; break;
			case 'c': text[i] = 'ñ'; break;
			case 'v': text[i] = 'ì'; break;
			case 'b': text[i] = 'è'; break;
			case 'n': text[i] = 'ò'; break;
			case 'm': text[i] = 'ü'; break;
			case ',': text[i] = 'á'; break;
			case '.': text[i] = 'þ'; break;
			case '/': text[i] = '.'; break;
			case 'Q': text[i] = 'É'; break;
			case 'W': text[i] = 'Ö'; break;
			case 'E': text[i] = 'Ó'; break;
			case 'R': text[i] = 'Ê'; break;
			case 'T': text[i] = 'Å'; break;
			case 'Y': text[i] = 'Í'; break;
			case 'U': text[i] = 'Ã'; break;
			case 'I': text[i] = 'Ø'; break;
			case 'O': text[i] = 'Ù'; break;
			case 'P': text[i] = 'Ç'; break;
			case 123: text[i] = 'Õ'; break;
			case 125: text[i] = 'Ú'; break;
			case 'A': text[i] = 'Ô'; break;
			case 'S': text[i] = 'Û'; break;
			case 'D': text[i] = 'Â'; break;
			case 'F': text[i] = 'À'; break;
			case 'G': text[i] = 'Ï'; break;
			case 'H': text[i] = 'Ð'; break;
			case 'J': text[i] = 'Î'; break;
			case 'K': text[i] = 'Ë'; break;
			case 'L': text[i] = 'Ä'; break;
			case ':': text[i] = 'Æ'; break;
			case 34 : text[i] = 'Ý'; break;
			case 'Z': text[i] = 'ß'; break;
			case 'X': text[i] = '×'; break;
			case 'C': text[i] = 'Ñ'; break;
			case 'V': text[i] = 'Ì'; break;
			case 'B': text[i] = 'È'; break;
			case 'N': text[i] = 'Ò'; break;
			case 'M': text[i] = 'Ü'; break;
			case '<': text[i] = 'Á'; break;
			case '>': text[i] = 'Þ'; break;
			case '?': text[i] = ','; break;
			case '¨': text[i] = '~'; break;
			case '¸': text[i] = '`'; break;
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

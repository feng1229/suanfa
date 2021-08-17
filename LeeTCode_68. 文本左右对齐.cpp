#include<iostream>
#include<malloc.h>
using namespace std;

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
	int renum = 0, num = 0, ii, jj, jnum, kgkg, oi = 0;
	char* po;
	char** p = (char**)malloc(sizeof(char*) * 600);
	while (oi < wordsSize) {
		ii = oi;
		num = 0;
		while (num < maxWidth && oi < wordsSize) {
			int  j = 0;
			while (words[oi][j++] != '\0');
			num += j;
			jnum = j;
			++oi;
		}
		po = (char*)malloc(sizeof(char) * (maxWidth + 1));
		if (oi != wordsSize || num >= maxWidth) {
			if (num > maxWidth + 1) {
				num -= jnum;
				--oi;
			}
			int kg = maxWidth - num + oi - ii;
			jj = 0;
			while (ii < oi) {
				int j = 0;
				while (words[ii][j] != '\0') po[jj++] = words[ii][j++];
				++ii;
				if (ii == oi)break;
				if (kg % (oi - ii) == 0)
					kgkg = kg / (oi - ii);
				else
					kgkg = kg / (oi - ii) + 1;
				for (int u = 0; u < kgkg; ++u)
					po[jj++] = ' ';
				kg -= kgkg;
			}
		}
		while (jj < maxWidth)po[jj++] = ' ';
		jj = 0;
		while (ii < oi) {
			int j = 0;
			while (words[ii][j++] != '\0')po[jj++] = words[ii][j - 1];
			if (jj < maxWidth)po[jj++] = ' ';
			++ii;
			if (ii == oi)while (jj < maxWidth)po[jj++] = ' ';
		}
		po[maxWidth] = '\0';
		p[renum++] = po;
	}
	*returnSize = renum;
	return p;
}

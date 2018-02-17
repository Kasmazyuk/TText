#include <iostream>



class TLink
{
public:
	TLink *pNext;
	TLink *pDown;
	char str[80];




	TLink(char *s=NULL, TLink *pn=NULL, TLink *pd=NULL)
{
	pNext=pn; pDown=pd;
	if (s==NULL)
		str[0]='\o';
	else
	strcpy (str,s);
}
};

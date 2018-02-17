#include "TLink.h"

class TText {
	TLink *pFirst;
	TLink *pCurr;
	TStack <TLink*> st;

public:
	TText (TLink *pf=NULL) {
		if (pf==NULL) pf = new TLink();
		pFirst = pf;
	}

	void GoNextLink () { 
		if (pCurr->pNext != NULL)
		{
			st.Push(pCurr);
			pCurr = pCurr -> pNext;
		}
	}
	void GoDownLink () {
				if (pCurr->pDown != NULL)
		{
			st.Push(pCurr);
			pCurr = pCurr -> pDown;
		}
	}
	void GoPrewLink () {
		if (!st.IsEmpty()) {
			pCurr=st.Pop();
		}
	}
	void InsNextLine (char *ch) {
		TLink *tmp = new TLink (ch, pCurr ->pNext, NULL);
		pCurr -> pNext = tmp;
	}
	void InsNextSection (char *ch) {
		TLink *tmp = new TLink(ch, NULL, pCurr -> pNext);
		pCurr -> pNext = tmp;
	}
	void InsDownSection (char *ch) { 
		TLink *tmp = new TLink(ch, NULL, pCurr -> pDown);
		pCurr -> pDown = tmp;
	}

	void InsDownLine (char *ch) { 
		TLink *tmp = new TLink(ch, pCurr -> pDown, NULL);
		pCurr -> pDown = tmp;
	}
	void DelNext () {
		TLink *tmp = pCurr ->pNext;
		if (pCurr -> pNext != NULL) 
			pCurr -> pNext = tmp -> pNext;
		delete tmp;
	}
		void DelDown () {
		TLink *tmp = pCurr ->pDown;
		if (pCurr -> pDown != NULL) 
			pCurr -> pDown = tmp -> pNext;
		delete tmp;
	}



};

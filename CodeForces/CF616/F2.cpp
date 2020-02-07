#include <bits/stdc++.h>
using namespace std;

bool ask(int pos)
{
    cout << "? " << pos+1 << endl << flush;
    char c; cin >> c;
    if (c == 'E') exit(0);
    return (c == 'Y');
}

int main()
{
    int nbElem, memSize, nbBlocks;
    cin >> nbElem >> memSize;
    nbBlocks = nbElem / memSize;

    vector<bool> isAlive(nbElem, true);

    for (int startBlock = 0; startBlock < nbBlocks; ++startBlock) {
	    int delta = 0;
	    cout << "R" << endl << flush;
	    for (int iDo = 0; iDo < nbBlocks; ++iDo) {
		    int curBlock = (startBlock+delta+nbBlocks) % nbBlocks;
		    int st = curBlock*memSize;
		    for (int elem = st; elem < st+memSize; ++elem) {
			    if (isAlive[elem]) {
				    if (ask(elem)) isAlive[elem] = false;
			    }
		    }

		    if (delta >= 0) ++delta;
		    delta = -delta;
	    }
    }

    int nbAlive = count(isAlive.begin(), isAlive.end(), true);
    cout << "! " << nbAlive << endl << flush;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool pierwsza = true;

ifstream w("wiadomosci.txt");
ifstream p("podpisy.txt");
ofstream epw("epodpis_epwnik.txt");

string skrot(string t) {
   string S = "ALGORYTM";
   while (t.length()%8 !=0) t += '.';
   int n = t.length();
   if (pierwsza) epw << "Dlugosc pierwszej wiadomosci = " << n << endl;
   int i=0;
   while (i<n) 
   {
        for (int j=0; j<8; j++) 
		{
           S[j] = (S[j]+t[i]) %128;
           i++;
        }
   }
   if (pierwsza) 
   {
        epw << "Bajty pierwszej wiadomosci po przetworzeniu: ";
        for (int j=0; j<8; j++) epw << (int)S[j] << " ";
        epw << endl;
   }
   for (int j=0; j<8; j++)
        S[j] = 65 + S[j]%26;
   if (pierwsza) 
   {
        epw << "Skrot pierwszej wiadomosci = " << S << endl << endl;
        pierwsza = false;
   }
   return S;
}

int main()
{
    string t;
    string s, ms;
    int x,y;
    int n =200 , d = 3;

    vector<int> W;

    for (int i=1; i<=11; i++) 
	{

        getline(w,t);
        s = skrot(t);

        ms = "";
        for (int j=0; j<8; j++) {
           p >> y;
           x = (y*d) % n;
           ms += (char)x;
        }
        epw << i << "\t" << ms << "\t";
        if (s==ms) {
                epw << "wiarygodna\n";
                W.push_back(i);
        }
        else epw << "zmieniona\n";
    }

    epw << "\nNumery wiarygodnych wiadomosci: ";
    for (int i=0; i<W.size(); i++) epw << W[i] << " ";

    w.close();
    p.close();
    epw.close();

    return 0;
}

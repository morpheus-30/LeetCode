#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        set<char> sett;
        sett.insert('a');
        sett.insert('e');
        sett.insert('i');
        sett.insert('o');
        sett.insert('u');
        sett.insert('A');
        sett.insert('E');
        sett.insert('I');
        sett.insert('O');
        sett.insert('U');
        int vcount = 0;
        for(int i=0;i<n/2;i++){
            if(sett.find(s[i])!=sett.end()){
                vcount++;
            }
        }
        for(int i = n/2;i<n;i++){
            if(sett.find(s[i])!=sett.end()){
                vcount--;
            }
        }
        return vcount==0;
    }
};
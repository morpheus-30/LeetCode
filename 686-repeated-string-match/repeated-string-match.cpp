class Solution {
public:

    

    int repeatedStringMatch(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        int n = lenB/lenA;
        int cnt = n;
        string modiA = "";
        while(cnt--){
            modiA =modiA +a;
        }    
        if(modiA.find(b) != std::string::npos ){
            return n;
        }
        modiA = modiA+a;
        if(modiA.find(b) != std::string::npos ){
            return n+1;
        }
        modiA = modiA+a;
        if(modiA.find(b) != std::string::npos ){
            return n+2;
        }
        return -1;

    }
};
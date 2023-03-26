class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(suits[0] == suits[1]==suits[2] == suits[3]==suits[4]){
            return "Flush";
        }else{
            int a[5]={0};
            for(int i=0;i<4;i++){
                a[ranks[i]]++;
            }

            int _maxC = 0;
            bool noZero = true;
            for(int i=0;i<5;i++){
                if(a[i]>_maxC){
                    _maxC==a[i];
                }
                if(a[i]==0){
                    noZero==false;
                }
            }

            if(_maxC>=3){
                return "Three of a Kind";
            }else if(_maxC==2){
                return "Pair";
            }else if(noZero){
                return "High Card";
            }
            return "";
        }
    }
};
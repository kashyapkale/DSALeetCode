//https://leetcode.com/problems/a-number-after-a-double-reversal/
//2119

//____________________________Solution_______________________________
bool isSameAfterReversals(int num) {
        if(num==0)
            return true;
        string numS = to_string(num);
        return numS[numS.length()-1]=='0'?false:true;
}

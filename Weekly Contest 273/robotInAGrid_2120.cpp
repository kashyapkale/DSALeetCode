//https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
//2120

//___________________________Solution__________________________________
bool isValid(int x, int y, int n){
    int row = n;
    int col = n;
    return (x >= 0 && x < row && y < col && y >= 0);
}

pair<int, int> getDir(char Dir){
    int xDir[] = { 0, 1, 0, -1 };
    int yDir[] = { 1, 0, -1, 0 };

    if (Dir == 'L')
        return make_pair(xDir[2], yDir[2]);
    if (Dir == 'R')
        return make_pair(xDir[0], yDir[0]);
    if (Dir == 'U')
        return make_pair(xDir[3], yDir[3]);

    return make_pair(xDir[1], yDir[1]);
}


int executeInstructionsUtil(int n,int start, vector<int>& startPos, string &s){
    int ans = 0;
    int stepX = startPos[0];
    int stepY = startPos[1];
    
    for(int i=start;i<s.size();i++){
            pair<int, int> dir = getDir(s[start]);
            stepX += dir.first;
            stepY += dir.second;
            if(isValid(stepX,stepY,n)){
                ans++;
                start++; 
            }
            else
                return ans;
    }
    return ans;
}    
    
vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    vector<int> ans;
    
    for (int i = 0; i < s.length(); i++) {
        ans.push_back(executeInstructionsUtil(n,i, startPos, s));
    }
    return ans;
}

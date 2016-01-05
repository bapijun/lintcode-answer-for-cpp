class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> v;
        sort(S.begin(), S.end());
        subsetsCore(S, 0, v);
        return res;
    }
private:
    vector<vector<int> > res;
    void subsetsCore(vector<int> &S, int start, vector<int> &v){
        if(start == S.size()) { res.push_back(v); return;}
        vector<int> v2;
        for(vector<int>::iterator i = v.begin(); i < v.end(); v2.push_back(*(i++)));
        v.push_back(S[start]);
        subsetsCore(S, start+1, v); //包含S[start]
        subsetsCore(S, start+1, v2); //不包含S[start]
    }
};

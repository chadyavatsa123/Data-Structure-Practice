class Solution {
    unordered_map<string,int>mpp;
    string b;
    vector<vector<string>>ans;
private:
  void dfs(string word,vector<string>&seq){
    if(word==b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int step=mpp[word];
    int size=word.size();
    for(int i=0;i<size;i++){
        char original=word[i];
        for(char c='a';c<='z';c++){
            word[i]=c;
            if(mpp.find(word)!=mpp.end() && mpp[word]+1==step){
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i]=original;
    }
  }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push(beginWord);
        st.erase(beginWord);
        mpp[beginWord]=1;
        int size=beginWord.size();
        b=beginWord;
        while(!q.empty()){
            string word=q.front();
            q.pop();
            if(word==endWord)break;
            int step=mpp[word];
            for(int i=0;i<size;i++){
                char original=word[i];
                for(char ch='a' ;ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        mpp[word]=step+1;
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
          vector<string>seq;
          seq.push_back(endWord);
          dfs(endWord,seq);
        }
        return ans;

    }
};
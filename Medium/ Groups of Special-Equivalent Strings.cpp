class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
      set<pair<string,string>> s;
        for(auto i: words){
          string p="",q="";
          for(int j=0;j<i.size();j++){
              if(j%2==0){
                  p+=i[j];
              }
              else{
                  q+=i[j];
              }
          }
          sort(p.begin(),p.end());
          sort(q.begin(),q.end());
            s.insert({p,q});
        }

        return s.size();
    }
};
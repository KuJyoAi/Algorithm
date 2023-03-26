#include<iostream>
#include<vector>

using namespace std;
vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> _map;
        for(auto domain:cpdomains){
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space + 1);
            counts[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    string subdomain = domain.substr(i + 1);
                    counts[subdomain] += count;
                }
            }
        }

        vector<string> res;
        for(auto [k,v]:_map){
            string to_string(v)+ " " + k;
            res.push_back(str);
        }
        return res;
}

int main(){
    vector<string> test;
    test.push_back("9001 discuss.leetcode.com");
    auto res = subdomainVisits(test);
    for(r:res){
        cout<<res<<endl;
    }
}
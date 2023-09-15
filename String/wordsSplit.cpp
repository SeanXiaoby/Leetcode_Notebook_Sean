#include <string>
#include <iostream>
#include <vector>

using namespace std;


vector<string> wordSplit(string input){
    vector<string> words;
    auto pos = 0;
    string space = " ";

    while((pos = input.find(space))!=string::npos){
        if(input.substr(0, pos).size()){
            words.push_back(input.substr(0, pos));
        }
        input.erase(0, pos+space.length());
    }

    if(input.size()){
        words.push_back(input);
    }
    
    return words;
}



int main(){
    string input = "   the sky    is blue   ";
    auto res = wordSplit(input);
    return 0;
}
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string lower(string s)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

int GetWordFrequency(const vector<string> &words, const string &word)
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < words.size(); i++)
    {
        if (lower(words[i]) == lower(word))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    size_t sizeV;
    cin >> sizeV;
    vector<string> words(sizeV);
    for (size_t i = 0; i < sizeV; i++)
    {
        cin >> words[i];
    }
    for (size_t i = 0; i < sizeV; i++)
    {
        cout << words[i] << ' ' << GetWordFrequency(words, words[i]) << endl;
    }
}
#ifndef LAB0_HEADER_H
#define LAB0_HEADER_H

#endif //LAB0_HEADER_H

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>
#include <iomanip>
#include <cmath>

using namespace std;

class Reader
{
private:
    multimap<int, string, greater<size_t>> sort;
    int count = 0;
public:
    Reader(const char* in)
    {
        ifstream input;
        string str;
        map<string, int> freq;
        regex word("([a-zA-Z0-9]+)");
        input.open(in);
        if (!input)
        {
            cout << "File cannot open!" << endl;
        }
        while (!(input.eof()))
        {
            getline(input, str);
            sregex_iterator pos(str.begin(), str.end(), word);
            sregex_iterator end;
            for (; pos != end; pos++)
            {
                freq[pos->str(0)]++;
            }
        }
        input.close();

        map<string, int>::iterator i = freq.begin();
        for (; i != freq.end(); i++)
        {
            sort.emplace(make_pair(i->second, i->first));
            count += i->second;
        }
    }
    const multimap<int, string, greater<size_t>>& GetMultimap() const
    {
        return sort;
    }
    const int GetCount() const
    {
        return count;
    }
};

class Writer
{
private:
    ofstream output;
    int count = 0;
public:
    Writer(const char* out)
    {
        output.open(out);
    }
    void WI(const Reader& RI)
    {
        const multimap<int, string, greater<size_t>>& sort = RI.GetMultimap();
        count = RI.GetCount();

        for (auto& item_multimap : sort)
        {
            double freq_in_percentage = round((double)item_multimap.first / (double)count * 10000.0) / 100.0;
            output << item_multimap.second << " , " << item_multimap.first << " , " << freq_in_percentage << "%" << endl;
        }
        output.close();
    }
};

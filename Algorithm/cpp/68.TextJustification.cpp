/*
 * 68.Text Justification
 * Given an array of words and aLength L,format the text such that each line has exactly L characters and is fully(left and right) justified.
 * You should pack your words in a greedy approach;that is,pack as many words you can in each line.Pad extra spaces ' ' when necessary so that
 * each line has exactly L charaters.
 *
 * Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words,
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of the text,it should be leftr justified and no extra space is inserted between words.
 * For example,
 * words:["This","is","an","example","of","text","justification."]
 * L: 16.
 * Return the formatted lines as:
 *  [
 *      "This    is    an",
 *      "example  of text",
 *      "justification.  "
 *  ]
 *
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * Corner Cases:
 *      A line other than the last line,might  contain only one word.What should you do in this case?
 *      In this case,that line should be left-justified.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> res;
        for (int i = 0, k, l; i < words.size(); i += k)
        {
            for (k = l = 0; ((i + k) < words.size()) && ((l + words[i + k].size()) <= (maxWidth - k)); k++)
            {
                l += words[i + k].size();
            }
            string tmp = words[i];
            for (int j = 0; j < k - 1; j++)
            {
                if (i + k >= words.size()) tmp += " ";
                else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');//Great
                tmp += words[i + j + 1];
            }
            tmp += string(maxWidth = tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};

void printVector(vector<string> &words, bool newline = false)
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << "\"" << words[i] << "\",";
        if (newline) 
            cout << endl;
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<string> A{"This","is","an","example","of","text","justfication."};
    vector<string> R = s.fullJustify(A, 16);
    printVector(R);

    return 0;
}

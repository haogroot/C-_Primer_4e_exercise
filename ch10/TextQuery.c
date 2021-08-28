#include "TextQuery.h"

using std::set;
using std::string;
using std::vector;
using std::istringstream;

set<TextQuery::lineno> TextQuery::run_query (const string& target) const {
    auto it = word_map.find (target);
    if (it != word_map.end())
    {
        return it->second;
    }
    else
        return set<lineno>();
    
}

/* return each line of string by string no. */
string TextQuery::text_line (TextQuery::lineno line) const {
    if (line < lines_of_text.size())
    {
        return lines_of_text[line];
    }
    throw std::out_of_range ("line out of range");

}

void TextQuery::store_file (std::ifstream& input)
{
    string line;
    while (getline (input, line))
    {
       lines_of_text.push_back (line); 
    }

}

void TextQuery::build_map ()
{
    for (lineno num = 0; num < lines_of_text.size(); num++)
    {
        string word;
        istringstream line (lines_of_text[num]);
        while (line >> word)
        {
            word_map[get_real_word(word)].insert (num);
        }
    }
}

string TextQuery::get_real_word (const string &origin)
{
    string ret;
    for (string::const_iterator it = origin.begin(); it != origin.end(); it++)
    {
        if (!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}

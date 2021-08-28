#include "TextQuery.h"
using std::string;
using std::cin;
using std::cout;
using std::set;

std::ifstream& open_file (std::ifstream &input, const std::string &file)
{
    input.close();
    input.clear();

    input.open(file.c_str());
    return input;
}

void print_set (const set<TextQuery::lineno>& st, const TextQuery &file) 
{
    if (st.size() ==  0)
        return;

    for (auto text_line:st)
    {
        cout << "Line " <<  text_line << ": " << file.text_line(text_line) << std::endl;
    }
}

int main (int argc, char ** argv)
{
    std::ifstream infile;
    if (argc < 2 || !open_file(infile, argv[1])) {
        std::cerr << "No input file" << std::endl;
        return EXIT_FAILURE;
    }
    TextQuery tq;
    tq.read_file (infile);
         

    while (true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        cin >> s;

        if (!cin || s == "q") break;
        set<TextQuery::lineno> locs = tq.run_query(s);
        if (locs.size() > 0)
        {
            cout << "Found!" << std::endl;
            print_set (locs, tq);
        }
        else
        {
            cout << "Not Found!" << std::endl;
        }
    }

    return 0;
}

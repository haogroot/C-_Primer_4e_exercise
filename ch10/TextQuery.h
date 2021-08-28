#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <sstream>


class TextQuery {
    public:
        typedef std::vector<std::string>::size_type lineno;
        void read_file (std::ifstream &input)
        {
            store_file (input);
            build_map ();
        }
        std::set<lineno> run_query (const std::string &) const;
        // Return the content of line "lineno" of the text file
        std::string text_line(lineno) const;
    private:
        void store_file (std::ifstream &);
        void build_map();
        std::vector<std::string> lines_of_text;
        std::map< std::string, std::set<lineno> > word_map;
        // Remove punctation and convert all letter to lowercase
        std::string get_real_word (const std::string &);

};


#endif

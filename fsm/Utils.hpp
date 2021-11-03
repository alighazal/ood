
#ifndef UTILS
#define UTILS

#include <iostream>
#include <vector>

using namespace std;


class Utils{

    public:
        static bool isNumber(const string& str){
            for (char const &c : str) {
                if (std::isdigit(c) == 0) return false;
            }
            return true;
        }

        static string removeWhiteSpaces(string s){
            string ns = "";
            for (int i = 0; i < s.length(); i++ ){
                if (s[i] != ' ') ns+=s[i];
            }
            return ns;
        }

        static string Captialize(string s){
            string ns = "";
            for (int i = 0; i < s.length(); i++ ){
                ns+= toupper(s[i]);
            }
            return ns;
        }

        static bool isSpeparator(char c)
        {
            if (c == ' ' || c == ',' || c == '\0' || c == '\n')
                return true;
            else
                return false;
        }

        static vector<string> tokenizer(string text)
        {
            vector<string> tokens;

            string buffer = "";
            bool cont = false;
            for (int i = 0; i <= text.length(); i++)
            {
                if (Utils::isSpeparator(text[i]) && !cont)
                {
                    if (buffer != "")
                        tokens.push_back(buffer);
                    buffer = "";
                }
                else
                {
                    if (text[i] == '\"')
                        cont = !cont;
                    buffer += text[i];
                }
            }
            return tokens;
        }

        static vector<string> splitByLine(string text){
            string buffer;
            vector<string> lines;

            buffer = "";
            for (int i = 0; i <= text.length(); i++)
            {
                if (text[i] != '\n')
                {
                    buffer += text[i];
                }
                else
                {
                    lines.push_back(buffer);
                    buffer = "";
                }
            }

            return lines;

        }

};


#endif 
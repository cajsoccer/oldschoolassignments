#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <Stack.h>

bool vecContains(std::vector<std::string> list, std::string s)
{
    bool contains = false;
    for (auto e: list)
        if (e == s)
        {
            contains = true;
            break;
        }
    return contains;
}

void moveIdensToOps(std::vector<std::string> &actIdens, std::vector<std::string> &operators)
{
    std::vector<std::string> newActIdens;
    for (auto iden: actIdens)
    {
        if (iden == "+" || iden == "-" || iden == "*" || iden == "/" || iden == "++" || iden == "=")
        {
            if (!vecContains(operators, iden))
                operators.push_back(iden);
        }
        else
            newActIdens.push_back(iden);
    }
    actIdens = newActIdens;
}

bool isConstant(std::string s)
{
    bool isConst = true;
    for (int i = 0; i < (int)s.length(); i++)
        if (isdigit(s[i]) == 0)
        {
            isConst = false;
            break;
        }
    return isConst;
}

bool stringIsUpper(std::string s)
{
    bool isUpper = true;
    for (int i = 0; i < (int)s.length(); i++)
        if (isupper(s[i]) == 0)
        {
            isUpper = false;
            break;
        }
    return isUpper;
}

bool hasEq(std::string s)
{
    bool hasEq = false;
    for (int i = 0; i < (int)s.length(); i++)
        if (s[i] == '=')
            hasEq = true;
    return hasEq;
}

std::string removeIdenParens(std::string iden)
{
    std::string ret = "";
    std::string temp = "";
    for (int i = 0; i < (int)iden.length(); i++)
        if (iden[i] != '(' && iden[i] != ')')
        {
            temp = iden[i];
            ret.append(temp);
        }
    return ret;
}

int main()
{
    Stack forDepth;
    Stack leftParens;
    Stack rightParens;
    Stack fors;
    Stack ends;
    int maxDepth = 0;
    std::vector<std::string> syntaxErrors;
    std::ifstream file;
    file.open("test1.txt");
    std::vector<std::string> segs;
    std::string seg = "";
    while (!file.eof())
    {
        file >> seg;
        segs.push_back(seg);
    }
    for (auto seg: segs)
    {
        for (int i = 0; i < (int)seg.length(); i++)
        {
            if (seg[i] == '(')
                leftParens.push();
            else if (seg[i] == ')')
                rightParens.push();
        }
    }
    if (leftParens.findDepth() > rightParens.findDepth())
        syntaxErrors.push_back("(");
    else if (leftParens.findDepth() < rightParens.findDepth())
        syntaxErrors.push_back(")");
    /*std::cout << "SEGS: " << std::endl;
    for (auto seg: segs)
        std::cout << seg << std::endl;
    std::cout << std::endl;*/
    std::vector<std::string> cleanSegs = segs;
    for (auto &seg: cleanSegs)
    {
        if (seg[0] == '(')
            seg = seg.substr(1, seg.length() - 1);
        else if (seg[seg.length() - 1] == ')')
            seg = seg.substr(0, seg.length() - 1);
    }
    bool colExists = false;
    bool comExists = false;
    for (auto &seg: cleanSegs)
    {
        if (seg[seg.length() - 1] == ',')
        {
            seg = seg.substr(0, seg.length() - 1);
            comExists = true;
        }
        else if (seg[seg.length() - 1] == ';')
        {
            seg = seg.substr(0, seg.length() - 1);
            colExists = true;
        }
    }
    /*std::cout << "CLEANSEGS:" << std::endl;
    for (auto seg: cleanSegs)
        std::cout << seg << std::endl;
    std::cout << std::endl;*/
    std::vector<std::string> idens = cleanSegs;
    std::vector<std::string> extraIdens;
    
    std::vector<std::string> keyWords;
    for (int i = 0; i < (int)cleanSegs.size(); i++)
    {
        if (cleanSegs[i] == "BEGIN")
        {
            if (!vecContains(keyWords, cleanSegs[i]))
                keyWords.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if (cleanSegs[i] == "END")
        {
            if (!vecContains(keyWords, cleanSegs[i]))
                keyWords.push_back(cleanSegs[i]);
            idens[i] = "--";
            ends.push();
            forDepth.pop();
        }
        else if (cleanSegs[i] == "FOR")
        {
            if (!vecContains(keyWords, cleanSegs[i]))
                keyWords.push_back(cleanSegs[i]);
            idens[i] = "--";
            fors.push();
            forDepth.push();
        }
        if (forDepth.findDepth() > maxDepth)
            maxDepth = forDepth.findDepth();
    }
    if (fors.findDepth() > ends.findDepth())
        syntaxErrors.push_back("END");
    else if (fors.findDepth() < ends.findDepth())
        syntaxErrors.push_back("FOR");
    std::cout << "The maximum loop depth of nested loops is: " << maxDepth - 1 << std::endl << std::endl;
    std::cout << "Keywords: "; 
    for (auto keyWord: keyWords)
        std::cout << keyWord << " ";
    std::cout << std::endl;
    
    std::vector<std::string> operators;
    for (int i = 0; i < (int)cleanSegs.size(); i++)
    {
        if (cleanSegs[i] == "+")
        {
            if (!vecContains(operators, cleanSegs[i]))
                operators.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if (cleanSegs[i] == "-")
        {
            if (!vecContains(operators, cleanSegs[i]))
                operators.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if (cleanSegs[i] == "*")
        {
            if (!vecContains(operators, cleanSegs[i]))
                operators.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if (cleanSegs[i] == "/")
        {
            if (!vecContains(operators, cleanSegs[i]))
                operators.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if (cleanSegs[i] == "++")
        {
            if (!vecContains(operators, cleanSegs[i]))
                operators.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
        else if ((int)cleanSegs[i].find('=') != -1)
        {
            int eqPos = cleanSegs[i].find('=');
            std::string lval = cleanSegs[i].substr(0, eqPos);
            std::string rval = cleanSegs[i].substr(eqPos + 1, cleanSegs[i].length() - 1);
            if (lval == rval && !vecContains(extraIdens, lval))
                extraIdens.push_back(lval);
            else
            {
                if (!vecContains(extraIdens, lval))
                    extraIdens.push_back(lval);
                if (!vecContains(extraIdens, rval))
                    extraIdens.push_back(rval);
            }
            if (!vecContains(operators, "="))
                operators.push_back("=");
        }
    }
    
    std::vector<std::string> constants;
    for (int i = 0; i < (int)cleanSegs.size(); i++)
        if (isConstant(cleanSegs[i]))
        {
            if (!vecContains(constants, cleanSegs[i]))
                constants.push_back(cleanSegs[i]);
            idens[i] = "--";
        }
    
    std::vector<std::string> actIdens;
    for (auto iden: idens)
    {
        if (!vecContains(actIdens, iden) && iden != "--" && !stringIsUpper(iden) && !hasEq(iden))
            actIdens.push_back(removeIdenParens(iden));
        else if (!vecContains(syntaxErrors, iden) && stringIsUpper(iden))
            syntaxErrors.push_back(iden);
    }
    for (auto iden: extraIdens)
        actIdens.push_back(iden);
    moveIdensToOps(actIdens, operators);
    std::cout << "Identifiers: ";
    for (auto iden: actIdens)
        std::cout << iden << " ";
    std::cout << std::endl;
    std::cout << "Constants: ";
    for (auto con: constants)
        std::cout << con << " ";
    std::cout << std::endl;
    std::cout << "Operators: ";
    for (auto op: operators)
        std::cout << op << " ";
    std::cout << std::endl;
    std::cout << "Delimiters: "; 
    if (colExists)
        std::cout << "; ";
    if (comExists)
        std::cout << ", ";
    std::cout << std::endl << std::endl;
    std::cout << "Syntax Errors: ";
    if (syntaxErrors.empty())
        std::cout << "NA" << std::endl;
    else
    {
    for (auto e: syntaxErrors)
        std::cout << e << " ";
    std::cout << std::endl;
    }
    return 0;
}
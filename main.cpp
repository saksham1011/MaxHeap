// ============================================================================
// main.cpp
// ~~~~~~~~
// ============================================================================
#include <cstdlib>   // for exit(0)
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "UBHeap.h"
#include "error_handling.h"
#include "term_control.h"

using namespace std; // BAD PRACTICE

void prompt();
typedef void (*cmd_t)(istringstream&);
void bye(istringstream&);
void new_cmd(istringstream&);
void print_cmd(istringstream&);
void push_cmd(istringstream&);
void pop_cmd(istringstream&);
void top_cmd(istringstream&);

map<string, UBHeap> heap_table;

const string usage_msg = "UBHeap: Heap data structure";

int main()
{
    map<string,cmd_t> cmd_map;
    cmd_map["exit"]   = &bye;
    cmd_map["bye"]    = &bye;
    cmd_map["quit"]   = &bye;
    cmd_map["new"]    = &new_cmd;
    cmd_map["print"]  = &print_cmd;
    cmd_map["push"]   = &push_cmd;
    cmd_map["pop"]    = &pop_cmd;
    cmd_map["top"]    = &top_cmd;
    
    cout << term_cc(YELLOW) << usage_msg << endl;
    
    istringstream iss;
    string cmd, line;
    while (cin) {
        prompt();
        getline(cin, line);
        iss.clear();
        iss.str(line);
        if (!(iss >> cmd))
            continue;
        
        if (cmd_map.find(cmd) != cmd_map.end()) {
            try {
                cmd_map[cmd](iss);
            } catch (runtime_error &e) {
                error_return(e.what());
            }
        } else {
            error_return("Unknown command");
        }
    }
    return 0;
}

void bye(istringstream& iss)
{
    exit(0);
}

void new_cmd(istringstream& iss)
{
    string heapname;
    char a;
    int member;
    if (!(iss >> heapname) || !(iss >> a) || a != '=') {
        throw runtime_error("Syntax: new heapname = [list of integers]");
    }
    vector<int> int_list;
    while (iss >> member)
        int_list.push_back(member);
    
    UBHeap ubheap = UBHeap(int_list);
    heap_table[heapname] = ubheap;
}

void print_cmd(istringstream& iss)
{
    string heapname, tmp;
    if (!(iss >> heapname) || (iss >> tmp))
        throw runtime_error("Syntax: print heapName");
    if (heap_table.find(heapname) == heap_table.end())
        throw runtime_error(string("Heap ") + heapname + " not found");
    cout << term_cc(YELLOW) << heap_table[heapname].toString()
    << endl << term_cc();
}

void push_cmd(istringstream& iss)
{
    int i;
    string heapname, tmp;
    if (!(iss >> heapname) || !(iss >> i) || (iss >> tmp))
        throw runtime_error("Syntax: push someheap someint");
    if (heap_table.find(heapname) == heap_table.end())
        throw runtime_error(string("Heap ") + heapname + " not found");
    heap_table[heapname].push(i);
}

void pop_cmd(istringstream& iss)
{
    string heapname, tmp;
    if (!(iss >> heapname) || (iss >> tmp))
        throw runtime_error("Syntax: pop heapname");
    if (heap_table.find(heapname) == heap_table.end())
        throw runtime_error(string("Heap ") + heapname + " not found");
    if(heap_table[heapname].empty())
        throw runtime_error("Heap is Empty");
    heap_table[heapname].pop();
}

void top_cmd(istringstream& iss)
{
    string heapname, tmp;
    if (!(iss >> heapname) || (iss >> tmp))
        throw runtime_error("Syntax: top heapname");
    if (heap_table.find(heapname) == heap_table.end())
        throw runtime_error(string("Heap ") + heapname + " not found");
    if(heap_table[heapname].empty())
        throw runtime_error("Heap is Empty");
    
    cout << term_cc(YELLOW) << heap_table[heapname].top() << endl << term_cc();
}

void prompt()
{
    cout << term_cc(BLUE) << "> " << term_cc() << flush;
}

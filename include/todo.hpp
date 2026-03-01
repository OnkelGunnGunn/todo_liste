#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

struct Row {
    std::string task;
    std::string status;
    int priority;
    bool completed;
};

class todo
{
private:
    std::vector<Row> rows;
    bool static sort_priority(const Row&, const Row&);
    bool static sort_A_Z(const Row&, const Row&);
public:
    todo(void);
    ~todo(void);    
    void print(void);
    void add_row(Row);
    void save(void);
    void load(void);
    void remove(int);
    void sort(int);
    void complete(int);
    
};



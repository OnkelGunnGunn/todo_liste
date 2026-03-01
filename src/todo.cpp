#include "todo.hpp"



todo::todo()
{
}

todo::~todo()
{
}




// Show tasks
void todo::print(void)
{
    int number = 0;
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(3) << "#" << std::setw(40) << "Task" << std::setw(25) << "Status" << std::setw(14) << "Priority" << std::setw(5) << "Completed" << std::endl;
    
    for (const Row& r : rows) 
    {
        std::cout << std::left << std::setw(3) << number << std::setw(40) << r.task << std::setw(25) << r.status << std::setw(14) << r.priority << std::setw(5) << (r.completed?"✓":"-") << std::endl;
        number++;
    }
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}




// Add task
void todo::add_row(Row user_input)
{
    this->rows.push_back(user_input);
}


// Save tasks after closing to do list
void todo::save(void)
{
    std::ofstream file("tasks.txt");

    if (!file)
    {
        std::cout << "Could not open file\n";
    }

    for (const Row& r : rows) 
    {
        file << r.task << "+" << r.status << "+" << r.priority << "+" << r.completed << "\n";
    }

    file.close();
}


// Load tasks when opening todo list
void todo::load(void)
{
    std::ifstream file("tasks.txt");

    if (!file)
    {
        std::cout << "Could not open file\n";
    }

    std::string line;
    
    while (std::getline(file, line)) 
    {
        std::vector<std::string> tmp;
        std::istringstream sstream(line);
        std::string buffer;
        
        while (std::getline(sstream, buffer, '+')) 
        {
            tmp.push_back(buffer);
        }

        if (tmp.size() >= 4)
        {
            Row imported;
            imported.task = tmp[0];
            imported.status = tmp[1];
            imported.priority = std::stoi(tmp[2]);
            imported.completed = std::stoi(tmp[3]);

            this->add_row(imported);
        }
    }
}

// Delete task
void todo::remove(int index)
{
    this->rows.erase(this->rows.begin() + index);
}


// Sort task
void todo::sort(int sort_type)
{
    if (sort_type == 0)
    {
        std::sort(this->rows.begin(), this->rows.end(), sort_priority);
    }
    else if (sort_type == 1)
    {
        std::sort(this->rows.begin(), this->rows.end(), sort_A_Z);
    }
    this->print();
    
    
}

void todo::complete(int index)
{
    this->rows[index].completed = true;
}

// Sort after priority
bool todo::sort_priority(const Row & a, const Row & b)
{
    return a.priority < b.priority;
}

// Sort after A to Z
bool todo::sort_A_Z(const Row & a, const Row & b)
{
    return a.task < b.task;
}

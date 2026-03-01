#include <iostream>
#include "todo.hpp"

todo my_todo;



void add_task(){
    Row user_input;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Task name: " << std::endl;
        std::getline(std::cin, user_input.task);

        std::cout << "State of task: " << std::endl;
        std::getline(std::cin, user_input.status);

        std::cout << "Task priority: " << std::endl;
        std::cin >> user_input.priority;

        user_input.completed = false;

    my_todo.add_row(user_input);
    my_todo.save();

}

void remove_task(void)
{
    std::string delete_index;
    my_todo.print();
    std::cout << "Type task number to edit/delete" << std::endl;
    std::cin >> delete_index;
    my_todo.remove(std::stoi(delete_index));
    my_todo.save();
}


void set_completed(void)
{
    std::string completed_index;
    my_todo.print();
    std::cout << "Type task number that you completed" << std::endl;
    std::cin >> completed_index;
    my_todo.complete(std::stoi(completed_index));
    my_todo.save();
}


void print_menu(){
    std::cout << "Press Key for action:" << std::endl;
    std::cout << "1 show todo" << std::endl;
    std::cout << "2 add task" << std::endl;
    std::cout << "3 Quit" << std::endl;
    std::cout << "4 Delete task" << std::endl;
    std::cout << "5 Sort A-Z" << std::endl;
    std::cout << "6 Sort by priority" << std::endl;
    std::cout << "7 Edit task" << std::endl;
    std::cout << "8 Set task as completed" << std::endl;

}

int main(void){
    my_todo.load();
    std::string user_input;
    bool running = true;
    while(running){
        print_menu();
        std::cin >> user_input;

        switch(std::stoi(user_input))
        {
            case 1:
            my_todo.print();
            break;
        
            case 2:
            add_task();
            break;
        
            case 3:
            running = false;
            break;

            case 4:
            remove_task();
            my_todo.print();
            break;

            case 5:
            my_todo.sort(1);
            break;

            case 6:
            my_todo.sort(0);
            break;

            case 7:
            remove_task();
            add_task();
            my_todo.print();
            break;

            case 8:
            set_completed();
            break;

        default:
            break;
        }
    }



}



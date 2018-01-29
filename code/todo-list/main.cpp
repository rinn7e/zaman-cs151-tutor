#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Task {
    public:
        Task(int id_new, string title_new, string content_new){
            id = id_new;
            title = title_new;
            content = content_new;
        }

        int id;
        string title;
        string content;

        // Member Function (Method)
        string toString() {
            stringstream ss;
            ss  << id << ". " << title << ": " << content;
            string s = ss.str();
            return s;
        }
};

// string taskContent = "Task 2 Content";
// taskList.push_back(taskTitle);
// vector<string> taskList;
// void listFile(string fileName) {
//     // string line;
//     // ifstream myfile (fileName);
//     // if (myfile.is_open()) {
//     //     while (getline(myfile,line)) {
//     //         cout << line << '\n';
//     //     }
//     //     myfile.close();
//     // }

//     // else cout << "Unable to open file"; 
//     cout << fileName << endl;
//     string line;
//     ifstream myfile ("todo.txt");
//     if (myfile.is_open())
//     {
//         while ( getline (myfile,line) )
//         {
//         cout << line << '\n';
//         }
//         myfile.close();
//     }

//     else cout << "Unable to open file"; 
// }

// void addTask(string fileName, string newTask){
//     ofstream myfile (fileName);
//     if (myfile.is_open()){
//         myfile << newTask;
//         myfile.close();
//     }
// }
// int length (vector<Task *> &taskList) {
//     return sizeof(taskList)/sizeof(taskList[0]);
// }

// void listTask(vector<Task *> taskList){
//     cout << taskList.size() << endl;
//     // for (int i = 0; i < length(taskList); i++){
//     //     cout << taskList[i].title << endl;
//     // }
// }

// void listTask(vector<Task *> taskList){
//     cout << taskList.size() << endl;

//     Task task = Task (* taskList.at(0));
    
//     cout << task.title << endl;
// }


// void addTaskByPointer(vector<Task>* taskListPointer, string title, string content){

// }

void listTask(vector<Task> taskList){
    for (int i = 0; i < taskList.size(); i++){
        cout << taskList.at(i).toString() << endl;
    }
}


vector<Task> addTask(vector<Task> taskList, string title, string content){
    taskList.push_back(Task (taskList.size() + 1, title, content));
    listTask(taskList);
    return taskList;
}

void loop(vector<Task> taskList){
    // Task task1 (1, "Title 1", "Task 1");
    // Task taskList[] = {task1};
    // vector<Task*> taskList;
    // Task* task1Address = new Task (1, "Title 1", "Task 1");
    // Task task1 = Task (*task1Address);
    // cout << task1.title <<endl;
    // taskList.push_back(new Task (1, "Title 1", "Task1"));
    
    int i;
    cout << "[1] View all task" << endl;
    cout << "[2] Add new task" << endl;
    cout << "[0] Quit program" << endl;
    cout << "Please Input your command: ";
    cin >> i;
    if (i == 0){
        cout << "Thank you for using this app!" << endl;
        // return 0;
    } else if (i == 1){
        listTask(taskList);
        loop(taskList);
    } else if (i == 2){
        vector<Task> newTaskList = addTask(taskList, "New Task", "New Task Content");
        loop(newTaskList);
    } else {
        cout << "List all task" << endl;
        loop(taskList);
    }
}

int main() {
    // listFile("todo.txt");
    // addTask("todo.txt", "task");
    // Task task1 (1, "My Task Today", "I need to go home\nGet some food");

    // Task taskList[] = {task1};
    // cout << task1.title << endl;
    // cout << taskList[0].title << endl;
    vector<Task> defaultTaskList;
    defaultTaskList.push_back(Task (1, "Today", "Go buy sth"));
    defaultTaskList.push_back(Task (2, "Tomorrow", "Go eat sth"));
    loop(defaultTaskList);
}


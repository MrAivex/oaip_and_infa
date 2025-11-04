#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Command {
    string name;
    int value;
};

void parseCommand(const char* input, vector<Command>& buffer) {
    const char* ptr = input;
    
    // Читаем имя команды (до пробела или конца строки)
    const char* name_start = ptr;
    while (*ptr != ' ' && *ptr != '\0') ptr++;
    
    string name(name_start, ptr - name_start);
    
    int value = 0;
    
    // Если есть пробел, читаем число
    if (*ptr == ' ') {
        ptr++; // Пропускаем пробел
        
        // Конвертируем строку в число
        while (*ptr >= '0' && *ptr <= '9') {
            value = value * 10 + (*ptr - '0');
            ptr++;
        }
    }
    
    Command cmd;
    cmd.name = name;
    cmd.value = value;
    
    buffer.push_back(cmd);
}

int main() {
    vector<Command> buffer;
    
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);
    parseCommand("BACKWARD 5", buffer);
    
    cout << "Команды робота:" << endl;
    for (const Command& cmd : buffer) {
        cout << "Command: " << cmd.name << ", Value: " << cmd.value << endl;
    }
    
    return 0;
}
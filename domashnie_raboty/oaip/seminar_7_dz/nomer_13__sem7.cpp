#include <iostream>

using namespace std;

void parseTelemetry(const char* data) {
    const char* ptr = data;
    
    while (*ptr != '\0') {
        // Пропускаем начальные пробелы
        while (*ptr == ' ') ptr++;
        
        // Читаем имя параметра
        const char* name_start = ptr;
        while (*ptr != ':' && *ptr != '\0') ptr++;
        
        if (*ptr == '\0') break;
        
        // Выводим имя
        cout << "Параметр: ";
        const char* name_ptr = name_start;
        while (name_ptr < ptr) {
            cout << *name_ptr;
            name_ptr++;
        }
        cout << endl;
        
        ptr++; // Пропускаем ':'
        
        // Читаем значение
        const char* value_start = ptr;
        while (*ptr != ';' && *ptr != '\0') ptr++;
        
        cout << "Значение: ";
        const char* value_ptr = value_start;
        while (value_ptr < ptr && *value_ptr != '\0') {
            cout << *value_ptr;
            value_ptr++;
        }
        cout << endl << endl;
        
        if (*ptr == ';') ptr++;
    }
}

int main() {
    const char* telemetry = "TEMP:24.5;PRESS:101.3;HUM:55.2";
    
    cout << "Телеметрический пакет: " << telemetry << endl << endl;
    parseTelemetry(telemetry);
    
    return 0;
}
#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    BankAccount(std::string accNum, std::string name, double bal)
        : accountNumber(accNum), ownerName(name), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void display() const {
        std::cout << "Account: " << accountNumber
                  << ", Owner: " << ownerName
                  << ", Balance: " << balance << std::endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(std::string accNum, std::string name, double bal, double rate)
        : BankAccount(accNum, name, bal), interestRate(rate) {}

    void addInterest() {
        balance += balance * interestRate / 100;
    }

    void display() const {
        BankAccount::display();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};

int main() {
    BankAccount ba("123456", "John Doe", 1000.0);
    ba.deposit(500.0);
    ba.withdraw(200.0);
    ba.display();

    SavingsAccount sa("789012", "Jane Smith", 2000.0, 5.0);
    sa.deposit(1000.0);
    sa.withdraw(500.0);
    sa.addInterest();
    sa.display();

    return 0;
}
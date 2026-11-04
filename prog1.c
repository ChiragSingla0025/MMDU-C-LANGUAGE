// ATM SIMULATION SYSTEM
// Your Atm Pin is 1234
#include <stdio.h>

typedef struct {
    char name[50];
    int account_no;
    float balance;
    int pin;
} Account;

// Function to check balance
void checkBalance(Account acc) {
    printf("\nYour Current Balance: Rs. %.2f\n", acc.balance);
}

// Function to deposit money
void depositMoney(Account *acc) {
    float amount;

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        acc->balance += amount;
        printf("Money deposited successfully!\n");
        printf("Updated Balance: Rs. %.2f\n", acc->balance);
    }
    else {
        printf("Invalid amount!\n");
    }
}

// Function to withdraw money
void withdrawMoney(Account *acc) {
    float amount;

    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount\n");
    }
    else if (amount > acc->balance) {
        printf("Insufficient balance!\n");
    }
    else {
        acc->balance -= amount;
        printf("Please collect your cash.\n");
        printf("Remaining Balance: Rs. %.2f\n", acc->balance);
    }
}

// Function to change PIN
void changePIN(Account *acc) {
    int oldPin, newPin;

    printf("\nEnter your old PIN: ");
    scanf("%d", &oldPin);

    if (oldPin == acc->pin) {
        printf("Enter new PIN: ");
        scanf("%d", &newPin);

        if (newPin >= 1000 && newPin <= 9999) {
            acc->pin = newPin;
            printf("PIN changed successfully!\n");
        }
        else {
            printf("PIN must be 4 digits!\n");
        }
    }
    else {
        printf("Incorrect old PIN!\n");
    }
}

int main() {

    Account acc = {"Chirag", 123456, 10000.00, 1234};

    int Pin, choice;
    int running = 1;
    printf("       WELCOME TO ATM SYSTEM     \n");
    printf("\nEnter your ATM PIN: ");
    scanf("%d", &Pin);

    if (Pin != acc.pin) {
        printf("\nIncorrect PIN! Access Denied.\n");
        return 0;
    }

    // While loop for repeating ATM menu
    while (1) {

        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case statements
        switch (choice) {

            case 1:
                checkBalance(acc);
                break;

            case 2:
                depositMoney(&acc);
                break;

            case 3:
                withdrawMoney(&acc);
                break;

            case 4:
                changePIN(&acc);
                break;

            case 5:
                printf("\nThank you for using our ATM!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

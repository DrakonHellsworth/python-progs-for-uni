#Design a Bank Account Management System using Object-Oriented Programming (OOP) in Python.
#Requirements:
#Create a class BankAccount with the following attributes:
#account_number (string)
#account_holder (string)
#balance (float, default to 0)
#Implement the following methods:
#deposit(amount): Adds the given amount to the account balance.
#withdraw(amount): Deducts the given amount if the balance is sufficient, otherwise prints "Insufficient funds" and does not change the balance.
#display_balance(): Prints the current balance.
#Create two instances of BankAccount, perform a few deposit and withdrawal operations, and display the final balance for each account.

class BankAccount:
    def __init__(self,account_number,account_holder,balance):
        self.account_number=account_number
        self.account_holder=account_holder
        self.balance=balance
        balance=0

    def deposit(self,amount):
        self.balance+=amount

    def withdraw(self,amount):
        if self.balance>=amount:
            self.balance-=amount
        else:
            print("Insufficient funds")

    def display_balance(self):    
        print(f"Account Number:{self.account_number}")
        print(f"Account Holder:{self.account_holder}")
        print(f"Balance:{self.balance}")   
t=1
while t:
    n=int(input("Enter account number-"))
    c=input("Enter account holder name-")
    b=float(input("Enter balance-"))
    obj=BankAccount(n,c,b)
    while True:
        print("1.Deposit\n2.Withdraw\n3.Display balance\n4.Exit")
        ch=int(input("Enter your choice"))
        if ch==1:
            amount=float(input("Enter amount to deposit"))
            obj.deposit(amount)
        elif ch==2:
            amount=float(input("Enter amount to withdraw"))
            obj.withdraw(amount)
        elif ch==3:
            obj.display_balance()
        elif ch==4:
            break
        else:
            print("Invalid choice")
            break
    ans=input("Do you want to continue(yes/no)")
    if ans=="no":
        t=0

from pathlib import Path

def view_pass():
    passwords = Path("vault.txt")
    if passwords.is_file():
        #Display all passwords in specific set up
        #email : 
        #website :
        #password :

        returnkey = ""
        while returnkey != 1:
            returnkey = input("Press 1 to return to menu. ")
            if (returnkey == 1):
                return
    else:
        print("There are no passwords stored.")

def enter_pass():
    passwords = Path("vault.txt")
    #Creates or appends vault.txt to passwords in

def new_master():
    master = Path("auth.txt")
    #Creates a new master password and stores the new one in auth.txt by rewriting txt file

def exit_menu():
    #returns back to beginning
    return
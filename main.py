from pathlib import Path
import menu

master_pass = Path("auth.txt")
attempts = 0

if master_pass.is_file():
    while (attempts < 3):
        inputPass = input("Please enter your password: ")
        savedPass = master_pass.read_text.strip
        if (inputPass == savedPass):
            print("Select number corresponding to menu option.\n(1) View Passwords\n(2) Add Password\n(3) Create New Master Password\n(4) Exit Program.")
            code = input("Enter option: ")
            match code:
                case 1:
                    view_pass()
                case 2:
                    enter_pass()
                case 3:
                    new_master()
                case 4:
                    exit_menu()

            break
        else:
            attempts += 1
            print("Incorrect password. " + {3-attempts} + " attempts remaining.")
    
    if (attempts == 3):
        print("Too many attempts. Please try again later.")
        exit()  
else:
    rawPass = input("Please set a password before continuing: ")
    master_pass.write_text(rawPass)
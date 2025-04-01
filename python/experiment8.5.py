#Create multiple suitable exceptions for a file handling program. 
def fileopr(f):
    try:
        with open(f,"r") as file:
            a=file.read()
            print("File Content:\n",a)
    except FileNotFoundError:
        print("Error: The file does not exist.")
    except PermissionError:
        print("Error: You do not have permission to access the file.")
    except Exception as e:
        print(f"An error occurred: {e}")
f=input("Enter the filename: ")
fileopr(f)

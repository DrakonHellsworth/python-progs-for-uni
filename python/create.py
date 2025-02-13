import os

def create_files(folder_path, a, b_end):
    # Ensure the folder exists or create it
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
        print(f"Folder '{folder_path}' created.")
    else:
        print(f"Folder '{folder_path}' already exists.")
    
    # Create files with the specified format
    for b in range(1, b_end + 1):
        file_name = f"{a}.{b}.c"
        file_path = os.path.join(folder_path, file_name)
        with open(file_path, 'w') as f:
            pass  # Create an empty file
        print(f"File created: {file_path}")

# Input folder path
folder_path = input("Enter the folder path where you want to create files: ")

# Input for constant A
a = input("Enter the constant value for 'A': ")

# Input for the range of B
b_end = int(input("Enter the maximum value for 'B': "))

# Create files
create_files(folder_path, a, b_end)

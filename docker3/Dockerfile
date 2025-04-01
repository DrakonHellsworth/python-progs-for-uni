# Use an official GCC image
FROM gcc:latest

# Set working directory inside the container
WORKDIR /app

# Copy all files from the current directory to /app in the container
COPY . .

# Compile the test program
RUN gcc -o test test.c

# Command to run the compiled program
CMD ["./test"]

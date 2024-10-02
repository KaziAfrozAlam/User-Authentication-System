# Simple C Registration and Login System

This is a basic **C** program that implements a simple registration and login system. It allows users to register with a unique username, password, email, and phone number. The system also includes basic login functionality with username and password validation.

## Features

- **User Registration:**
  - Ensures each user has a unique username.
  - Passwords, email, and phone number are stored securely.
  - A simple verification system using a placeholder function (`send_verification_code`).

- **User Login:**
  - Checks user credentials against registered users.
  - Allows for up to 3 login attempts before locking out the user.

## Code Structure

The project is made up of a single source file:

- **source.c**: Contains the main program logic, user registration, and login functionality.

### Main Functions

- **register_user()**: Handles user registration. It ensures a unique username and stores the user details in memory. Also includes a placeholder for verification code handling.
- **login()**: Allows users to log in by validating their credentials (username and password) against previously registered users.
- **valid_username()**: Checks if the entered username already exists.
- **valid_credentials()**: Verifies if the provided username and password match any registered user.
- **send_verification_code()**: Placeholder function to simulate sending a verification code to the user's email and phone.
- **valid_verification_code()**: Placeholder function to validate a user's verification code.

## How to Use

1. **Clone the repository:**
   git clone https://github.com/yourusername/your-repo-name.git
   cd your-repo-name
2. **Compile the code:**
   gcc source.c -o login_system
3. **Run the program:**
   ./login_system
4. **The program provides a simple menu where you can:**
    Register a new user.
    Log in using an existing username and password.
    Exit the application.

## Example Usage

1. Register
2. Login
3. Exit
Enter your choice: 1

Enter a new username: john_doe
Enter a new password: securePass123
Enter your email: john@example.com
Enter your phone number: 123-456-7890
Verification code sent to email: john@example.com and phone: 123-456-7890
Enter the verification code sent to your email and phone: 1234
Registration successful!

1. Register
2. Login
3. Exit
Enter your choice: 2

Enter username: john_doe
Enter password: securePass123
Access granted!

## Future Enhancements
**Password Strength Validation:** Implement checks to ensure passwords meet security criteria (minimum length, inclusion of special characters, etc.).
**Email and Phone Verification:** Add actual functionality for sending and validating verification codes.
**Persistent Storage:** Store user data in a file or database for persistence.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to submit a pull request or open an issue.

Happy coding! 😊
This **README.md** provides a clear overview of the project, instructions on how to use it, and suggestions for future improvements. You can adjust the repository URL, project name, and other details as needed.

# 🗳️ Sri Lanka Parliamentary Election Voting System

A comprehensive console-based election voting system developed in C programming language, simulating the Sri Lankan parliamentary election process for Colombo District.

## 📋 Project Overview

This system allows voters to register, login, cast votes for political parties and candidates, and view election results. The project implements a realistic voting mechanism where voters select one party and then choose three preferred candidates from that party.

## ✨ Features

### 🔐 User Management
- **User Registration**: Secure voter registration with NIC validation
- **Age Verification**: Automatic eligibility checking (minimum 18 years)
- **User Authentication**: Secure login system with credential validation
- **Duplicate Prevention**: Prevents multiple registrations and voting

### 🗳️ Voting System
- **Party Selection**: Choose from available political parties
- **Candidate Selection**: Select 3 different candidates from chosen party
- **Vote Validation**: Ensures unique candidate selection per vote
- **Single District**: Implements Colombo District election system

### 📊 Results & Analytics
- **Real-time Results**: View current election statistics
- **Party Vote Count**: Track votes by political party
- **Candidate Preferences**: Monitor individual candidate performance

### 🎨 User Interface
- **Colorful Console**: Enhanced visual experience with colors
- **Professional Layout**: Clean, organized menu system
- **Error Handling**: User-friendly error messages and validation
- **Navigation**: Intuitive menu-driven interface

## 🏗️ System Architecture

```
├── index.c              # Main program entry point
├── menu.c               # Main menu and navigation system
├── fun.h                # Utility functions (UI, colors, formatting)
├── register.c           # User registration functionality
├── login.c              # User authentication system
├── vote.c               # Voting mechanism implementation
├── results.c            # Results display and analytics
├── welcome.c            # Welcome screen and instructions
├── file_handle_register.c  # File operations for registration
├── file_handle_login.c     # File operations for login
├── auto-compile.bat     # Windows batch file for compilation
└── data/                # Database files
    ├── users.txt        # Registered voter information
    ├── candidates.txt   # Election candidates by party
    ├── votes.txt        # Cast votes records
    └── parties.txt      # Political party information
```

## 💾 Database Structure

### Users Database (`data/users.txt`)
```
Format: NIC,Name,Password,Age,District,Status
Example: 200012345678,Arjun,password123,24,Colombo,ACTIVE
Fields:
  - NIC: 12-digit National Identity Card number
  - Name: User's full name
  - Password: Account password
  - Age: User's age
  - District: Electoral district
  - Status: ACTIVE or VOTED
```

### Candidates Database (`data/candidates.txt`)
```
Format: ID,NIC,Name,Password,Age,Party,Position
Example: 1,000000000001,Amal Liyanage,pass001,0,BP,1
Fields:
  - ID: Unique candidate identifier
  - NIC: Candidate's NIC number
  - Name: Candidate's full name
  - Password: Candidate account password
  - Age: Candidate's age
  - Party: Party code (BP, GA, RM, PF, NU)
  - Position: Position number in party list
```

### Votes Database (`data/votes.txt`)
```
Format: VoterNIC,VoterName,Candidate1|Candidate2|Candidate3,District
Example: 199112233445,Atticus Finch,1|2|3,Matara
Fields:
  - VoterNIC: NIC of the voter
  - VoterName: Name of the voter
  - Candidates: Three candidate IDs separated by |
  - District: Voting district
```

### Parties Database (`data/parties.txt`)
```
Format: PartyCode,PartyName,Symbol,Color
Example: BP,Blue Party,Flower,Blue
Available Parties:
  - BP: Blue Party (Symbol: Flower, Color: Blue)
  - GA: Green Alliance (Symbol: Elephant, Color: Green)
  - RM: Red Movement (Symbol: Telephone, Color: Red)
  - PF: People's Front (Symbol: Compass, Color: Purple)
  - NU: National Unity (Symbol: Key, Color: Orange)
```

## 🚀 Getting Started

### Prerequisites
- GCC Compiler (MinGW for Windows or GCC for Linux/Mac)
- C Standard Library
- Terminal/Command Prompt with color support

### Installation

1. Clone or download the project:
```bash
git clone <repository-url>
cd election-voting-system
```

2. Ensure the `data/` directory exists with all required files:
```bash
mkdir data
# Create or copy the data files (users.txt, candidates.txt, votes.txt, parties.txt)
```

### Compilation

#### Windows (using batch file):
```bash
auto-compile.bat
```

#### Manual compilation:
```bash
gcc index.c -o index.exe
```

#### Linux/Mac:
```bash
gcc index.c -o index
./index
```

## 📖 Usage Guide

### Main Menu Options

1. **Login**
   - Enter your 12-digit NIC number
   - Enter your password
   - Access the voting system

2. **Register**
   - Choose registration type (Voter or Candidate)
   - For Candidates: Select district and party
   - Enter personal details (Name, NIC, DOB)
   - Set up password
   - Minimum age: 18 years

3. **Vote**
   - Must be logged in to vote
   - Select your district
   - Choose a political party
   - Select 3 candidates from that party
   - Confirm your vote

4. **View Results**
   - Display current election statistics
   - Party-wise vote distribution
   - Candidate performance metrics

5. **Instructions**
   - Detailed system instructions
   - Registration guidelines
   - Voting procedures

### Voting Process

1. **District Selection**: Choose your electoral district (currently Matara)
2. **Party Selection**: Select one of five political parties
3. **Candidate Selection**: Vote for exactly 3 candidates from your chosen party
4. **Confirmation**: Review and confirm your votes
5. **Completion**: Vote is recorded and status updated to "VOTED"

## 🛡️ Security Features

- **NIC Validation**: 12-digit NIC number verification
- **Duplicate Prevention**: Each NIC can register only once
- **Vote Once Policy**: Status tracking prevents multiple voting
- **Password Protection**: Secure password-based authentication
- **Age Verification**: Automatic eligibility checking

## 🎨 Color Scheme

The system uses ANSI color codes for enhanced visual experience:
- **White**: Default text
- **Red**: Errors and warnings
- **Green**: Success messages and active users
- **Blue**: Party-specific (Blue Party)
- **Yellow**: Highlights and People's Front
- **Magenta**: National Unity and options
- **Cyan**: Additional highlights

## 📝 File Operations

### Registration
- Validates NIC format and uniqueness
- Checks age eligibility
- Stores user data in `users.txt`
- Candidates stored in `candidates.txt`

### Voting
- Verifies user login status
- Validates district and party selection
- Ensures candidates belong to selected party
- Records votes in `votes.txt`
- Updates user status to "VOTED"

### Results
- Reads from `votes.txt`
- Aggregates party and candidate votes
- Displays statistics and rankings

## 🔧 Technical Details

### Data Structures
- **User struct**: Stores voter information
- **Candidate struct**: Stores candidate details
- **File-based storage**: Text files for persistence

### Key Functions
- `register_user()`: Handles user registration
- `login_user()`: Authenticates users
- `vote_user()`: Manages voting process
- `view_results()`: Displays election results
- `save_user_as_voter()`: Saves voter data
- `save_user_as_candidate()`: Saves candidate data
- `check_nic_exists()`: Validates NIC uniqueness
- `find_nic()`: Retrieves user information

## 🐛 Known Issues

- Login functionality partially implemented (`login.c` needs completion)
- Results viewing shows placeholder (implementation pending)
- Limited to single district (Matara) for full functionality
- No encryption for passwords (stored in plain text)

## 🔮 Future Enhancements

- [ ] Complete login authentication system
- [ ] Implement comprehensive results dashboard
- [ ] Add password encryption
- [ ] Support multiple districts fully
- [ ] Database integration (SQLite)
- [ ] Admin panel for election management
- [ ] Vote counting algorithms
- [ ] Export results to PDF/CSV
- [ ] Multi-language support
- [ ] GUI implementation

## 👥 Sample Data

The system comes with pre-populated sample data:
- **17 registered users** with various statuses
- **25 candidates** across 5 political parties
- **100+ sample votes** for testing

### Test Credentials
```
NIC: 200012345678
Password: password123
District: Colombo
Status: ACTIVE
```

## 📜 License

This project is developed for educational purposes as part of a programming course.

## 👨‍💻 Contributing

This is an academic project. For suggestions or improvements:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## 📞 Support

For issues or questions:
- Create an issue in the repository
- Contact the development team
- Refer to the in-system instructions (Option 5 in Main Menu)

## 🙏 Acknowledgments

- Inspired by the Sri Lankan Parliamentary Election System
- Developed using C programming language
- Console-based UI with ANSI color support

---

**Note**: This is a simulation system for educational purposes and does not represent an official election system.

**Version**: 1.0.0  
**Last Updated**: October 2025  
**Developed for**: Sri Lanka Parliamentary Election Simulation
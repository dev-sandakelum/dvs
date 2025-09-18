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
├── index.c          # Main program entry point
├── menu.c           # Main menu and navigation system
├── fun.c            # Utility functions (UI, colors, formatting)
├── register.c       # User registration functionality
├── login.c          # User authentication system
├── vote.c           # Voting mechanism implementation
├── results.c        # Results display and analytics
└── data/            # Database files
    ├── users.txt        # Registered voter information
    ├── candidates.txt   # Election candidates by party
    ├── votes.txt        # Cast votes records
    └── parties.txt      # Political party information
```

## 💾 Database Structure

### Users Database (`users.txt`)
```
Format: NIC,Name,Password,Age,District,Status
Example: 200012345678,Arjun Wijesinghe,password123,24,Colombo,ACTIVE
```

### Candidates Database (`candidates.txt`)
```
Format: CandidateID,Name,Party,Position  
Example: 001,Amal Liyanage,Blue Party,1
```

### Votes Database (`votes.txt`)
```
Format: VoteID,VoterNIC,PartyVoted,Candidate1,Candidate2,Candidate3
Example: V001,200012345678,Blue Party,001,003,005
```

### Parties Database (`parties.txt`)
```
Format: PartyCode,PartyName,Symbol,Color
Example: BP,Blue Party,Flower,Blue
```

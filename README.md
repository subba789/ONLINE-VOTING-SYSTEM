# ONLINE-VOTING-SYSTEM
Led the development of an Online Voting System in C, demonstrating expertise in data structures and file handling, overseeing candidate and voter management features.

1. Header Files: The code includes the necessary header files such as `<stdio.h>`, `<stdlib.h>`, `<string.h>`, and `<windows.h>` for standard input-output operations, memory allocation, string manipulation, and Windows-specific functions respectively.

2. Constants: It defines two constants `pass` and `mainpass`, presumably for passwords to access certain functionalities.

3. Data Structures: 
   - `candidate`: It defines a structure for a candidate with fields like name, votes received, and a pointer to the next candidate.
   - `voter`: It defines a structure for a voter with fields like ID, a flag indicating if the voter has voted or not, and a pointer to the next voter.
   
4. Global Variables: 
   - `head`: A global variable to store the head of the candidate list.
   - `vhead`: A global variable to store the head of the voter list.
   - `cfile` and `vfile`: Global variables to store file names for candidates' and voters' data respectively.

5. Functions:
   - `load_candidates()`: Loads candidate data from a file.
   - `load_voters()`: Loads voter data from a file.
   - `find_candidate()`: Finds a candidate by name and returns its pointer.
   - `find_voter()`: Finds a voter by ID and returns its pointer.
   - `create_candidate()`: Creates a new candidate and adds it to the list.
   - `create_voter()`: Creates a new voter and adds it to the list.
   - `display_candidates()`: Displays all candidates and their votes.
   - `display_voters()`: Displays all voters and their voting status.
   - `cast_vote()`: Casts a vote for a given voter ID and candidate name.
   - `declare_winner()`: Declares the winner of the election based on maximum votes.
   - `save_candidates()`: Saves candidates' data to a file.
   - `save_voters()`: Saves voters' data to a file.
   - `main()`: The main function that provides a menu-driven interface for admins to manage candidate registration, voter registration, voting process, and winner declaration.

6. Flow:
   - Admins are required to input passwords to access certain functionalities.
   - Admins can register candidates and voters.
   - Voters can cast their votes after entering their voter ID and selecting their preferred candidate.
   - After the voting process, admins can declare the winner based on maximum votes.
   - Data about candidates and voters are stored in files for persistence.


# PROCview - CSC403 Project



## Problem Statement

> Write a code to create a user command `my_ps` such that it merges the information of commands `ps aux` & `ps -eLf`.
>
> The desired output combines specific columns from both commands to provide a comprehensive view of system processes, including thread and resource utilization details.

## Description

`PROCview` is a C program designed for the CSC403 Project. It executes standard Linux process monitoring commands (`ps -eLf` and `ps aux`) and merges their output into a single, unified view. It matches processes based on their Process ID (PID) to combine thread information with resource usage statistics.

The program generates a tab-separated output containing the following columns:

| # | Column | Description |
|---|---|---|
| 1 | **UID** | User ID |
| 2 | **PID** | Process ID |
| 3 | **PPID** | Parent Process ID |
| 4 | **LWP** | Light Weight Process (Thread ID) |
| 5 | **C** | Processor Utilization |
| 6 | **NLWP** | Number of Light Weight Processes (Threads) |
| 7 | **%CPU** | CPU Usage Percentage |
| 8 | **%MEM** | Memory Usage Percentage |
| 9 | **VSZ** | Virtual Memory Size |
| 10 | **RSS** | Resident Set Size |
| 11 | **TTY** | Terminal Type |
| 12 | **STAT** | Process State |
| 13 | **START** | Start Time |
| 14 | **TIME** | CPU Time |
| 15 | **COMMAND** | Command Name/Line |

## Setup & Execution

Follow these steps to compile and run the project:

### Step 1: Clone and Navigate
First, clone the repository and navigate into the project directory:
```bash
git clone https://github.com/Arghajit-Saha/CSC403-PROCview.git
cd CSC403-PROCview
```

### Step 2: Compile and Setup Alias
Run the following single-line command to compile the source code and create a temporary alias for ease of use:
```bash
gcc main.c -o my-ps && alias my_ps='./my-ps'
```

### Step 3: Run the Command
Once the alias is set, simply execute:
```bash
my_ps
```

## Submission Requirement

After running the program, please take a screenshot of the terminal output and save it in the `screenshot_output` folder with the filename format: `<Name>_output` (e.g., `Arghajit_Saha_output.png`).

## Output Format

The output is a tab-separated list of processes. Example:

```text
UID     PID     PPID    LWP     C       NLWP    %CPU    %MEM    VSZ     RSS     TTY     STAT    START   TIME    COMMAND
root    1       0       1       0       1       0.0     0.4     167156  13372   ?       Ss      Feb14   0:02    /sbin/init
argha   1234    1       1234    0       1       1.2     2.1     543210  45678   pts/0   R+      10:00   0:05    ./my_ps
...
```

## Files

-   `main.c`: The main source code file.
-   `txt_output/`: Directory where the output text file is saved.
-   `screenshot_output/`: Directory for storing screenshots of the output.

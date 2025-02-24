# Pipex

## Introduction

Pipex is a 42 School project that involves reproducing the behavior of shell piping (`|`). The goal is to gain a deeper understanding of process management, file descriptors, and inter-process communication using pipes in C.

## Features

- Simulates shell piping for two commands
- Handles input and output redirection
- Uses `fork()`, `execve()`, `pipe()`, and `dup2()`
- Supports handling of absolute and relative paths
- Manages errors gracefully

## Installation

### Prerequisites

- `gcc`
- `Make`

### Build

```sh
# Clone the repository
git clone https://github.com/yubi42/pipex.git
cd pipex

# Compile the program
make
```

### Run

```sh
./pipex infile "cmd1" "cmd2" outfile
```

## Usage

Pipex mimics the behavior of the following shell command:

```sh
< infile cmd1 | cmd2 > outfile
```

### Example

```sh
$ echo "Hello, World!" > input.txt
$ ./pipex input.txt "cat" "wc -w" output.txt
$ cat output.txt
2
```

## Error Handling

- Displays an error message if incorrect arguments are provided
- Handles failures in system calls such as `open()`, `pipe()`, and `execve()`
- Ensures proper memory management and process cleanup

## Contributors

- yubi42


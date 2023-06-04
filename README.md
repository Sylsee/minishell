# MiniShell

A minimal Unix shell project written in C.

## Description

MiniShell is a simplified shell that imitates the behavior of a Bash shell. It can search and launch executables based on the PATH variable or using a relative or absolute path. The shell also includes handling of environment variables, redirections, pipes, and a few built-in commands.

## Features

- Maintain a working history of commands.
- Support for relative and absolute path execution.
- Redirections: **<**, **>**, **<<**, **>>**
- Pipes using **|**
- Environment variables
- Special **$?** variable for the exit status of the most recently executed foreground pipeline.
- Interactive mode:
  - **ctrl-C**: displays a new prompt on a new line
  - **ctrl-D**: exits the shell
- Built-in commands:
  - **echo** with option -n
  - **cd** with only a relative or absolute path
  - **pwd**
  - **export**
  - **unset**
  - **env**
  - **exit**

## Installation

1. Clone this repository:
   ```
   git clone https://github.com/<your-username>/minishell.git
   ```
2. Enter the repository:
   ```
   cd minishell
   ```
3. Compile the project:
   ```
   make all
   ```
4. Run the shell:
   ```
   ./minishell
   ```

## Usage

```sh
./minishell
```

## License

MiniShell is licensed under the [LICENSE](LICENSE).

## Contact

If you want to contact me you can reach me at spoliart@student.42.fr.

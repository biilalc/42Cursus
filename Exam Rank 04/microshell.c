//By: bcayir <bcayir@student.42kocaeli.com.tr

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	g_fd; // Global variable to keep track of the file descriptor for the pipe

static int	print(char *str) // Function to print a string to standard error
{
	int	len = 0;

	while (str[len]) len++; // Get the length of the string
	write(2, str, len); // Write the string to standard error
	return (1);
}

static int	exec(char **av, int i, char **env) // Function to execute a command
{
	int	status;
	int	fd[2];
	int	pid;
	int	next = 0;

	if (av[i] && strcmp(av[i], "|") == 0) next = 1; // Check if there is a pipe symbol in the arguments
	if (av[i] == *av) return (0); // If the command is the first argument, return
	if (pipe(fd) == -1) return (print("error: fatal\n")); // Create a pipe

	pid = fork(); // Create a child process

	if (pid == -1) return (print("error: fatal\n")); // Check if fork failed
	else if (pid == 0) // Child process
	{
		close(fd[0]);
		dup2(g_fd, 0); // Redirect the input to the previous output
		av[i] = 0;
		if (next) dup2(fd[1], 1); // If there is a next command, redirect the output to the pipe
		if (g_fd != 0) close(g_fd); // Close the previous output if it's not standard input
		close(fd[1]);
		if (execve(*av, av, env) == -1) // Execute the command
		{
			print("error: cannot execute "); // If execve fails, print an error message
			print(*av);
			print("\n");
			exit(0);
		}
	}
	else // Parent process
	{
		close(fd[1]);
		waitpid(pid, &status, 0); // Wait for the child process to finish
		if (g_fd != 0) close(g_fd); // Close the previous output if it's not standard input
		if (next) g_fd = dup(fd[0]); // If there is a next command, redirect the input to the pipe
		close(fd[0]);
	}
	return (0);
}

static int	built_cd(char **av) // Function to handle the built-in command "cd"
{
	if (av[2] && strcmp(av[2], "|") != 0 && strcmp(av[2], ";") != 0) // Check if there are any invalid arguments
		return (print("error: cd: bad arguments\n"));
	if (chdir(av[1]) == -1) // Change the current working directory (cwd)
		return (print("error: cannot execute cd\n"));
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	i = 1;

	if (ac == 1) return (0); // If there are no arguments, return
	av[ac] = 0;
	while (av[i - 1] && av[i]) // Loop through the arguments
	{
		av += i;
		i = 0;
		
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0) i++; // Get the index of the next command separator
		if (!strcmp(*av, "cd")) built_cd(av); // If the command is "cd", call the built-in function
		else exec(av, i, env); // Otherwise, execute the command
		i++;
	}
}

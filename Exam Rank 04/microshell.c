#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	g_fd; // Global variable to keep track of the file descriptor for the pipe

static int	print(char *str) // Function to print a string to standard error
{
	int	len = 0;

	while (str[len]) // Get the length of the string
		len++;
	write(2, str, len); // Write the string to standard error
	return (1);
}

static int	exec(char **av, int i, char **env) // Function to execute a command
{
	int	status;
	int	fd[2];
	int	pid;
	int	next = 0;

	if (av[i] && strcmp(av[i], "|") == 0) // Check if there is a pipe symbol in the arguments
		next = 1;
	
	if (av[i] == *av) // If the command is the first argument, return
		return (0);

	if (pipe(fd) == -1) // Create a pipe
		return (print("error: fatal\n"));

	pid = fork(); // Create a child process

	if (pid == -1) // Check if fork failed
		return (print("error: fatal\n"));
	else if (pid == 0) // Child process
	{
		close(fd[0]);
		dup2(g_fd, 0); // Redirect the input to the previous output
		av[i] = 0;
		if (next) // If there is a next command, redirect the output to the pipe
			dup2(fd[1], 1);
		if (g_fd != 0) // Close the previous output if it's not standard input
			close(g_fd);
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
		if (g_fd != 0) // Close the previous output if it's not standard input
			close(g_fd);
		if (next) // If there is a next command, redirect the input to the pipe
			g_fd = dup(fd[0]);
		close(fd[0]);
	}
	return (0);
}

static int	built_cd(char **av) // Function to handle the built-in command "cd"
{
	// Check if there are any invalid arguments
	if (av[2] && strcmp(av[2], "|") != 0 && strcmp(av[2], ";") != 0)
		return (print("error: cd: bad arguments\n"));
	// Change the current working directory (cwd)
	if (chdir(av[1]) == -1)
		return (print("error: cannot execute cd\n"));
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	i = 1;

	if (ac == 1) // If there are no arguments, return
		return (0);
	av[ac] = 0;
	while (av[i - 1] && av[i]) // Loop through the arguments
	{
		av += i;
		i = 0;
		// Get the index of the next command separator
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		if (!strcmp(*av, "cd")) // If the command is "cd", call the built-in function
			built_cd(av);
		else // Otherwise, execute the command
			exec(av, i, env);
		i++;
	}
}

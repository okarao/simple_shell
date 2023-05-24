#include "shell.h"


/**
 * find_command_path - Finds the full path of a command by searching through the directories in PATH
 * @cmd: Command passed from getline in main
 *
 * Return: Pointer to the new_path string on success, NULL if command not found
 */
char *find_command_path(char *cmd)
{
	char *path = _strdup(_getenv("PATH"));
	char *path_token, *command_path = NULL;
	struct stat buf;

	if (!path)
		return NULL;

	if (_getenv("PATH")[0] == ':' && stat(cmd, &buf) == 0)
		return _strdup(cmd);

	path_token = strtok(path, ":");
	while (path_token)
	{
		command_path = malloc((_strlen(path_token) + _strlen(cmd) + 2) * sizeof(char));
		if (!command_path)
		{
			free(path);
			return NULL;
		}

		_strcpy(command_path, path_token);
		_strcat(command_path, "/");
		_strcat(command_path, cmd);

		if (stat(command_path, &buf) == 0)
		{
			free(path);
			return command_path;
		}

		free(command_path);
		path_token = strtok(NULL, ":");
	}

	free(path);

	/* Check if cmd is available locally */
	if (stat(cmd, &buf) == 0)
		return _strdup(cmd);

	return NULL;
}


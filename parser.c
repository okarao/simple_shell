#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command
 * @info: The info struct
 * @path: Path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	if (!path || stat(path, &st) != 0)
		return 0;

	return S_ISREG(st.st_mode);
}

/**
 * find_path - Finds the full path of a command in the PATH string
 * @info: The info struct
 * @pathstr: The PATH string
 * @cmd: The command to find
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;

	if (!pathstr)
		return NULL;

	if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return cmd;
	}

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			char *path = dup_chars(pathstr, curr_pos, i);
			_strcat(path, "/");
			_strcat(path, cmd);

			if (is_cmd(info, path))
				return path;

			if (!pathstr[i])
				break;

			curr_pos = i + 1;
		}
		i++;
	}

	return NULL;
}


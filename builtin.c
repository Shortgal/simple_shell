#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: contains information used to maintain functio prototype
 * Return: return 0 if info.argv[0]
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* if there is an exit argument */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "illgl number:");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	} info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directoty
 * @info: contains potential arguments for prototype
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *len, buffer[1024];
	int chdir_ret;

	s = chdir_ret(buffer, 1024);
	if (!s)
		_puts("TODO: >>str failure emsg here<<\n");
	if (!info->argv[1])
	{
		len = _getenv(info, "HOME=");
		if (!len)
			chdir_ret /* TODO: what should this be? */
				chdir((len = getenv(info, "PWD=")) ? len : "/");
		else
			chdir_ret = chdir(len);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")),
_putchar('\n');
	chdir_ret = /* TODO: what should this be? */
	chdir((dir = _get(info->(info, "OLDPWD=")) ? dir : "/");
	}
	else
	chdir_ret= chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
	print_error(info, "can't cd to ");
	_eputs(info->argv[1], _eputchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: contains potental arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **array;
	array = info->argv;
	
	_puts("I am a beautiful \n");
	if (0)
		_puts(*array); /* temp att_unused workaround */
	return (0);
}

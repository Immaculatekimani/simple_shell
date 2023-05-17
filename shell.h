#ifndef SHELL_H
#define SHELL_H
#define OUT 0
#define IN 1

/* --Global_Variables-- */
extern char **env;
int forked;

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>


/* locationList */
/**
 * struct locations - Stores adresses
 * @location: Address being stored
 * @next: Pointer to next node in list
 */
typedef struct locations
{
	void *location;
	struct locations *next;
} loc_t;

/* Builtin_Struct*/
/**
 * struct built_ins - Struct for builtins names & ptrs to the function
 * @name: Name of the builtin
 * @func: Points to the function to call from the name
 */
typedef struct built_ins
{
	char *name;
	int (*func)();
} builtins_t;

/* --Help Struct --*/
/**
 * struct help_struct - for descriptions of builtins
 * @name: Name of builtin
 * @func: print the help for the named function
 */
typedef struct help_struct
{
	char *name;
	void (*func)();
} help_t;


/* --General Functions-- */
void shell_loop(void);
char **create_arg(char *input);
int wordcount(char *st);
char *tokenize(char *input, const char *delim, char **saveptr);
void display(char **commands);
void run_shell(char **commands);
void sighandler(int sig_digit);
int is_arg(char *first_com, char *arg0);

/* memory_functions */
void clear_arr(char **vector);
void *mem_alloc(size_t size);

/* path_functions */
char **is_path(char **commands);
char *concat_path(char *s1, char *s2);
char *path_copy(char *name);

/* builtin_functions */
int is_builtins(char **commands, char *input);
int print_environ(char **commands);
int set_environ(char **commands);
int unset_environ(char **commands);
int shell_exit(char **commands, char *input);
int shell_help(char **commands);

/* environment_functions */
int unset_env(char *name);
char *find_env(char *name);
int add_env(char *new_arr, char *name);

/* print_functions*/
void _push(char *str);
int _putchar(char c);

/* string_functions */
char *_strdup(char *str);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, char *accept);
int _strspn(char *s, const char *accept);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/* number_functions */
int _atoi(char *st);

/* helpers */
void push_exit(void);
void push_env(void);
void push_setenv(void);
void push_unsetenv(void);
void push_help(void);
void display_help(void);
#endif /* SHELL_H */

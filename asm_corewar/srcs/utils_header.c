#include "asm.h"

/*
** add_backlash_to_name - ajoute au .name existant un \n
*/

void		add_backslash_to_name(t_header *header, char *str)
{
	if (header->name_length < PROG_NAME_LENGTH)
		header->prog_name[header->name_length++] = '\n';
	else
		header_error(NAME_TOO_LONG, 0, str);
}

/*
** add_backlash_to_comment - ajoute au .comment existant un \n
*/

void		add_backslash_to_comment(t_header *header, char *str)
{
	if (header->comment_length < COMMENT_LENGTH)
		header->comment[header->comment_length++] = '\n';
	else
		header_error(COMMENT_TOO_LONG, 0, str);
}

/*
** header_is_set - fonction qui vérifie a chaque GNL
** si ce que l'on recherche est set
*/

int			header_is_set(t_header *header)
{
	if (!header->name_is_set || !header->comment_is_set)
		return (0);
	return (1);
}

/*
** add_to_header - ajoute le contenu soit a .name soit a .comment
*/

void		add_to_header(char *line, t_header *header, int line_nb)
{
	if (header->name_is_set == 0)
		add_to_name(line, header, line_nb);
	else
		add_to_comment(line, header, line_nb);
}
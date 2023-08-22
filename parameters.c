#include "main.h"

/**
 * init_params - clear struct fields
 * @params: para
 * @va: argument
 * Return: void
*/

void init_params(params_t *params, va_list va)
{
	params->unsign = 0;
	params->plusflag = 0;
	params->hashtagflag = 0;
	params->negativeflag = 0;
	params->zeroflag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)va;
}

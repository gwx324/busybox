#include <stdlib.h>
#include <string.h>
#include "libbb.h"

/*
 * Returns a [multi-line] package field
 */
extern char *read_package_field(const char *package_buffer)
{
	int field_length = 0;	
	int buffer_length = 0;

	if (package_buffer == NULL) {
		return(NULL);
	}
	buffer_length = strlen(package_buffer);
	field_length = strcspn(package_buffer, "\n");
	while (field_length < buffer_length) {
		if (package_buffer[field_length + 1] != ' ') {
			return(xstrndup(package_buffer, field_length));
		}
		field_length++;
		field_length += strcspn(&package_buffer[field_length], "\n");
	}
	return(xstrdup(package_buffer));
}


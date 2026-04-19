#include "row.h"

#include <stdio.h>
#include <string.h>

#define size_of_attribute(Struct, Attribute) sizeof(((Struct *)0)->Attribute)

const uint32_t ID_SIZE = size_of_attribute(Row, id);
const uint32_t USERNAME_SIZE = size_of_attribute(Row, username);
const uint32_t EMAIL_SIZE = size_of_attribute(Row, email);
const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

void print_row(const Row *row)
{
	printf("(%d, %s, %s)\n", row->id, row->username, row->email);
}

void serialize_row(void *dest, const Row *src)
{
	memcpy(dest + ID_OFFSET, &(src->id), ID_SIZE);
	memcpy(dest + USERNAME_OFFSET, &(src->username), USERNAME_SIZE);
	memcpy(dest + EMAIL_OFFSET, &(src->email), EMAIL_SIZE);
}

void deserialize_row(Row *dest, const void *src)
{
	memcpy(&(dest->id), src + ID_OFFSET, ID_SIZE);
	memcpy(&(dest->username), src + USERNAME_OFFSET, USERNAME_SIZE);
	memcpy(&(dest->email), src + EMAIL_OFFSET, EMAIL_SIZE);
}

#ifndef __HASHCODE_H__
#define __HASHCODE_H__

#include <string>

int hashCode(bool key);
int hashCode(char key);
int hashCode(double key);
int hashCode(float key);
int hashCode(int key);
int hashCode(long key);
int hashCode(const char* str);
int hashCode(const std::string& str);
int hashCode(void* key);

#endif /*__HASHCODE_H__*/

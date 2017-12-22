#pragma once
template <typename T>
static bool defaultCompare(const T &key1, const T &key2) {
	return key1 < key2;
}


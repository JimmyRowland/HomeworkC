#pragma once
namespace cs20a {
	template<class K, class V>
	struct kvpair {
		kvpair() {}
		kvpair(K key, V value = V()) : key(key), value(value) {}
		kvpair(const kvpair<K, V> & kvp) : key(kvp.key), value(kvp.value) {}

		void operator =(const kvpair<K, V> & rhs) {
			key = rhs.key;
			value = rhs.value;
		}

		bool operator==(const kvpair<K, V> & a) const { return key == a.key; }
		bool operator!=(const kvpair<K, V> & a) const { return key != a.key; }
		bool operator < (const kvpair<K, V> & a) const { return key < a.key; }
		bool operator <= (const kvpair<K, V> & a) const { return key <= a.key; }
		bool operator > (const kvpair<K, V> & a) const { return key > a.key; }
		bool operator >= (const kvpair<K, V> & a) const { return key >= a.key; }

		K key;
		V value;
	};
}
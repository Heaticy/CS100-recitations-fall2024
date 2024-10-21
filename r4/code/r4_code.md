---
marp: true
math: mathjax
paginate: true
style: |
  section::after {
    content: attr(data-marpit-pagination) '/' attr(data-marpit-pagination-total);
  }

  .columns {
    display: grid;
    grid-template-columns: repeat(2, minmax(0, 1fr));
    gap: 1rem;
  }

---

# Recitation 4 Code

## From Xiao Liu

---

# Exercise 1

- **`int** const`**: A `const` pointer to a pointer to an `int`.
  - The pointer itself is constant and cannot change, but the `int` it points to can be modified.
- **`int* const*`**: A pointer to a `const` pointer to an `int`.
  ```c
  int a = 42;
  int* const p = &a; // const pointer to int
  int* const* ptr = &p; // pointer to a const pointer
  ```
  - The `const` pointer cannot change, but the `int` it points to can.
- **`int const**`** or **`const int**`**: A pointer to a pointer to a `const int`.
  - The `int` is `const` and cannot be modified, but the pointers can change.
- **`int* const* const`**: A `const` pointer to a `const` pointer to an `int`.
  - Both pointers are `const` and cannot change, but the `int` can be modified.

---

# Exercise 2

Most people cannot resist the urge to use **indexing** and thus call `strlen` first:

```c
char *strcpy(char *dest, const char *src) {
  size_t length = strlen(src);
  for (size_t i = 0; i <= length; ++i)
    dest[i] = src[i];
  return dest;
}
```

However, `strlen` also scans the `src` string.
- Why scan it twice?

---

# Exercise 2

It is possible to scan only once: the termination condition should be **when encountering `'\0'`**, rather than `i == strlen(src)`.

```c
char *strcpy(char *dest, const char *src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
  return dest;
}
```

---

# Exercise 2: A More Direct Approach

You can directly **manipulate pointers** without needing indexing.

- Both `dest` and `src` are local variables within your function, so you can modify them freely!

```c
char *strcpy(char *dest, const char *src) {
  char *ret = dest;
  while (*src != '\0')
    *dest++ = *src++;
  *dest = '\0';
  return ret;
}
```

```c
char a[100], b[] = "hello";
strcpy(a, b); // This works fine.
```

---

# Recitation 4 Code

## From Xiao Liu